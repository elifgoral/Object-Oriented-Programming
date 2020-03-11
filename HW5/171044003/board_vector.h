#ifndef BOARD_VECTOR_H
#define BOARD_VECTOR_H

#include <vector>
#include "abstract_board.h"

using std::vector;
 
namespace puzzleOfElif{

	class BoardVector : public AbstractBoard{
		public:
			BoardVector(); // default constructor
			BoardVector(int row,int column); // 2 parameter constructor
			BoardVector(const BoardVector& object);//copy constructor
			~BoardVector(); // KONTROL ET
			void initRandomly() override; // it inits randomly the board.
			void initRespectively(vector<vector<int>> &vec); // it inits respectively the board.
			void print() const override; //Prints the board on the screen by sending it to cout
			void move(const char direction) override; //Makes a move according to the given char parameter. If the parameter is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
			void move_left() override;
			void move_right() override;
			void move_up() override;
			void move_down() override;
			void reset() override; //Resets the board to the solution.
			bool isSolved() override; //Returns true if the board is a solution
			void writeToFile(string fileName) override; //Writes the board to the file given as function parameter
			void readFromFile(string fileName)override; //Reads the board from the file given as function parameter. The file format is defined as in HW2.
			void init(string fileName); // init after the read the board.
			int operator()(const int i,const int j) override; //Takes two indexes and returns the corresponding cell content. Terminates program if the indexes are not valid.
			bool operator==(AbstractBoard& object)override; //Two boards are equal, if the boards are the same. This operator does not consider last move or the number of steps

		protected:
			vector<vector<int>> v;

	};
}

#endif