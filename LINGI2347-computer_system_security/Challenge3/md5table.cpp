#include "md5table.h"

void Md5Table::init(int capacity)
{

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
    if(getMatch(pc) != NULL)
        //there is alredy a matching 
        return;
    int position  = hash(pc);
    if(table[position] == NULL)
    {
        table[position] = new Md5ChainedList();
    }
    table[position]->insert(pc);
    size++;
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
            insert(new PassChain(start,end));
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

       int i = 0;
       for(i=0;i<capacity;i++)
       {
           if(table[i] != NULL)
           {
                Md5ChainedItem * elem;
                elem = table[i]->getRoot();
                while(elem != NULL)
                {
                    unsigned int start = elem->pc->getStart();
                    unsigned int end = elem->pc->getEnd();
                    file.write((char*)&start, sizeof(unsigned int));
                    file.write((char *)&end, sizeof(unsigned int));
                    elem = elem->next;
                }
           }
       }
       file.close();
    }
    else cout << "Unable to open file";

}

string Md5Table::repr()
{
    string repr = "";
    int i = 0;
    for(i=0;i<capacity;i++)
    {
       if(table[i] == NULL)
            repr += "NULL \n";
       else
           repr += table[i]->repr() + "\n";
    }
    return repr;
}
