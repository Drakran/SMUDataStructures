
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "node.hpp"
#include <iostream>


using namespace std;

int runCatchTests()
{
    return Catch::Session().run();
}

int main(int argc, char* const argv[])
{
    if(strcmp(argv[1], "-t") == 0)
    {
        return runCatchTests();
    }
    else
    {
        //temp holder till more
        return runCatchTests();
    }

}
