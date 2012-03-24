#ifndef MD5CHAINESLIST

#define MD5CHAINESLIST

#include "passchain.h"
#include "stdlib.h"

typedef struct Md5ChainedItem Md5ChainedItem;

struct Md5ChainedItem{
    Md5ChainedItem  * next;
    PassChain       * pc;
};

class Md5ChainedList
{
    Md5ChainedItem* root;
    int             size;
    
    public:
        Md5ChainedList() {size = 0; root = NULL;}
        PassChain* getMatch(PassChain * ref);
        int getSize() {return size;}
        void insert(PassChain* pc);
        
};

#endif /* end of include guard: MD5CHAINESLIST */
