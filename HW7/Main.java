import java.util.Scanner;

public class Main {
	
	// a static method that takes an array of AbstractBoard references and returns true if the array contains a valid sequence of moves for a solution.
	public static boolean ValidSequence(AbstractBoard[] board) {
		int current_i,current_j,next_i,next_j;
		int size = board.length;
		for(int index = 0 ; index < size-1 ; index++) {
			current_i = board[index].get_empty_i();
			next_i = board[index+1].get_empty_i();
			current_j = board[index].get_empty_j();
			next_j = board[index+1].get_empty_j();
			// if user moves, either of the row or column should be change. because no cross move in this our game.
			if(current_i != next_i && current_j != next_j)
				return false;
			else if(current_i == next_i && current_j == next_j)
				return false;
		}	
		return true;			
	}

	public static void main(String[] args) {
	String text;
	int choice;
	int b_row,b_column;
	int co_i,co_j;

	if(args.length == 0){
		do{
			System.out.println("what type do you want to initilaze the board:");
			System.out.println("1: one dimensional board");
			System.out.println("2: two dimensional board");
			System.out.println("press any other key for quit");

			Scanner input = new Scanner(System.in);
			choice = input.nextInt();
			boolean result;

			if(choice == 1){
					BoardArray1D board1 = new BoardArray1D();
					System.out.println("Your 1 dimensional board1...");
					System.out.println();
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					board1.setSize(b_row,b_column);
					System.out.println("board1 is initilazing randomly...");
					board1.initRandomly();
					System.out.println("board1 is:");
					board1.print();
					System.out.println("Your choices:");	
					int i,j;
					char c;
					String str;
					do{
						System.out.println( "L:	moves the empty cell left if there is room" );
						System.out.println( "R:	moves the empty cell right if there is room" );
						System.out.println( "U:	moves the empty cell up if there is room" );
						System.out.println( "D:	moves the empty cell down if there is room" );
						System.out.println( "E:	Asks a file name and saves the current board configuration as a loadable shape file.");
						System.out.println( "O:	Asks a file name and loads the current board configuration from the shape file." );
						
						System.out.println("choice:");
						c = input.next().charAt(0);
						switch(c){
							case 'l':
							case 'L':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved() == true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'r':
							case 'R':
									board1.move(c);
									System.out.println();
									board1.print();	
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'u':
							case 'U':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;								
							case 'D':
							case 'd':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;
							case 'E':
							case 'e': 
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.writeToFile(str); 
								break;
							case 'O':
							case 'o':
									System.out.println("Name of the new file: ");
									str = input.next();
									System.out.println("str:"+str);
									board1.readFromFile(str);
									board1.print();
									
								break;
							case 'q':
							case 'Q':
								break;
							default :
								break;

						}
					}while(c != 'q' && c != 'Q');
					System.out.println("board1 is solved or not ?");
					result = board1.isSolved();
					if(result == false)
						System.out.println("board1 is not finish.");	
					else if(result == true)
						System.out.println("board1 sis finished. Congratulations !!");	

					System.out.println("which coordinate value do you want to learn? ");
					System.out.println("coordinate i:");
					co_i = input.nextInt();
					System.out.println("coordinate j:");
					co_j = input.nextInt();
					System.out.println("value is: " + board1.cell(co_i,co_j));
					System.out.println("Your 1 dimensional board2...");
					BoardArray1D board2 = new BoardArray1D();
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					board2.setSize(b_row,b_column);
					System.out.println( "board2 is initilazing randomly...");
					board2.initRandomly();
					System.out.println("board2 is:");
					board2.print();		
					System.out.println("we are checking board1 and board2 are equal or not.");
					result = board1.equals(board2);
					if(result == true)
						System.out.println("Board1 and Board2 are euqal.");
					else{
						System.out.println("Board1 and Board2 are not euqal.");
					}

					System.out.println("Now, we are reseting board2...");
					board2.reset();
					board2.print();
					int size = 3;
					BoardArray2D[] arr = new BoardArray2D[size];
					for(i = 0 ; i < size ; i++){
						arr[i] = new BoardArray2D();
					}
					
					arr[0].readFromFile("aa.txt");
					arr[0].print();
					arr[1].readFromFile("moveLeft.txt");
					arr[1].print();
					arr[2].readFromFile("moveUp.txt");
					arr[2].print();
					System.out.printf("sequence is ");
					if(ValidSequence(arr) == true)
						System.out.println("valid");
					else
						System.out.println("not valid");
			}

			else if(choice == 2){
					BoardArray2D board1 = new BoardArray2D();
					System.out.println("Your 2 dimensional board1...");
					System.out.println();
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					board1.setSize(b_row,b_column);
					System.out.println("board1 is initilazing randomly...");
					board1.initRandomly();
					System.out.println("board1 is:");
					board1.print();
					System.out.println("Your choices:");	
					int i,j;
					char c;
					String str;
					do{
						System.out.println( "L:	moves the empty cell left if there is room" );
						System.out.println( "R:	moves the empty cell right if there is room" );
						System.out.println( "U:	moves the empty cell up if there is room" );
						System.out.println( "D:	moves the empty cell down if there is room" );
						System.out.println( "E:	Asks a file name and saves the current board configuration as a loadable shape file.");
						System.out.println( "O:	Asks a file name and loads the current board configuration from the shape file." );
						
						System.out.println("choice:");
						c = input.next().charAt(0);;
						switch(c){
							case 'l':
							case 'L':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved() == true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'r':
							case 'R':
									board1.move(c);
									System.out.println();
									board1.print();	
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'u':
							case 'U':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;								
							case 'D':
							case 'd':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;
							case 'E':
							case 'e': 
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.writeToFile(str); 
								break;
							case 'O':
							case 'o':
									System.out.println("Name of the new file: ");
									str = input.next();
									System.out.println(str);
									board1.readFromFile(str);
									board1.print();
									
								break;
							case 'q':
							case 'Q':
								break;
							default :
								break;

						}
					}while(c != 'q' && c != 'Q');
					System.out.println("board1 is solved or not ?");
					result = board1.isSolved();
					if(result == false)
						System.out.println("board1 is not finish.");	
					else if(result == true)
						System.out.println("board1 sis finished. Congratulations !!");	

					System.out.println("which coordinate value do you want to learn? ");
					System.out.println("coordinate i:");
					co_i = input.nextInt();
					System.out.println("coordinate j:");
					co_j = input.nextInt();
					System.out.println("value is: " + board1.cell(co_i,co_j));
					System.out.println("Your 1 dimensional board2...");
					BoardArray2D board2 = new BoardArray2D();
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					board2.setSize(b_row,b_column);
					System.out.println( "board2 is initilazing randomly...");
					board2.initRandomly();
					System.out.println("board2 is:");
					board2.print();		
					System.out.println("we are checking board1 and board2 are equal or not.");
					result = board1.equals(board2);
					if(result == true)
						System.out.println("Board1 and Board2 are euqal.");
					else{
						System.out.println("Board1 and Board2 are not euqal.");
					}

					System.out.println("Now, we are reseting board2...");
					board2.reset();
					board2.print();
			}
			else
				System.exit(0);

		}while(choice != 1 && choice != 2);
	}

	else if(args.length == 1){
		text = args[0];	
		do{
			System.out.println("what type do you want to initilaze the board:");
			System.out.println("1: one dimensional board");
			System.out.println("2: two dimensional board");
			System.out.println("press any other key for quit");

			Scanner input = new Scanner(System.in);
			choice = input.nextInt();
			boolean result;

			if(choice == 1){
					BoardArray1D board1 = new BoardArray1D();
					System.out.println("Your 1 dimensional board1...");
					board1.readFromFile(text);
					board1.print();	
					System.out.println("Your choices:");
					int i,j;
					char c;
					String str;
					do{
						System.out.println( "L:	moves the empty cell left if there is room" );
						System.out.println( "R:	moves the empty cell right if there is room" );
						System.out.println( "U:	moves the empty cell up if there is room" );
						System.out.println( "D:	moves the empty cell down if there is room" );
						System.out.println( "E:	Asks a file name and saves the current board configuration as a loadable shape file.");
						System.out.println( "O:	Asks a file name and loads the current board configuration from the shape file." );
						
						System.out.println("choice:");
						c = input.next().charAt(0);;
						switch(c){
							case 'l':
							case 'L':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved() == true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'r':
							case 'R':
									board1.move(c);
									System.out.println();
									board1.print();	
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'u':
							case 'U':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;								
							case 'D':
							case 'd':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;
							case 'E':
							case 'e': 
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.writeToFile(str); 
								break;
							case 'O':
							case 'o':
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.readFromFile(str);
									board1.print();
									
								break;
							case 'q':
							case 'Q':
								break;
							default :
								break;

						}
					}while(c != 'q' && c != 'Q');
					System.out.println("board1 is solved or not ?");
					result = board1.isSolved();
					if(result == false)
						System.out.println("board1 is not finish.");	
					else if(result == true)
						System.out.println("board1 sis finished. Congratulations !!");		
					System.out.println("which coordinate value do you want to learn? ");
					System.out.println("coordinate i:");
					co_i = input.nextInt();
					System.out.println("coordinate j:");
					co_j = input.nextInt();
					System.out.println("value is: " + board1.cell(co_i,co_j));
					System.out.println("Your 1 dimensional board2...");
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					BoardArray1D board2 = new BoardArray1D(b_row,b_column);
					System.out.println( "board2 is initilazing randomly...");
					board2.initRandomly();
					System.out.println("board2 is:");
					board2.print();	
					System.out.println("we are checking board1 and board2 are equal or not.");
					result = board1.equals(board2);
					if(result == true)
						System.out.println("Board1 and Board2 are euqal.");
					else{
						System.out.println("Board1 and Board2 are not euqal.");
					}
					System.out.println("Now, we are reseting board2...");
					board2.reset();
					board2.print();
			}

			if(choice == 2){
					BoardArray2D board1 = new BoardArray2D();
					System.out.println("Your 2 dimensional board1...");
					board1.readFromFile(text);
					board1.print();	
					System.out.println("Your choices:");	
					char c;
					String str;
					do{
						System.out.println( "L:	moves the empty cell left if there is room" );
						System.out.println( "R:	moves the empty cell right if there is room" );
						System.out.println( "U:	moves the empty cell up if there is room" );
						System.out.println( "D:	moves the empty cell down if there is room" );
						System.out.println( "E:	Asks a file name and saves the current board configuration as a loadable shape file.");
						System.out.println( "O:	Asks a file name and loads the current board configuration from the shape file." );
						
						System.out.println("choice:");
						c = input.next().charAt(0);;
						switch(c){
							case 'l':
							case 'L':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved() == true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'r':
							case 'R':
									board1.move(c);
									System.out.println();
									board1.print();	
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;							
							case 'u':
							case 'U':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + board1.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;								
							case 'D':
							case 'd':
									board1.move(c);
									System.out.println();
									board1.print();
									System.out.println("numberOfMove: " + AbstractBoard.numberOfMoves());
									if(board1.isSolved()==true){
										System.out.println("Game is solved");
										System.exit(0);
									}
									break;
							case 'E':
							case 'e': 
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.writeToFile(str); 
								break;
							case 'O':
							case 'o':
									System.out.println("Name of the new file: ");
									str = input.next();
									board1.readFromFile(str);
									board1.print();
									
								break;
							case 'q':
							case 'Q':
								break;
							default :
								break;

						}
					}while(c != 'q' && c != 'Q');
					System.out.println("board1 is solved or not ?");
					result = board1.isSolved();
					if(result == false)
						System.out.println("board1 is not finish.");	
					else if(result == true)
						System.out.println("board1 sis finished. Congratulations !!");		
					System.out.println("which coordinate value do you want to learn? ");
					System.out.println("coordinate i:");
					co_i = input.nextInt();
					System.out.println("coordinate j:");
					co_j = input.nextInt();
					System.out.println("value is: " + board1.cell(co_i,co_j));
					System.out.println("Your 1 dimensional board2...");
					System.out.println("Enter a row:");
					b_row = input.nextInt();
					System.out.println("Enter a column:");
					b_column = input.nextInt();
					BoardArray1D board2 = new BoardArray1D(b_row,b_column);
					System.out.println( "board2 is initilazing randomly...");
					board2.initRandomly();
					System.out.println("board2 is:");
					board2.print();	
					System.out.println("we are checking board1 and board2 are equal or not.");
					result = board1.equals(board2);
					if(result == true)
						System.out.println("Board1 and Board2 are euqal.");
					else{
						System.out.println("Board1 and Board2 are not euqal.");
					}
					System.out.println("Now, we are reseting board2...");
					board2.reset();
					board2.print();
			}
			else
				System.exit(0);

		}while(choice != 1 && choice != 2);
	}

	}

}