#include "md5chainedlist.h"

PassChain* Md5ChainedList::getMatch(PassChain * ref)
{
    Md5ChainedItem * elem;
    elem = root;
    while(elem != NULL)
    {
        if (elem->pc->match(ref))
                return elem->pc;
        elem = elem->next;
    }
    return NULL;
}


void Md5ChainedList::insert(PassChain * pc)
{
    Md5ChainedItem *ci = (Md5ChainedItem*)malloc(sizeof(Md5ChainedItem));
    ci->next = root;
    ci->pc = pc;
    root = ci;
    size ++;
}

string Md5ChainedList::repr()
{
    string repr = "";
    Md5ChainedItem * elem;
    elem = root;
    while(elem != NULL)
    {
        repr += elem->pc->repr() + ", ";
        elem = elem->next;
    }
    return repr;
}
