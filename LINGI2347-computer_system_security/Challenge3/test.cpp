#include "util.h"
#include "md5i.h"
#include "md5table.h"
#include "passchain.h"
#include <stdio.h> 
#include <iostream>
using namespace std;

void testHashTable()
{
    unsigned int p1 = 123456789;
    PassChain * pc = new PassChain(p1);
    Md5Table mt = Md5Table();
    mt.insert(pc);
    PassChain * res = mt.getMatch(new PassChain(123456789));
    if(res == NULL)
        cout << "NULL" << endl;
    else
        cout << res->getEnd() << endl;
}

int main(int argc, const char *argv[])
{

    testHashTable();

    return 0;
}
