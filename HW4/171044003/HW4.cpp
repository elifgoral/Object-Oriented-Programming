#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

class NPuzzle{

	private:
		class Board{
			private:
				vector<vector<int>> v;
				int row;
				int column;
				int empty_i;
				int empty_j;
				int way;
				int wall_number;
				int number_of_move;

			public:
				void print()const; //Prints the board on the screen by sending it to cout
				void readFromFile(string text); //Reads the board from the file given as function parameter. The file format is defined as in HW2.
				void writeToFile(string text); //Writes the board to the file given as function parameter
				void setSize();//Sets the board size to given values. The values are given as parameters and they can be at most 9x9. After setting the size, the boards should be reset.
				void move(char choice);//Makes a move according to the given char parameter. If the parameters is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
				bool isSolved();//Returns true if the board is a solution
				void initRandomly();
				int control_random(vector<int> &v,int num,int a);
				void move_left();
				void move_right();
				void move_up();
				void move_down();
				void menu(string text);
				void init(string text);
				int stoi_converter(string text);
				void reset(vector<vector<int>> &vec);//Resets the board to the solution.
				void printReport();
				void shuffle(int random_move);
				void move_random(char choice);
				int numberOfMoves(){ return number_of_move; }
				int lastMove(){ return way;}
	};
		
	public:
		vector<Board> board;
		void print()const{ //Prints the current configuration on the screen by sending it to cout
			board[0].print();
		}
		void printReport(){//Prints a report about how many moves have been done since reset and if the solution is found
			board[0].printReport();
		}
		void readFromFile(string text){ //Reads the current configuration from the file given as function parameter. The file format is defined as in HW2.
			board.resize(1);
			board[0].readFromFile(text);
		}
		void writeToFile(string text){ // Writes the current configuration to the file given as function parameter
			board[0].writeToFile(text);
		}
		void setSize() //Sets the board size to given values. The values are given as parameters and they can be at most 9x9. After setting the size, the boards should be reset.
		{
			board.resize(1);
			board[0].setSize();
		}
		void moveRandom(); //Makes a valid random move
		void moveIntelligent(); // Makes an “intelligent” move
		void move(char choice){ //Makes a move according to the given char parameter. If the parameters is ‘L’ then, the blank tiles moves left, ..., etc, as defined in HW1.
			board[0].move(choice);
		}
		void initRandomly(){
			board.resize(1);
			board[0].initRandomly();
		}
		void menu(string text){
			board[0].menu(text);
		}
		bool isSolved(){
			board[0].isSolved();
		}
		void reset(vector<vector<int>> &vec){//Resets the current configuration to the solution.
			board[0].reset(vec);
		}
		void shuffle(int random_move){//Makes N random moves to shuffle the board. N is given as a function parameter.
			board[0].shuffle(random_move);
		}
		void move_random(char choice){
			board[0].move_random(choice);
		}
		int numberOfMoves(){
			board[0].numberOfMoves();
		}
		int lastMove(){
			board[0].lastMove();
		}
};


int main(int argc, char const *argv[]){
	NPuzzle puzzle;
	srand(time(NULL));
	string text;

	if(argc==1){
		puzzle.setSize();
		puzzle.initRandomly();
		puzzle.print();
		puzzle.menu(text);
	}
	
	else if(argc==2){
		text=*(argv+1);	
		puzzle.readFromFile(text);
		puzzle.print();
		puzzle.menu(text);
	
	}

	return 0;
}

