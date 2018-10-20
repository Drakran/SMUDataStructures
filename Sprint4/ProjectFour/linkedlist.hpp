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
        head{nullptr}, tail{nullptr}, currIter{nullptr},length(0) {}
    ~LinkedList();
    void insertFront(T val);
    void insertBack(T val);
    void insertAt(int pos, T val);
    int getSize();
    void print();
    void clear();
    bool isEmpty() const;

private:
    void insertHere(int pos, T val);
    void insertBack(Node<T>*);
    void insertFront(Node<T>*);
    Node<T>* head, *tail, *currIter;
    int length;
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

/* Get size return the size/length of the List
 * @return size the size of the list
 */
template<typename T>
int LinkedList<T>::getSize()
{
    return length;
}

/* The insert front function gets a val and sends it to the
 * other insertFront function that puts it in the front of a node
 * @param val the value to put it in
 */
template<typename T>
void LinkedList<T>::insertFront(T val)
{
    Node<T>* temp = new Node<T>(val);
    insertFront(temp);
}

/* The insertFront function inserts a node into the beginning of the List
 * @param val wiht node
 */
template<typename T>
void LinkedList<T>::insertFront(Node<T>* val)
{
    if(isEmpty())
    {
        head = val;
        tail = head; //Works b/c head == nullptr
    }
    else
    {
        val->next = head;
        head->prev = val;
        head = head->prev;
    }
    length++;
}

/* The insert back function gets a val and sends it to the
 * other insertBack function that puts it int the end of anode
 * @param val the value to put it in
 */
template<typename T>
void LinkedList<T>::insertBack(T val)
{
    Node<T>* temp = new Node<T>(val);
    insertBack(temp);
}

/* The insertBack function inserts a node into the end of the List
 * @param val wiht node
 */
template<typename T>
void LinkedList<T>::insertBack(Node<T>* val)
{
    if(isEmpty())
    {
        head = val;
        tail = head; //Works b/c head == nullptr
    }
    else
    {
        tail->next = val;
        tail->next->prev = tail;
        tail = tail->next;
    }
    length++;
}

/* InsertAt inserts a value at a position
 * @param val the value that wil be added
 * @param pos the position of the value
 */
template<typename T>
void LinkedList<T>::insertAt(int pos, T val)
{
    insertHere(pos,val);
}

/*InsertHere inserts a value at a position but for real
 * @param val the value that will be added
 * @param pos position of vlaue
 */
template<typename T>
void LinkedList<T>::insertHere(int pos, T val)
{
    if(pos < 0 || pos > length)
    {
        throw std::logic_error("insertHere position is out of bounds");
    }

    if(head != nullptr)
    {
        Node<T>* current = head;
        if(pos == 0){insertFront(val); return;}
        while(current->next !=nullptr && pos > 0)
        {
            current = current->next;
            pos--;
        }

        if(current == tail){insertBack(val); return;}

        Node<T>* temp = new Node<T>(val);
        temp->prev = current;
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
        length++;
    }
    insertFront(val);
    length++;
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
        std::cout << "Starting Printing"; // Remove when done
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

//Clear function removes all of the nodes in the linked list
template<typename T>
void LinkedList<T>::clear()
{
    while(head != nullptr)
    {
        Node<T>* temp = head->next;
        delete[] head;
        head = temp;
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
