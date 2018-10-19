/*
 * LinkedList is a container that is a sequential list
 * with each list having a node with data and pointing to the
 * node before and the node after
 *
 *
 * Terry Wang
 *
 * OCtober 19th, 2018
 *
 * Fontenots and the Gang
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>


template<typename T>

class LinkedList{
public:
    //Constructor for nullptr
    LinkedList():
        head{nullptr}, tail{nullptr}, currIter{nullptr} {}
    ~LinkedList();
    void insertFront(T val);
    void insertBack(T val);
    void print();
    bool isEmpty() const;

private:
    Node<T>* head, *tail, *currIter;
};

//Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
    if(!isEmpty())
    {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while(current != nullptr)
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
}



/* The insertBack function inserts a node into the end of the List
 * @param val is the value to put in
 */
template<typename T>
void LinkedList<T>::insertBack(T val)
{
    if(isEmpty())
    {
        head = new Node<T>(val);
        tail = head; //Works b/c head == nullptr
    }
    else
    {
        tail->next = new Node<T>(val);
        tail->next->prev = tail;
        tail = tail->next;
    }
}

/* The Print methods prints everything out
 * Usually just a test method
 */
template<typename T>
void LinkedList<T>::print()
{
    if(!isEmpty())
    {
        Node<T>* current = head;
        while(current != nullptr)
        {
           std::cout << current->data;
           current = current->next;
        }
    }
    else{
        throw std::logic_error("Print but Nothings here");
    }
}

//IsEmpty
//So don't have to keep typing head==nullptr?
template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

#endif // LINKEDLIST_H
