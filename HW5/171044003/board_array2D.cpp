#include <iostream>
#include <fstream>

#include "board_array2D.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ofstream;


namespace puzzleOfElif{

	BoardArray2D::BoardArray2D():AbstractBoard(0,0){ //constructor

		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardArray2D::BoardArray2D(int b_row, int b_column):AbstractBoard(b_row,b_column){ //  2 parameter constructor

		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardArray2D::~BoardArray2D(){ // destructor
		for(int i = 0 ; i < row ; i++)
			delete [] board2D[i];
		delete [] board2D;
		numberOfBoard--;
		numberOfMove = 0;
	}

	BoardArray2D::BoardArray2D(const BoardArray2D & object):AbstractBoard(object){//copy constructor
		board2D = new int*[object.row];
			for(int i = 0 ; i < object.row ; i++)
				board2D[i] = new int[object.column];

		numberOfBoard++;
		
		row = object.row;
		column = object.column;
		empty_i = object.empty_i;
		empty_j = object.empty_j;

		for(int i = 0 ; i < row ; i++){
			for (int j = 0; j < column ; j++){	
				board2D[i][j] = object.board2D[i][j];
			}
		}
	}	

	BoardArray2D& BoardArray2D::operator=(const BoardArray2D & rightSide){ //assignment operator
		
		if(row != rightSide.row && column != rightSide.column){
			for(int i = 0 ; i < row ; i++)
					delete [] board2D[i];
				delete [] board2D;

			board2D = new int*[rightSide.row];
			for(int i = 0 ; i < rightSide.row ; i++)
				board2D[i] = new int[rightSide.column];
		}

		row = rightSide.row;
		column = rightSide.column;
		empty_i = rightSide.empty_i;
		empty_j = rightSide.empty_j;

		for(int i = 0 ; i < row ; i++){
			for (int j = 0; j < column ; j++){	
				board2D[i][j] = rightSide.board2D[i][j];
			}
		}
	}

	int BoardArray2D::operator()(const int i,const int j){
		if(i > row && i < 0 && j < 0 && j > column){
			cout << "illegal indexes" << endl;
			exit(1);
		}
		return board2D[i][j];
	}

	void BoardArray2D::init(string fileName){ //0: wall -1:empty(random)
		fstream inputStream;
		cout << endl;
		inputStream.open(fileName);
		string str;
		int i,j,temp;
		
		board2D = new int*[row];
		for(int i = 0 ; i < row ; i++)
			board2D[i] = new int[column];

		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < column ; j++){
				inputStream >> str;
				if(str == "bb"){
					board2D[i][j] = -1;
					empty_i = i;
					empty_j = j;
				}
				else if(str == "00"){
					board2D[i][j] = 0;
				}
				else{
					temp = stoi_converter(str);
					board2D[i][j] = temp;
				}
			}
		}
		inputStream.close();
	}

	void BoardArray2D::readFromFile(string fileName){ //Reads the board from the file given as function parameter. The file format is defined as in HW2.
		int counter = 0;
		int b_row,b_column;
		fstream inputStream;
		inputStream.open(fileName);
		string str;

		while(getline(inputStream,str)){ // finding line number.
			counter++;
		}
		row = counter;

		inputStream.close();
		
		inputStream.open(fileName);
		counter = 0;
		wall_number = 0;

		while(inputStream >> str){
			if(str == "00")
				wall_number++;

			counter++;
		}
		
		column = counter/row;
		
		init(fileName);

		inputStream.close();
	}

