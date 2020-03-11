#ifndef ABSTRACT_BOARD_H
#define ABSTRACT_BOARD_H

#include <vector>

using std::string;
using std::vector;

namespace puzzleOfElif{

	class AbstractBoard{
		public:
			AbstractBoard(); // default constructor
			AbstractBoard(int b_row,int b_column); // 2 parameter constructor
			AbstractBoard(const AbstractBoard& object); // copy consturctor
			int get_row()const;
			int get_column()const;
			int get_empty_i()const;
			int get_empty_j()const;
			static int numberOfMoves(); //Returns the number of steps (moves) this board made
			static int numberOfBoards(); //Returns the number of Board objects created so far.
			string lastMove()const; //Returns the last move, if there is no last move, returns ‘S’
			void setSize(int b_row,int b_column);//Sets the board size to given values. The values are given as parameters and there are no restrictions on the board size. The board is reset after this operation.
			void set_empty_i(int b_empty_i);
			void set_empty_j(int b_empty_j);
			void menu();
			int stoi_converter(string text); 
			int control_random(int *array,int counter,int random_number); // it checks if there is a same number while setting random board.
			virtual void print() const = 0; //Prints the board on the screen by sending it to cout
			virtual void initRandomly() = 0;
			virtual void move(const char direction) = 0; //Makes a move according to the given char parameter. If the parameter is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
			virtual void move_left() = 0;
			virtual void move_right() = 0;
			virtual void move_up() = 0;
			virtual void move_down() = 0;
			virtual void reset() = 0; //Resets the board to the solution.
			virtual bool isSolved() = 0; //Returns true if the board is a solution
			virtual void writeToFile(string fileName) = 0; //Writes the board to the file given as function parameter
			virtual void readFromFile(string fileName) = 0; //Reads the board from the file given as function parameter. The file format is defined as in HW2.
			virtual int operator()(const int i,const int j) = 0; //Takes two indexes and returns the corresponding cell content. Terminates program if the indexes are not valid.
			virtual bool operator==( AbstractBoard& object) = 0; //Two boards are equal, if the boards are the same. This operator does not consider last move or the number of steps
	
		
		protected:
			int row;
			int column;
			string last_move;
			int empty_i;
			int empty_j;
			int wall_number;
			static int numberOfMove;
			static int numberOfBoard;
	};

}

#endif