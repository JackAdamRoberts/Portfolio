 

import jsjf.exceptions.*;
import java.util.Iterator;

/**
 * Represents a linked implementation of a stack.
 *
 * @author Lewis and Chase 
 * @version 4.0
 */
public class LinkedStack<T> implements StackADT<T>
{
    private int count;  
    private LinearNode<T> top; 

    /**
     * Creates an empty stack.
     */
    public LinkedStack()
    {
        count = 0;
        top = null;
    }

    /**
     * Adds the specified element to the top of this stack.
     * @param element element to be pushed on stack
     */
    public void push(T element)
    {
        LinearNode<T> temp = new LinearNode<T>(element);

        temp.setNext(top);
        top = temp;
        count++;
    }

    /**
     * Removes the element at the top of this stack and returns a
     * reference to it. 
     * @return element from top of stack
     * @throws EmptyCollectionException if the stack is empty
     */
    public T pop() throws EmptyCollectionException
    {
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        T result = top.getElement();
        top = top.getNext();
        count--;
 
        return result;
    }
   
    /**
     * Returns a reference to the element at the top of this stack.
     * The element is not removed from the stack.  
     * @return element on top of stack
     * @throws EmptyCollectionException if the stack is empty  
     */
    public T peek() throws EmptyCollectionException
    {
        //returns the first reference to the first element of the stack by calling the getElement() method.
        return top.getElement();
    }

    /**
     * Returns true if this stack is empty and false otherwise. 
     * @return true if stack is empty
     */
    public boolean isEmpty()
    {
        //conditional statments check to see if the value in the top of the stack is null, if there is a null value
        //anywhere in the top of the stack, then its empty.
        if(top == null){
            return true;
        }
        else
            return false;
    }
 
    /**
     * Returns the number of elements in this stack.
     * @return number of elements in the stack
     */
    public int size()
    {
        //Counts the size of the stack by using the while loop below.
        int counter = 0;
        while(top != null){
            T result = top.getElement();
            counter++;
            top.getNext();
        }
        return counter;
    }

    /**
     * Returns a string representation of this stack. 
     * @return string representation of the stack
     */
    public String toString()
    {
        //I didnt need this toString method since we weren't required to print the string reversed to the screen.
        return "";
    }
}
