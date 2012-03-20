#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <openssl/md5.h> 


void int32_to_char(int i, char * c)
{
    int j;
    for(j =0; j<4; j++)
        c[j] = (i>>(8*j))  & 0xff;
}

void md5_iterate(char * p, int plength, int niter, unsigned char* out)
{
    int i;
    for(i=0;i<niter;i++)
    {
        if(i == 0)
        {
            MD5(p, plength,out); 
        }
        else
        {
            MD5(out, MD5_DIGEST_LENGTH,out); 
        }
    }
}

void print_hex(unsigned char* h,int length)
{
    int i;
    for(i=0;i<length;i++)
        printf("%02x",h[i]);
    
}

int main() { 
    int har = 123456789;
    char a[4];
    unsigned char out[MD5_DIGEST_LENGTH];
    int32_to_char(har,a);
    md5_iterate(a,4,5,out);
    print_hex(out,16);
    printf("\n");
    return 0; 
}
