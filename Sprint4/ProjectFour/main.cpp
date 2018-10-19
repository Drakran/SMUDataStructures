
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
    return runCatchTests();
}
