/*
 * This file tests thing using the CATCH method (whyyyyy)
 *
 * Terry Wang
 *
 * October 19th, 2018
 *
 * Fontenots and the Gang
 */

#include "catch.hpp"
#include "node.hpp"
#include "linkedlist.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("LinkedList")
{
    LinkedList<string> mainTest;
    SECTION("BASIC CONSTUCTOR")
    {
        LinkedList<int> intTest;
        LinkedList<string> stringTest;
    }


    SECTION("InsertBack, InsertFront, Getsize, and print error")
    {
        REQUIRE_THROWS_AS(mainTest.print(), logic_error);
        mainTest.insertBack("Hi");
        mainTest.insertBack("Hi2");
        REQUIRE(mainTest.getSize() == 2);
        mainTest.insertFront("HI-1");
        mainTest.insertFront("Hi-2");
        REQUIRE(mainTest.getSize() == 4);
    }

    SECTION("[] Test")
    {
        mainTest.insertBack("1");
        mainTest.insertBack("2");
        REQUIRE(mainTest[1] == "2");
        REQUIRE_THROWS_AS(mainTest[2], out_of_range);

        LinkedList<int> intTests;
        REQUIRE_THROWS_AS(intTests[0], out_of_range);

        intTests.insertFront(1);
        REQUIRE(intTests[0] == 1);
    }

    SECTION("test InsertAt")
    {
        //Check if can insert an empty list
        mainTest.insertAt(0, "zero");
        REQUIRE(mainTest[0] == "zero");
        REQUIRE_THROWS_AS(mainTest[1], out_of_range);
        //Can check if can add at end
        mainTest.insertAt(1, "one");
        REQUIRE(mainTest[1] == "one");
        mainTest.insertAt(2, "two");
        REQUIRE(mainTest[2] == "two");
        REQUIRE(mainTest.getSize() == 3);
        //Check if can insert at middle
        mainTest.insertAt(2, "NewTwo");
        REQUIRE(mainTest[2] == "NewTwo");
        //Check inserting at end again
        mainTest.insertAt(4, "Three");
        CHECK(mainTest[4] == "Three");
        //Check if insert right before end
        mainTest.insertAt(4,"NewThree");
        REQUIRE(mainTest[4] == "NewThree");
        //Check if can insertAt front and back is still in order
        mainTest.insertAt(0,"Front");
        mainTest.print();
        REQUIRE(mainTest[0] == "Front");
        REQUIRE(mainTest[6] == "Three");

    }

    SECTION("Clear Test and getSize")
    {
        mainTest.clear();
        REQUIRE(mainTest.getSize() == 0);
        REQUIRE_THROWS_AS(mainTest.print(),logic_error);
        mainTest.insertFront("Meap");
        mainTest.clear();
        REQUIRE(mainTest.getSize() == 0);

    }
}



