#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <openssl/md5.h> 
#include "util.h"


void md5_iterate(unsigned char * p, int plength, int niter, unsigned char* out)
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

void md5i_iterate(int pass, int niter, unsigned char* out)
{
    unsigned char a[4];
    int32_to_char(pass,a);
    md5_iterate(a,4,niter,out);

}


