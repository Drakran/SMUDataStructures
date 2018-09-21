
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
        CHECK(testDefault.isEmpty() == true);
        //DSvector<int> sizeBelowZero(-1);
        //CHECK_THROWS_AS(DSvector<int> belowZero(-1), logic_error);
        DSvector<int> testInt(0);
        DSvector<int> testInt2(5);
        testInt2[0] = 5;
        REQUIRE(testInt2[0] ==5);
        //DSvector<int> testList = {1,2,3};

    }

    SECTION("DOuble TEsts")
    {
        DSvector<double> doublething(1);
        doublething[0] = 2.4;
        REQUIRE(doublething[0] == Approx(2.4));
    }

    SECTION("String tests")
    {
        DSvector<string> testString(5);
        string hi = "hi";
        testString[0] = hi;
        REQUIRE(testString[0] == "hi");
        testString[1] = "2nd";
        REQUIRE(testString[1] == "2nd");

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
            REQUIRE(testint[x] == x);
        }
//        for(int i = 0; i < testint.getSize(); i++)
//        {
//            cerr << testint[i] << '\n';
//        }
//        DSvector<string> testString(5);
//        for(int i = 0; i < testString.getSize(); i++)
//        {
//            //if(testi)
//            cerr << testString[i] << '\n';
//        }

    }

    SECTION("at Tests")
    {
        DSvector<std::string> testAt(3);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

    SECTION("put_back and pop_back")
    {
        DSvector<std::string> emptyString(0);
        emptyString.put_back("First");
        REQUIRE(emptyString[0] == "First");
        DSvector<std::string> testPut(1);
        testPut.put_back("One");
        //cerr << testPut.getCapacity() << '\n';
        testPut.put_back("Two");
         //cerr << testPut.getCapacity() << '\n';
        REQUIRE(testPut.getSize() == 3);
        testPut.put_back("Three - Increase cap by 2");
         //cerr << testPut.getCapacity() << '\n';
        REQUIRE(testPut.getSize() == 4);

        testPut.pop_back();
        testPut.pop_back();
        testPut.pop_back();
        testPut.pop_back();
        CHECK_THROWS_AS(testPut.pop_back(),logic_error);

    }

    SECTION("Front and Back")
    {
        DSvector<std::string> v(0);
        CHECK_THROWS_AS(v.front(), logic_error);
        CHECK_THROWS_AS(v.back(), logic_error);
        v.put_back("First");
        REQUIRE(v.front() == "First");
        REQUIRE(v.back() == "First");
    }

    SECTION("[testing]")
    {
        DSvector<int> v(0);
        CHECK_THROWS_AS(v[-1], logic_error);
    }

}
