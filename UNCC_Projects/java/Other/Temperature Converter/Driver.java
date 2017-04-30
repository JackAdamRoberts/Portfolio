/**
 * The Driver class creates objects of the SearchFile class and sends a file path 
 * and word to the SearchFile class to be searched
 * driver prints out the results.
 * 
 * @author Jack Roberts 
 * @version 03/02/2016
 */

//Importing the java packages to be used by Driver
import java.util.*;
import java.io.*;

public class Driver
{
    /**
     * main() is where the program starts and creates objects to be used by the SearchFile class.
     * 
     * @throws IOException
     */
    public static void main(String[] args)throws IOException{
        String filepath;        //declaring the file path as filepath
        String wordSearched;        //declaring the word to be searched by the program as wordSearched
        String results;     //declaring the results to be printed out as results
        char goAgain = 'y';     //declaring the variable that will be checked by the while loop to run the program over and over again
        Scanner input;      //the scanner object that will be used to read input by the user declared as input
        input = new Scanner(System.in);     //setting the scanner object using System.in equal to input
        SearchFile sf;      //declarig an instance of the SearchFile class
        sf = new SearchFile();      //creating a new instance of the SearchFile class and declaring it as 
        
        //the while loop will allow the program to run as long as the user wishes it to
        while(goAgain == 'y'){
            System.out.print("\n\n\n\n\n\n\n\n\nNew Search:\n\nPlease enter the file path: ");     //Prompting the user for the file path
            filepath = input.next();        //setting the input from the user as the filepath
            sf.setFilePath(filepath);       //creating an object of the setFilePath method in the SearchFile class
            
            System.out.print("Please enter a word to search for: ");      //Prompting the user to enter the word they would like to search within the file
            wordSearched = input.next();        //declaring the input from the user as the wordSearched variable
            sf.setWordSearched(wordSearched);       //initiating an instance of the setWordSearched() method in the SearchFile class
            sf.setWordLength(wordSearched);     //initiating the setWordLength() method in the SearchFile class  
                
            sf.findWord();      //initiating the findWord() method in the SearchFile class
            
            results = sf.toString();       //setting the return results of the toString() method in the SearchFile class as the results
                
            System.out.println("\n" + results);     //prints out the results of the search to the terminal
            System.out.println("__________________________________________________________________");
            System.out.print("\n\nEnter 'y' to continue, or 'q' to quit: ");       //prompting the user to input a character to continue the program or quit.
            goAgain = input.next().charAt(0);        //setting the variable goAgain to the character that the user enters to be checked by the while loop
        }//end of while loop
    }//end of main
}//end of class