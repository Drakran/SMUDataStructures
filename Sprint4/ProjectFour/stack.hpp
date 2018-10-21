/*
 * The Stack if Last in First out container with this specific
 * implementation being a linkedList
 *
 * Terry Wang
 *
 * OCtober 21st, 2018
 *
 * Fontenot and the Gang question reality
 *
 */

#ifndef STACK_H
#define STACK_H

#include "linkedlist.hpp"

template<typename T>

class Stack
{
public:
    void push(const T&);
    T pop();
    bool isEmpty();
    bool contains(T);
    T peek(); //Not Peak
    int getSize();
private:
    LinkedList<T> data;
};

/*Pushes an element into the top of the stack
 * @param val is the values being pushed
 */
template<typename T>
void Stack<T>::push(const T& val)
{
    data.insertBack(val);
}

/*Pop will return the element at the top of the stack and remove it afterwards
 *@return the val at the top of the stack
 */
template<typename T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        throw std::logic_error("pop, the stack is empty");
    }
    T temp = peek();
    data.removeBack();
    return temp;
}

//Checks if stack isEmpty and returns a boo
//@return true if empty, false otherwise
template<typename T>
bool Stack<T>::isEmpty()
{
    return data.isEmpty();
}

/*isContains goes through the stack and checks if the element is in the stack
 * @param val is the element the stack is looking for
 * @return true if the stack contains val, false otherwise
 */
template<typename T>
bool Stack<T>::contains(T val)
{
    for(int x = 0; x < data.getSize(); x++)
    {
        if(data[x] == val)
        {
            return true;
        }
    }
    return false;
}


/*Peek returns the element at the top of the stack
 * @return is the element on top
 */
template<typename T>
T Stack<T>::peek()
{
    return data.getLast();
}

//Returns size
//@return the size
template<typename T>
int Stack<T>::getSize()
{
    return data.getSize();
}
#endif // STACK_H
