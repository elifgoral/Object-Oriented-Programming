import java.lang.Math;
import java.io.*;
import java.util.Scanner;  

public class BoardArray2D extends AbstractBoard {
	private int [][] board2D;
	
	public BoardArray2D(){
		super(0,0);
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}
	
	public BoardArray2D(int row,int column){
		super(row,column);
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	public void print(){
		for(int i = 0 ; i < row ; i++){
			for(int j=0 ; j < column ; j++){
				if(board2D[i][j] == -1)				
					System.out.printf("      ");
				else
					System.out.printf("%5d ",board2D[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public void move_down(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}
	
	public void move_up(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}
	
	public void move_right(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}

	public void move_left(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}

	public void move(char direction){ //Makes a move according to the given char parameter. If the parameter is L then the blank tiles moves left, ..., etc, as defined in HW1.
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
				System.exit(0);
				break;
		}
	}

	/**
	 * Resets the board to the solution.
	 */
	public void reset(){ //Resets the board to the solution.
		initRespectively(board2D);
	}
	
	/**
	 * This method init randomly the board.
	 * @param array which we will init respectively
	 */
	public void initRespectively(int [][]array){
		int k = 1;
		int border;
		border = (row * column) - wall_number;
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(k < border){
					array[i][j] = k;
					k++;
				}
				else if(k == border){
					array[i][j] = -1;
				}
			}
		}
	}

	public boolean isSolved(){//Returns true if the board is a solution
		int [][]array = new int[row][column];
		initRespectively(array);

		int counter = 0;
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(board2D[i][j] == array[i][j])
					counter++;
			}	
		}
		
		if(counter == row * column)
			return true; // game is over
		else
			return false;	//game is continue.
	} 
	
	public void initRandomly(){ // it inits randomly the board.
		int i,j,counter = 0 , random_number;
		int num = row * column;
		int [] array = new int[num];
		
		board2D = new int[row][column];
		for(i = 0 ; i < row ; i++)
			board2D[i] = new int[column];

		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < column ; j++){
				do{
					double temp = Math.random()*num;
					random_number = (int) temp;
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
	
	public void readFromFile(String fileName){ //Reads the board from the file given as function parameter. The file format is defined as in HW2.
		findRow(fileName);
		findColumn(fileName);
		System.out.println("row: " + row);
		System.out.println("column: " + column);

		try {
			FileInputStream file = new FileInputStream(fileName);       
			Scanner input = new Scanner(file); 
			String str;
			board2D = new int[row][column];
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < column ; j++){
					str = input.next();
					if(str.equals("bb")){
						board2D[i][j] = -1;
						empty_i = i;
						empty_j = j;
					}
					else if(str == "00"){
						board2D[i][j] = 0;
					}
					else{
						board2D[i][j] = Integer.parseInt(str);
					}
				}
			}
		    input.close(); 
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void writeToFile(String fileName){//Writes the board to the file given as function parameter

		try{
			FileWriter fileWriter = new FileWriter(fileName);
		    PrintWriter printWriter = new PrintWriter(fileWriter);
		    for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < column ; j++){
					if(board2D[i][j] == -1){
						printWriter.print("bb");
						printWriter.print(" ");
					}
					else if(board2D[i][j] == 0){
						printWriter.print("00");
						printWriter.print(" ");
					}
					else if(board2D[i][j] < 10){
						printWriter.print("0");
						printWriter.print(board2D[i][j]);
						printWriter.print(" ");
					}
					else{
						printWriter.print(board2D[i][j]);
						printWriter.print(" ");
					}
				}
		   		printWriter.print("\n");
			}	
		    printWriter.close();
		}

		catch(IOException e){
			System.out.println("write to file hatasi");
		}
	}

	public int cell(int i,int j){
		if(i < 0 && i > row && j < 0 && j > column){	
			System.out.println("illegal indexes");
			System.exit(0);
		}
		return board2D[i][j];
	}

	public String toString(){
		String temp = "";
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(board2D[i][j] == -1){
					temp += "bb ";
				}
				else if(board2D[i][j] < 10){
					temp += "0";
					temp += board2D[i][j];
					temp += " ";
				}
				else{
					temp += board2D[i][j];
					temp += " ";
				}
			}
			temp += "\n";
		}	
		return temp;
	}

	public boolean equals(Object obj) { 
		if (obj == null || getClass() != obj.getClass()) {
        	return false;
   		}
    	BoardArray2D p = (BoardArray2D) obj;
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column ; j++){
				if(board2D[i][j] != p.cell(i,j)){
					return false;
				}
			}
		}
		return true;
	}


}