	void BoardArray2D::writeToFile(string fileName){//Writes the board to the file given as function parameter
		int i,j;
		ofstream myfile;
		myfile.open(fileName);
		
		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < column ; j++){
				if(board2D[i][j] == -1){
					myfile.width(5);
					myfile << "bb" << " ";
				}
				else if(board2D[i][j] == 0){
					myfile.width(5);
					myfile << "00" << " ";
				}
				else if(board2D[i][j] < 10){
					myfile.width(4);
					myfile << '0' << board2D[i][j] << ' ';
				}
				else{
					myfile.width(5);
					myfile << board2D[i][j] << ' ';
				}
			}
			myfile << endl;
		}	
		myfile.close();
	}

	void BoardArray2D::initRandomly(){ // it inits randomly the board.
		int i,j,counter = 0 , random_number;
		int num = row * column;
		int array[num];
		
		board2D = new int*[row];
		for(int i = 0 ; i < row ; i++)
			board2D[i] = new int[column];

		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < column ; j++){
				do{
					random_number = rand()%num;
					array[counter] = random_number;
				}while(control_random(array,counter,random_number) != 1);
				counter++;
				board2D[i][j] = random_number;
				
				if(board2D[i][j] == 0){
					empty_i = i;
					empty_j = j;
					board2D[i][j] = -1; 
				}
			}	
		}
	}

	bool BoardArray2D::isSolved(){//Returns true if the board is a solution
		int **array = new int*[row];
		for(int i = 0 ; i < row ; i++)
			array[i] = new int[column];

		initRespectively(array);
					
		int counter=0;
		for(auto i = 0 ; i < row ; i++){
			for(auto j = 0 ; j < column ; j++){
				if(board2D[i][j] == array[i][j])
					counter++;
			}	
		}
		
		if(counter == row * column)
			return true; // game is over
		else
			return false;	//game is continue.
	} 

	void BoardArray2D::initRespectively(int **array){
		int k = 1;
		int border;
		border = (row * column) - wall_number;
		for(auto i = 0 ; i < row ; i++){
			for(auto j = 0 ; j < column ; j++){
				if(k < border){
					if(array[i][j] != 0){
						array[i][j] = k;
						k++;
					}
				}
				else if(k == border){
					array[i][j] = -1;
				}
			}
		}
	}

	void BoardArray2D::reset(){ //Resets the board to the solution.
		initRespectively(board2D);
	}

	void BoardArray2D::move(const char direction){ //Makes a move according to the given char parameter. If the parameter is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
		switch(direction){
			case 'l':
			case 'L':
				move_left();
				break;

			case 'r':
			case 'R':
				move_right();
				break;
			
			case 'u':
			case 'U':
				move_up();
				break;

			case 'd':
			case 'D':
				move_down();
				break;

			default:
				exit(1);
				break;
		}
	}

	void BoardArray2D::move_left(){
		int a;
		if(empty_j != 0){
			if(board2D[empty_i][empty_j-1] != 0){
				a = board2D[empty_i][empty_j-1];
				board2D[empty_i][empty_j-1] = -1;
				board2D[empty_i][empty_j] = a;
				empty_j--;	
				last_move = "left";
				numberOfMove++;
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}

	void BoardArray2D::move_right(){
		int a;
		if(empty_j != column-1){ 
			if(board2D[empty_i][empty_j+1] != 0){
				a = board2D[empty_i][empty_j+1];
				board2D[empty_i][empty_j+1] = -1;
				board2D[empty_i][empty_j] = a;
				empty_j++;	
				last_move = "right";
				numberOfMove++;
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}
	
	void BoardArray2D::move_up(){
		int a;
		if(empty_i != 0){
			if(board2D[empty_i-1][empty_j] != 0){
				a = board2D[empty_i-1][empty_j];
				board2D[empty_i-1][empty_j] = -1;
				board2D[empty_i][empty_j] = a;
				empty_i--;	
				last_move = "up";
				numberOfMove++;
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}

	void BoardArray2D::move_down(){
		int a;
		if(empty_i != row-1){
			if(board2D[empty_i+1][empty_j]!=0){
				a = board2D[empty_i+1][empty_j];
				board2D[empty_i+1][empty_j] = -1;
				board2D[empty_i][empty_j] = a;
				empty_i++;
				last_move = "down";	
				numberOfMove++;
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}

	void BoardArray2D::print()const{
		for(int i = 0 ; i < row ; i++){
			for(int j=0 ; j < column ; j++){
				cout.width(5);
				if(board2D[i][j] == -1)				
					cout << " " << " ";
				else
					cout << board2D[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	bool BoardArray2D::operator==(AbstractBoard& object){ //Two boards are equal, if the boards are the same. This operator does not consider last move or the number of steps
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(board2D[i][j] != object.operator()(i,j))
					return false;
			}
		}
		return true;
	}

}