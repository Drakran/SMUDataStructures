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
    void pop_out(T){}
    T erase(int){}
    void clear(){}
public:
    DSvector();
    DSvector(int);
    DSvector(const DSvector&);
    ~DSvector();

    DSvector& operator= (const DSvector&);
    T& operator[] (int);

    int getSize();
    T front();
    T back();
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
//    if(loc > size || loc < 0)
//        throw logic_error("[] out of bounds");
    return data[loc];
}

//Assignment Operator
template<class T>
DSvector<T>& DSvector<T>::operator=(const DSvector& arg)
{
    //Self-Assignment Precaution
    if(this == &arg)
    {
        return *this;
    }

    //Delete data of THIS if there is data
    if((this -> size) > 0)
    {
        delete[] data;
    }

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

//Get Size
template<class T>
int DSvector<T>::getSize()
{
    return size;
}

//Front - Gets first Element
template<class T>
T DSvector<T>::front()
{
    if(size > 0)
    {
        return data[0];
    }
    else
        throw logic_error("Front - Vector is empty");
}

//Back - Gets last element
template<class T>
T DSvector<T>::back()
{
    if(size > 0)
    {
        return data[size - 1];
    }
    else
        throw logic_error("Back - Vector is empty");
}
/*Put_back inserts an element at the end of the
 * vector. If size is the same as capacity, then
 * the method doubles the vector capacity and stores
 * it in a new memory location before adding
 * the new element at the end of the vector
 * @param val is the value to put in at the end
 */
template<class T>
void DSvector<T>::put_back(T val)
{
    if(capacity == size)
    {
        T* temp = new T[capacity * 2]; //Two is standard
        for(int x = 0; x< size; x++)
        {
            temp[x] = data[x];
        }
        capacity*= 2; //Doubles cap of THIS
        delete[] data;
        data = temp;
    }
    data[size++] = val; //Will increment after
}

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
