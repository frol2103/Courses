
#include "util.h"
#include "md5i.h"
#include "md5table.h"
#include "passchain.h"
#include <sstream>
#include <stdio.h> 
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000000
using namespace std;


void generateRandom()
{

    cout << "random " << endl;
    ostringstream filename;
    Md5Table mt = Md5Table();
    unsigned int i;
    for (i = 0; i <= MAX_SIZE; i++)
    {
        if ((i%1000)==0)
        {
            cout << i << endl;
            cout << i << " " << mt.getSize() << endl;
        }
        unsigned int r = rand() * RAND_MAX + rand();
        PassChain * pc = new PassChain(r);
      //  cout << pc->getStart() << " - " << pc->getEnd() << endl;
        mt.insert(pc);
    }
    filename << "precRand/s" << CHAIN_LENGTH << "-r" << rand() << ".bin";
    cout << "saved in : " << filename.str() << endl;
    mt.toFile(filename.str());
}

void generateSorted(int from, int to)
{
    ostringstream filename;
    cout << "from " << from << " to  " << to << endl;
    Md5Table mt = Md5Table();
    unsigned int i;
    for (i = from; i <= to; i++)
    {
        if ((i%1000)==0)
            cout << i << endl;
        mt.insert(new PassChain(i));
    }
    filename << "s" << CHAIN_LENGTH << "-f" << from << "-t" << to << ".bin";
    cout << "saved in : " << filename.str() << endl;
    mt.toFile(filename.str());
    
}

int main(int argc, const char *argv[])
{
    ostringstream filename;
    unsigned int from,to;
    if (argc == 3)
    {
        from = atoi(argv[1]);
        to = atoi(argv[2]);
        generateSorted(from,to);
    }else{
        srand ( time(NULL) );
        generateRandom();
    }

    
    return 0;
}


