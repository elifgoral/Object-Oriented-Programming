#include <iostream>
#include <fstream>

#include "board_array1D.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ofstream;


namespace puzzleOfElif{

	BoardArray1D::BoardArray1D():AbstractBoard(0,0){ //default constructor
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardArray1D::BoardArray1D(int b_row,int b_column):AbstractBoard(b_row,b_column){ //2 parameter constructor
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardArray1D::~BoardArray1D(){ //destructor
		delete [] board1D;
		numberOfBoard--;
		numberOfMove = 0;
	}

	BoardArray1D::BoardArray1D(const BoardArray1D& object){ //copy constructor
		board1D = new int[row * column];
		numberOfBoard++;
		row = object.row;
		column = object.column;
		empty_i = object.empty_i;
		empty_j = object.empty_j;

		for(int i = 0 ; i < row * column ; i++){
			board1D[i] = object.board1D[i];
		}
	}

	BoardArray1D& BoardArray1D::operator=(const BoardArray1D& rightSide){ // assignment operator
		if(row != rightSide.row && column != rightSide.column){
			delete [] board1D;
			board1D = new int[row * column];
		}

		row = rightSide.row;
		column = rightSide.column;
		empty_i = rightSide.empty_i;
		empty_j = rightSide.empty_j;
		
		for(int i = 0 ; i < row * column ; i++){
			board1D[i] = rightSide.board1D[i];
		}
	}

	void BoardArray1D::print()const{
		int counter = 0;
		for(int i = 0 ; i < row * column ; i++){
			cout.width(5);
			if(counter == column){
				counter = 0;
				cout << endl;
			}

			if(board1D[i] == -1){
				cout << " " << " ";
				counter++;
			}

			else{
				cout << board1D[i] << " ";
				counter++;
			}
		}
		cout << endl << endl;
	}

	void BoardArray1D::reset(){ //Resets the board to the solution.
		initRespectively(board1D);
	}

	void BoardArray1D::initRespectively(int *array){
		int k = 1;
		int border;
		int num = row * column;
		border = num - wall_number;
		
		for(auto i = 0 ; i < num ; i++){
			if(k < border){
				if(array[i] != 0){
					array[i] = k;
					k++;
				}
			}

			else if(k == border){
				array[i] = -1;
			}
		}
	}

	void BoardArray1D::move(const char direction){ //Makes a move according to the given char parameter. If the parameter is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
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

	void BoardArray1D::move_left(){
		int a;
		int index = (empty_i * column) + empty_j;

		if(empty_j != 0){
			if(board1D[index - 1] != 0){
				a = board1D[index -1];
				board1D[index - 1] = -1;
				board1D[index] = a;
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

	void BoardArray1D::move_right(){
		int a;
		int index = (empty_i * column) + empty_j;

		if(empty_j != column-1){ 
			if(board1D[index + 1] != 0){
				a = board1D[index + 1];
				board1D[index + 1] = -1;
				board1D[index] = a;
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

	void BoardArray1D::move_up(){
		int a;
		int index = (empty_i * column) + empty_j;

		if(empty_i != 0){
			if(board1D[index - column] != 0){
				a = board1D[index - column];
				board1D[index - column] = -1;
				board1D[index] = a;
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

	void BoardArray1D::move_down(){
		int a;
		int index = (empty_i * column) + empty_j;
			
		if(empty_i != row-1){
			if(board1D[index + column] != 0){
				a = board1D[index + column];
				board1D[index + column] = -1;
				board1D[index] = a;
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

	void BoardArray1D::initRandomly(){
		int i,j,counter = 0 , random_number;
		int num = row * column;
		int array[num];
		
		cout << "row:" << row << endl;
		cout << "column: " << column << endl;
		board1D = new int[num];
		for(int i = 0 ; i < num ; i++){
			do{
				random_number = rand() % num;
				array[counter] = random_number;
			}while(control_random(array,counter,random_number) != 1);
				
			counter++;
			board1D[i] = random_number ;
			if(board1D[i] == 0){
				empty_i = i / column;
				empty_j = i % column;
				board1D[i] = -1;
			}
		}
	}

	bool BoardArray1D::isSolved(){ //Returns true if the board is a solution

		int num = row * column;
		int *array = new int[num];

		initRespectively(array);
		int counter = 0;

		for(auto i = 0 ; i < num ; i++){
			if(array[i] == board1D[i])
				counter++;
		}

		if(counter == num)
			return true; // game is over
		else
			return false;	//game is continue.
	}	

	void BoardArray1D::writeToFile(string fileName){ //Writes the board to the file given as function parameter
		int i,j;
		ofstream myfile;
		myfile.open(fileName);
		int counter = 0;
		int num = row * column;	

		for(int i = 0 ; i < num ; i++){
			if(board1D[i] == -1){
				myfile.width(5);
				myfile << "bb" << " ";
				counter++;
			}	
			else if(board1D[i] == 0){
				myfile.width(5);
				myfile << "00" << " ";
				counter++;
			}
			else if(board1D[i] < 10){
				myfile.width(4);
				myfile << '0' << board1D[i]  << ' ';
				counter++;
			}
			else{
				myfile.width(5);
				myfile << board1D[i] << ' ';
				counter++;
			}
			if(counter == column){
				counter = 0;
				myfile << endl;
			}
		}
		myfile.close();
	}

	void BoardArray1D::readFromFile(string fileName){ //Reads the board from the file given as function parameter. The file format is defined as in HW2.
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

	void BoardArray1D::init(string fileName){ //0: wall -1:empty(random)
		fstream inputStream;
		inputStream.open(fileName);
		//cout << " fileName:" << fileName << endl;
		string str;
		int i,j,temp;
		int num = row * column;
		board1D = new int[num];

		for(auto i = 0 ; i < num ; i++){
			inputStream >> str;
			if(str == "bb"){
				board1D[i] = -1;
				empty_i = i / column;
				empty_j = i % column;
			}
			else if(str == "00"){
				board1D[i] = 0;
			}
			else{
				temp = stoi_converter(str);
				board1D[i] = temp;
			}
		}

		inputStream.close();
	}
	
	int BoardArray1D::operator()(const int i,const int j){ //Takes two indexes and returns the corresponding cell content. Terminates program if the indexes are not valid.
		if(i > row && i < 0 && j < 0 && j > column){
			cout << "illegal indexes" << endl;
			exit(1);
		}
		return board1D[(i * column) + j];
	}

	bool BoardArray1D::operator==(AbstractBoard& object){
		int index , num = row * column ;
		for(int index = 0 ; index < num ; index++){
			int j = index % column;
			int i = index / column;
			if(board1D[index] != object.operator()(i,j))
				return false;
		}
		return true;
	}

}
