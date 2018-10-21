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
#include "linkedlist.hpp"
#include "stack.hpp"
#include "adjlist.hpp"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("LinkedList")
{
    //Table of Contents
    /* 1. Constructor
     * 2. InsertBack Insert Front, getsize, and print errors
     * 3. [] operator
     * 4.insert At operator
     * 5.removeFront and Remove back
     * 6.Remove at
     * 7.getLast and get Front
     * 8.Iterator Tests(get,reset,next)
     * 9.=operator and copy
     * 10.clear
     */
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
        mainTest.insertBack("HI-4");
        REQUIRE(mainTest[4] == "HI-4");
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
        REQUIRE(mainTest[0] == "Front");
        REQUIRE(mainTest[6] == "Three");

    }

    SECTION("test removeFront and removeBack")
    {
        REQUIRE_THROWS_AS(mainTest.removeFront(), logic_error);
        REQUIRE_THROWS_AS(mainTest.removeBack(), logic_error);
        mainTest.insertAt(0, "zero");
        mainTest.removeFront();
        REQUIRE(mainTest.getSize() == 0);
        REQUIRE_THROWS_AS(mainTest[0], out_of_range);
        mainTest.insertAt(0, "zero");
        mainTest.removeBack();
        REQUIRE(mainTest.getSize() == 0);
        REQUIRE_THROWS_AS(mainTest[0], out_of_range);
        mainTest.insertAt(0, "zero");
        mainTest.insertAt(1, "one");
        mainTest.removeBack();
        REQUIRE(mainTest[0] == "zero");
        REQUIRE_THROWS_AS(mainTest[1], out_of_range);
        mainTest.insertAt(1,"one");
        mainTest.removeFront();
        REQUIRE(mainTest[0] == "one");
        REQUIRE_THROWS_AS(mainTest[1], out_of_range);
    }

    SECTION("removeAt")
    {
        REQUIRE_THROWS_AS(mainTest.removeAt(0), out_of_range);
        mainTest.insertAt(0, "zero");
        mainTest.removeAt(0);
        REQUIRE(mainTest.isEmpty() == true);
        mainTest.insertAt(0, "zero");
        mainTest.insertAt(1, "one");
        //Test remove if tail
        mainTest.removeAt(1);
        REQUIRE(mainTest[0] == "zero");
        REQUIRE_THROWS_AS(mainTest[1], out_of_range);
        mainTest.insertAt(1, "one");
        //Test remove if head
        mainTest.removeAt(0);
        REQUIRE(mainTest[0] == "one");
        REQUIRE(mainTest.getSize() == 1);

        mainTest.clear();

        mainTest.insertAt(0, "zero");
        mainTest.insertAt(1, "one");
        mainTest.insertAt(2, "two");
        //Test in middle
        mainTest.removeAt(1);
        REQUIRE(mainTest[0] == "zero");
        REQUIRE(mainTest[1] == "two");
        REQUIRE(mainTest.getSize() == 2);
    }


    SECTION("GetLast and get firsttest")
    {
        mainTest.insertBack("0");
        REQUIRE(mainTest.getLast() == "0");
        mainTest.insertBack("1");
        REQUIRE(mainTest.getLast() == "1");
        REQUIRE(mainTest.getFirst() == "0");
    }

    SECTION("iterator test Tests")
    {
        mainTest.insertAt(0, "zero");
        REQUIRE(mainTest.getIter() == "zero");
        mainTest.insertAt(1, "one");
        mainTest.insertAt(2, "two");
        REQUIRE(mainTest.next() == "zero");
        REQUIRE(mainTest.next() == "one");
        //Iter is at two
        REQUIRE(mainTest.getIter() == "two");
        REQUIRE(mainTest.next() == "two");
        REQUIRE(mainTest.getIter() == "zero");
        REQUIRE(mainTest.next() == "zero");
    }

    SECTION("=operator and copy consutrcotr")
    {
        mainTest.insertBack("0");
        mainTest.insertBack("1");
        mainTest.next();
        LinkedList<string> copy;
        copy.insertFront("NOT SUPPOSED TO BE HERE");
        copy = mainTest;
        REQUIRE(copy.getSize() == 2);
        REQUIRE(copy[0] == "0");
        REQUIRE(copy[1] == "1");
        REQUIRE(copy.getIter() == "1");
    }

    SECTION("copy constructor")
    {
        mainTest.insertBack("0");
        mainTest.insertBack("1");
        mainTest.next();
        LinkedList<string> test = mainTest;
        LinkedList<string> cConstructor(mainTest);
        REQUIRE(cConstructor.getSize() == 2);
        REQUIRE(cConstructor[0] == "0");
        REQUIRE(cConstructor[1] == "1");
        REQUIRE(cConstructor.getIter() == "1");
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


TEST_CASE("Stack Tests")
{
    Stack<string> mainStack;
    SECTION("push and peek and get Size")
    {
        REQUIRE(mainStack.getSize() == 0);
        REQUIRE_THROWS_AS(mainStack.peek(), logic_error);
        mainStack.push("0");
        REQUIRE(mainStack.peek() == "0");
        REQUIRE(mainStack.getSize() == 1);
        mainStack.push("1");
        REQUIRE(mainStack.peek() == "1");
    }

    SECTION("pop and is empty")
    {
        mainStack.push("0");
        REQUIRE(mainStack.isEmpty() == false);
        REQUIRE(mainStack.pop() == "0");
        REQUIRE(mainStack.getSize() == 0);
        REQUIRE(mainStack.isEmpty() == true);
    }

    SECTION("contains")
    {
        mainStack.push("0");
        REQUIRE(mainStack.contains("0") == true);
    }

}

TEST_CASE("Adjacency List Graph Thingy Test")
{
    AdjList<string> mainList;
    string bob = "Bob";
    string jim = "Jim";
    string terry = "Terry";
    SECTION("addEdges test")
    {
        mainList.addEdge(bob,jim);
        mainList.addEdge(bob,terry);
        mainList.addEdge(jim,bob);
    }

    SECTION("find Front")
    {
        mainList.addEdge(bob,jim);
        mainList.addEdge(jim,bob);
        mainList.addEdge(jim,terry);
        LinkedList<string> one = mainList.findFirst(bob);
        REQUIRE(one[0] == "Bob");
        REQUIRE(one[1] == "Jim");
        LinkedList<string> two = mainList.findFirst(jim);
        REQUIRE(two[0] == "Jim");
        REQUIRE(two[1] == "Bob");
        REQUIRE(two[2] == "Terry");
    }

    SECTION("step and reset")
    {
        mainList.addEdge(bob,jim);
        mainList.addEdge(bob,terry);
        REQUIRE(mainList.step("Bob") == "Bob");
        REQUIRE(mainList.step("Bob") == "Jim");
        REQUIRE(mainList.step("Bob") == "Terry");
        mainList.reset("Bob");
        REQUIRE(mainList.step("Bob") == "Bob");
        mainList.reset("Bob");
    }

    SECTION("print")
    {
        //This shoudn't matter too much just testing print
        //BTW IT WORKS!
//        mainList.addEdge(bob,jim);
//        mainList.addEdge(bob,terry);
//        mainList.addEdge(jim,bob);
//        mainList.print();
    }

}



