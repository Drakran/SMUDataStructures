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

    SECTION("TestinsertBack and insert frontprint and length#1")
    {
        REQUIRE_THROWS_AS(mainTest.print(), logic_error);
        mainTest.insertBack("Hi");
        mainTest.insertBack("Hi2");
        //mainTest.print();
        REQUIRE(mainTest.getSize() == 2);
        mainTest.insertFront("HI-1");
        mainTest.insertFront("Hi-2");
        REQUIRE(mainTest.getSize() == 4);
    }


    SECTION("test InsertAt")
    {
        mainTest.insertFront("Hi - Pos Former Pos1");
        mainTest.insertFront("Hi - Pos 0");
        mainTest.print();
        cout << '\n';
        mainTest.insertAt(1, "SUPPOSED TO BE AT POS 1");
        mainTest.print();
    }

    SECTION("Clear Test and getSize")
    {
        mainTest.clear();
        REQUIRE_THROWS_AS(mainTest.print(),logic_error);
    }
}



