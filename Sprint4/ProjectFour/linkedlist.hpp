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
    void insertFront(T);
    void insertBack(T);
    void insertAt(int, T);
    T& operator[](int);
    int getSize();
    void print();
    void clear();
    bool isEmpty() const;

private:
    void insertHere(int, T);
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

/*[] operator return the value at that location
 * @param loc the index to return from
 * @return the data type at that index
 */
template<typename T>
T& LinkedList<T>::operator[](int loc)
{
    //Guaranttes no out of range
    if(loc < 0 || loc > length - 1)
        throw std::out_of_range("[] is out of range");
    Node<T>* current = head;
    while(loc > 0)
    {
        current = current->next;
        loc--;
    }
    return current->data;
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
    //if empty or want to put at front(pos==0), skip if condition
    if(head != nullptr && pos != 0)
    {
        Node<T>* current = head;
        while(current->next !=nullptr && (pos-1) > 0)
        {
            current = current->next;
            pos--;
        }

        if(current == tail){insertBack(val); return;}

        Node<T>* temp = new Node<T>(val);
        temp->prev = current;
        temp->next = current->next;
        current->next->prev = temp;//This is why need if == tail
        current->next = temp;
        length++;
    }
    else
        //if looking at front put front
        insertFront(val);

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
        delete head;
        head = temp;
    }
    length = 0;

}

//IsEmpty
//So don't have to keep typing head==nullptr?
template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

#endif // LINKEDLIST_H
