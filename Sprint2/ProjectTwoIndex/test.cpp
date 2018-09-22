
#include "catch.hpp"
#include "DSvector.hpp"
#include <string>
#include <iostream>


using namespace std;

TEST_CASE("Testing Int" )
{
    SECTION("Basic Constructors(Default and Full)")
    {
        DSvector<int> testDefault;
        DSvector<int> testInt(0);
        DSvector<int> testInt2(5);
    }

    SECTION("operator []")
    {
        DSvector<int> test(5);
        test[0] = 0;
        test[4] = 4;
        REQUIRE_THROWS_AS(test[10] = 10, out_of_range);
        REQUIRE(test[0] == 0);
        REQUIRE(test[4] == 4);
        DSvector<int> testint(5);
        for(int i = 0; i < 5; i++)
        {
            testint[i] = i;
        }
        for(int x = 0; x < 5; x++)
        {
            REQUIRE(testint[x] == x);
        }
        DSvector<int> v(0);
        CHECK_THROWS_AS(v[-1], out_of_range);
    }

    SECTION("IsEmpty")
    {
        DSvector<int> testDefault;
        CHECK(testDefault.isEmpty() == true);
        DSvector<int> testEmpty(0);
        REQUIRE(testEmpty.isEmpty() == true);
    }

    SECTION("Size and capacity test")
    {
        DSvector<int> zero;
        DSvector<int> number(5);
        REQUIRE(zero.getSize() == 0);
        REQUIRE(zero.getCapacity() == 10);
        REQUIRE(number.getSize() == 5);
        REQUIRE(number.getCapacity() == 5);
        number.put_back(6);
        REQUIRE(number.getSize() == 6);
        REQUIRE(number.getCapacity() == 5*2);
    }

    SECTION("Copy Constructors")
    {
        DSvector<int> orginal(5);
        orginal[0] = 5;
        DSvector<int> copy = orginal;
        REQUIRE(copy.getSize() == orginal.getSize());
        REQUIRE(copy[0] == orginal[0]);

        DSvector<int> emptyOrg;
        DSvector<int> empty = emptyOrg;
        REQUIRE(empty.getSize() == emptyOrg.getSize());
    }

    SECTION("Assignment Operator")
    {
        DSvector<int> testEmpty;
        DSvector<int> testFull(3);
        for(int x = 0; x <testFull.getSize(); x++)
        {
            testFull[x] = x * 2;
        }
        testEmpty = testFull;
        REQUIRE(testEmpty.getSize() == testFull.getSize());
        REQUIRE(testEmpty[2] == testFull[2]);
        REQUIRE(testEmpty.getCapacity() == testFull.getCapacity());

        DSvector<int> testSelf(5);
        for(int i = 0; i < testSelf.getSize(); i++)
        {
            testSelf[i] = i;
        }
        testSelf = testSelf;
        REQUIRE(testSelf[3] == testSelf[3]);
        REQUIRE(testSelf.getSize() == testSelf.getSize());

        testFull = testSelf;
        REQUIRE(testFull.getSize() == testSelf.getSize());
        REQUIRE(testFull[0] == testSelf[0]);

    }

    SECTION("put_back and pop_back")
    {
        DSvector<int> emptyInt(0);
        emptyInt.put_back(0);
        REQUIRE(emptyInt[0] == 0);
        DSvector<int> testPut(1);
        testPut.put_back(1);
        testPut.put_back(2);
        REQUIRE(testPut.getSize() == 3);
        testPut.put_back(3);
        REQUIRE(testPut.getSize() == 4);

        testPut.pop_back();
        REQUIRE(testPut.getSize() == 3);
        testPut.pop_back();
        testPut.pop_back();
        testPut.pop_back();
        CHECK_THROWS_AS(testPut.pop_back(),logic_error);

    }

    SECTION("Front and Back")
    {
        DSvector<int> v(0);
        CHECK_THROWS_AS(v.front(), logic_error);
        CHECK_THROWS_AS(v.back(), logic_error);
        v.put_back(1);
        REQUIRE(v.front() == 1);
        REQUIRE(v.back() == 1);
    }

    SECTION("at Tests")
    {
        DSvector<int> testAt(3);
        testAt[0] = 0;
        REQUIRE(testAt.at(0) == 0);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

    SECTION("Clear method")
    {
        DSvector<int> v(10);
        v.clear();
        REQUIRE(v.getSize() == 0);
    }
}

TEST_CASE("Testing Strings")
{
    string hi = "hi";
    string one = "one";
    string random = "random";
    string horde = "FOR THE HORDE";
    DSvector<string> testEmpty;
    DSvector<string> testString(5);

    SECTION("Basic Constructor")
    {
        DSvector<string> empty;
        DSvector<string> notEmpty(5);
    }

    SECTION("operator []")
    {
        DSvector<string> test(5);
        test[0] = hi;
        test[4] = random;
        REQUIRE(test[0] == hi);
        REQUIRE(test[4] == random);
        REQUIRE_THROWS_AS(test[10] = one, out_of_range);
        DSvector<string> v(0);
        CHECK_THROWS_AS(v[-1], out_of_range);
    }

    SECTION("IsEmpty")
    {
        DSvector<string> testDefault;
        CHECK(testDefault.isEmpty() == true);
        DSvector<string> testEmpty(0);
        REQUIRE(testEmpty.isEmpty() == true);
    }

    SECTION("Size and capacity test")
    {
        DSvector<string> zero;
        DSvector<string> word(3);
        REQUIRE(zero.getSize() == 0);
        REQUIRE(zero.getCapacity() == 10);
        REQUIRE(word.getSize() == 3);
        REQUIRE(word.getCapacity() == 3);
        word.put_back(random);
        REQUIRE(word.getSize() == 4);
        REQUIRE(word.getCapacity() == 6);
    }

    SECTION("Copy Constructors")
    {
        DSvector<string> orginal(5);
        orginal[0] = hi;
        DSvector<string> copy = orginal;
        REQUIRE(copy.getSize() == orginal.getSize());
        REQUIRE(copy[0] == orginal[0]);

        DSvector<string> emptyOrg;
        DSvector<string> empty = emptyOrg;
        REQUIRE(empty.getSize() == emptyOrg.getSize());
    }

    SECTION("Assignment Operator")
    {
        DSvector<string> testEmpty;
        DSvector<string> testFull(3);
        for(int x = 0; x <testFull.getSize(); x++)
        {
            testFull[x] = hi;
        }
        testEmpty = testFull;
        REQUIRE(testEmpty.getSize() == testFull.getSize());
        REQUIRE(testEmpty[2] == testFull[2]);
        REQUIRE(testEmpty.getCapacity() == testFull.getCapacity());

        DSvector<string> testSelf(5);
        for(int i = 0; i < testSelf.getSize(); i++)
        {
            testSelf[i] = random;
        }
        testSelf = testSelf;
        REQUIRE(testSelf[3] == testSelf[3]);
        REQUIRE(testSelf.getSize() == testSelf.getSize());

        testFull = testSelf;
        REQUIRE(testFull.getSize() == testSelf.getSize());
        REQUIRE(testFull[0] == testSelf[0]);

    }

    SECTION("put_back and pop_back")
    {
        DSvector<string> emptyString(0);
        emptyString.put_back("First");
        REQUIRE(emptyString[0] == "First");
        DSvector<string> testPut(1);
        testPut.put_back("One");
        testPut.put_back("Two");
        REQUIRE(testPut.getSize() == 3);
        testPut.put_back("Three - Increase cap by 2");
        REQUIRE(testPut.getSize() == 4);

        testPut.pop_back();
        REQUIRE(testPut.getSize() == 3);
        testPut.pop_back();
        testPut.pop_back();
        testPut.pop_back();
        CHECK_THROWS_AS(testPut.pop_back(),logic_error);

    }

    SECTION("Front and Back")
    {
        DSvector<string> v(0);
        CHECK_THROWS_AS(v.front(), logic_error);
        CHECK_THROWS_AS(v.back(), logic_error);
        v.put_back("First");
        REQUIRE(v.front() == "First");
        REQUIRE(v.back() == "First");
    }

    SECTION("at Tests")
    {
        DSvector<string> testAt(3);
        testAt[0] = hi;
        REQUIRE(testAt.at(0) == hi);
        REQUIRE_THROWS_AS(testAt.at(4), logic_error);
    }

    SECTION("Clear method")
    {
        DSvector<string> v(10);
        v.clear();
        REQUIRE(v.getSize() == 0);
    }
}
