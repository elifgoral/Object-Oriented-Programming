/*
	menüyü her hareketten sonra gösterme. 
	inline yao
*/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

class NPuzzle{

	private:
		class Board{
			private:
				int board[9][9];
				int row;
				int column;
				int empty_i;
				int empty_j;
				int way;
				int wall_number;
				int number_of_move;
				double distance_total_left;
				double distance_total_right;
				double distance_total_up;
				double distance_total_down;

			public:
				void print()const; //Prints the board on the screen by sending it to cout
				void readFromFile(string text); //Reads the board from the file given as function parameter. The file format is defined as in HW2.
				void writeToFile(string text); //Writes the board to the file given as function parameter
				void setSize();//Sets the board size to given values. The values are given as parameters and they can be at most 9x9. After setting the size, the boards should be reset.
				void move(char choice);//Makes a move according to the given char parameter. If the parameters is ‘L’ then the blank tiles moves left, ..., etc, as defined in HW1.
				bool isSolved(int& argc,string text);//Returns true if the board is a solution
				void initRandomly();
				int control_random(int array[],int num,int a);
				void move_left();
				void move_right();
				void move_up();
				void move_down();
				void menu(int& argc,string text);
				void init(string text);
				int stoi_converter(string text);
				void reset(int array[][9],int &argc,string text);//Resets the board to the solution.
				void printReport(int& argc,string text);
				void shuffle(int& argc,int random_move,string text);
				void move_random(char choice);
				void find_distance_total_left();
				void find_distance_total_right();
				void find_distance_total_up();
				void find_distance_total_down();
				void move_intelligent();
				void solve_puzzle(int& argc,string text);
		};
		
	public:
		Board board;
		void print()const{ //Prints the current configuration on the screen by sending it to cout
			board.print();
		}
		void printReport(int& argc,string text){//Prints a report about how many moves have been done since reset and if the solution is found
			board.printReport(argc,text);
		}
		void readFromFile(string text){ //Reads the current configuration from the file given as function parameter. The file format is defined as in HW2.
			board.readFromFile(text);
		}
		void writeToFile(string text){ // Writes the current configuration to the file given as function parameter
			board.writeToFile(text);
		}
		void shuffle(); //Makes N random moves to shuffle the board. N is given as a function parameter.
		void reset();//Resets the current configuration to the solution.
		void setSize() //Sets the board size to given values. The values are given as parameters and they can be at most 9x9. After setting the size, the boards should be reset.
		{
			board.setSize();
		}
		void moveRandom(); //Makes a valid random move
		void moveIntelligent(); // Makes an “intelligent” move
		void move(char choice){ //Makes a move according to the given char parameter. If the parameters is ‘L’ then, the blank tiles moves left, ..., etc, as defined in HW1.
			board.move(choice);
		}
		void solvePuzzle(); //Makes an attempt to solve the puzzle using your own algorithm from HW2.
		void initRandomly(){
			board.initRandomly();
		}
		void menu(int& argc,string text){
			board.menu(argc,text);
		}
		bool isSolved(int& argc,string text){
			board.isSolved(argc,text);
		}
		void reset(int array[][9],int &argc,string text){
			board.reset(array,argc,text);
		}
		void shuffle(int& argc,int random_move,string text){
			board,shuffle(argc,random_move,text);
		}
		void move_random(char choice){
			board.move_random(choice);
		}
		void find_distance_total_left(){
			board.find_distance_total_left();
		}
		void find_distance_total_right(){
			board.find_distance_total_right();
		}
		void find_distance_total_up(){
			board.find_distance_total_up();
		}
		void find_distance_total_down(){
			board.find_distance_total_down();
		}
		void move_intelligent(){
			board.move_intelligent();
		}
		void solve_puzzle(int& argc,string text){
			board.solve_puzzle(argc,text);
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
		puzzle.menu(argc,text);
	}
	else if(argc==2){
		text=*(argv+1);	
		puzzle.readFromFile(text);
		puzzle.print();
		puzzle.menu(argc,text);
	}

