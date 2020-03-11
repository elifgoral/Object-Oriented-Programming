import java.lang.IllegalArgumentException;
import java.util.NoSuchElementException; 
import java.lang.reflect.Array;
/**
 * Date 17.01.2020
 * This class is sub class of HW7.
 * @author Elif Goral
 * 		   171044003
 *
 */

public class GTUSet<T> extends GTUContainer<T>{
	public GTUSet(Class<T[]> classType) {
		super(classType);		
	}
		
	public GTUSet(Class<T[]> classType,int capacity) {
		super(classType,capacity);
	}
		
	/**
	 * This method tests whether container is empty
	 * @return if container is empty ,returns true, otherwise return false.
	 */
	public boolean empty(){ 
		if(this.used == 0)
			return true;
		return false;
	}

	/**
	 * @return This method returns container's size.
	 */
	public int size(){  
		return this.used;	
	}

	/**
	 * @return This method returns container's maximum size which is container's capacity.
	 */
	public int max_size(){  
		return this.capacity;
	}

	/**
	 * This method clear all contents.
	 */
	public void clear(){ 
		this.used = 0;
	}

	/**
	 * @return This method returns iterator to beginning
	 */
	public GTUIterator<T> iterator(){
		GTUIterator<T> it= new Iterator();
		return it;
	}
	
	/**
	 * This method erase a element.
	 * @param element Element which will be remove from container.
	 * @throws NoSuchElementException This method throws exception NoSuchElementException if there is a problem with erasing.
	 */
	public void erase(T element)throws NoSuchElementException{ 
		if(empty()){
	        throw new NoSuchElementException();
		}	
		else { // I create iterator and continue to see the element which I will erase. I save the index which I see the element, to backUpIndex. Because after that I assign container[i+1] to container[i].
			GTUIterator<T> iter = this.iterator();
			int backUpIndex = 0;
			int k = 0;
			while(iter.hasNext()) {
			T value = iter.next();
				if(element == value) {
					for(int j = 0 ; j < used ; j++) {
						if( j == backUpIndex && j+1 < used) {
							j++;
							container[k] = container[j];
							k++;
						}
						else {
							container[k] = container[j];
							k++;
						}
					}
				}	
				backUpIndex++;
			}
			used--;
		}	
	}
	
	/**
	 *  if container has a same element return 1 ,otherwise return 0
	 * @param element  Element which will be control if container has a same element
	 * @return  if container has a same element return 1 ,otherwise return 0
	 */
	public int FindSameElement(T element){ 
		GTUIterator<T> iter = this.iterator();
		while(iter.hasNext()) {
			if(iter.next() == element) {
				return 1;
			}
		}
		return 0;
	}
	
	/**
	 * @param o object which will be control if container has a same object
	 * @return Returns true if this collection contains the specified element.
	 */
	public boolean contains(Object o) {
		GTUIterator<T> iter = this.iterator();
		while(iter.hasNext()) {
			if(iter.next() == o) {
				return true;
			}
		}
		return false;
	}
	
	/**
	 * This method insert a element to end of the container.
	 * @param element Element which will be add to container.
	 * @throws IllegalArgumentException This method throws exception java.lang.IllegalArgumentException if there is a problem with insertion
	 */
	public void insert(T element)throws IllegalArgumentException{ 
			if(element == null) {
				throw new IllegalArgumentException("Element can not be null");
			}
			
			else if(used != capacity) {
				if(FindSameElement(element) == 1){
		            throw new IllegalArgumentException("same element has already added.");
				}
				else {
					container[used] = element;
					used++;
				}
			}
			
			else if(used  == capacity) {
				if(FindSameElement(element) == 1){
		            throw new IllegalArgumentException("same element has already added.");
				}
				else {
					T[] temp = ClassType.cast(Array.newInstance(ClassType.getComponentType(), capacity *2 ));
					for(int i = 0 ; i < used ; i++)
						temp[i] = container[i];
					container = ClassType.cast(Array.newInstance(ClassType.getComponentType(), capacity * 2 ));
					for(int i = 0 ; i < used ; i++)
						container[i] = temp[i];			
					capacity *= 2;
					container[used] = element;
					used++;
				}
			}				
	} 
	
	/**
	 * This method print the container's content.
	 */
	public void print(){ 
		GTUIterator<T> iter = this.iterator();
		while(iter.hasNext()) {
		       System.out.print(iter.next() +" ");
		}
		System.out.println();
	}
}