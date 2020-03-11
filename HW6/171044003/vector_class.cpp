#include <iostream>
#include <memory>
#include "vector_class.h"
#include "iterator_class.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::default_delete;

namespace ContainerOfElif{
		
	template <class T>
	GTUVector<T>::GTUVector(){
		used = 0;
		capacity = 2;
		v = shared_ptr<T>(new T[capacity],default_delete<T>());
	}

	template <class T>
	GTUVector<T>::GTUVector(int v_capacity){
		used = 0;
		capacity = v_capacity;
		v = shared_ptr<T>(new T[capacity],default_delete<T>());
	}

	template <class T>
	bool GTUVector<T>::empty(){ //Test whether container is empty
		if(used == 0)
			return true;
		return false;
	}

	template <class T>
	int GTUVector<T>::size(){
		return used;
	}

	template <class T>
	int GTUVector<T>::max_size(){ //Return maximum size
		return capacity;
	}

	template<class T>
	void GTUVector<T>::clear(){ //Clear all content
		used = 0;
	}

	template<class T>
	T GTUVector<T>::operator[](int index){
		GTUIterator<T> iter(&(*v));
		for(int i = 0 ; i < used ; i++){
			if(i != index){
				iter++;
			}
			else if(i == index){
				return *iter;
			}
		}
	}

	template<class T>
	void GTUVector<T>::print(){
		GTUIterator<T> iter(&(*v));
		for(int i = 0 ; i < used ; i++){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;//printing the object
	}

	template <class T>
	void GTUVector<T>::insert(T element){
		if(empty()){// if vector is empty...
			*v = element;
			used++;
		}
		else if(used == capacity){  // it checks capacity border.
			capacity *= 2;
			GTUIterator<T> iter(&(*v));
			while(iter != end()){
				iter++;
			}
			iter++;
			*iter = element;
			used++;
		}
		else{
			GTUIterator<T> iter(&(*v));
			while(iter != end()){
				iter++;
			}
			iter++;
			*iter = element;
			used++;
		} 
	}

	template <class T>
	void GTUVector<T>::erase(T element){
		if(empty()){
			cout << "vector is empty" << endl;
		}	
		else{
			shared_ptr<T>temp(new T[capacity],default_delete<T>());
			GTUIterator<T> iter(&(*v));
			GTUIterator<T> iter2(&(*temp));
			int counter = 0;
			while(counter < used){
				if(element != *iter){
					*iter2 = *iter;
					iter2++;
					iter++;
					counter++;
				}
				else{
					iter++;
					counter++;
				}
			}
			iter--;
			used--;
			v = temp;
		}
	}

	template <class T>
	GTUIterator<T> GTUVector<T>::begin(){
		GTUIterator<T> iter(&(*v));
		return iter;
	}
	
	template <class T>
	GTUIterator<T> GTUVector<T>::end(){
		GTUIterator<T> iter(&(*v));
		for(int i = 0 ; i < used ; i++){
			iter++;
		}	
		iter--;
		return iter;
	}
 	
 }