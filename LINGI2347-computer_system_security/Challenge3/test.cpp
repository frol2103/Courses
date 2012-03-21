#include "util.h"
#include "md5i.h"
#include "passchain.h"
#include <stdio.h> 
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    unsigned char t[2];
    t[0] = 0;
    t[1] = 2;

    printf("bit 7 : %d ; bit 9:%d \n",get_bit(t,7), get_bit(t,9));
    


    
    unsigned int har = 123456749;
    cout << har << endl;
    unsigned char hash[16];
    md5i_iterate(har,5,hash);
    cout << har << endl;
    printf("%i > ", har);
    print_hex(hash,16);
    PassChain pc = PassChain(har);
    return 0;
}

