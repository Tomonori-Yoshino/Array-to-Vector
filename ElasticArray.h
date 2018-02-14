/**
 * @file    ElasticArray.cpp
 *
 * This file gives the definition of the class "ElasticArray".
 *
 * @author        Tomonori Yoshino
 * @date          February, 11
 */
#ifndef ELASTICARRAY_H
#define ELASTICARRAY_H



class ElasticArray
{
public:
    //constructors for initialization
    //and a destructor for freeing memory
    ElasticArray() = default;
    ElasticArray(int size);
    ElasticArray(const ElasticArray& source);
    ~ElasticArray();
    
    //member functios
    int                   size()     const { return _size; }
    int                   max_size() const { return _max_size; }
    int&                  at(int i);
    void                  push_back(int v);
    int                   front() const;
    int                   back()  const;
    int                   pop_back();
    void                  shrink_to_fit();
    void                  copy(const ElasticArray& rhs);
    const ElasticArray&   operator=(const ElasticArray& rhs);
    
    
    
private:
    int*    _array      = nullptr;
    int     _size       = 0;
    int     _max_size   = 0;
};

#endif
