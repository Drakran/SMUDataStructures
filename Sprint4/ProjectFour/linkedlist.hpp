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
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator=(const LinkedList&);
    T& operator[](int);
    int getSize();
    void insertFront(T);
    void insertBack(T);
    void insertAt(int, T);
    void removeFront();
    void removeBack();
    void removeAt(int);
    T& getIter();
    void resetIter();
    T& next();
    T& getLast();
    void print();
    void clear();
    bool isEmpty() const;

private:
    //Note: These are private but remove aren't for
    //Testing difference between private and public methods
    //Not consistent coding design technically but easily changed
    void insertHere(int, T);
    void insertBack(Node<T>*);
    void insertFront(Node<T>*);
    Node<T>* head, *tail, *currIter;
    int length;
};


/*Copy Consutrctor
 * @param arg is the one being copyed from
 */
template<typename T>
LinkedList<T>::LinkedList(const LinkedList& arg):
    head{nullptr},tail{nullptr},currIter{nullptr},length{0}
{
    Node<T>* current = arg.head;
    while(current !=nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }
    length = arg.length;
    resetIter();
}

//Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;

    while(current != nullptr)
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
        length--;
    }
}

/*=operator is the assignment operator
 * @param arg is the one being copyed from(right hand side)
 * @return is the new copyed one
 */
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& arg)
{
    //Self assignement protetion
    if(this == &arg){return *this;}
    //If not empty, clear first
    if(head !=nullptr){clear();}
    Node<T>* current = arg.head;
    while(current !=nullptr)
    {
        insertBack(current->data);
        current = current->next;
    }
    length = arg.length;
    resetIter();
    return *this;
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
        currIter = head;
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
        currIter = head;
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

/*Removefront removes at the beginning
 */
template<typename T>
void LinkedList<T>::removeFront()
{
    if(isEmpty())
    {
        throw std::logic_error("removeFront but list is empty");
    }
    //If only one element
    else if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        length--;
    }

}

/*Remove back removes list at end
 */
template<typename T>
void LinkedList<T>::removeBack()
{
    if(isEmpty())
    {
        throw std::logic_error("removeBack but list is empty");
    }
    else if(head == tail)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        length--;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length--;
    }

}

/*Removeat removes a value at that index
 * @param location to remove
 */
template<typename T>
void LinkedList<T>::removeAt(int loc)
{
    if(loc < 0 || loc > length || isEmpty() == true)
    {
        throw std::out_of_range("removeAt is out of range");
    }
    Node<T>* current = head;
    while(loc > 0)
    {
        current = current->next;
        loc--;
    }
    if(current == head){removeFront();}
    else if(current == tail){removeBack();}
    else
    {
        //Sets node before current to one after current
        current->prev->next = current->next;
        //Sets node after current to one berfore current
        current->next->prev=current->prev;
        delete current;
        length--;
    }
}

/*getIter returns the data where currIter is without moving it
 * @return the data of currIter
 */
template<typename T>
T& LinkedList<T>::getIter()
{
    return currIter->data;
}

/*resetIter resets the iter pointer to the begiining
 */
template<typename T>
void LinkedList<T>::resetIter()
{
    currIter = head;
}

/*next moves the iter up and returns the data at that iter
 */
template<typename T>
T& LinkedList<T>::next()
{
    if(isEmpty())
    {
        throw std::logic_error("next but list is empty");
    }
    if(head == tail){return currIter->data;}
    if(currIter != tail)
    {
        T& temp = currIter->data;
        currIter = currIter->next;
        return temp;
    }
    else
    {
        T& temp = currIter->data;
        resetIter();
        return temp;
    }
}

/*GetLast gets the last element
 */
template<typename T>
T& LinkedList<T>::getLast()
{
    if(isEmpty())
    {
        throw std::logic_error("next but list is empty");
    }
    return tail->data;
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
