#ifndef MD5TABLE

#define MD5TABLE
#define DEFAULT_SIZE 10

#include "passchain.h"
#include "md5chainedlist.h"
#include "stdlib.h"

class Md5Table
{
    Md5ChainedList**    table;
    int                 size;       //the number of elements in the table
    int                 capacity;   //the length of the array
    int hash(PassChain* pc) {return (pc->getEnd() % capacity);}
    public : 
        Md5Table() {Md5Table(DEFAULT_SIZE);}
        Md5Table(int capacity);
        void insert(PassChain* pc);
        PassChain* getMatch(PassChain * ref);

};
#endif /* end of include guard: MD5TABLE */