	return 0;
}

void NPuzzle::Board::find_distance_total_left(){ 
	int distance_i,distance_j;
	int a; 
	int i,j;// place that the number where it supposed to be.
	//way-> 0:left 1:right 2:up 3:down
	
	if(empty_j==0 || way==1 || board[empty_i][empty_j-1]==0)// if the number on leftmost column or previous move was right or there is a wall, I am cancelling to move left.
		distance_total_left=100000;
		
	else if(empty_j!=0){
		a=board[empty_i][empty_j-1];
		
		i=(a-1)/column; // number's location of i, where it should be
		j=(a-1)%column; // number's location of j, where it should be
		
		if(i==empty_i && j+1==empty_j)  // it doesn't move the number if that number already where it should be
			distance_total_left=50000;// if all of the posibilities locked, it moves the number that is already it should be.
		
		else{		
			distance_i=empty_i-i;
			if(distance_i<0)
				distance_i*=-1;
			
			distance_j=empty_j-j;
			if(distance_j<0)
				distance_j*=-1;	
			
			distance_total_left=sqrt(pow(distance_i,2)+pow(distance_j,2));
		}
	}
}

void NPuzzle::Board::find_distance_total_right(){
	int distance_i,distance_j;

	int i,j;// sayının olması gereken yer
	//way-> 0:left 1:right 2:up 3:down
	decltype(i)a;
	if(empty_j==column-1 || way==0 || board[empty_i][empty_j+1]==0) // if the number on rightmost column or previous move was left or there is a wall, I am cancelling to move right.
		distance_total_right=100000;
		
	else if(empty_j!=column-1){
		a=board[empty_i][empty_j+1];

		
		i=(a-1)/column; // number's location of i, where it should be
		j=(a-1)%column; // number's location of j, where it should be
		
		if(i==empty_i && j-1==empty_j) // it doesn't move the number if that number already where it should be
			distance_total_right=50000;// if all of the posibilities locked, it moves the number that is already it should be.
		
		else{
			distance_i=empty_i-i;
			if(distance_i<0)
				distance_i*=-1;
			
			distance_j=empty_j-j;
			if(distance_j<0)
				distance_j*=-1;
			
			distance_total_right=sqrt(pow(distance_i,2)+pow(distance_j,2));
		}
	}
}

void NPuzzle::Board::find_distance_total_up(){

	int distance_i,distance_j;
	int i,j;// sayının olması gereken yer
	//way-> 0:left 1:right 2:up 3:down
	decltype(i) a;
	
	if(empty_i==0 || way==3 || board[empty_i-1][empty_j]==0) // if the number on top row or previous move was down or there is a wall, I am cancelling to move up.
		distance_total_up=100000;
	
	else if(empty_i!=0){
		a=board[empty_i-1][empty_j];

		
		i=(a-1)/column; // number's location of i, where it should be
		j=(a-1)%column;// number's location of j, where it should be
		
		if(j==empty_j && i+1==empty_i)// it doesn't move the number if that number already where it should be
			distance_total_up=50000;// if all of the posibilities locked, it moves the number that is already it should be.
			
		else{
			distance_i=empty_i-i;
			if(distance_i<0)
				distance_i*=-1;
			
			distance_j=empty_j-j;
			if(distance_j<0)
				distance_j*=-1;
			
			distance_total_up=sqrt(pow(distance_i,2)+pow(distance_j,2));	
		}
	}
}

