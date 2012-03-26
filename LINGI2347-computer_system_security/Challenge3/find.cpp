
#include <string>
#include <stdio.h>
#include "md5table.h"
#include "util.h"
using namespace std;
int hashesFromFile(string filename, unsigned char*** hashes)
{
    string line;
    ifstream myfile (filename.c_str());
    int i;
    if (myfile.is_open())
    {
        int fileSize = 0;
        while ( myfile.good() )
        {
            getline(myfile,line);
            if (line != "")
                fileSize++;
        }

        myfile.clear();
        myfile.seekg (0, ios::beg);
        *hashes = new unsigned char*[fileSize];
        for(i =0; i< fileSize && myfile.good(); i++)
        {
            (*hashes)[i] = new unsigned char[16];
            getline (myfile,line);
            hex_string_to_char(line.substr(0,32), (*hashes)[i]);
           
        }
        myfile.close();
        return fileSize;
    }
    else cerr << "Unable to open file " << filename; 
    return -1;
}


unsigned int findPass(unsigned char* hash, Md5Table* table)
{
    int chainsize = CHAIN_LENGTH;
    unsigned int p;
    PassChain pc = PassChain();
    PassChain * match;
    int position;
    //chainsize -1 because : 
    //  position go from 0 to chainsize-1
    for(position = chainsize -1; position>= 0 ; position--)
    {
        pc.computeFrom(hash, position);
        match = table->getMatch(&pc);
        if(match != NULL)
        {
            //position -1 because the hash is in the position next the pass
            p = match->matchInPosition(hash,position);
            if(p != -1)
                return p;
            
        }

    }    
    return -1;
}

int main(int argc, const char *argv[])
{
    unsigned char** hashes;
    int nbhashes, i;
    nbhashes = hashesFromFile(argv[1], &hashes);
    Md5Table mt = Md5Table();
    mt.fromFile(argv[2]);
    for(i=0;i<nbhashes; i++)
    {
        unsigned int p = findPass(hashes[i],&mt);
        print_hex(hashes[i],16);
        cout << " : " << p<<endl;

    }
    return 0;
}

