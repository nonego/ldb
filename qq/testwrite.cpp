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

    char delim;
    if( argc == 3 )
        delim = argv[2][0];
    else
        delim = '\t';

    leveldb::Status status = leveldb::DB::Open(options, argv[1], &db);
    string line;
    int n=0;
    while( getline(cin, line))
    {
        size_t i=line.find(delim);
        if( i == string::npos )
            continue;
        db->Put(leveldb::WriteOptions(), line.substr(0, i), line.substr(i+1));
        ++n;
        if( ( n & 0xFFFF ) == 0 )
            cout << n << endl;
    }

    return 0;

}
