#include "util.h"

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


void int32_to_char(int i, unsigned char * c)
{
    int j;
    for(j =0; j<4; j++)
        c[j] = (i>>(8*j))  & 0xff;
}

void hex_string_to_char(string s, unsigned char*c)
{
    
    int i=0;
    int bshift[] = {4, 0};
    for(i=0; i< s.length()/2 ; i++)
        c[i] = 0;
    i=0;
    while(i < s.length())
    {

        c[i/2] = c[i/2] | (hex_char_value(s[i])<<bshift[i%2]);
        i++;
    }
}

int hex_char_value(char c)
{
    c = tolower(c);
    char val[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int i;
    for(i =0; i<16; i++)
        if(val[i] == c)
            return i;
    return -1;
}

bool hash_equal(unsigned char* h1, unsigned char* h2)
{
    int i;
    for(i=0;i<16;i++)
        if(h1[i] != h2[i])
            return false;
    return true;
}
