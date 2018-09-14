#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "DSvector.hpp"
#include <string>
#include <iostream>


using namespace std;

TEST_CASE("Testing dsvectrs", "[dsvectors]")
{
    SECTION("Int Tests")
    {
        DSvector<int> testDefault;
//        DSvector<int> sizeBelowZero(-1);
//        CHECK_THROWS_AS(sizeBelowZero, logic_error);
        DSvector<int> testInt(0);
        DSvector<int> testInt2(5);
        testInt2[0] = 5;
        cerr << testInt2[0] << '\n';
        //DSvector<int> testList = {1,2,3};

    }

    SECTION("DOuble TEsts")
    {
        DSvector<double> doublething(1);
        doublething[0] = 2.4;
        cerr << doublething[0];
    }

    SECTION("String tests")
    {
        DSvector<string> testString(5);
        string hi = "hi";
        testString[0] = hi;
        cerr << testString[0] << '\n';
        testString[1] = "2nd";
        cerr << testString[1];

    }

    SECTION("TEst copy and assignment")
    {
        DSvector<string> testString(5);
//        for(int i = 0; i < 5; i++)
//        {

//        }
        DSvector<string> testStringAs = testString;
    }

    SECTION("at Tests")
    {
        DSvector<std::string> testAt(3);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

}
