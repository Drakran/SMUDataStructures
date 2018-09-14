#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <exception>
#include <stdexcept>

using namespace std;

template<class T>
class DSvector
{
private:
    T* data;
    int size; //numElements
    int capacity;
public:
    DSvector(int);
    ~DSvector();
    bool isEmpty();
    T operator[] (int);
    void put_back(T);
    T at(int);

};

//default constructor


//Full Contructor
template<class T>
DSvector<T>::DSvector(int initCap)
{
    size = 0;
    capacity = initCap;
    data =  new T[size];
}
//Deconstructor
template<class T>
DSvector<T>::~DSvector()
{
    delete[] data;
}

//template<class T>
//void DSvector<T>::put_back(T val)
//{

//}
//Returns element at location
template<class T>
T DSvector<T>::at(int loc)
{
    if(loc > size || loc < 0)
    {
        throw logic_error("Location out of bounds");
    }
    return data[loc];
}

#endif // DSVECTOR_H