void NPuzzle::Board::find_distance_total_down(){
		
	int distance_i,distance_j;
	int a; 
	int i,j;// sayının olması gereken yer
		//way-> 0:left 1:right 2:up 3:down
		
	if(empty_i==row-1 || way==2 || board[empty_i+1][empty_j]==0) // if the number on bottom row or previous move was up or there is a wall, I am cancelling to move down.
		distance_total_down=100000;
	
	else if(empty_i!=row-1){
		a=board[empty_i+1][empty_j];

		
		i=(a-1)/column; // number's location of i, where it should be
		j=(a-1)%column; // number's location of j, where it should be
		
		if(j==empty_j && i-1==empty_i) // it doesn't move the number if that number already where it should be
			distance_total_down=50000; // if all of the posibilities locked, it moves the number that is already it should be.
		
		else{
			distance_i=empty_i-i;
			if(distance_i<0)
				distance_i*=-1;
			
			distance_j=empty_j-j;
			if(distance_j<0)
				distance_j*=-1;
			
			distance_total_down=sqrt(pow(distance_i,2)+pow(distance_j,2));
		}
	}
}

void NPuzzle::Board::move_intelligent(){ //As a result of the move, the number will be closer to where it should be. 
	//So even if that move makes the solution difficult, the moving number will be closer to the position it should be.	
	//looks at the numbers around the blank. move whichever is closer to where it should be.
	// if distance is same, do respectively as left, right, up and down. if all of the posibilities locked, it moves the number that is already it should be.
	
	double array[4];
	
	find_distance_total_left();
	find_distance_total_right();
	find_distance_total_up();
	find_distance_total_down();
	
	array[0]=distance_total_left;
	array[1]=distance_total_right;
	array[2]=distance_total_up;
	array[3]=distance_total_down;
	
	cout << "left: " << distance_total_left << endl;
	cout << "right:  " << distance_total_right << endl;
	cout << "up: " << distance_total_up << endl;
	cout << "down: " << distance_total_down << endl;
	
		// whichever is the smallest distance, makes that move with that way. So which move makes it move closer to where it should be.
	double min=array[0];
	int i;
	way=0;
	for(i=1;i<4;i++){
		if(array[i]<min){
			min=array[i];
			way=i;
		}
	}
			
	switch(way){
		case 0:
				cout << "L"  << endl;
				move_left();
				break;
			
		case 1:
				cout << "R" << endl;
				move_right();
				break;
					
		case 2:
				cout << "U" << endl;
				move_up();
				break;
					
		case 3:
				cout << "D" << endl;
				move_down();
				break;
		}
		print();
}

inline void NPuzzle::Board::printReport(int& argc,string text){
	cout << "number of move: " << number_of_move << endl;
	if(isSolved(argc,text)==1){
		cout << "congratulations!"<< endl;
	}
	else{
		cout << "game is continue" << endl;
	}
}

void NPuzzle::Board::reset(int array[][9],int &argc,string text){
	int k=1;
	int border;
	border=(row*column)-wall_number;
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
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

bool NPuzzle::Board::isSolved(int& argc,string text){
	int array[9][9];
		
	reset(array,argc,text);
				
	int counter=0;
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			if(board[i][j]==array[i][j])
				counter++;
		}	
	}
	
	if(counter==row*column)
		return true; // game is over
	else
		return false;	//game is continue.
}

