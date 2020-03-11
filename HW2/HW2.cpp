//00: wall(0) bb: space(-1)

#include <iostream>
#include <fstream> // for file.open file.close
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


int show(int board[][9],const int row,const int column,int &argc);
int init_respectively(int board[][9],const int row,const int column,int wall_number,int& argc);
int control_finish(int board[][9],const int row,const int column,int wall_number,int &argc);
inline int find_row(string text);
int find_column(const int row,string text);
int init(const int row,const int column,int board[][9],int& empty_i,int& empty_j,int& wall_number,string text,int&argc);
int h_score(int board[][9],const int row,const int column,int wall_number,int&argc); // it finds how many number is not the place where it shouldn't be.
int move_left(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc);
int move_right(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc); 
int move_up(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc); 
int move_down(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc);
int find_distance_total_left(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_left,int &way);
int find_distance_total_right(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_right,int &way);
int find_distance_total_up(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_up,int &way);
int find_distance_total_down(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_down,int &way); 
int intelligent(int board[][9],const int row,const int column,int &empty_i,int &empty_j,double& distance_total_left,double& distance_total_right,double& distance_total_up,double &distance_total_down,int &way,int& argc);
int menu(int board[][9],const int row,const int column,int empty_i,int empty_j,int wall_number,double distance_total_left,double distance_total_right,double distance_total_up,double distance_total_down,int way,int& number_of_move,int&argc);
int write_to_txt(int board[][9],const int row,const int column,int& argc);
int stoi_converter(string text);
int shuffle(int board[][9],const int row,const int column,int &empty_i,int& empty_j,double& distance_total_left,double& distance_total_right,double& distance_total_up,double& distance_total_down,int &way,int& wall_number,int& argc);
int init_randomly(int board[][9],const int row,const int column,int& empty_i,int& empty_j);
int control_random(int array[],int num,int a); // it checks if there is a same number while setting random board.

int main(int argc,char* argv[]){
	
	int row,column;
	string str;
	int board[9][9];
	int empty_i,empty_j,wall_number=0;
	decltype(row) number_of_move=0; 
	auto way=10;
	double distance_total_left,distance_total_right,distance_total_up,distance_total_down;
	string text;
	
	if(argc==1){
		cout << "row:" ;
		cin >> row;
		cout << "column:" ;
		cin >> column;
		init_randomly(board,row,column,empty_i,empty_j);
		menu(board,row,column,empty_i,empty_j,wall_number,distance_total_left,distance_total_right,distance_total_up,distance_total_down,way,number_of_move,argc);
	}
		
	else if(argc==2){
		text=*(argv+1);	
		
		row = find_row(text);
		column = find_column(row,text);
	
		cout << "row: " << row << endl;
		cout << "column:" << column << endl;
		init(row,column,board,empty_i,empty_j,wall_number,text,argc);
		cout << endl;
		show(board,row,column,argc);	
		menu(board,row,column,empty_i,empty_j,wall_number,distance_total_left,distance_total_right,distance_total_up,distance_total_down,way,number_of_move,argc);

	}
	
	return 0;
}

int show(int board[][9],const int row,const int column, int &argc){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
				if(argc==2){
					if(board[i][j]==0){
						cout.width(5);
						cout << "00" << ' ';
					}
					else if(board[i][j]==-1){
						cout.width(5);
						cout << "bb" << ' ';
					}
					else{
						if(board[i][j]<10){
							cout.width(4);
							cout << '0' << board[i][j] << ' ';
						}
						else{
							cout.width(5);
							cout << board[i][j] << ' ';
						}
					}
				}
				else if(argc==1){
					if(board[i][j]==0){
						cout.width(5);
						cout << ' ' << ' ';
					}
					else if(board[i][j]==-1){
						cout.width(5);
						cout << ' ' << ' ';
					}
					else{
						cout.width(5);
						cout << board[i][j] << ' ';
					}
				}				
		}
		cout << endl;
	}
	cout << endl;
}

int init_randomly(int board[][9],const int row,const int column,int& empty_i,int &empty_j){
	int i,j,k=0,a;
	int num=row*column;
	int array[num];
	while(k<num-1){
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
						cout.width(5);
						cout << ' ' << ' ';
					}
					else{
						cout.width(5);
						cout << board[i][j] << ' ';
					}
			}	
			cout << endl;
		}
	}
	cout << endl;	
}

int control_random(int array[],int num,int a){ // it checks if there is a same number while setting random board.
	int i;
	for(i=0;i<num;i++){
		if(array[i]==a)
			return 0; // fail
	}
	return 1;//success
}


