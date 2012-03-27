#ifndef UTIL

#define UTIL
#include <stdio.h> 
#include <ctype.h>
#include <string>
#include <iostream>
 using namespace std;

void print_hex(unsigned char* h,int length,ostream& out=cout);
int get_bit(unsigned char* h,int position);
void int32_to_char(int i, unsigned char * c);
void hex_string_to_char(string s, unsigned char*c);
int hex_char_value(char c);
bool hash_equal(unsigned char* h1, unsigned char* h2);
void hex_repr_from_char(unsigned char * number,char * repr, int nsize);

#endif /* end of include guard: UTIL */

