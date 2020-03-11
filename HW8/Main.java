import java.util.NoSuchElementException;

/**
 * Date 17.01.2020
 * This class is test class.
 * @author Elif Goral
 * 		   171044003
 */

public class Main {

	public static void main(String[] args) {
		
		System.out.println("we are creating a vector object");
		GTUVector<Integer> objectVector = new GTUVector<Integer>(Integer[].class);
		System.out.println("our vector object is");
		if(objectVector.empty())
			System.out.println("empty");
		else if(!objectVector.empty()) {
			System.out.println(" not empty");
		}
		
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println("inserting 1...");
		objectVector.insert(1);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("inserting 2...");
		objectVector.insert(2);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("inserting 3...");
		objectVector.insert(3);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("inserting 4...");
		objectVector.insert(4);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("erasing 4...");
		objectVector.erase(4);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("erasing 2...");
		objectVector.erase(2);
		System.out.println("our vector:");
		objectVector.print();
		System.out.println("our vector object's size:" + objectVector.size() );
		System.out.println("our vector object's maximum size:" + objectVector.max_size() );
		System.out.println();

		System.out.println("clearing the vector object...");
		objectVector.clear();
		System.out.println("our vector:");
		objectVector.print();
		
		System.out.println("----------------------------------------------------------------");
		try {
			System.out.println("we are creating a set object");
			GTUSet<String> objectSet = new GTUSet<String>(String[].class);
			System.out.println("our set object is");
			if(objectSet.empty())
				System.out.println("empty");
			else if(!objectSet.empty()) {
				System.out.println(" not empty");
			}
			
			System.out.println("our set object's size:" + objectSet.size() );
			System.out.println("our set object's maximum size:" + objectSet.max_size() );
			
			System.out.println("inserting Elif...");
			if(!objectSet.contains("Elif")) {
				objectSet.insert("Elif");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			System.out.println("inserting Levent...");
			if(!objectSet.contains("Levent")) {
				objectSet.insert("Levent");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			System.out.println("inserting Abdullah...");
			if(!objectSet.contains("Abdullah")) {
				objectSet.insert("Abdullah");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			System.out.println("inserting Neslihan...");
			if(!objectSet.contains("Neslihan")) {
				objectSet.insert("Neslihan");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			
			System.out.println("erasing Neslihan...");
			if(objectSet.contains("Neslihan")) {
				objectSet.erase("Neslihan");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			

			System.out.println("erasing Levent...");
			if(objectSet.contains("Levent")) {
				objectSet.erase("Levent");
				System.out.println("our set:");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );	
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			System.out.println("clearing the set object...");
			objectSet.clear();
			System.out.println("our set:");
			objectSet.print();
			System.out.println();
		
			System.out.println("inserting Elif...");
			if(!objectSet.contains("Elif")) {
				objectSet.insert("Elif");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();
			
			System.out.println("inserting Elif...");
			if(!objectSet.contains("Elif")) {
				objectSet.insert("Elif");
				objectSet.print();
				System.out.println("our set object's size:" + objectSet.size() );
				System.out.println("our set object's maximum size:" + objectSet.max_size() );
				System.out.println();
			}
			else
		        throw new NoSuchElementException();		
		}
		
		catch(Exception InvalidParameterException){
	         System.out.println( "Program executed.The element is already in the Set Object\n");
	    }
		
	}
}