int init_respectively(int board[][9],const int row,const int column,int wall_number, int &argc){
	fstream inputStream;
	inputStream.open("puzzle.txt");
	string str;
	int i,j,k=1;
	int border;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(argc==2){
				inputStream >> str;
				border=(row*column)-wall_number;
				if(str == "00")
					board[i][j]=0;
								
				else if(k<border){
					board[i][j]=k;
					k++;
				}	
				else if(k==border) // it creates a space in the end.
					board[i][j]=-1;
			}
			else if(argc==1){
				border=row*column;
				if(k<border){
					board[i][j]=k;	
					k++;
				}
				else
					board[i][j]=0;	
			}
		}		
	}
	
	inputStream.close();			
}

int control_finish(int board[][9],const int row,const int column,int wall_number,int &argc){
	int i,j;
	int array[row][9];
		
	init_respectively(array,row,column,wall_number,argc);
			
	int counter=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(board[i][j]==array[i][j])
				counter++;
		}	
	}
	if(counter==row*column)
		return 1; // game is over
	else
		return 0;	//game is continue.
}

inline int find_row(string text){
	
	fstream inputStream;
	inputStream.open(text);
	
	int row=0;
	string str;
	while(getline(inputStream,str)){ // finding line number.
		row++;
	}
	
	inputStream.close();
	return row;
}

int find_column(const int row,string text){	

	fstream inputStream;
	inputStream.open(text);
	string str;
	int counter=0,column;
	
	while(inputStream >> str){
		counter++;
	}
	
	column = counter/row;

	inputStream.close();
	return column;

}

int stoi_converter(string text){
	char temp;	
		
	if(text[1]=='\0'){
		temp=text[0];
		text[1]=temp;
		text[0]=48;
	}
	
	if((text[0]>=48 && text[0]<=57) && (text[1]>=48 && text[1]<=57))
				return (text[0]-48)*10+(text[1]-48);
}



int init(const int row,const int column,int board[][9],int& empty_i,int& empty_j,int& wall_number,string text,int&argc){
	fstream inputStream;
	cout << endl;
	inputStream.open(text);
	string str;
	int i,j,temp;
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			inputStream >> str;
			if(str== "bb"){
				board[i][j]=-1;
				empty_i=i;
				empty_j=j;
			}
			else if(str=="00"){
				wall_number++;
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

int move_left(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc){
	int a;
	if(empty_j!=0){
		if(argc==1){
			a=board[empty_i][empty_j-1];
			board[empty_i][empty_j-1]=0;
			board[empty_i][empty_j]=a;
			empty_j--;	
		}
		else{
			if(board[empty_i][empty_j-1]!=0){
				a=board[empty_i][empty_j-1];
				board[empty_i][empty_j-1]=-1;
				board[empty_i][empty_j]=a;
				empty_j--;	
			}
			else
				cout<< "wrong move" << endl;
		}
	}
	else
	cout<< "wrong move" << endl;
}

int move_right(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc){ 
	int a;
	if(empty_j!=column-1){ 
		if(argc==1){
			a=board[empty_i][empty_j+1];
			board[empty_i][empty_j+1]=0;
			board[empty_i][empty_j]=a;
			empty_j++;	
		}
		else{
			if(board[empty_i][empty_j+1]!=0){
				a=board[empty_i][empty_j+1];
				board[empty_i][empty_j+1]=-1;
				board[empty_i][empty_j]=a;
				empty_j++;		
			}
			else
				cout<< "wrong move" << endl;
		}
	}
	else
		cout<< "wrong move" << endl;
}

int move_up(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc){
	int a;
	if(empty_i!=0){
		if(argc==1){
			a=board[empty_i-1][empty_j];
			board[empty_i-1][empty_j]=0;
			board[empty_i][empty_j]=a;
			empty_i--;	
		}
		else{
			if(board[empty_i-1][empty_j]!=0){
				a=board[empty_i-1][empty_j];
				board[empty_i-1][empty_j]=-1;
				board[empty_i][empty_j]=a;
				empty_i--;	
			}
			else
				cout<< "wrong move" << endl;
		}
	}
	else 
	cout<< "wrong move" << endl;

}

int move_down(int board[][9],const int row,const int column,int& empty_i,int& empty_j,int &way,int& argc){ 
	int a;
	if(empty_i!=row-1){
		if(argc==1){
			a=board[empty_i+1][empty_j];
			board[empty_i+1][empty_j]=0;
			board[empty_i][empty_j]=a;
			empty_i++;	
		}
		else{
			if(board[empty_i+1][empty_j]!=0){	
				a=board[empty_i+1][empty_j];
				board[empty_i+1][empty_j]=-1;
				board[empty_i][empty_j]=a;
				empty_i++;	
			}
			else
				cout<< "wrong move" << endl;
		}
	}
	else
	cout<< "wrong move" << endl;
}

int h_score(int board[][9],const int row,const int column,int wall_number,int& argc){ // kaç tane sayı olması gereken yerde değil onu buluyor.
	int i,j;
	int array[row][9];
	init_respectively(array,row,column,wall_number,argc);

	int counter=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(board[i][j]!=array[i][j] && board[i][j]>0 && array[i][j]>0)
				counter++;			
		}		
	}
	cout << endl;
	return counter;
}


