#ifndef PASSCHAIN
#define PASSCHAIN
#define CHAIN_LENGTH 10
class PassChain{
        unsigned int start;
        unsigned int end;
    public:
        PassChain(unsigned int start,unsigned int end);
        PassChain(unsigned int start);
        PassChain();
        unsigned int computeFrom(unsigned int pass, int place);
        unsigned int nextIterFromHash(unsigned char hash[4], int position);
    
};


#endif /* end of include guard: PASSCHAIN */

