#include "util.h"
#include <stdio.h> 


void print_hex(unsigned char* h,int length)
{
    int i;
    for(i=0;i<length;i++)
        printf("%02x",h[i]);
}

int get_bit(unsigned char* h,int position)
{
    return (h[position/8]>>(position%8)) & 1;
}