void NPuzzle::Board::shuffle(int& argc,int random_move,string text){
	
	reset(board,argc,text);	
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

void NPuzzle::Board::solve_puzzle(int& argc,string text){
	int i;
	for(i=0;i<10;i++){
		move_intelligent();	
		number_of_move++;
		if(isSolved(argc,text)==true){
			cout << "Game is solved" << endl;
			printReport(argc,text);
			exit(1);
		}
	}
}

void NPuzzle::Board::menu(int& argc,string text){
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
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;
			
			case 'r':
			case 'R':
					move(choice);
					cout << endl;
					print();	
					number_of_move++;
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;
			
			case 'u':
			case 'U':
					move(choice);
					cout << endl;
					print();
					number_of_move++;
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;
				
			case 'D':
			case 'd':
					move(choice);
					cout << endl;
					print();
					number_of_move++;
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;
			
			case 'i':
			case 'I':
					move_intelligent();
					number_of_move++;
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;			
			
			case 'S':
			case 's':
					int num_random;
					num_random=row*column;
					shuffle(argc,num_random,str);
					if(isSolved(argc,text)==true){
						cout << "Game is solved" << endl;
						printReport(argc,text);
						exit(1);
					}
					break;
			
			case 'V':
			case 'v':
					solve_puzzle(argc,text);
					break;
			
			case 'T':
			case 't':
					printReport(argc,text);
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

void NPuzzle::Board::init(string text){ //0: wall -1:empty(random)
	fstream inputStream;
	cout << endl;
	inputStream.open(text);
	cout << " text:" << text << endl;
	string str;
	int i,j,temp;
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			inputStream >> str;
			if(str == "bb"){
				board[i][j]=-1;
				empty_i=i;
				empty_j=j;
			}
			else if(str == "00"){
				board[i][j]=0;
			}
			else{
				temp=stoi_converter(str);
				board[i][j]=temp;
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

void NPuzzle::Board::readFromFile(string text){
	
	cout << endl;	
	int counter=0;
	//cout << " text:" << text << endl;
	fstream inputStream;
	inputStream.open(text);
	string str;

	while(getline(inputStream,str)){ // finding line number.
		counter++;
	}
		
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
	
	init(text);

	inputStream.close();
}

void NPuzzle::Board::writeToFile(string text){ // 0: wall -1:empty(random)
	
	cout << endl;
	int i,j;
	
	ofstream myfile;
	myfile.open(text);
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(board[i][j]==-1){
				myfile.width(5);
				myfile << "bb" << " ";
			}
			else if(board[i][j]==0){
				myfile.width(5);
				myfile << "00" << " ";
			}
			else if(board[i][j]<10){
					myfile.width(4);
					myfile << '0' << board[i][j] << ' ';
			}
			else{
				myfile.width(5);
				myfile << board[i][j] << ' ';
			}
		}
		myfile << endl;
	}	
	myfile.close();
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

void NPuzzle::Board::move_left(){
	int a;
	if(empty_j!=0){
		if(board[empty_i][empty_j-1]!=0){
			a=board[empty_i][empty_j-1];
			board[empty_i][empty_j-1]=-1;
			board[empty_i][empty_j]=a;
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
		if(board[empty_i][empty_j+1]!=0){
			a=board[empty_i][empty_j+1];
			board[empty_i][empty_j+1]=-1;
			board[empty_i][empty_j]=a;
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
		if(board[empty_i-1][empty_j]!=0){
			a=board[empty_i-1][empty_j];
			board[empty_i-1][empty_j]=-1;
			board[empty_i][empty_j]=a;
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
		if(board[empty_i+1][empty_j]!=0){
			a=board[empty_i+1][empty_j];
			board[empty_i+1][empty_j]=-1;
			board[empty_i][empty_j]=a;
			empty_i++;
			way=3;	
		}
		else
			cout<< "wrong move" << endl;
	}
	else
		cout<< "wrong move" << endl;
}

void NPuzzle::Board::print()const{
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(board[i][j]==-1){
				cout.width(5);
				cout << " " << " ";
			}
			else if(board[i][j]==0){
				cout.width(5);
				cout << "00" << " ";
			}
			else if(board[i][j]<10){
				cout.width(4);
				cout << "0" << board[i][j] << " ";
			}

			else{
				cout.width(5);
				cout << board[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;	
}

int NPuzzle::Board::control_random(int array[],int num,int a){ // it checks if there is a same number while setting random board.
	int i;
	for(i=0;i<num;i++){
		if(array[i]==a)
			return 0; // fail
	}
	return 1;//success
}

void NPuzzle::Board::initRandomly(){
	int i,j,k=0,a;
	int num=row*column;
	int array[num];
	wall_number=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			do{
				a=rand()%num;
				array[k]=a;
			}while(control_random(array,k,a)!=1);
			k++;
			board[i][j]=a;
			if(board[i][j]==0){
				empty_i=i;
				empty_j=j;
				board[i][j]=-1; 
			}
		}	
	}	
}

void NPuzzle::Board::setSize(){
	cout << "enter row:" ;
	cin >> row; 
	cout << "Enter column: ";
	cin >> column;
}
