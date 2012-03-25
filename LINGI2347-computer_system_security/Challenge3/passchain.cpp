#include "passchain.h"
#include "md5i.h"
#include "util.h"
    
#include <iostream>
using namespace std;

PassChain::PassChain()
{
    start   = 0;
    end     = 0;
}


PassChain::PassChain(unsigned int aStart)
{
    start = aStart;
    computeFrom(start,0);
}

PassChain::PassChain(unsigned int aStart, unsigned int aEnd)
{
    start   = aStart;
    end     = aEnd;
}

unsigned int PassChain::computeFrom(unsigned int pass, int place)
{
    int i;
    unsigned char hash[16];
    unsigned int p = pass;
    for(i =place+1; i<CHAIN_LENGTH ;i++)
    {
        md5i_iterate(p, 5, hash); 
        p = nextIterFromHash(hash,i);
    }
    end = p;
    return p;
}


unsigned int PassChain::nextIterFromHash(unsigned char hash[16], int position){    
    unsigned int np = 0;
    int i;
    for(i = 0; i < 32; i++)
    {
        np = np | (get_bit(hash,(i+position)%128)<<i);
    }
    return np;
}
        
bool PassChain::match(PassChain *chain)
{
    return chain->getEnd() == end;
}

string PassChain::repr()
{
    ostringstream oss;
    oss << start << "->" << end;
    return oss.str();
}
