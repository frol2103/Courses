#include "merge.h"
int main(int argc, const char *argv[])
{
    int i; 
    int chainLength = -1;
    int start=-1,end=-1;
    Md5Table mt = Md5Table();
    for(i = 1; i< argc; i++)
    {
        int i_chainLength, i_from, i_to;
        getInfos(argv[i],&i_chainLength, &i_from,&i_to);
        string filename = argv[i];
        if(chainLength == -1)
            chainLength = i_chainLength;

        if(chainLength != i_chainLength)
            cerr << "Error the chain length (" << i_chainLength << ") in "<< argv[i] <<" doesnt match previous chain length (" << chainLength << ")" <<endl;
        else{
            cout << "merging " << filename.substr(filename.find_last_of("/")+1) << endl;
            start=(start > i_from || start == -1)?i_from:start;
            end=(end < i_to || end == -1)?i_to:end;

            mt.fromFile(filename);
        }
    }
    ostringstream oss;
    oss << "s" << chainLength << "-f" << start <<"-t" << end << ".bin";
    cout <<"writing in : " << oss.str() << endl;
    mt.toFile(oss.str());
    cout << "elem in table : " << mt.getSize() << endl;
    return 0;
}



int getInfos(string filename, int *chainLength, int *from, int *to)
{
    size_t p0 = filename.find_last_of("/");
    size_t p1 = filename.find("s",p0);
    size_t p2 = filename.find("f",p1);
    size_t p3 = filename.find("t",p2);

    *chainLength = atoi(filename.substr(p1+1,p2-p1-2).c_str());
    *from = atoi(filename.substr(p2+1,p3-p2-2).c_str());
    *to = atoi(filename.substr(p3+1).c_str());
}
