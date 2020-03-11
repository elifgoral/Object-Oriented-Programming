/*
	Elif Goral	
	171044003
*/

#include <iostream>
#include "abstract_class.h"
#include "abstract_class.cpp"
#include "vector_class.h"
#include "vector_class.cpp"
#include "set_class.h"
#include "set_class.cpp"
#include "iterator_class.h"
#include "iterator_class.cpp"

using namespace ContainerOfElif;

using std::cout;
using std::cin;
using std::endl;


int main(){

	try{
		GTUVector<int> objectVector;

		if(objectVector.empty())
			cout << "empty" << endl;

		cout << "our vector's size:";
		cout << objectVector.size() << endl;

		cout << "our vector's max size:";
		cout << objectVector.max_size() << endl;

		cout << "we are creating vector object:" << endl;
		cout << "inserting 1.." << endl; 
		objectVector.insert(1);
		
		cout << "our vector's size:";
		cout << objectVector.size() << endl;

		cout << "our vector's max size:";
		cout << objectVector.max_size() << endl;

		cout << "inserting 2.." << endl; 
		objectVector.insert(2);

		cout << "our vector's size:";
		cout << objectVector.size() << endl;

		cout << "our vector's max size:";
		cout << objectVector.max_size() << endl;

		cout << "inserting 3.." << endl; 
		objectVector.insert(3);

		cout << "our vector's size:";
		cout << objectVector.size() << endl;

		cout << "our vector's max size:";
		cout << objectVector.max_size() << endl;

		cout << "inserting 4.." << endl; 
		objectVector.insert(4);

		cout << "our vector object's begin element:"; 
		cout << *(objectVector.begin()) << endl;

		cout << "our vector object's end element:"; 
		cout << *(objectVector.end()) << endl << endl;

		cout << "printing our vector object.. " << endl;
		objectVector.print(); 
		cout << endl;

		cout << "our vector's size:";
		cout << objectVector.size() << endl;

		cout << "our vector's max size:";
		cout << objectVector.max_size() << endl;

		cout << "erasing 2:" << endl;
		objectVector.erase(2);

		objectVector.print();

		if(objectVector.empty())
			cout << "empty" << endl;

		cout << endl << endl << endl;

		for(int i = 0 ; i < objectVector.size(); i++){
			cout << " object1[" << i << "]:  " << objectVector.operator[](i) << endl;
		}
		cout << endl;
		/*
		-----------------------------------------------------------------------------
		*/
		cout << "now we are creating a set object." << endl;
		GTUSet<int> objectSet1;
		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "inserting 5.." << endl; 
		objectSet1.insert(12);

		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "inserting 6.." << endl; 
		objectSet1.insert(16);

		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "inserting 7.." << endl; 
		objectSet1.insert(23);
		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "inserting 6.." << endl; 
		objectSet1.insert(36);

		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "inserting 6.." << endl; 
		objectSet1.insert(56);

		cout << "our set's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		cout << "now we are printing the set object.." << endl;
		objectSet1.print();
		
		cout << "erasing 23.." << endl;
		objectSet1.erase(23);
		cout << "now we are printing our set again: ";
		objectSet1.print();

		cout << "our set object's begin element:"; 
		cout << *(objectSet1.begin()) << endl;

		cout << "our set object's end element:"; 
		cout << *(objectSet1.end()) << endl << endl;

		cout << "our set object's size:";
		cout << objectSet1.size() << endl;

		cout << "our set's max size:";
		cout << objectSet1.max_size() << endl;

		/*
		------------------------------------------------------------------------------
		*/
		cout << "now we are creating a set object." << endl;
		GTUSet<int> objectSet;

		cout << "our set's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

		cout << "inserting 5.." << endl; 
		objectSet.insert(5);

		cout << "our set's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

		cout << "inserting 6.." << endl; 
		objectSet.insert(6);

		cout << "our set's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

		cout << "inserting 7.." << endl; 
		objectSet.insert(7);
		cout << "our set's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

		cout << "inserting 6.." << endl; 
		objectSet.insert(6);

		cout << "our set's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

		cout << "now we are printing the set object.." << endl;
		objectSet.print();
		
		cout << "erasing 6.." << endl;
		objectSet.erase(6);
		cout << "we couldn't insert 6 because same element has already added." << endl;
		cout << "now we are printing our set again: ";
		objectSet.print();

		cout << "our set object's begin element:"; 
		cout << *(objectSet.begin()) << endl;

		cout << "our set object's end element:"; 
		cout << *(objectSet.end()) << endl << endl;

		cout << "our set object's size:";
		cout << objectSet.size() << endl;

		cout << "our set's max size:";
		cout << objectSet.max_size() << endl;

	}

	catch(const std::exception &_exception){
		cout << _exception.what() << endl;
	}	

	return 0;
}