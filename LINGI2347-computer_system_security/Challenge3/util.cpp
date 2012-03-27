#include "util.h"

void print_hex(unsigned char* h,int length, ostream& out)
{
    int i; 
    char hash_repr[(length*2)+1];
    
  //  for(i=0;i<length;i++)
  //      out << hex << (int) h[i];
  //  cout << endl;
    hex_repr_from_char(h,hash_repr,length);
    out << hash_repr;
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
void hex_repr_from_char(unsigned char * number,char * repr, int nsize)
{
    char val[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int i;
    for(i =0; i<nsize; i++)
    {
        
        repr[i*2] = val[(int)((number[i] & 0xf0)>>4)];
        repr[i*2+1] = val[(int)(number[i] & 0xf)];
    }
    repr[2*nsize] = '\0';
}

bool hash_equal(unsigned char* h1, unsigned char* h2)
{
    int i;
    for(i=0;i<16;i++)
        if(h1[i] != h2[i])
            return false;
    return true;
}
