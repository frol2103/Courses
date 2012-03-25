#ifndef PASSCHAIN
#define PASSCHAIN
#define CHAIN_LENGTH 1000
#include <string>
#include <sstream>
using namespace std;

class PassChain{
        unsigned int start;
        unsigned int end;
    public:
        PassChain(unsigned int start,unsigned int end);
        PassChain(unsigned int start);
        PassChain();
        unsigned int computeFrom(unsigned int pass, int place);
        unsigned int nextIterFromHash(unsigned char hash[4], int position);
        bool match(PassChain *chain);
        string repr();
        unsigned int getStart(){return start;}
        unsigned int getEnd(){return end;}
    
};


#endif /* end of include guard: PASSCHAIN */

