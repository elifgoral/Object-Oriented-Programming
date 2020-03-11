import java.util.Scanner;
import java.io.*;

public abstract class AbstractBoard {
	protected int row;
	protected int column;
	protected String last_move;
	protected int empty_i;
	protected int empty_j;
	protected int wall_number;
	static int numberOfMove = 0;
	static int numberOfBoard = 0;
	
	public AbstractBoard() {
		row = 0;
		column = 0;
		wall_number = 0;
		last_move = "s";
	}

	public AbstractBoard(int row, int column) {
		this.row = row;
		this.column = column;
		wall_number = 0;
		last_move = "s";
	}
	
	/**
	 * That method returns the Board's row number.
	 * @return Board's row number.
	 */
	public int get_row() {
		return row;
	}
	
	/**
	 * That method returns the Board's column number.
	 * @return Board's column number.
	 */
	public int get_column() {
		return column;	
	}
	
	/**
	 * That method returns the Board's empty block's x axis index.
	 * @return Board's empty block's x axis index
	 */
	public int get_empty_i() {
		return empty_i;	
	}
	
	/**
	 * That method returns the Board's empty block's y axis index.
	 * @return Board's empty block's y axis index
	 */
	public int get_empty_j() {
		return empty_j;
	}
	
	
	/**
	 * That method returns the Number of Move.
	 * @return Returns Number of Move
	 */
	public static int numberOfMoves() {
		return numberOfMove;
	}
	
	/**
	 * That method returns the Number of Board.
	 * @return Returns Number of Board
	 */
	public static int numberOfBoards() {
		return numberOfBoard;
	}
	
	/**
	 * That method returns the last move of the game.
	 * @return Returns the last move of the game.
	 */
	public String lastMove() {
		return last_move;
	}
	
	/**
	 * That method assign the parameter row to Board's row number and the parameter column to Board's column number.
	 * @param row  Board's row number
	 * @param column Board's column number
	 */
	public void setSize(int row,int column) {
		this.row = row;
		this.column = column;
	}
	
	/**
	 * That method assign the parameter empty_j to Board's empty block's x axis index.
	 * @param empty_i  Board's empty block's x axis index.
	 */
	public void set_empty_i(int empty_i) {
		this.empty_i = empty_i;
	}
		
	/**
	 * That method assign the parameter empty_j to Board's empty block's y axis index.
	 * @param empty_j Board's empty block's y axis index.
	 */
	public void set_empty_j(int empty_j) {
		this.empty_j = empty_j;
	}
	
	/**
	 * That method checks if there is a same number while setting random board.
	 * @param array the Board which we will check
	 * @param counter counter block number which is row * counter
	 * @param random_number  Number which we will be check
	 * @return if there is same number fail and return 0. if there isn't same number it will be success and returns 1.
	 */
	public int control_random(int array[],int counter,int random_number){ 
		int i;
		for(i = 0 ; i < counter ; i++){
			if(array[i] == random_number)
				return 0; // fail
		}
		return 1;//success
	}

	/**
	 * That method find the row when reading a board from a file.
	 * @param fileName txt file name where we read the board.
	 */
	public void findRow(String fileName) {
		try {
			int counter = 0;
			FileInputStream file = new FileInputStream(fileName);       
			Scanner sc = new Scanner(file); 
			while(sc.hasNextLine())  
			{  
				sc.nextLine();
				counter++;//returns the line that was skipped  
			}  
			sc.close();     //closes the scanner  	
			row = counter;
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	/**
	 * That method find the column when reading a board from a file.
	 * @param fileName txt File name where we read the board
	 */
	public void findColumn(String fileName) {
		try {
			FileInputStream file = new FileInputStream(fileName);       
			Scanner input = new Scanner(file); 
			    int counter = 0;
			    wall_number = 0;
			    while (input.hasNext()) {
			      String str = input.next();
			      if(str == "00")
			      	wall_number++;
			      counter++;
			    }
			    input.close(); 
			    column = counter / row;
		}
		catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	/**
	 * That method print the board.
	 */
	public abstract void print();
	
	/**
	 * the blank tiles moves left.
	 */
	public abstract void move_left();
	
	/**
	 * the blank tiles moves right.
	 */
	public abstract void move_right();
	
	/**
	 * the blank tiles moves up.
	 */
	public abstract void move_up();
	
	/**
	 * the blank tiles moves down.
	 */
	public abstract void move_down();
	
	/**
	 * This is the character that the empty box goes this direction. If the parameter is L then the blank tiles moves left. If the parameter is R then the blank tiles moves right. If the parameter is U then the blank tiles moves up, If the parameter is D then the blank tiles moves down
	 * @param direction Direction which we move to
	 */
	public abstract void move(char direction);
	
	/**
	 * This method check the board is finished or continue.
	 * @return if board is finished, method return true,otherwise false.
	 */
	public abstract boolean isSolved();
	
	/**
	 * This method init randomly the board.
	 */
	public abstract void initRandomly();
	
	/**
	 * This method reads the board from txt file which is given as a parameter.
	 * @param fileName txt file which we read from.
	 */
	public abstract void readFromFile(String fileName);
	
	/**
	 * This method writes the board to the txt file which is given as a parameter.
	 * @param fileName txt file name which we will write.
	 */
	public abstract void writeToFile(String fileName);
	
	/**
	 * This method returns board's value on given indexes.
	 * @param i defines x axis index.
	 * @param j  defines y axis index.
	 * @return board's value on given indexes.
	 */
	public abstract int cell(int i,int j);
	
	/**
	 *produces the board as string
	 */
	public abstract String toString();
	
	/**
	 *This method controlled the equivalence of Boards. Board1 is our object, Board2 is given as a parameter. if they are equal returns true,otherwise false.
	 */
	public abstract boolean equals(Object obj);

}
