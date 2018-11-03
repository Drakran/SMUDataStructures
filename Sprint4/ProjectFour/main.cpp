
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
//argc haunts my issues tab and my dreams
int main(int argc, char* const argv[])
{
    std::cout << argv[1] << argv[2] << argv[3] << argv[4];
    if(strcmp(argv[1], "-t") == 0){return runCatchTests();}
    else if(strcmp(argv[1], "-r") == 0)
    {
        std::cout << "The Terry Linkedin Presents: A Thing" << '\n';
        LinkedIn mainList;
        mainList.readData(argv[2]);
        mainList.readCompare(argv[3]);
        mainList.outputData(argv[4]);
    }
    else
    {
        //Note if you're here something went horribly wrong
        std::cerr << "Welp, I guess somethings went and borked up" << '\n';
    }

}
