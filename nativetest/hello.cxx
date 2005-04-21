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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tst.h"
#include <time.h>

class stringserializer : public serializer<char,char*> {
    virtual void write(FILE* file,char* data) {
        size_t len=strlen(data);
        fwrite(&len,sizeof(int),1,file);
        fwrite(data,sizeof(char),len,file);
    }

    virtual char* read(FILE* file) {
        size_t len;
        fread(&len,sizeof(size_t),1,file);
        char* data=(char*)tst_malloc((len+1)*sizeof(char));
        fread(data,sizeof(char),len,file);
        data[len]='\0';
        return data;
    }
};

class donothing : public action<char,char*> {
    public:
        virtual void perform(char* key,int remaining_distance,char* data);
        virtual char* result();
};

void donothing::perform(char* key,int remaining_distance,char* data) {
}

char* donothing::result() {
    return NULL;
}

class printer : public donothing {
    public:
        virtual void perform(char* key,int remaining_distance,char* data) {
            printf("%s = %s (%i)\n",key,data,remaining_distance);
        }
};

class stringtst : public tst<char,char*> {
    public:
        stringtst() : tst<char,char*>(1600,NULL) {
        }

        virtual ~stringtst() {
            clear_nodes();
        }

        stringtst(FILE* file) : tst<char,char*>() {
            stringserializer* s=new stringserializer();
            read(file,s);
            delete s;
        }

    protected:
       virtual void store_data(tst_node<char,char*>* node,char* data);
};

void stringtst::store_data(tst_node<char,char*>* node,char* data) {
            // printf("sd %x %x %x %s\n",(int)node,(int)node->data,node->c,data);
            if(node->data) {
                // printf("freeing %x\n",(int)node->data);
                tst_free(node->data);
            }
            node->data=data;
        }

class tester : public donothing {
    public:
        tester(tst<char,char*>* mytst) : donothing() {
            this->mytst=mytst;
        }

        virtual void perform(char* key,int remaining_distance,char* data) {
            donothing* dn = new donothing();
            mytst->almost(key,(int)strlen(key),3,NULL,dn);
            mytst->common_prefix(key,NULL,dn);
            delete dn;
        }

    private:
        tst<char,char*>* mytst;
};

int main(int argc,char** argv) {
    tst<char,char*>* linetst=new stringtst();

    clock_t start, end;
    double elapsed;

    start = clock();
    for(int i=0;i<4000000;i++) {
        char line[256];
        sprintf(line,"%d",i);
    }
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Build : %f\n",elapsed);

    start = clock();
    for(int i=0;i<4000000;i++) {
        char line[256];
        sprintf(line,"%d",i);
        linetst->put(line,line);
    }
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Write : %f\n",elapsed);

    linetst->pack();
    linetst->debug_print_root();

    start = clock();
    for(int i=0;i<4000000;i++) {
        char line[256];
        sprintf(line,"%d",i);
        if(strcmp(line,linetst->get(line))!=0) {
            printf("%s != %s\n",line,linetst->get(line));
        }
    }
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Read : %f\n",elapsed);

    /*char line[256];    
    printf("OK...");
    scanf("%s\n",line);*/

    return 0;
}
