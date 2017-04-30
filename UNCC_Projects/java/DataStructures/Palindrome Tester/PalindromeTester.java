/**
 * PalindromeTester uses the queue, and stack classes and determines whether a string is a palindrome
 * or not and returns a true or false value based upon the results.
 * 
 * @author Jack Roberts 
 * @version 06/03/2016
 */
public class PalindromeTester
{
    /**
     * palindromeTester(String string) takes in a string, calls the methods of the CircularArrayQueue and LinkedStack
     * each character is added into the queue in the order the user entered it into the keyboard, however becuase of 
     * the way that stack works, it will enter it into the stack with the last character of the stack being the first 
     * one in the string, because this happens, the program can check to see if the reversed version of the string is 
     * the same as the forwards version.
     * 
     * @param A string to be tested for the characters of a palindrome.
     * @return A boolean value that lets the user know if the string entered is a palindrome. 
     */
    public static boolean palindromeTester(String string)
    {
        StackADT<String> stack = new LinkedStack<String>(); //creating the stack 
        QueueADT<String> queue = new CircularArrayQueue<String>();  //creating the queue
        String s;
        for (int i = 0; i < string.length( ); i++) {
            s = "" + string.charAt(i);
            s = s.toLowerCase(); //handling the capitalization possibility
            queue.enqueue(s);   //putting the charcachter into the queue 
            stack.push(s);  //putting the characters into the top of the stack 
        }
        System.out.print("\n_________________________________________________________________\n\nResults:\n\nIs '" + string + "' a Palindrome?: ");
        while (!queue.isEmpty( )){
            if (!queue.dequeue().equals(stack.pop( ))){
                return false; //if the dequeued character does not equal the popped character from the stack, it returns false.
            }
        }
        return true; //returns true if the strings are the same.
    }
}
