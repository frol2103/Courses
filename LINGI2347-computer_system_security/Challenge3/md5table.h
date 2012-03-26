#ifndef MD5TABLE

#define MD5TABLE
#define DEFAULT_SIZE 50000000

#include "passchain.h"
#include "md5chainedlist.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Md5Table
{
    Md5ChainedList**    table;
    int                 size;       //the number of elements in the table
    int                 capacity;   //the length of the array
    int hash(PassChain* pc) {return (pc->getEnd() % capacity);}
    private:
        void init(int capacity);
    public : 
        Md5Table(){init(DEFAULT_SIZE);}
        Md5Table(int capacity){init(capacity);}
        void insert(PassChain* pc);
        PassChain* getMatch(PassChain * ref);
        void fromFile(string filePath);
        void toFile(string filePath);
        string repr();
        int getSize(){return size;}
};
#endif /* end of include guard: MD5TABLE */
