
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"


#define TEST true


int runCatchTests(int argc, char* const argv[])
{
    return Catch::Session().run();
}

int main( int argc, char* const argv[] )
{
    if (TEST)
    {
        return runCatchTests(argc, argv);
    }

    //start working on other parts of your project here.
    return 0;
}