int write_to_txt(int board[][9],const int row,const int column,int& argc){
	string text;
	cout << "Name of the new file: " ;
	cin >> text;
	cout << endl;
	int i,j;
	
	ofstream myfile;
	myfile.open(text);
	
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			myfile.width(5);
			if(argc==2){	
				if(board[i][j]==0)
					myfile << "00" << " ";
				else if(board[i][j]==-1)
					myfile << "bb" << " ";
				else{
					if(board[i][j]<10){
						myfile.width(4);
						myfile << '0' << board[i][j] << ' ';
					}
					else{
						myfile.width(5);
						myfile << board[i][j] << ' ';
					}
				}
			
			
			}
			else if(argc==1){
				if(board[i][j]==0)
					myfile << "bb" << " ";
				else
					myfile << board[i][j] << " ";
			}
		}
		 
		myfile << endl;
	}	
	myfile.close();
}


int find_distance_total_left(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_left,int &way){ 
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

int find_distance_total_right(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_right,int &way){
	int distance_i,distance_j;
	int a; 
	int i,j;// sayının olması gereken yer
	//way-> 0:left 1:right 2:up 3:down
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

int find_distance_total_up(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_up,int &way){

	int distance_i,distance_j;
	int a; 
	int i,j;// sayının olması gereken yer
	//way-> 0:left 1:right 2:up 3:down
	
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

int find_distance_total_down(int board[][9],const int row, const int column, int& empty_i,int& empty_j,double& distance_total_down,int &way){
		
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

int intelligent(int board[][9],const int row,const int column,int &empty_i,int &empty_j,double& distance_total_left,double& distance_total_right,double& distance_total_up,double &distance_total_down,int &way,int& number_of_move,int &argc){ //As a result of the move, the number will be closer to where it should be. So even if that move makes the solution difficult, the moving number will be closer to the position it should be.	
	//looks at the numbers around the blank. move whichever is closer to where it should be.
	// if distance is same, do respectively as left, right, up and down. if all of the posibilities locked, it moves the number that is already it should be.
	
	double array[4];
	
	find_distance_total_left(board,row,column,empty_i,empty_j,distance_total_left,way);
	find_distance_total_right(board,row,column,empty_i,empty_j,distance_total_right,way);
	find_distance_total_up(board,row,column,empty_i,empty_j,distance_total_up,way);
	find_distance_total_down(board,row,column,empty_i,empty_j,distance_total_down,way);
	
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
				move_left(board,row,column,empty_i,empty_j,way,argc);
				number_of_move++;
				break;
			
		case 1:
				cout << "R" << endl;
				move_right(board,row,column,empty_i,empty_j,way,argc);
				number_of_move++;
				break;
					
		case 2:
				cout << "U" << endl;
				move_up(board,row,column,empty_i,empty_j,way,argc);
				number_of_move++;
				break;
					
		case 3:
				cout << "D" << endl;
				move_down(board,row,column,empty_i,empty_j,way,argc);
				number_of_move++;
				break;
		}
		show(board,row,column,argc);
}

int shuffle(int board[][9],const int row,const int column,int &empty_i,int& empty_j,double& distance_total_left,double& distance_total_right,double& distance_total_up,double& distance_total_down,int &way,int& wall_number,int &argc){// olması gereken sonucu göster sonra  size*size random hareket yap .
	init_respectively(board,row,column,wall_number,argc);
	show(board,row,column,argc);
	empty_i=row-1;
	empty_j=column-1;
	
	int i,j,a;	
	for(i=0;i<row*column;i++){ // 1: left  2: right 3: up  4: down
		a=rand()%4;
		if(a==0){
			if(empty_j!=0 || way!=1 || board[empty_i][empty_j-1]!=0)
				move_left(board,row,column,empty_i,empty_j,way,argc);
		}
		else if(a==1){
			if(empty_j!=column || way!=0 || board[empty_i][empty_j+1]!=0)
				move_right(board,row,column,empty_i,empty_j,way,argc);			
		}
		else if(a==2){
			if(empty_i!=0 || way!=3 || board[empty_i-1][empty_j]!=0)
				move_up(board,row,column,empty_i,empty_j,way,argc);
		}
		else if(a==3){
			if(empty_i!=row || way!=2 || board[empty_i+1][empty_j]!=0)	
				move_down(board,row,column,empty_i,empty_j,way,argc);
		}
		show(board,row,column,argc);
	}
}


int menu(int board[][9],const int row,const int column,int empty_i,int empty_j,int wall_number,double distance_total_left,double distance_total_right,double distance_total_up,double distance_total_down,int way,int &number_of_move,int &argc){
	int i,j;
	char choice;
	string text;
	
	do{
			cout << "L:	left" << endl;
			cout << "R:	right" << endl;
			cout << "U:	up" << endl;
			cout << "D:	down" << endl;	
			cout << "S:	Shufle" << endl;	
			cout << "I:	intelligent " << endl;
			cout << "V:	Solves the problem from the current configuration using the new intelligent algorithm." << endl;
			cout << "T:	Prints a report about how many moves have been done and if the solution is found." << endl;
			cout << "E:	Asks a file name and saves the current board configuration as a loadable shape file." << endl;
			cout << "Y:	Asks a file name and loads the current board configuration from the shape file." << endl;
		
		cout << "choice:" ;
		cin >> choice;
		switch(choice){
			case 'l':
			case 'L':
					move_left(board,row,column,empty_i,empty_j,way,argc);
					show(board,row,column,argc);
					cout << endl;
					number_of_move++;
					if(control_finish(board,row,column,wall_number,argc)==1){
						cout << "Game is finished." << endl;
						exit(1);
					}
					break;
			
			case 'r':
			case 'R':
					move_right(board,row,column,empty_i,empty_j,way,argc);	
					show(board,row,column,argc);	
					cout << endl;
					number_of_move++;
					if(control_finish(board,row,column,wall_number,argc)==1){
						cout << "Game is finished." << endl;
						exit(1);
					}
					break;
			
			case 'u':
			case 'U':
					move_up(board,row,column,empty_i,empty_j,way,argc);				
					show(board,row,column,argc);
					cout << endl;
					number_of_move++;
					if(control_finish(board,row,column,wall_number,argc)==1){
						cout << "Game is finished." << endl;
						exit(1);
					}
					break;
				
			case 'D':
			case 'd':
					move_down(board,row,column,empty_i,empty_j,way,argc);	
					show(board,row,column,argc);
					cout << endl;
					number_of_move++;
					if(control_finish(board,row,column,wall_number,argc)==1){
						cout << "Game is finished." << endl;
						exit(1);
					}
					break;
			
			case 'i':
			case 'I':
					intelligent(board,row,column,empty_i,empty_j,distance_total_left,distance_total_right,distance_total_up,distance_total_down,way,number_of_move,argc);
					cout << endl;
					number_of_move++;
					if(control_finish(board,row,column,wall_number,argc)==1){
						cout << "Game is finished." << endl;
						exit(1);
					}
					break;			
			
			case 'S':
			case 's':
					shuffle(board,row,column,empty_i,empty_j,distance_total_left,distance_total_right,distance_total_up,distance_total_down,way,wall_number,argc);
					number_of_move++;
					break;
			
			case 'V':
			case 'v':
					do{
						intelligent(board,row,column,empty_i,empty_j,distance_total_left,distance_total_right,distance_total_up,distance_total_down,way,number_of_move,argc);
						if(control_finish(board,row,column,wall_number,argc)==1){
							cout << "Game is finished." << endl;
							exit(1);
						}
					}while(control_finish(board,row,column,wall_number,argc)!=1);
					break;
			
			case 'T':
			case 't':
					cout << "Number of move: " << number_of_move << endl;
					if(control_finish(board,row,column,wall_number,argc)==1){
							cout << "Game is finished." << endl;
							exit(1);
					}
					else
						cout << "Game is continue." << endl;
					
					break;
					
			case 'E':
			case 'e': 
					write_to_txt(board,row,column,argc); 
				break;
			
			case 'Y':
			case 'y':
					cout << "Name of the new file: " ;
					cin >> text;
					cout << endl;		
					int row,column;
					row = find_row(text);
					column = find_column(row,text);	

					cout << "row: " << row << endl;
					cout << "column:" << column << endl;
					wall_number=0;
					init(row,column,board,empty_i,empty_j,wall_number,text,argc);
					argc=2;
					show(board,row,column,argc);
				break;
			
			case 'q':
			case 'Q':
					exit(1);	
					break;
		}
	}while(choice != 'q' || choice != 'Q');

}	

