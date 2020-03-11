emp: exe

exe: abstract_class.o set_class.o vector_class.o iterator_class.o main.o
	g++ abstract_class.o set_class.o vector_class.o iterator_class.o main.o -o exe

abstract_class.o: abstract_class.cpp
	g++ -c abstract_class.cpp

set_class.o: set_class.cpp
	g++ -c set_class.cpp

vector_class.o: vector_class.cpp
	g++ -c vector_class.cpp

iterator_class.o: iterator_class.cpp
	g++ -c iterator_class.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o exe
