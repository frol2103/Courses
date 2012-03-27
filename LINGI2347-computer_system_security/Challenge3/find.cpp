
#include <string>
#include <stdio.h>
#include "md5table.h"
#include "util.h"
#define NB_THREAD 8
using namespace std;

typedef struct{
    int start;
    int end;
    unsigned char **hashes;
    int* pass;
    Md5Table* mt;
}find_pass_args;
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
    cout << "looking for ";
    print_hex(hash,16);
    cout << endl;
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
void * thread_find_pass(void * p_data)
{
    int i;
    find_pass_args* data = (find_pass_args*)p_data;

    for(i=data->start;i<=data->end; i++)
    {
        cout << i << endl;
        unsigned int p = findPass(data->hashes[i],data->mt);
        data->pass[i] = p;

    }

}

int main(int argc, const char *argv[])
{
    unsigned char** hashes;
    int nbhashes, i;
    nbhashes = hashesFromFile(argv[1], &hashes);
    Md5Table mt = Md5Table();
    mt.fromFile(argv[2]);
    int pass[nbhashes];
    pthread_t threads[NB_THREAD];
    int j=0;
    for(i=0; i<NB_THREAD; i++)
    {
        find_pass_args *p_data = new find_pass_args;
        p_data->start = j;
        j += (nbhashes/NB_THREAD);
        if (i < nbhashes % NB_THREAD)
            j+=1;

        p_data->end = j-1;
        p_data->hashes = hashes;
        p_data->pass = pass;
        p_data->mt = &mt;
        cout << "thread " << i << " from: " << p_data->start << " to:" << p_data->end << endl;
        pthread_create(&(threads[i]), NULL, thread_find_pass,(void *) p_data);
        
    }

    for(i=0; i<NB_THREAD; i++)
    {
        pthread_join(threads[i],NULL);
    }

    cout << "Value in B                       | Solution " << endl << "---------------------------------+-----------" << endl;
    for(i = 0; i < nbhashes; i++)
    {
        print_hex(hashes[i],16);
        unsigned p = pass[i];
        if(p!= -1)
            cout << " | " << hex << p << endl;
        else
            cout << " | " << endl;
    
    }

    return 0;
}

