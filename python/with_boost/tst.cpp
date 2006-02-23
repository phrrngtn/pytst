/* 
 # $Id$
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

#include <boost/python.hpp>
using namespace boost::python;

#define SCANNER

#include <string>
#include "tst.h"

/********************* ACTION & FILTER ***********************************/

template <class S, class T> class NullAction : public action<S,T>, public wrapper< action<S,T> > {
    public:
        void perform(const S* string,size_t string_length,int remaining_distance,T data) {
        }
        
        T result() {
            return T();
        }
        
};

template <class S,class T> class DictAction : public action<S,T>, public wrapper< action<S,T> > {
    public:
        void perform(const S* string,size_t string_length,int remaining_distance,T data) {
            str s(string,string_length);
            object r = result_dict.get(s);
            if(!r || (r[0] > remaining_distance) ) {
                result_dict[s] = make_tuple(remaining_distance,data);
            }
        }        
        
        T result() {
            return result_dict;
        }
    
    private:
        dict result_dict;
};

template <class S,class T> class TupleListAction : public action<S,T>, public wrapper< action<S,T> > {
    public:
        void perform(const S* string,size_t string_length,int remaining_distance,T data) {
            str s(string,string_length);
            result_list.append(make_tuple(s,remaining_distance,data));
        }        
        
        T result() {
            return result_list;
        }
    
    private:
        list result_list;
};

template <class S,class T> class ListAction : public action<S,T>, public wrapper< action<S,T> > {
    public:
        void perform(const S* string,size_t string_length,int remaining_distance,T data) {
            result_list.append(data);
        }        
        
        T result() {
            return result_list;
        }
    
    private:
        list result_list;
};

template <class S,class T> class CallableAction : public action<S,T>, public wrapper< action<S,T> > {
    public:
        CallableAction<S,T>(object perform, object result) :
            _perform(perform),
            _result(result) {
        }
    
        void perform(const S* string,size_t string_length,int remaining_distance,T data) {
            _perform(
                str(string,string_length),
                remaining_distance,
                data
            );
        }        
        
        T result() {
            return call<T>(
                _result.ptr()
            );
        }
    
    private:
        object _perform;
        object _result;
};

template <class S, class T> class NullFilter : public filter<S,T>, public wrapper< filter<S,T> > {
    public:
        T perform(const S* string,size_t string_length,int remaining_distance,T data) {
            return data;
        }
};

template <class S,class T> class CallableFilter : public filter<S,T>, public wrapper< filter<S,T> > {
    public:
        CallableFilter<S,T>(object perform) :
            _perform(perform) {
        }
    
        T perform(const S* string,size_t string_length,int remaining_distance,T data) {
        	return _perform(str(string,string_length),remaining_distance,data);
        }        
    
    private:
        object _perform;
};

/********************* SERIALIZER ***********************************/

class ObjectSerializer {
    public:
        ObjectSerializer();
        
        void write(FILE* file,object data);
        object ObjectSerializer::read(FILE* file);
    
        void write_to_file(object file,object data);
        object ObjectSerializer::read_from_file(object file);
    
    private:
        object dumps,loads;
};

ObjectSerializer::ObjectSerializer() {
    object cPickle(handle<>(PyImport_ImportModule("cPickle")));
    dumps = cPickle.attr("dumps");
    loads = cPickle.attr("loads");
}

void ObjectSerializer::write(FILE* file,object data) {
    str result = (str)dumps(data,2);
    char *string;
    int length;
    PyString_AsStringAndSize(result.ptr(),&string,&length);
    fwrite(&length,sizeof(int),1,file);
    fwrite(string,sizeof(char),length,file);
}

void ObjectSerializer::write_to_file(object file,object data) {
    return write(PyFile_AsFile(file.ptr()),data);
}

object ObjectSerializer::read(FILE* file) {
    int length;
    fread(&length,sizeof(int),1,file);
    char* string=(char*)tst_malloc(length);
    fread(string,sizeof(char),length,file);
    
    str dumped(string,length);
    object result = loads(dumped);
    tst_free(string);
    return result;
}

object ObjectSerializer::read_from_file(object file) {
    return read(PyFile_AsFile(file.ptr()));
}

/********************* ITERATOR ***********************************/

class TST;

template <typename iterator_type> class TSTIterator {
    private:
        friend class TST;
        
    public:
        TSTIterator copy() {
            return *this;
        }
    
        tuple next() {
            iterator_type::value_type v = iterator.next();
            if(v.second) {
                return make_tuple(v.first,*(v.second));
            } else {
                object exception(handle<>(
                    PyImport_ImportModule("exceptions"))
                );
                exception = exception.attr("StopIteration");
                PyErr_SetNone(exception.ptr());
                throw_error_already_set();
                
                // ( this is never called, it's just to remove the warning )
                return make_tuple();
            }
        }
    
    private:
        TSTIterator(iterator_type i) : iterator(i) {
        }
        
        iterator_type iterator;
};

