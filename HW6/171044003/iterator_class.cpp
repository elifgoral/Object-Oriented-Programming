#include <iostream> 
#include "iterator_class.h"
using std::cout;
using std::endl;

namespace ContainerOfElif{
    template<class T>
    GTUIterator<T>::GTUIterator(T *mIter){ // constructor
        p = mIter;
    }

    template <class T>
    GTUIterator<T>::GTUIterator(const GTUIterator& mIter){ // copy constructor
        p = mIter.p;
    }


    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator<T>& mIter){ // assignment operator
        p = mIter.p;
        return *this;
    }
   
    template <class T>
    T& GTUIterator<T>::operator->(){
        return p;
    }

    template <class T>
    T& GTUIterator<T>::operator*() {
        return *p;
    }

    template <class T>
    bool GTUIterator<T>::operator==(const GTUIterator<T>& mIter){
       if(p == mIter.p)
            return true;
        return false;
    }

    template <class T>
    bool GTUIterator<T>::operator!=(const GTUIterator<T>& mIter){
        if(p == mIter.p)
            return false;
        return true;
    }

    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator++() {
        ++p;
        return *this;
    }

    template <class T>
    GTUIterator<T> GTUIterator<T>::operator++(T) {
        GTUIterator mIter(*this);
        operator++();
        return mIter;
    }  
    
    template <class T>
    GTUIterator<T>& GTUIterator<T>::operator--() {
        p--;
        return *this;
    }
        
    template <class T>
    GTUIterator<T> GTUIterator<T>::operator--(T) {
        GTUIterator mIter(*this);
        operator--();
        return mIter;
    }
}


