#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "board_vector.h"

using namespace std;

namespace puzzleOfElif{
	
	BoardVector::BoardVector():AbstractBoard(0,0){ //default constructor
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardVector::BoardVector(int row,int column):AbstractBoard(row,column){ // 2 parameter constructor
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	BoardVector::BoardVector(const BoardVector& object):AbstractBoard(object){//copy constructor
		v.resize(row);
		for(int i = 0 ; i < row ; i++)
			v[i].resize(column);

		row = object.row;
		column = object.column;
		empty_i = object.empty_i;
		empty_j = object.empty_j;


		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				v[i][j] = object.v[i][j];				
			}
		}
		numberOfBoard++;
	}

	BoardVector::~BoardVector(){
		numberOfBoard--;
		numberOfMove = 0;
	}

	void BoardVector::init(string fileName){ //0: wall -1:empty(random)
		fstream inputStream;
		cout << endl;
		inputStream.open(fileName);
		string str;
		int i,j,temp;
		v.resize(row);
		for(i = 0 ; i < row ; i++){
			v[i].resize(column);
			for(j = 0 ; j < column ; j++){
				inputStream >> str;
				if(str == "bb"){
					v[i][j] = -1;
					empty_i = i;
					empty_j = j;
				}
				else if(str == "00"){
					v[i][j] = 0;
				}
				else{
					temp = stoi_converter(str);
					v[i][j] = temp;
				}
			}
		}
		inputStream.close();
	}

	void BoardVector::readFromFile(string fileName){ //Reads the board from the file given as function parameter. The file format is defined as in HW2.

		int counter = 0;
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

		inputStream.close();
		init(fileName);
	}

	void BoardVector::writeToFile(string fileName){ //Writes the board to the file given as function parameter
		int i,j;
		ofstream myfile;
		myfile.open(fileName);
		
		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < column ; j++){
				if(v[i][j] == -1){
					myfile.width(5);
					myfile << "bb" << " ";
				}
				else if(v[i][j] == 0){
					myfile.width(5);
					myfile << "00" << " ";
				}
				else if(v[i][j] < 10){
					myfile.width(4);
					myfile << '0' << v[i][j] << ' ';
				}
				else{
					myfile.width(5);
					myfile << v[i][j] << ' ';
				}
			}
			myfile << endl;
		}	
		myfile.close();
	}

	bool BoardVector::isSolved(){ //Returns true if the board is a solution
		vector<vector<int>>a;
		a.resize(row);
		for(int i = 0 ; i < row ; i++)
			a[i].resize(column);				
			
		initRespectively(a);
		int counter = 0;
		for(auto i = 0 ; i < row ; i++){
			for(auto j = 0 ; j < column ; j++){
				if(v[i][j] == a[i][j])
					counter++;
			}	
		}
		
		if(counter == row*column)
			return true; // game is over
		else
			return false;	//game is continue.
	}
	void BoardVector::initRespectively(vector<vector<int>> &vec){ // it inits respectively the board.
		int k = 1;
		int border;
		border = (row * column) - wall_number;
		vec.resize(row);
		for(auto i = 0 ; i < row ; i++){
			vec[i].resize(column);		
			for(auto j = 0 ; j < column ; j++){
				if(k < border){
					if(vec[i][j] != 0){
						vec[i][j] = k;
						k++;
					}
				}
				else if(k == border){
					vec[i][j] = -1;
				}
			}
		}
	}

	void BoardVector::reset(){
		initRespectively(v);
	}

	void BoardVector::move(const char direction){
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

	void BoardVector::move_left(){
		int a;
		if(empty_j != 0){
			if(v[empty_i][empty_j-1] != 0){
				a = v[empty_i][empty_j-1];
				v[empty_i][empty_j-1] = -1;
				v[empty_i][empty_j] = a;
				empty_j--;	
				numberOfMove++;
				last_move = "left";
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}
	
	void BoardVector::move_right(){
		int a;
		if(empty_j != column-1){ 
			if(v[empty_i][empty_j+1] != 0){
				a=v[empty_i][empty_j+1];
				v[empty_i][empty_j+1] = -1;
				v[empty_i][empty_j] = a;
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

	void BoardVector::move_up(){
		int a;
		if(empty_i != 0){
			if(v[empty_i-1][empty_j] != 0){
				a=v[empty_i-1][empty_j];
				v[empty_i-1][empty_j] = -1;
				v[empty_i][empty_j] = a;
				empty_i--;	
				numberOfMove++;
				last_move = "up";
			}
			else
				cout<< "wrong move" << endl;
		}
		else
			cout<< "wrong move" << endl;
	}

	void BoardVector::move_down(){
		int a;
		if(empty_i != row-1){
			if(v[empty_i+1][empty_j]!=0){
				a = v[empty_i+1][empty_j];
				v[empty_i+1][empty_j] = -1;
				v[empty_i][empty_j] = a;
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

	void BoardVector::initRandomly(){
		int random_number,counter=0;
		int num = row * column;
		
		int array[num];

		v.resize(row);
		for(int i = 0 ; i < row ; i++){
			v[i].resize(column);
			for(int j = 0 ; j < column ; j++){
				do{
					random_number = rand() % num;
					array[counter] = random_number;
				}while(control_random(array,counter,random_number) != 1);
				counter++;
				v[i][j] = random_number;

				if(v[i][j] == 0){
					empty_i = i;
					empty_j = j;
					v[i][j] = -1;
				}			
			}
		}
	}

	void BoardVector::print()const{
		for(int i = 0 ; i < row ; i++){
			for(int j=0 ; j < column ; j++){
				cout.width(5);
				if(v[i][j] == -1)				
					cout << " " << " ";
				else
					cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	
	int BoardVector::operator()(const int i,const int j){//Takes two indexes and returns the corresponding cell content. Terminates program if the indexes are not valid.
		if(i > row && i < 0 && j < 0 && j > column){
			cout << "illegal indexes" << endl;
			exit(1);
		}
		return v[i][j];
	}
	
	bool BoardVector::operator==(AbstractBoard& object){ //Two boards are equal, if the boards are the same. This operator does not consider last move or the number of steps
		
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(v[i][j] != object.operator()(i,j))
					return false;
			}
		}
		return true;

	}	
}