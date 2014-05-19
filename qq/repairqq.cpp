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
        rlt.resize(0);
        status = dbgroup->Get(ro, line, &rlt);
        cout << rlt << endl;
        size_t i=rlt.rfind('\002');
        if( i == string::npos)
            continue;
        rlt.resize(i);
        dbgroup->Put(wo, line, rlt);

    }

    return 0;

}
