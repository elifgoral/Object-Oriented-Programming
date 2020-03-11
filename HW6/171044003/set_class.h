#ifndef SET_CLASS_H
#define SET_CLASS_H

#include "abstract_class.h"
#include <iostream>
#include <memory>

using std::shared_ptr;

namespace ContainerOfElif{
	template <class T>
	class GTUSet : public GTUContainer<T>{
		public:
			GTUSet(); //default constructor
			GTUSet(int s_capacity); //one parameter constructor
			bool empty()override; //Test whether container is empty
			int size()override;	//Return container size
			int max_size()override; //Return maximum size
			void insert(T element)override;//Insert element, throws exception std::bad_pafram if there is a problem with insersion
			void erase(T element)override;//Erase element
			void clear()override; //Clear all content
			GTUIterator<T> begin()override; //Return iterator to beginning
			GTUIterator<T> end()override; //Return iterator to end
			void print()override;
			int FindSameElement(T element);

		private:
			shared_ptr<T> s;
			int used;
			int capacity;
	};
} 

#endif