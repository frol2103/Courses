
#include "util.h"
#include "md5i.h"
#include "md5table.h"
#include "passchain.h"
#include <sstream>
#include <stdio.h> 
#include <iostream>
using namespace std;


int main(int argc, const char *argv[])
{
    unsigned int from,to;
    if (argc == 3)
    {
        from = atoi(argv[1]);
        to = atoi(argv[2]);
    }else{
        from = 0;
        to = 10000;
    }
    ostringstream filename;
    filename << "s" << CHAIN_LENGTH << "-f" << from << "-t" << to << ".bin";
    cout << "from " << from << " to  " << to << endl;
    cout << "saved in : " << filename.str() << endl;

    Md5Table mt = Md5Table();
    unsigned int i;
    for (i = from; i <= to; i++)
    {
        if ((i%1000)==0)
            cout << i << endl;
        mt.insert(new PassChain(i));
    }
    mt.toFile(filename.str());
    return 0;
}
