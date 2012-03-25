#include "md5table.h"

void Md5Table::init(int capacity)
{
    cout << "init with capacity "<< capacity << endl;

    this->capacity = capacity;
    size = 0;
    //table = new Md5ChainedList*[capacity];

    table = (Md5ChainedList**) malloc(sizeof(Md5ChainedList*) * capacity);
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

void Md5Table::fromFile(string filePath)
{
    int size;
    ifstream file (filePath.c_str(), ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        file.seekg (0, ios::beg);
        while(file.tellg() <= (size - (int)(2*sizeof(unsigned int))))
        {
            unsigned int start,end;
            file.read((char *)&start, sizeof(unsigned int));
            file.read((char *)&end, sizeof(unsigned int));
        }
        file.close();

    }
    else cout << "Unable to open file" << endl;

}

void Md5Table::toFile(string filePath)
{
    ofstream file (filePath.c_str(), ios::out|ios::binary);
    if (file.is_open())
    {
            unsigned int start=1230;
            unsigned int end=12384;
            file.write((char*)&start, sizeof(unsigned int));
            file.write((char *)&end, sizeof(unsigned int));
        file.close();

    }
    else cout << "Unable to open file";

}
