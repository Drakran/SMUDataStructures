/*
 * The Adjlist is a graph that has elements attatched to each other by edges in aweb like format
 * Essentialy its a linkedlist of linkedlist with each element being the first linkedlist
 * and each element connected to other elements, and all those connections being in
 * the 2nd linkedlist
 *
 * Terry Wang
 *
 * October 21st, 2018
 *
 * Fontenot and the Gang asks, why not recurison?
 */

#ifndef ADJLIST_H
#define ADJLIST_H

#include "linkedlist.hpp"

template<typename T>
class AdjList
{
private:
    LinkedList<LinkedList<T>> data;
public:
    void addEdge(T, T);
    LinkedList<T> first(T);
    void print();
    T step(); //Save for later when figuring out how to iterate
    void reset();
};
#endif // ADJLIST_H

/* addEgde inserts an element in the linkedList
 * @param find the element its looking for
 * @param val the connection it will put for find
 */
template<typename T>
void AdjList<T>::addEdge(T find,T val)
{
    bool inserted = false;
    for(int x = 0; x < data.getSize(); x++)
    {
        if(data[x][0] == find)
        {
            data[x].insertBack(val);
            inserted = true;
        }
    }
    if(!inserted)
    {
        LinkedList<T> temp;
        temp.insertBack(find);
        temp.insertBack(val);
        data.insertBack(temp);
    }
}

/*first returns the LinkedList of the first element in the list for a val
 * @return the first element in the Adjlist
 */
template<typename T>
LinkedList<T> AdjList<T>::first(T val)
{
    for(int x = 0; x < data.getSize(); x++)
    {
        if(data[x][0] == val)
        {
            return data[x];
        }
        else
        {
            return; //If not here just don't return anything?
        }
    }
}

/*step iterates through the list iterativly
 * @return the data at that point in the list
 */
