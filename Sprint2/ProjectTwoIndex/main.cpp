
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "DSvector.hpp"
#include "reader.h"
#include "word.h"
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
        DSvector<Word> words;
        scanner.sortData(pages,words);
        scanner.printOutput(words);
    }
    return 0;
}
