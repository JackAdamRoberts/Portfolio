import java.util.*;
/**
 * The Driver class tests the methods of the stack and queue classes to see if it in fact can test a string
 * that the user enters is a palindrome.
 * 
 * @author Jack Roberts
 * @version 06/03/2016 
 */
public class Driver   {
    public static void main(String[]args){
        
        //Introduction Output
        System.out.println("                        Palindrome Tester\n                       Author: Jack Roberts\n                       Version: 06/03/2016");
        //Declaring the scanner to enter the string.
        Scanner input = new Scanner (System.in);
        
        //local variables
        boolean quit = false;   //boolean value associated with the users choice to continue or quit.
        char choice;    //char value that the user will enter to conintue using the program after testing the first string.
        int counter = 0;    //counter used for the error that occurs on line: 25.
        
        //while loop allows the user to repeat the palindrome checker if they wish to.
        while(quit == false){
            
            PalindromeTester test = new PalindromeTester();
            System.out.print("\n_________________________________________________________________\n\nEnter a string to be tested: ");
            System.out.flush();
            //Because of an error that occured when testing the program, I had to write in this
            //conditional statment that takes the extra character left behind from the last string
            //that the user checked and displaces it. 
            String string = input.nextLine();           
            
            //This will only execute if the user enters more than one string.
            if(counter > 0){
                string = input.nextLine();
            }
            counter++; 
            string = string.replaceAll("[\\W]",""); //handles the possibility of any punctuation

            System.out.print(test.palindromeTester(string)); //Prints the results of the palindrome test.
            
            //Go again menu.
            System.out.print("\n_________________________________________________________________\n\n       Would you like to enter another string to be tested?\n\n                 G) - Go Again (Enter 'g' or 'G')\n                 Q) - Quit (Enter 'q' or 'Q')\n\n                       Enter Choice: ");
            choice = input.next().charAt(0);
            if(choice == 'q' || choice == 'Q'){
                quit = true;
                System.out.println("\n\n    Thank you for using this Palindrome Tester, goodbye!\n_________________________________________________________________");
            }
            else if(choice != 'q' && choice != 'Q'){
                quit = false;
            }
        }
    }
}

