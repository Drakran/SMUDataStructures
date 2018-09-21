
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSvector.hpp"
#include "reader.h"

#define TEST false


int runCatchTests()
{
    return Catch::Session().run();
}

int main( int argc, char* const argv[] )
{
    if (TEST)
    {
        return runCatchTests();
    }
//    for(int x = 0; x < argc; x++)
//    {
//        std::cout << argv[x] << '\n';
//    }

    Reader scanner(argv[3],argv[4]);
    scanner.getData();
    //start working on other parts of your project here.
    return 0;
}
