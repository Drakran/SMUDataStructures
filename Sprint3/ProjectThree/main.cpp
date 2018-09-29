
#include <iostream>
#include <DSvector.hpp>
#include "reader.h"
#include <word.h>


using namespace std;

int main(int argc, char* const argv[])
{
//    DSvector<int> test;
//    for(int x = 0; x < 30; x++)
//    {
//        test.put_back(-x);
//    }
//    //cerr << test.getSize();
//    //cout << test[0];
//    test.sort(0,test.getSize()-1);
//    for(int x = 0; x < test.getSize(); x++)
//    {
//        cerr << test[x] << '\n';
//    }
//    //cout << "Hello World!" << endl;
    Reader scanner(argv[2],argv[3]);
    scanner.getData();
    scanner.sortData();
    scanner.printData();
    return 0;
}
