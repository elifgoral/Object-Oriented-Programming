import java.util.NoSuchElementException;

/**
 * Date 17.01.2020
 * @author Elif Goral
 * 		   171044003
 *
 */
public interface GTUIterator<T> {

	/**
	 * currentIndex defines iterator's current index.
	 */
	int currentIndex = 0;
	
	/**
	 * Returns true if the iteration has more elements. (In other words, returns true if next() would return an element rather than throwing an exception.)
	 * @return true if the iteration has more elements
	 */
	boolean hasNext();

	/**
	 * Returns the next element in the iteration.
	 * @return Returns the next element in the iteration.
	 * @throws NoSuchElementException  if the iteration has no more elements, This method throws NoSuchElementException.
	 */
	T next() throws NoSuchElementException;
	
}