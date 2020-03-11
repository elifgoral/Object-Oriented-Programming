#include <iostream>
#include <string>
#include "abstract_board.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


namespace puzzleOfElif{

	int AbstractBoard::numberOfMove = 0;
	int AbstractBoard::numberOfBoard = 0;

	AbstractBoard::AbstractBoard():row(0),column(0){
		wall_number = 0;
		last_move = "s";
	}
	
	AbstractBoard::AbstractBoard(int b_row,int b_column):row(b_row),column(b_column){
		wall_number = 0;
		last_move = "s";
	}

	AbstractBoard::AbstractBoard(const AbstractBoard& object){ // copy consturctor
		row = object.row;
		column = object.column;
		empty_i = object.empty_i;
		empty_j = object.empty_j;
		last_move = object.last_move;
		wall_number = object.wall_number;
		numberOfMove = object.numberOfMove;
	}

	int AbstractBoard::get_row() const {return row;}
	
	int AbstractBoard::get_column()const {return column;}
	
	int AbstractBoard::get_empty_i()const {return empty_i;}
	
	int AbstractBoard::get_empty_j()const {return empty_j;}
	
	int AbstractBoard::numberOfMoves(){return numberOfMove;}
	
	int AbstractBoard::numberOfBoards(){return numberOfBoard;}
	
	string AbstractBoard::lastMove()const {return last_move;}
	
	void AbstractBoard::setSize(int b_row,int b_column){
		row = b_row;
		column = b_column;
	}

	void AbstractBoard::set_empty_i(int b_empty_i){
		empty_i = b_empty_i;
	}
	
	void AbstractBoard::set_empty_j(int b_empty_j){
		empty_j = b_empty_j;
	}

	void AbstractBoard::menu(){
		int i,j;
		char choice;
		string str;
		last_move = "s"; // 0:left 1:right 2:up 3:down

		do{
				cout << "L:	moves the empty cell left if there is room" << endl;
				cout << "R:	moves the empty cell right if there is room" << endl;
				cout << "U:	moves the empty cell up if there is room" << endl;
				cout << "D:	moves the empty cell down if there is room" << endl;	
				cout << "E:	Asks a file name and saves the current board configuration as a loadable shape file." << endl;
				cout << "O:	Asks a file name and loads the current board configuration from the shape file." << endl;
			
			cout << "choice:" ;
			cin >> choice;
			switch(choice){
				case 'l':
				case 'L':
						move(choice);
						cout << endl;
						print();
						cout << "numberOfMove: " << numberOfMove << endl;
						if(isSolved() == true){
							cout << "Game is solved" << endl;
							exit(1);
						}
						break;
				
				case 'r':
				case 'R':
						move(choice);
						cout << endl;
						print();	
						cout << "numberOfMove: " << numberOfMove << endl;
						if(isSolved()==true){
							cout << "Game is solved" << endl;
							exit(1);
						}
						break;
				
				case 'u':
				case 'U':
						move(choice);
						cout << endl;
						print();
						cout << "numberOfMove: " << numberOfMove << endl;
						if(isSolved()==true){
							cout << "Game is solved" << endl;
							exit(1);
						}
						break;
					
				case 'D':
				case 'd':
						move(choice);
						cout << endl;
						print();
						cout << "numberOfMove: " << numberOfMove << endl;
						if(isSolved()==true){
							cout << "Game is solved" << endl;
							exit(1);
						}
						break;
			
				case 'E':
				case 'e': 
						cout << "Name of the new file: ";
						cin >> str;
						writeToFile(str); 
					break;
				
				case 'O':
				case 'o':
						cout << "Name of the new file: " ;
						cin >> str;
						readFromFile(str);
						print();
						
					break;
				
				case 'q':
				case 'Q':
					break;

				default :
					break;

			}
		}while(choice != 'q' && choice != 'Q');
	}

	int AbstractBoard::stoi_converter(string text){
		char temp;	
		if(text[1] == '\0'){
			temp = text[0];
			text[1] = temp;
			text[0] = 48;
		}
		
		if((text[0] >= 48 && text[0] <= 57) && (text[1] >= 48 && text[1] <= 57))
			return (text[0] - 48) * 10 +(text[1] - 48);
	}

	int	AbstractBoard::control_random(int array[],int counter,int random_number){ // it checks if there is a same number while setting random board.
		int i;
		for(i = 0 ; i < counter ; i++){
			if(array[i] == random_number)
				return 0; // fail
		}
		return 1;//success
	}

}

