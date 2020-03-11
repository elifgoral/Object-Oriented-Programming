#ifndef ITERATOR_CLASS_H
#define ITERATOR_CLASS_H   

#include <iostream>
#include <memory>

namespace ContainerOfElif{

    template<class T>
    class GTUIterator{
    public: 
        GTUIterator(T *mIter); //constructor
        GTUIterator(const GTUIterator& mIter); // copy constructor
        GTUIterator& operator=(const GTUIterator& mIter); // assignment operator  
        GTUIterator& operator++();
        GTUIterator operator++(T);   
        GTUIterator& operator--();
        GTUIterator operator--(T);
        T& operator*();
        T& operator->();
        bool operator==(const GTUIterator<T>& mIter);
        bool operator!=(const GTUIterator<T>& mIter);

    private:
        T* p;
    };
}
#endif