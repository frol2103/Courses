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
    Md5Table mt = Md5Table(10);
    cout << "test1" << endl;
    mt.insert(pc);
    cout << "test2" << endl;
    PassChain * res = mt.getMatch(new PassChain(123456789));
    cout << "passe par ici" << endl;
    if(res == NULL)
        cout << "NULL" << endl;
    else
        cout << res->getEnd() << endl;
}

void testHashTableInOut()
{
    Md5Table mt = Md5Table(10);
    
    mt.toFile("test.bin");
    mt.fromFile("test.bin");
    mt.insert(new PassChain(123456789));
    cout << mt.repr();
}

void computeMd5()
{
    int i;
    unsigned int pass[] = {2404660588,1978320671};
    int lpass = 2;
    unsigned char hash[16];
    for(i = 0; i<lpass; i++)
    {
        cout << pass[i] << endl;
    }
    
    cout << endl;
    cout << endl;
    cout << endl;
    
    for(i = 0; i<lpass; i++)
    {
        md5i_iterate(pass[i],5,hash);
        print_hex(hash,16);
        cout << endl;
    }
}

int main(int argc, const char *argv[])
{

    //testHashTable();
    //testHashTableInOut();
    computeMd5();
    return 0;
}
