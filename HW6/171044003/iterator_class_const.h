#ifndef ITERATOR_CLASS_CONST_H
#define ITERATOR_CLASS_CONST_H   

#include <iostream>
#include <memory>

namespace ContainerOfElif{

    template<class T>
    class GTUIteratorConst{
    public: 
        GTUIteratorConst(T *mIter); // constructor
        GTUIteratorConst(const GTUIteratorConst& mIter); // copy constructor
        GTUIteratorConst& operator=(const GTUIteratorConst& mIter); // assignment operator    
        GTUIteratorConst& operator++();
        GTUIteratorConst operator++(T);   
        GTUIteratorConst& operator--();
        GTUIteratorConst operator--(T);
        T& operator*()const;
        T& operator->()const;
        bool operator==(const GTUIteratorConst<T>& mIter);
        bool operator!=(const GTUIteratorConst<T>& mIter);

    private:
        T* p;
    };
}
#endif