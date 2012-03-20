#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <openssl/md5.h> 


unsigned char md5(int p)
{
    
}


int main() { 
int i;
int har = 123456789;
char* a = malloc(sizeof(char) *4);
a[0] = har & 0xff;
a[1] = (har>>8)  & 0xff;
a[2] = (har>>16) & 0xff;
a[3] = (har>>24) & 0xff;
//printf("a length: %d\n",strlen(a));
//printf("a : %d\n",a[1]);
//printf("a : %d\n",a[2]);
//printf("a : %d\n",a[3]);
//printf("a : %d\n",a[4]);
//printf("a : %s\n",a);
unsigned char md1[MD5_DIGEST_LENGTH];
unsigned char md2[MD5_DIGEST_LENGTH];
unsigned char md3[MD5_DIGEST_LENGTH];
unsigned char md4[MD5_DIGEST_LENGTH];
unsigned char md5[MD5_DIGEST_LENGTH];
MD5(a, 4,md1); 
MD5(md1, 16,md2); 
MD5(md2, 16,md3); 
MD5(md3, 16,md4); 
MD5(md4, 16,md5); 
for(i=0;i<MD5_DIGEST_LENGTH;i++)
    printf("%02x",md5[i]);
return 0; 
}
