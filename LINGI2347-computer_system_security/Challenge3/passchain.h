#ifndef PASSCHAIN
#define PASSCHAIN
#define CHAIN_LENGTH 10
class PassChain{
        unsigned int start;
        unsigned int end;
    public:
        unsigned int getEnd() {return end;}
        PassChain(unsigned int start,unsigned int end);
        PassChain(unsigned int start);
        PassChain();
        unsigned int computeFrom(unsigned int pass, int place);
        unsigned int nextIterFromHash(unsigned char hash[4], int position);
        bool match(PassChain *chain);
    
};


#endif /* end of include guard: PASSCHAIN */

