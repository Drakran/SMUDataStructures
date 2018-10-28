
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "node.hpp"
#include "reader.h"
#include <iostream>


using namespace std;

int runCatchTests()
{
    return Catch::Session().run();
}

int main(int argc, char* const argv[])
{
    if(strcmp(argv[1], "-t") == 0){return runCatchTests();}
    else if(strcmp(argv[1], "-r") == 0)
    {
        Reader scanner(argv[2],argv[3],argv[4]);
        scanner.readData();
    }

}