typedef lexical_iterator<char,object,memory_storage<char,object>,ObjectSerializer> lexical_iterator_type;
typedef match_iterator<char,object,memory_storage<char,object>,ObjectSerializer> close_match_iterator_type;
typedef TSTIterator<lexical_iterator_type> TSTLexicalIterator;
typedef TSTIterator<close_match_iterator_type> TSTCloseMatchIterator;

/********************* TST ***********************************/

class TST : public string_tst<char,object,memory_storage<char,object>,ObjectSerializer> {
    public:
        TST() : string_tst<char,object,memory_storage<char,object>,ObjectSerializer>() {
        }
    
        void write_to_file(object file) const {
            this->write(PyFile_AsFile(file.ptr()));
        }
    
        void read_from_file(object file) {
            this->read(PyFile_AsFile(file.ptr()));
        }

        TSTLexicalIterator iterator1() {
            return TSTLexicalIterator(string_tst<char,object,memory_storage<char,object>,ObjectSerializer>::iterator());
        }
        
        TSTLexicalIterator iterator2(std::basic_string<char> s) {
            return TSTLexicalIterator(string_tst<char,object,memory_storage<char,object>,ObjectSerializer>::iterator(s.c_str(),s.size()));
        }
        
        TSTCloseMatchIterator close_match_iterator(std::basic_string<char> s, int distance) {
            return TSTCloseMatchIterator(string_tst<char,object,memory_storage<char,object>,ObjectSerializer>::close_match_iterator(s.c_str(),s.size(),distance));
        }
};

BOOST_PYTHON_MODULE(tst)
{
    filter<char,object> *test = new NullFilter<char,object>;
    action<char,object> *test2 = new NullAction<char,object>;

    scope().attr("TST_VERSION") = std::string(TST_VERSION)+"-Boost.Python";

    class_< TSTLexicalIterator >("TSTLexicalIterator",no_init)
        .def("__iter__",&TSTLexicalIterator::copy)
        .def("copy",&TSTLexicalIterator::copy)
        .def("next",&TSTLexicalIterator::next)
    ;

    class_< TSTCloseMatchIterator >("TSTCloseMatchIterator",no_init)
        .def("__iter__",&TSTCloseMatchIterator::copy)
        .def("copy",&TSTCloseMatchIterator::copy)
        .def("next",&TSTCloseMatchIterator::next)
    ;

    class_< TST >("TST")
        .def("put",&TST::put)
        .def("__setitem__",&TST::put)
        
        .def("get",&TST::get)
        .def("__getitem__",&TST::get)
        
        .def("__delitem__",&TST::remove)
        
        .def("contains",&TST::contains)
        .def("__contains__",&TST::contains)

        .def("get_or_build",&TST::get_or_build)
        
        .def("get_maximum_key_length",&TST::get_maximum_key_length)
        
        .def("get_number_of_nodes",&TST::get_number_of_nodes)

        .def("remove",&TST::remove)

        .def("scan",&TST::scan)
        .def("scan_with_stop_chars",&TST::scan_with_stop_chars)

        .def("write_to_file",&TST::write_to_file)
        .def("read_from_file",&TST::read_from_file)

        .def("walk",&TST::walk1)
        .def("walk",&TST::walk2)

        .def("close_match",&TST::close_match)
        .def("prefix_match",&TST::prefix_match)

        .def("pack",&TST::pack)

        .def("__iter__",&TST::iterator1)
        .def("iterator",&TST::iterator1)
        .def("iterator",&TST::iterator2)
        .def("close_match_iterator",&TST::close_match_iterator)
    ;
    
    class_< NullAction<char,object>, boost::noncopyable >("NullAction")
    ;

    class_< DictAction<char,object>, boost::noncopyable >("DictAction")
        .def("result", &DictAction<char,object>::result)
    ;

    class_< TupleListAction<char,object>, boost::noncopyable >("TupleListAction")
        .def("result", &TupleListAction<char,object>::result)
    ;

    class_< ListAction<char,object>, boost::noncopyable >("ListAction")
        .def("result", &ListAction<char,object>::result)
    ;

    class_< CallableAction<char,object>, boost::noncopyable >("CallableAction",init<object,object>())
        .def("result", &CallableAction<char,object>::result)
    ;

    class_< NullFilter<char,object>, boost::noncopyable >("NullFilter")
    ;

    class_< CallableFilter<char,object>, boost::noncopyable >("CallableFilter",init<object>())
    ;
}
