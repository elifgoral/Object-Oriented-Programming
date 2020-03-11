#ifndef ABSTRACT_CLASS_H
#define ABSTRACT_CLASS_H
#include "iterator_class.h"

namespace ContainerOfElif{
	template <class T>
	class GTUContainer{
		public:
			virtual bool empty() = 0; //Test whether container is empty
			virtual int size() = 0;	//Return container size
			virtual int max_size() = 0; //Return maximum size
			virtual void insert(T element) = 0;//Insert element, throws exception std::bad_pafram if there is a problem with insersion
			virtual void erase(T element) = 0;//Erase element
			virtual void clear() = 0; //Clear all content
			virtual GTUIterator<T> begin() = 0;//Return iterator to beginning
			virtual GTUIterator<T> end() = 0;//Return iterator to end
			virtual void print() = 0;

	};
}

#endif 