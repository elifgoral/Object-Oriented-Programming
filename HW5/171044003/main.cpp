#include <iostream>
#include "board_vector.h"
#include "board_array2D.h"
#include "board_array1D.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using puzzleOfElif::BoardVector;
using puzzleOfElif::BoardArray1D;
using puzzleOfElif::BoardArray2D;

int main(int argc, char const *argv[]){
	srand(time(NULL));
	string text;
	int choice;
	int b_row,b_column;
	int co_i,co_j;

	if(argc == 1){
		do{
			bool result;
			cout << "what type do you want to initilaze the board:" << endl;
			cout << "1: vector of board" << endl;
			cout << "2: one dimensional board " << endl;
			cout << "3: two dimensional board" << endl;
			cout << "press any other key for quit" << endl;
			cin >> choice;

			if(choice == 1){
					BoardVector *board1;
					board1 = new BoardVector[2];

					cout << "Your vector board..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board1[0].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board1[0].initRandomly();
					cout << "Your board is:" << endl;
					board1[0].print();	
					cout << "Your choices:" << endl;			
					board1[0].menu();
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board1[0].operator()(co_i,co_j) << endl;

					cout << "using copy constructor" << endl;
					BoardVector b(board1[0]);
					cout << "now our new copied board is:" << endl;
					b.print();
					
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board1[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board1[1].initRandomly();
					cout << "Your board is:" << endl;
					board1[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board1[0] = board1[1];
					board1[0].print();

					result = board1[0].operator==(board1[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}

					cout << "Lets look, is your first board reach the solution or not." << endl;
					result = board1[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board1[0].reset();
					board1[0].print();
			}

			else if(choice == 2){
					BoardArray1D *board2;
					board2 = new BoardArray1D[2];

					cout << "Your vector board..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board2[0].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board2[0].initRandomly();
					cout << "Your board is:" << endl;
					board2[0].print();	
					cout << "Your choices:" << endl;			
					board2[0].menu();
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board2[0].operator()(co_i,co_j) << endl;
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board2[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board2[1].initRandomly();
					cout << "Your board is:" << endl;
					board2[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board2[0] = board2[1];
					board2[0].print();

					result = board2[0].operator==(board2[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}

					cout << "Lets look, is your first board reach the solution or not." << endl;
					result = board2[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board2[0].reset();
					board2[0].print();
			}

			else if(choice == 3){
					BoardArray2D *board3;
					board3 = new BoardArray2D[2];

					cout << "Your vector board..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board3[0].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board3[0].initRandomly();
					cout << "Your board is:" << endl;
					board3[0].print();	
					cout << "Your choices:" << endl;			
					board3[0].menu();
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board3[0].operator()(co_i,co_j) << endl;

					cout << "using copy constructor" << endl;
					BoardArray2D b(board3[0]);
					cout << "now our new copied board is:" << endl;
					b.print();
					
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board3[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board3[1].initRandomly();
					cout << "Your board is:" << endl;
					board3[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board3[0] = board3[1];
					board3[0].print();

					result = board3[0].operator==(board3[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}

					cout << "Lets look, is your first board reach the solution or not." << endl;
					result = board3[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board3[0].reset();
					board3[0].print();
			}
			else
				exit(1);

		}while(choice != 1 && choice != 2 && choice != 3);
	}

	else if(argc == 2){
		text = *(argv+1);	
		do{
			bool result;
			cout << "what type do you want to initilaze the board:" << endl;
			cout << "1: vector of board" << endl;
			cout << "2: one dimensional board " << endl;
			cout << "3: two dimensional board" << endl;
			cout << "press any other key for quit" << endl;
			cin >> choice;

			if(choice == 1){
					BoardVector *board1;
					board1 = new BoardVector[2];
					cout << "Your vector board..." << endl;
					board1[0].readFromFile(text);
					board1[0].print();	
					cout << "Your choices:" << endl;			
					board1[0].menu();
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board1[0].operator()(co_i,co_j) << endl;

					cout << "using copy constructor" << endl;
					BoardVector b(board1[0]);
					cout << "now our new copied board is:" << endl;
					b.print();
					
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board1[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board1[1].initRandomly();
					cout << "Your board is:" << endl;
					board1[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board1[0] = board1[1];
					board1[0].print();

					result = board1[0].operator==(board1[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}

					cout << "Lets look, is your first board reach the solution or not." << endl;
					result = board1[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board1[0].reset();
					board1[0].print();
			}

			if(choice == 2){
					BoardArray1D *board2;
					board2 = new BoardArray1D[2];
					cout << "Your one dimensional board..." << endl;
					board2[0].readFromFile(text);
					board2[0].print();	
					cout << "Your choices:" << endl;			
					board2[0].menu();				
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board2[0].operator()(co_i,co_j) << endl;
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board2[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board2[1].initRandomly();
					cout << "Your board is:" << endl;
					board2[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board2[0] = board2[1];
					board2[0].print();

					result = board2[0].operator==(board2[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}
					
					cout << "Lets look is your first board reach the solution or not." << endl;
					result = board2[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board2[0].reset();
					board2[0].print();

			}

			if(choice==3){
					BoardArray2D *board3;
					board3 = new BoardArray2D[2];
					cout << "Your two dimensional board..." << endl;
					board3[0].readFromFile(text);
					board3[0].print();	
					cout << "Your choices:" << endl;			
					board3[0].menu();
					cout << "which coordinate value do you want to learn? " << endl;
					cout << "coordinate i:";
					cin >> co_i;
					cout << "coordinate j:";
					cin >> co_j;
					cout << "value is: " << board3[0].operator()(co_i,co_j) << endl;

					cout << "using copy constructor" << endl;
					BoardArray2D b(board3[0]);
					cout << "now our new copied board is:" << endl;
					b.print();
					
					cout << "Your vector board2..." << endl;
					cout << "Enter a row:" << endl;
					cin >> b_row;
					cout << "Enter a column:" << endl;
					cin >> b_column;
					board3[1].setSize(b_row,b_column);
					cout << "your board is initilazing randomly..." << endl;
					board3[1].initRandomly();
					cout << "Your board is:" << endl;
					board3[1].print();	
					
					cout << "assigning your second vector board to first vector board..." << endl;

					board3[0] = board3[1];
					board3[0].print();

					result = board3[0].operator==(board3[1]);
					if(result == true)
						cout << "Assignment done." << endl << endl;
					
					else{
						cout << "assignment couldn't done." << endl << endl;
					}

					cout << "Lets look, is your first board reach the solution or not." << endl;
					result = board3[0].isSolved();
					if(result == false)
						cout << "Your board is not finish." << endl;
					else if(result == true)
						cout << "your board is finish. Congratulations !!" << endl;

					cout << "Now, we are reseting your first board..." << endl;
					board3[0].reset();
					board3[0].print();
			}

			else
				exit(1);

		}while(choice != 1 && choice != 2 && choice != 3);
	}

	return 0;
}