void NPuzzle::Board::writeToFile(string text){ // 0: wall -1:empty(random)
	
	cout << endl;
	int i,j;
	
	ofstream myfile;
	myfile.open(text);
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(v[i][j]==-1){
				myfile.width(5);
				myfile << "bb" << " ";
			}
			else if(v[i][j]==0){
				myfile.width(5);
				myfile << "00" << " ";
			}
			else if(v[i][j]<10){
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

void NPuzzle::Board::menu(string text){
	int i,j;
	char choice;
	number_of_move=0;
	string str;
	way=10; // 0:left 1:right 2:up 3:down

	do{
			cout << "L:	moves the empty cell left if there is room" << endl;
			cout << "R:	moves the empty cell right if there is room" << endl;
			cout << "U:	moves the empty cell up if there is room" << endl;
			cout << "D:	moves the empty cell down if there is room" << endl;	
			cout << "S:	Shuffle- takes the board to the final solution, and makes size*size random moves to shuffle the board." << endl;	
			cout << "I:	makes an “intelligent” move for you. " << endl;
			cout << "V:	Solves the problem from the current configuration using the new intelligent algorithm." << endl;
			cout << "T:	Prints a report about how many moves have been done and if the solution is found." << endl;
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
					number_of_move++;
					if(isSolved()==true){
						cout << "Game is solved" << endl;
						printReport();
						exit(1);
					}
					break;
			
			case 'r':
			case 'R':
					move(choice);
					cout << endl;
					print();	
					number_of_move++;
					if(isSolved()==true){
						cout << "Game is solved" << endl;
						printReport();
						exit(1);
					}
					break;
			
			case 'u':
			case 'U':
					move(choice);
					cout << endl;
					print();
					number_of_move++;
					if(isSolved()==true){
						cout << "Game is solved" << endl;
						printReport();
						exit(1);
					}
					break;
				
			case 'D':
			case 'd':
					move(choice);
					cout << endl;
					print();
					number_of_move++;
					if(isSolved()==true){
						cout << "Game is solved" << endl;
						printReport();
						exit(1);
					}
					break;
			
			case 'i':
			case 'I':
					break;			
			
			case 'S':
			case 's':
					int num_random;
					num_random=row*column;
					shuffle(num_random);
					if(isSolved()==true){
						cout << "Game is solved" << endl;
						printReport();
						exit(1);
					}
					break;
			
			case 'V':
			case 'v':
					break;
			
			case 'T':
			case 't':
					printReport();
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
				exit(1);
				break;
		}
	}while(choice != 'q' || choice != 'Q');
}

void NPuzzle::Board::shuffle(int random_move){
	
	reset(v);	
	print();
	empty_i=row-1;
	empty_j=column-1;
	int i;
	for(i=0;i<random_move;i++){
		int choice=rand()%4;
		move_random(choice);
		print();
	}
}

void NPuzzle::Board::move_random(char choice){	
	if(choice==0 && way!=1){
		move_left();
	}
	else if(choice==1 && way!=0){
		move_right();
	}
	else if(choice==2 && way!=3){
		move_up();
	}
	else if(choice==3 && way!=2){
		move_down();
	}
}

void NPuzzle::Board::reset(vector<vector<int>> &vec){
	int k=1;
	int border;
	border=(row*column)-wall_number;

	vec.resize(row);
	for(auto i=0;i<row;i++){
		vec[i].resize(column);		
		for(auto j=0;j<column;j++){
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

inline void NPuzzle::Board::printReport(){
	cout << "number of move: " << numberOfMoves() << endl;
	if(isSolved()==1){
		cout << "congratulations!"<< endl;
	}
	else{
		cout << "game is continue" << endl;
	}
}

bool NPuzzle::Board::isSolved(){

	vector<vector<int>>a;
	a.resize(row);
	for(int i=0;i<row;i++){
		a[i].resize(column);				
		for(int j=0;j<column;j++){
			a[i][j]=v[i][j];
		}
	}

	reset(a);
	int counter=0;
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			if(v[i][j]==a[i][j])
				counter++;
		}	
	}
	
	if(counter==row*column)
		return true; // game is over
	else
		return false;	//game is continue.
}

void NPuzzle::Board::readFromFile(string text){
	int counter=0;
	fstream inputStream;

	inputStream.open(text);
	string str;

	while(getline(inputStream,str)){ // finding line number.
		counter++;
	}
	cout << counter;
	row=counter;
	
	inputStream.close();

	inputStream.open(text);
	counter=0;
	wall_number=0;

	while(inputStream >> str){
		if(str=="00")
			wall_number++;

		counter++;
	}
	
	column = counter/row;
	

	inputStream.close();
	init(text);
}

void NPuzzle::Board::init(string text){ //0: wall -1:empty(random)
	fstream inputStream;
	cout << endl;
	inputStream.open(text);
	string str;
	int i,j,temp;
	v.resize(row);
	for(i=0;i<row;i++){
		v[i].resize(column);
		for(j=0;j<column;j++){
			inputStream >> str;
			if(str == "bb"){
				v[i][j]=-1;
				empty_i=i;
				empty_j=j;
				//cout << str << " ";
			}
			else if(str == "00"){
				v[i][j]=0;
				//cout << str << " ";
			}
			else{
				temp=stoi_converter(str);
				v[i][j]=temp;
				//cout << str << " ";
			}
		}
	}
	inputStream.close();
}

int NPuzzle::Board::stoi_converter(string text){
	char temp;	
		
	if(text[1]=='\0'){
		temp=text[0];
		text[1]=temp;
		text[0]=48;
	}
	
	if((text[0]>=48 && text[0]<=57) && (text[1]>=48 && text[1]<=57))
				return (text[0]-48)*10+(text[1]-48);
}

void NPuzzle::Board::move(char choice){
	switch(choice){
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
	}
}

void NPuzzle::Board::move_left(){
	int a;
	if(empty_j!=0){
		if(v[empty_i][empty_j-1]!=0){
			a=v[empty_i][empty_j-1];
			v[empty_i][empty_j-1]=-1;
			v[empty_i][empty_j]=a;
			empty_j--;	
			way=0;
		}
		else
			cout<< "wrong move" << endl;
	}
	else
		cout<< "wrong move" << endl;
}	

void NPuzzle::Board::move_right(){
	int a;
	if(empty_j!=column-1){ 
		if(v[empty_i][empty_j+1]!=0){
			a=v[empty_i][empty_j+1];
			v[empty_i][empty_j+1]=-1;
			v[empty_i][empty_j]=a;
			empty_j++;	
			way=1;
		}
		else
			cout<< "wrong move" << endl;
	}
	else
		cout<< "wrong move" << endl;
}

void NPuzzle::Board::move_up(){
	int a;
	if(empty_i!=0){
		if(v[empty_i-1][empty_j]!=0){
			a=v[empty_i-1][empty_j];
			v[empty_i-1][empty_j]=-1;
			v[empty_i][empty_j]=a;
			empty_i--;	
			way=2;
		}
		else
			cout<< "wrong move" << endl;
	}
	else
		cout<< "wrong move" << endl;
}

void NPuzzle::Board::move_down(){
	int a;
	if(empty_i!=row-1){
		if(v[empty_i+1][empty_j]!=0){
			a=v[empty_i+1][empty_j];
			v[empty_i+1][empty_j]=-1;
			v[empty_i][empty_j]=a;
			empty_i++;
			way=3;	
		}
		else
			cout<< "wrong move" << endl;
	}
	else
		cout<< "wrong move" << endl;
}

// it checks if there is a same number while setting random board. 
int NPuzzle::Board::control_random(vector<int> &v,int num,int a){
	for(int i=0;i<num;i++){
		if(v[i]==a){
			return 0; // fail
		}
	}
	return 1; //success
}

// it takes sizes from user.
void NPuzzle::Board::setSize(){
	cout << "enter row:" ;
	cin >> row; 
	cout << "Enter column: ";
	cin >> column;
}

void NPuzzle::Board::initRandomly(){	
	int a,k=0;
	int num=row*column;
	vector<int> v2(num);

	v.resize(row);
	for(int i=0;i<row;i++){
		v[i].resize(column);
		for(int j=0;j<column;j++){
			do{
				a=rand()%num;
				v2[k]=a;
			}while(control_random(v2,k,a)!=1);
			k++;
			v[i][j]=a;

			if(v[i][j] == 0){
				empty_i=i;
				empty_j=j;
				v[i][j]=-1;
			}			
		}
	}	
}

void NPuzzle::Board::print() const{
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout.width(5);
			if(v[i][j]==-1)				
				cout << " " << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl<< endl;
}
