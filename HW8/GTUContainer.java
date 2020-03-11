import java.lang.reflect.Array;
import java.util.NoSuchElementException;
/**
 * Date 17.01.2020
 * This class is abstract super class of HW7.
 * @author Elif Goral
 * 		   171044003
 */

public abstract class GTUContainer<T>  {
	protected T container[]; //our container array
	protected int used; // container array's number of used element
	protected int capacity; // container array's number of capacity
	protected Class<T[]> ClassType;

	public GTUContainer(Class<T[]> classType) {
		used = 0;
		capacity = 2;
		ClassType = classType;
	    container = classType.cast(Array.newInstance(classType.getComponentType(), capacity));
	}
	
	 public GTUContainer(Class<T[]> classType,int Capacity) {
	     used = 0;
		 capacity = Capacity;
		 ClassType = classType;
	     container = classType.cast(Array.newInstance(classType.getComponentType(), capacity));
    }
	
	public class Iterator implements GTUIterator<T>{
		int currentIndex = 0;
	
		public boolean hasNext() {
			if(currentIndex < used && container[currentIndex] != null)
				return true;
			return false;
		}
			
		public T next() throws NoSuchElementException{   
			if(hasNext() == false)
				throw new NoSuchElementException("container has no more element");
			return container[currentIndex++];
		}		
	}

	/**
	 * This method tests whether container is empty
	 * @return if container is empty ,returns true, otherwise return false.
	 */
	public abstract boolean empty();
	
	/**
	 * This method returns container's size.
	 * @return This method returns container's size.
	 */
	public abstract int size();	

	/**
	 * This method returns container's maximum size which is container's capacity.
	 * @return This method returns container's maximum size which is container's capacity.
	 */
	public abstract int max_size(); 

	/**
	 * This method insert a element to end of the container.
	 * @param element Element which will be add to container.
	 * @throws IllegalArgumentException This method throws exception java.lang.IllegalArgumentException if there is a problem with insertion
	 */
	public abstract void insert(T element)throws IllegalArgumentException;

	/**
	 * This method erase a element.
	 * @param element Element which will be remove from container.
	 * @throws NoSuchElementException This method throws exception NoSuchElementException if there is a problem with erasing.
	 */
	public abstract void erase(T element)throws NoSuchElementException ;
	
	/**
	 * This method clear all contents.
	 */
	public abstract void clear(); 
	
	/**
	 * This method returns iterator to beginning
	 * @return This method returns iterator to beginning
	 */
	public abstract GTUIterator<T> iterator();
	
	/**
	 * This method print the container's content.
	 */
	public abstract void print();
	
	/**
	 * This method returns true if this collection contains the specified element.
	 * @param o o Object we will control the if it is in our container. 
	 * @return This method returns true if this collection contains the specified element.
	 */
	public abstract boolean contains(Object o); 
}
