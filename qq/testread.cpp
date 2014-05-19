#include <leveldb/db.h>
#include <string>
#include <iostream>

using namespace std;
using namespace leveldb;

int main( int argc, char* argv[])
{
    DB* db;
    Options options;
    options.create_if_missing = true;
    if( argc < 2 )
        return 0;

    leveldb::Status status = leveldb::DB::Open(options, argv[1], &db);
    string line, val;
    db->GetProperty("leveldb.stats", &val);
    cout << val << endl;
    ReadOptions ro;
    ro.fill_cache = false;
    while( getline(cin, line))
    {
        val.resize(0);
        Status status = db->Get(ro, line, &val);
        if(status.ok())
            cout << val << endl;
    }

    return 0;

}
