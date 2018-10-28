
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "node.hpp"
#include "linkedin.h"
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
        std::cout << "The Terry AdjList Below:" << '\n';
        LinkedIn mainList;
        mainList.readData(argv[2]);
    }
    else
    {
        //Note if you're here something went horribly wrong
        std::cout << "Welp, I guess somethings went and borked up" << '\n';
    }

}
