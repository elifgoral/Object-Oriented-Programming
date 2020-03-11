#include <iostream> 
#include "iterator_class_const.h"
using std::cout;
using std::endl;

namespace ContainerOfElif{
    template<class T>
    GTUIteratorConst<T>::GTUIteratorConst(T *mIter){ // constructor
        p = mIter;
    }

    template <class T>
    GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst& mIter){ //copy constructor
        p = mIter.p;
    }


    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst<T>& mIter){ // assignment operator
        p = mIter.p;
        return *this;
    }
   
    template <class T>
    T& GTUIteratorConst<T>::operator->()const{
        return p;
    }

    template <class T>
    T& GTUIteratorConst<T>::operator*()const{
        return *p;
    }

    template <class T>
    bool GTUIteratorConst<T>::operator==(const GTUIteratorConst<T>& mIter){
       if(p == mIter.p)
            return true;
        return false;
    }

    template <class T>
    bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst<T>& mIter){
        if(p == mIter.p)
            return false;
        return true;
    }

    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator++() {
        ++p;
        return *this;
    }

    template <class T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator++(T) {
        GTUIteratorConst mIter(*this);
        operator++();
        return mIter;
    }  
    
    template <class T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator--() {
        p--;
        return *this;
    }
        
    template <class T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator--(T) {
        GTUIteratorConst mIter(*this);
        operator--();
        return mIter;
    }
}


