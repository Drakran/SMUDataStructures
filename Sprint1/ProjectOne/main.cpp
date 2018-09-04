#include <iostream>
#include "Reader.h"


#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    Reader scanner(argv[1]);
    //cout << argv[1] << endl;
    scanner.printData();

    return 0;
}
