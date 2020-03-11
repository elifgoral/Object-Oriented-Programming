#ifndef BOARD_ARRAY2D_H
#define BOARD_ARRAY2D_H
#include "abstract_board.h"


namespace puzzleOfElif{

	class BoardArray2D : public AbstractBoard{
		public:
			BoardArray2D();//default constructor
			BoardArray2D(int b_row,int b_column); // 2 parameter constructor
			~BoardArray2D();//destructor
			BoardArray2D(const BoardArray2D & object); //copy constructor
			void print() const override; //Prints the board on the screen by sending it to cout
			void move(const char direction) override; //Makes a move according to the given char parameter. If the parameter is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
			void move_left() override;
			void move_right() override;
			void move_up() override;
			void move_down() override;
			void reset() override; //Resets the board to the solution.
			void initRespectively(int **array); // init the board respectively
			bool isSolved() override; //Returns true if the board is a solution
			void initRandomly() override; // it inits randomly the board.
			void writeToFile(string fileName) override; //Writes the board to the file given as function parameter
			void readFromFile(string fileName)override; //Reads the board from the file given as function parameter. The file format is defined as in HW2.
			void init(string fileName); //0: wall -1:empty(random)
			int operator()(const int i,const int j)override; //Takes two indexes and returns the corresponding cell content. Terminates program if the indexes are not valid.
			BoardArray2D& operator=(const BoardArray2D & rightSide); //assignment operator
			bool operator==(AbstractBoard& object)override; //Two boards are equal, if the boards are the same. This operator does not consider last move or the number of steps
			
		private:	
			int **board2D;
			
	};
}


#endif