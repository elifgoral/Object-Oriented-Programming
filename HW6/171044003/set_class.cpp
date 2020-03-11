#include <iostream>
#include <set>
#include "set_class.h"
#include "iterator_class.h"

using std::set;
using std::cout;
using std::endl;
using std::iterator;
using std::default_delete;
using std::invalid_argument;

namespace ContainerOfElif{
	template <class T>
	GTUSet<T>::GTUSet(){
		used = 0;
		capacity = 2;
		s = shared_ptr<T>(new T[capacity],default_delete<T>());
	}
	
	template <class T>
	GTUSet<T>::GTUSet(int s_capacity){
		used = 0;
		capacity = s_capacity;
		s = shared_ptr<T>(new T[capacity],default_delete<T>());
	}

	template <class T>
	bool GTUSet<T>::empty(){ //Test whether container is empty
		if(used == 0)
			return true;
		return false;
	}

	template <class T>
	int GTUSet<T>::size(){
		return used;	
	}

	template <class T>
	int GTUSet<T>::max_size(){ //Return maximum size
		return capacity;
	}

	template <class T>
	void GTUSet<T>::clear(){ //Clear all content
		used = 0;
	}

	template <class T>
	int GTUSet<T>::FindSameElement(T element){ // it searching the same element.
		GTUIterator<T> iter1(&(*s));
		for(int i = 0 ; i < used ; i++){
			if(*iter1 == element){
				return 1;
			}
			else
				iter1++;
		}
		return 0;
	}

	template <class T>
	void GTUSet<T>::insert(T element){
		if(empty()){ // if set is empty...
			*s = element;
			used++;
		}
		else if(used == capacity){ // it checks capacity border.
			capacity *= 2;
			GTUIterator<T> iter(&(*s));
			while(iter != end()){
				iter++;
			}
			iter++;
			*iter = element;
			used++;
		}
		else if(FindSameElement(element) == 1){
			throw std::invalid_argument("This element has already in set.");
		}
		else if(FindSameElement(element) != 1){ // it checks set contains the same element.
			GTUIterator<T> iter(&(*s));
			while(iter != end()){
				iter++;
			}
			iter++;
			*iter = element;
			used++;
		}
	}

	template <class T>
	void GTUSet<T>::erase(T element){
		if(empty()){
			cout << "set is empty" << endl;
		}
		else{
			shared_ptr<T>temp(new T[capacity],default_delete<T>());
			GTUIterator<T> iter(&(*s));
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
			s = temp;
		}
	}

	template <class T>
	GTUIterator<T> GTUSet<T>::begin(){ //Return iterator to beginning
		GTUIterator<T> iter(&(*s));
		return iter;
	}
	
	template <class T>
	GTUIterator<T> GTUSet<T>::end(){//Return iterator to end
		GTUIterator<T> iter(&(*s));
		for(int i = 0 ; i < used ; i++){
			iter++;
		}	
		iter--;
		return iter;
	}
	
	template <class T>
	void GTUSet<T>::print(){
		GTUIterator<T> iter(&(*s));
		for(int i = 0 ; i < used ; i++){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
}