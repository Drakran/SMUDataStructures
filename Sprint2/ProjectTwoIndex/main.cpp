
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSvector.hpp"
#include "reader.h"
//#include "page.h"

#define TEST false


int runCatchTests()
{
    return Catch::Session().run();
}

int main( int argc, char* const argv[] )
{
    if (strcmp(argv[1], "-t") == 0)
    {
        return runCatchTests();
    }

    else if(strcmp(argv[1], "-r") == 0)
    {
        DSvector<Page> pages;
        Reader scanner(argv[2],argv[3]);
        scanner.getData(pages);
    }

    for(int x = 0; x < argc; x++)
    {
        std::cout << argv[x] << '\n';
    }
    //start working on other parts of your project here.
    return 0;
}
