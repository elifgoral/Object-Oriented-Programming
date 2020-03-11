emp: exe

exe: abstract_board.o board_vector.o board_array1D.o board_array2D.o main.o
	g++ abstract_board.o board_vector.o board_array1D.o board_array2D.o main.o -o exe

abstract_board.o: abstract_board.cpp
	g++ -c abstract_board.cpp

board_vector.o: board_vector.cpp
	g++ -c board_vector.cpp

board_array1D.o: board_array1D.cpp
	g++ -c board_array1D.cpp

board_array2D.o: board_array2D.cpp
	g++ -c board_array2D.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o exe
