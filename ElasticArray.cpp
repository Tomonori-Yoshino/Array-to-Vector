/**
 * @file    ElasticArray.cpp
 *
 * This file gives the implementation of the member functions for the class "ElasticArray".
 *
 * @author        Tomonori Yoshino
 * @date          February, 11
 */
#include "ElasticArray.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <stdexcept>


/**
 * Constructor
 *
 * Constructs the object with the given physical size.
 *
 * @param        size       the physical size
 *
 */
ElasticArray::ElasticArray(int size)
{
    
    if (size > 0)
    {
        _max_size = size;
        _array = new int[_max_size];
    }
    
    cout << endl << "A dynamic array has been created with the size of "
         << size << ".\n" << endl;
}


/**
 * Destructor
 *
 * Destructs the object by freeing the allocated memory.
 *
 */
ElasticArray::~ElasticArray()
{
    delete [] _array;
    _array = nullptr;
    
    cout << endl << "The array's memory has been freed.\n" << endl;
}


/**
 * Copy constructor
 *
 * Creates a copy of the given object.
 * Overloaded assignment operator is defined below in this file.
 *
 * @param        source[out]       the object to be copied
 *
 */
ElasticArray::ElasticArray(const ElasticArray& source)
{
    *this = source;
}

/**
 * @detailed Accesses the value of the internal array with the given index.
 *
 * @remarks
 *      The exception is thown if the index is out of bound.
 *
 * @param        i      the index
 *
 *
 * @return  the value of the array
 *
 */
int& ElasticArray::at(int i)
{
    if (i > _size-1 || i < 0)
    {
        throw std::out_of_range{"Array index out of range."};
    }
    return _array[i];
}


/**
 * @brief       Adds the value at the end of the array.
 *
 * @detailed    Adds the given value at the end of the internal array and increments the
 *              logical size by one. If the physical size and logical size are the same,
 *              the physical size is doubled unless it is zero. If that is the case, then
 *              the physical size is set to 16.
 *
 * @param       v       the value to be added
 *
 */
 void ElasticArray::push_back(int v)
 {
     //the case the current array has enough space...
     if (_size < _max_size)
     {
         _array[_size] = v;
         //increment the logical array.
         _size++;
     }
     //the case the current array has no space...
     else if (_size == _max_size)
     {
         if (_max_size == 0)
         {
             //the physical size is set to 16.
             _max_size = 16;
             //assign the value.
             _array[0] = v;
         }
         else
         {
             //double the physical size.
             _max_size = _max_size * _max_size;
             
             //create the new array with new physical size.
             int* _new_array = new int[_max_size];
             
             //copy all elements to new array.
             for (int i = 0; i < _size; i++)
             {
                 _new_array[i] = _array[i];
             }
             
             //free the memory of old array.
             delete [] _array;
             
             //point the new array.
             _array = _new_array;
             
             //increment the logical size.
             _size++;
             
             //assign the value.
             _array[_size-1] = v;
         }
     }
 }


/**
 * @detailed Accesses the first element of the internal array.
 *
 * @remarks
 *      The exception is thown if the size is zero.
 *
 * @return  the first element of the array
 *
 */
int ElasticArray::front() const
{
    //throw an error if it's empty.
    if (_size == 0)
    {
        throw std::out_of_range{"Cannot retrieve a value from an empty container"};
    }
    //the first element.
    return _array[0];
}



/**
 * @detailed Accesses the last element of the internal array.
 *
 * @remarks
 *      The exception is thown if the size is zero.
 *
 * @return  the first element of the array
 *
 */
int ElasticArray::back() const
{
    //throw an error if it's empty.
    if (_size == 0)
    {
        throw std::out_of_range{"Cannot retrieve a value from an empty container"};
    }
    //the last element.
    return _array[_size - 1];
}



/**
 * @detailed Removes the last element of the array and return it.
 *
 * @remarks
 *      The exception is thown if the size is zero.
 *
 * @return  the removed element of the array
 *
 */
int ElasticArray::pop_back()
{
    //throw an error if it's empty.
    if (_size == 0)
    {
        throw std::out_of_range{"Cannot perform pop_back() on an empty container."};
    }
    //decrement the logical size.
    _size--;
    //return the removed element.
    return _array[_size];
}



/**
 * @detailed Makes the array's physical size fit to its logical size. If the logical size
 *           is zero, then the memory is freed and the physical size is set to 0.
 *
 */
void ElasticArray::shrink_to_fit()
{
    if (_max_size > _size)
    {
        //create the new array whose size is current logical size.
        int* _shrink_array = new int[_size];
        //assign the values into new array.
        for (int i = 0; i < _size; i++)
        {
            _shrink_array[i] = _array[i];
        }
        //free the memory of the current array.
        delete [] _array;
        //point the internal array pointer attribute to the new array.
        _array = _shrink_array;
        //set the physical size to the new one.
        _max_size = _size;
    }
    else if (_size == 0)
    {
        //free the memory of the current array.
        delete [] _array;
        _array = nullptr;
        _size = 0;
        _max_size = 0;
    }
}



/**
 * @detailed Makes a copy of the ElasticArray's object.
 *
 * @param        rhs[out]      the ElasticArray's object to be copied
 *
 */
void ElasticArray::copy(const ElasticArray& rhs)
{
    //free the old memory.
    delete [] _array;
    //create the new array with the physical size of rhs.
    _array = new int[ rhs.max_size() ];
    //assign all values.
    for (int i = 0; i < rhs.size(); i++)
    {
        _array[i] = rhs._array[i];
    }
    //update the logical and physical size.
    _size      = rhs.size();
    _max_size  = rhs.max_size();
}



/**
 * @detailed Overloaded assignement operand.
 *
 * @param        rhs[out]      the ElasticArray's object to be copied
 *
 * @return  the ElasticArray's object
 *
 */
 const ElasticArray& ElasticArray::operator=(const ElasticArray& rhs)
 {
     copy(rhs);
     return rhs;
 }


