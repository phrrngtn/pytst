/* 
 # $Id: tst.h 1566 2006-01-03 14:23:03Z nlehuen $
 # Copyright (C) 2004-2005 Nicolas Lehuen <nicolas@lehuen.com>
 #
 # This library is free software; you can redistribute it and/or
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # This library is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __ITERATORS__H_INCLUDED__
#define __ITERATORS__H_INCLUDED__

#include <string>
#include <stack>

template< typename S,typename T,typename M,typename RW > class lexical_iterator {
    public:
        enum state_enum {
            state_left, state_current, state_right, state_end    
        };

        class state_type {
            public:
                state_type(std::basic_string<S> k,state_enum s,int n) : key(k), state(s), node(n) {
                }
            
                std::basic_string<S> key;
                state_enum state;
                int node;
        };

        typedef std::pair< std::basic_string<S>, T* > value_type;

        lexical_iterator(const tst<S,T,M,RW> *t,std::basic_string<S> key,int root) : tree(t), stack() {
            stack.push(state_type(key,state_left,root));
        }

        value_type next() {
            while(!stack.empty()) {
                state_type& state = stack.top();

                if(state.node==UNDEFINED_INDEX) {
                    break;
                }

                tst_node<S,T>* node = tree->storage->get(state.node);
            
                switch(state.state) {
                    case state_left: {
                        state.state = state_current;
                        if(node->left!=UNDEFINED_INDEX) {
                            stack.push(state_type(state.key,state_left,node->left));
                            break;
                        }
                    }
                    
                    case state_current: {
                        bool must_break = false;
                        state.state = state_right;

                        if(node->next!=UNDEFINED_INDEX) {
                            state_type new_state = state_type(
                                state.key,
                                state_left,
                                node->next
                            );
                            new_state.key += node->c;
                            stack.push(new_state);
                            must_break = true;
                        }

                        if(node->data != tree->default_value) {
                            std::basic_string<S> new_key(state.key);
                            new_key += node->c;
                            return value_type(
                                new_key,
                                &(node->data)
                            );
                        }
                        else if(must_break) {
                            break;
                        }
                    }
                    
                    case state_right: {
                        state.state = state_end;
                        if(node->right!=UNDEFINED_INDEX) {
                            stack.push(state_type(state.key,state_left,node->right));
                            break;
                        }
                    }
                    
                    case state_end: {
                        stack.pop();
                        break;
                    }
                }
            }
            return value_type("",0);
        }
                
    private:
        const tst<S,T,M,RW> *tree;
        std::stack< state_type > stack;
};

template< typename S,typename T,typename M,typename RW > class match_iterator {
    public:
        enum state_enum {
            state_left, state_current, state_skip_input, state_skip_base, state_right, state_end    
        };

        class state_type {
            public:
                state_type(std::basic_string<S> k,state_enum s,int p,int d,int n) : key(k), state(s), position(p), distance(d), node(n) {
                }
            
                std::basic_string<S> key;
                state_enum state;
                int position;
                int distance;
                int node;
        };

        typedef std::pair< std::basic_string<S>, T* > value_type;

        match_iterator(const tst<S,T,M,RW> *t,std::basic_string<S> string,int distance,int root) : tree(t), stack(), base(string) {
            stack.push(state_type("",state_left,0,distance,root));
        }

        value_type next() {
            while(!stack.empty()) {
                state_type& state = stack.top();

                if(state.node==UNDEFINED_INDEX) {
                    break;
                }

                tst_node<S,T>* node = tree->storage->get(state.node);
            
                int diff = 1;
                if( (state.position < (int)base.size())
                    && (base[state.position]==node->c)) {
                    diff = 0;
                }
                
                switch(state.state) {
                    case state_left: {
                        state.state = state_current;
                        if(node->left!=UNDEFINED_INDEX) {
                            stack.push(state_type(state.key,state_left,state.position,state.distance,node->left));
                            break;
                        }
                    }
                    
                    case state_current: {
                        bool must_break = false;
                        state.state = state_skip_input;

                        if(state.distance>=diff) {
                            if(node->next!=UNDEFINED_INDEX) {
                                state_type new_state = state_type(
                                    state.key,
                                    state_left,
                                    state.position+1,
                                    state.distance-diff,
                                    node->next
                                );
                                new_state.key += node->c;
                                stack.push(new_state);
                                must_break = true;
                            }

                            // Cas o� la cl� courante est plus courte que la cl� recherch�e
                            int diff2 = ((int)base.size())-state.position-1;
                            if(diff2>0) {
                                diff += diff2;
                            }
                            
                            if(state.distance>=diff && node->data != tree->default_value) {
                                value_type result(
                                    state.key,
                                    &(node->data)
                                );
                                result.first += node->c;
                                return result;
                            }
                            else if(must_break) {
                                break;
                            }
                        }
                    }
                    
                    case state_skip_input: {
                        state.state = state_skip_base;
                        
                        if(state.distance>0) {
                            if(node->next!=UNDEFINED_INDEX) {
                                state_type new_state = state_type(
                                    state.key,
                                    state_left,
                                    state.position,
                                    state.distance-1,
                                    node->next
                                );
                                new_state.key += node->c;
                                stack.push(new_state);
                                break;
                            }
                        }
                    }

                    case state_skip_base: {
                        state.state = state_right;
                        
                        if(state.distance>0) {
                            state_type new_state = state_type(
                                state.key,
                                state_left,
                                state.position+1,
                                state.distance-1,
                                state.node
                            );
                            stack.push(new_state);
                            break;
                        }
                    }

                    case state_right: {
                        state.state = state_end;
                        if(node->right!=UNDEFINED_INDEX) {
                            stack.push(state_type(state.key,state_left,state.position,state.distance,node->right));
                            break;
                        }
                    }
                    
                    case state_end: {
                        stack.pop();
                        break;
                    }
                }
            }
            return value_type("",0);
        }
                
    private:
        const tst<S,T,M,RW> *tree;
        std::stack< state_type > stack;
        std::basic_string<S> base;
};

#endif
