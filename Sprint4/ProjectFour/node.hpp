/*
 * The Node class...is a node for a Link List,
 * the actual container with the data.
 *
 * Terry Wang
 *
 * October 19th, 2018
 *
 * Fontenots and the Gang
 *
 */

#ifndef NODE_H
#define NODE_H

template<typename T> class LinkedList;

template<typename T>
class Node {
    friend class LinkedList<T>;
public:
    //Constructor
    Node():
        next{nullptr},prev{nullptr} {}
    Node(T val):
        data{val}, next{nullptr}, prev{nullptr} {}
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};
#endif // NODE_H
