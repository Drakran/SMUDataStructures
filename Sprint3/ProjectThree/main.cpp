
#include <iostream>
#include <DSvector.hpp>
#include "reader.h"
#include <word.h>


using namespace std;

int main(int argc, char* const argv[])
{
    Reader scanner(argv[1],argv[2]);
    scanner.getData();
    scanner.sortData();
    scanner.printData();
    return 0;
}
