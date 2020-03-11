import java.lang.Math;
import java.io.*;
import java.util.Scanner;  

public class BoardArray1D extends AbstractBoard {
	private int [] board1D;

	public BoardArray1D(){
		super(0,0);
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	public BoardArray1D(int row,int column){
		super(row,column);
		wall_number = 0;
		last_move = "s";
		numberOfBoard++;
	}

	public void initRandomly(){
		int i,counter = 0 , random_number;
		int num = row * column;
		int [] array = new int[num];

		board1D = new int[num];
		for(i = 0 ; i < num ; i++){
			do{
				double temp = Math.random()*num;
				random_number = (int) temp;
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

	public void move(char direction){ 
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

	public void move_left(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}

	public void move_right(){
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
				System.out.println( "wrong move");
		}	
		else
			System.out.println( "wrong move");
	}

	public void move_up(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}

	public void move_down(){
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
				System.out.println( "wrong move");
		}
		else
			System.out.println( "wrong move");
	}
	
	/**
	 * Resets the board to the solution.
	 */
	public void reset(){ //Resets the board to the solution.
		initRespectively(board1D);
	}

	/**
	 * This method init randomly the board.
	 * @param array which we will init respectively
	 */
	public void initRespectively(int []array){
		int k = 1;
		int border;
		int num = row * column;
		border = num - wall_number;
		
		for(int i = 0 ; i < num ; i++){
			if(k < border){
				array[i] = k;
				k++;
			}
			else if(k == border){
				array[i] = -1;
			}
		}
	}

	public boolean isSolved(){ //Returns true if the board is a solution

		int num = row * column;
		int [] array = new int[num];

		initRespectively(array);
		int counter = 0;

		for(int i = 0 ; i < num ; i++){
			if(array[i] == board1D[i])
				counter++;
		}

		if(counter == num)
			return true; // game is over
		else
			return false;	//game is continue.
	}

	public void writeToFile(String fileName){ 
		try{
			FileWriter fileWriter = new FileWriter(fileName);
		    PrintWriter printWriter = new PrintWriter(fileWriter);
			int counter = 0;
			int num = row * column;	

			for(int i = 0 ; i < num ; i++){
				if(board1D[i] == -1){
					printWriter.print("bb");
					printWriter.print(" ");
					counter++;
				}	
				else if(board1D[i] == 0){
					printWriter.print("00");
					printWriter.print(" ");
					counter++;
				}
				else if(board1D[i] < 10){
					printWriter.print("0");
					printWriter.print(board1D[i]);
					printWriter.print(" ");
					counter++;
				}
				else{
					printWriter.print(board1D[i]);
					printWriter.print(" ");
					counter++;
				}
				if(counter == column){
					counter = 0;
					printWriter.print("\n");
				}
			}
		    printWriter.close();
		}
		catch(IOException e){
			System.out.println("write to file hatasi");
		}
	}

	public void readFromFile(String fileName){ 
		findRow(fileName);
		findColumn(fileName);
		System.out.println("row: " + row);
		System.out.println("column: " + column);

		try {
			FileInputStream file = new FileInputStream(fileName);       
			Scanner input = new Scanner(file); 
			String str;
			int num = row * column;
			board1D = new int[num];
			for(int i = 0 ; i < num ; i++){
				str = input.next();
				if(str.equals("bb")){
					board1D[i] = -1;
					empty_i = i / column;
					empty_j = i % column;
				}
				else if(str == "00"){
					board1D[i] = 0;
				}
				else{
					board1D[i] = Integer.parseInt(str);
				}
			}
		    input.close(); 
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public void print(){
		int counter = 0;
		for(int i = 0 ; i < row * column ; i++){
			if(counter == column){
				counter = 0;
				System.out.println();
			}

			if(board1D[i] == -1){
				System.out.printf("      ");
				counter++;
			}

			else{
				System.out.printf("%5d ",board1D[i]);
				counter++;
			}
		}
		System.out.println();		
		System.out.println();
	}

	public String toString(){
		String temp = "";
		int counter = 0;
		for(int i = 0 ; i < row * column ; i++){
				if(counter == column){
					counter = 0;
					temp += "\n";
				}
				if(board1D[i] == -1){
					temp += "bb ";
					counter++;
				}
				else if(board1D[i] < 10){
					temp += "0";
					temp += board1D[i];
					temp += " ";
					counter++;
				}
				else if (board1D[i] > 9){
					temp += board1D[i];
					temp += " ";
					counter++;
				}

		}
		return temp;
	}

	public int cell(int i,int j){
		if(i > row && i < 0 && j < 0 && j > column){
			System.out.println("illegal indexes");
			System.exit(0);
		}
		return board1D[(i * column) + j];
	}

	public boolean equals(Object obj) {
		if (obj == null || getClass() != obj.getClass()) {
        	return false;
   		}
    	BoardArray1D p = (BoardArray1D) obj;
		for(int index = 0 ; index < row * column; index++){
			int j = index % column;
			int i = index / column;		
			if(board1D[index] != p.cell(i,j)){
				return false;
			}
		}
		return true;
	}
		
}
