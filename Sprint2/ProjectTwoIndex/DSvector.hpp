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
    DSvector();
    DSvector(int);
    DSvector(const DSvector&);
    ~DSvector();

    DSvector& operator= (const DSvector&);
    T& operator[] (int);

    bool isEmpty();
    void put_back(T);
    T at(const int);

};

//default constructor
template<class T>
DSvector<T>::DSvector()
{
    size = 0;
    capacity = 10; //Default Capacity of 10
    data = new T[10];
}

//Full Constructor
template<class T>
DSvector<T>::DSvector(int initCap)
{
    if(initCap < 0)
    {
        throw logic_error("Size of vector is below zero");
    }
    size = 0;
    capacity = initCap;
    data =  new T[capacity];
}

//Copy Consustructor
template<class T>
DSvector<T>::DSvector(const DSvector& arg)
{
    this -> size = arg.size;
    this -> capacity = arg.capacity;
    data = new T[capacity];
    for(int x = 0; x < size; x++)
        this -> data[x] = arg.data[x];
}

//[] operator
template<class T>
T& DSvector<T>::operator[](int loc)
{
    return data[loc];
}
//Assignment Operator
template<class T>
DSvector<T>& DSvector<T>::operator=(const DSvector& arg)
{

    this -> size = arg.size;
    this -> capacity = arg.capacity;
    data = new T[capacity];
    for(int x = 0; x < size; x++)
        this -> data[x] = arg.data[x];
    return *this;
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
T DSvector<T>::at(int const loc)
{
    if(loc > size || loc < 0)
    {
        throw logic_error("Location out of bounds");
    }
    return data[loc];
}

#endif // DSVECTOR_H
