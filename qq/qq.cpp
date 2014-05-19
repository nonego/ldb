#include <leveldb/db.h>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
using namespace leveldb;

int main( int argc, char* argv[])
{
    DB* dbgroup;
    Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, argv[1], &dbgroup);
    assert(status.ok());

    string line;
    string group, group_pre, qq, member, rlt;
    int n=0;
    WriteOptions wo;
    ReadOptions ro;
    while( getline(cin, line))
    {
        line.erase( remove_if( line.begin(), line.end(), bind2nd( less<unsigned char>(), '\t')), line.end());
        size_t i=line.find('\t' );
        if( i == string::npos  )
            continue;
        
        rlt.resize(0);
        status = dbgroup->Get(ro, Slice(line.c_str(), i ), &rlt);
        size_t j =  rlt.rfind('\002');
        if( j != string::npos )
            continue;

        line[i]='\002';
        rlt += line.substr(i);
        status = dbgroup->Put(wo, Slice(line.c_str(), i), rlt);
        
        n++;
        if( (n & 0xFFFF) == 0 )
            cout << n << endl;
    }

    return 0;

}
