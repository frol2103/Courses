#include "md5table.h"
#include <iostream>
using namespace std;

Md5Table::Md5Table(int capacity)
{
    cout << "init with capacity "<< capacity << endl;

    this->capacity = capacity;
    size = 0;
    table = new Md5ChainedList*[capacity];
    int i;
    for(i=0; i< capacity; i++)
        table[i] = NULL;
}

void Md5Table::insert(PassChain* pc)
{
    int position  = hash(pc);
    if(table[position] == NULL)
    {
        table[position] = new Md5ChainedList();
    }
    table[position]->insert(pc);
}


PassChain* Md5Table::getMatch(PassChain * ref)
{
    int position  = hash(ref);
    if(table[position] != NULL)
        return table[position]->getMatch(ref);
    else
        return NULL;
}
