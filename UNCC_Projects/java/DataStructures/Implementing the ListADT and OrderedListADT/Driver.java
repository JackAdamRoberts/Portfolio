import java.util.*;
/**
 * Use this Driver with main( ) to test the
 * code you wrote for the OrderedList
 * 
 * @author L. Lehmann
 * @version October 2015
 */
public class Driver
{
    public static void main(String[ ] args)
    {
        ArrayOrderedList<String> fruitList = new ArrayOrderedList<String>( );
        
        fruitList.add("pear");
        fruitList.add("canteloupe");
        fruitList.add("quamquat");
        fruitList.add("watermelon");
        fruitList.add("tomato");
        
        //test of size( ) mwthod
        System.out.println("The list has " + fruitList.size( ) + " items in it.");
        
        //test of first( ) method
        System.out.println("The first item in the list is: " + fruitList.first( ) );
        
        //test of last( ) method
        System.out.println("The last item in the list is: " + fruitList.last( ));
        
        //test of the toString method
        System.out.println(fruitList);
        
        //test of the iterator( ) method
        Iterator it = fruitList.iterator( );
        while(it.hasNext( ))
        {
            System.out.println(it.next( ) );
        }
        
        //test of the remove method- remove from the interior
        fruitList.remove("tomato");
        System.out.println(fruitList);
        
        //test of the remove method- remove from the front of list
        fruitList.remove("canteloupe");
        System.out.println(fruitList);
        
        //test of the remove method- remove from end of list
        fruitList.remove("watermelon");
        System.out.println(fruitList);
        
        //test of add after the other operations have completed
        fruitList.add("banana");
        fruitList.add("apple");
        fruitList.add("strwberry");
        fruitList.add("cherry");
        
        System.out.println(fruitList);
        
        //test of isEmpty( ) method
        if(fruitList.isEmpty( ))
          System.out.println("List is empty");
        else
          System.out.println("List is not empty");
    } //end of main
        
} //end of TestDriver class
