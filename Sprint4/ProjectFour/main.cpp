
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
    if(strcmp(argv[1], "-t") == 0){return runCatchTests();}
    else if(strcmp(argv[1], "-r") == 0)
    {
        std::cout << "The Terry Linkedin Presents: A Thing" << '\n';
        LinkedIn mainList;
        mainList.readData(argv[1]);
        mainList.readCompare(argv[2]);
        mainList.outputData(argv[3]);
    }
    else
    {
        //Note if you're here something went horribly wrong
        std::cerr << "Welp, I guess somethings went and borked up" << '\n';
    }

}
