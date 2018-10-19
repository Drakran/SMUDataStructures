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

    SECTION("TestinsertBack and Print")
    {
        REQUIRE_THROWS_AS(mainTest.print(), logic_error);
        mainTest.insertBack("Hi");
        mainTest.insertBack("Hi2");
        mainTest.print();
    }
}



