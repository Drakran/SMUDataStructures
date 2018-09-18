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
        //DSvector<int> sizeBelowZero(-1);
        //CHECK_THROWS_AS(DSvector<int> belowZero(-1), logic_error);
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
        DSvector<int> testint(5);
        for(int i = 0; i < 5; i++)
        {
            testint[i] = i;
        }
        DSvector<int> testintAs(testint);
        for(int x = 0; x < 5; x++)
        {
            cerr << testint[x] << '\n';
        }
    }

    SECTION("at Tests")
    {
        DSvector<std::string> testAt(3);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

    SECTION("put_back")
    {
        DSvector<std::string> testPut(1);
        testPut.put_back("One");
        testPut.put_back("Two");
        cerr << testPut.getSize() << '\n';
        testPut.put_back("Three - Increase cap by 2");
        cerr << testPut.getSize() << '\n';
    }

    SECTION("Front and Back")
    {
        DSvector<std::string> v(1);
        CHECK_THROWS_AS(v.front(), logic_error);
        CHECK_THROWS_AS(v.back(), logic_error);
        v.put_back("First");

    }

}
