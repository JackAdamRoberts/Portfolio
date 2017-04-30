/**
 * The SearchFile Class gets a filePath and word from the Driver class, here
 * it opens the file and searches through it counting the number of instances of the word
 * and on which lines it appears.
 * 
 * @author Jack Roberts 
 * @version 03/02/2016
 */

//importing the libraries to be used by this class
import java.util.*;
import java.io.*;

public class SearchFile
{   
    private String wordSearched;    //wordSearched is a global variable that is sent from main()
    private String filePath;        //filePath is the the path of the file that will be opened and read from
    private int wordLength;         //wordLength is the length of wordSearched, it will be used to compare the words in the file
    private int occurrences;        //occurrences is the amount of times that the word appears in the file
    
    //SearchFile constructor sets all of the above variables to zero or 'unknown' so that nothing gets confused.
    public SearchFile(){
        filePath = "Unknown";
        wordSearched = "Unknown";
        wordLength = 0;
        occurrences = 0;
    }
    /**
     * setFilePath is a method that sets the path of the file to be used by the methods in this class.
     * 
     * @param filePath is the path of the file that the findWord() method will use.
     */
    public void setFilePath(String filePath){
        this.filePath = filePath;
    }
    /**
     * setWordSearched is a method that sets the word to be used by findWord() to find the word in the file.
     * 
     * @param wordSearched is the word that the findWord() method will use to compare the words it finds to.
     */
    public void setWordSearched(String wordSearched){
        this.wordSearched = wordSearched;
        setWordSearchedLower(wordSearched);
    }
    /**
     * setWordLength is a method that sets the path of the file to be used by the methods in this class.
     * 
     * @param wordSearched is the word that setWordLength() will use to determine the length of the word that will be used by the entire class.
     */
    public void setWordLength(String wordSearched){
        wordLength = wordSearched.length();
        this.wordLength = wordLength;
    }
    
    /**
     * setWordSearchedLower is a method that sets the word being searched to lower-case so that it can be matched up to the characters searched by the findWord().
     * 
     * @param wordSearched is the word that setWordLength() will use to determine the length of the word that will be used by the entire class.
     */
    public void setWordSearchedLower(String wordSearched){
        wordSearched = wordSearched.toLowerCase();
        this.wordSearched = wordSearched;
    }
    
    //findWord() uses the global variables at the top to search through the file character by character, all while comparing the characters it finds to the ones in the word being searched.
    public void findWord() throws IOException{
        int lineCounter = 0;           //lineCounter is the variable that will be used to print out on which line in the file the word is found on
        Scanner dataFile;              //dataFile is the declared variable name for the file this method will be searching through
        dataFile = new Scanner(new File(filePath));     //Opening the file and setting dataFile equal to it
        System.out.print("\n\n__________________________________________________________________\nResults:\nThe word '" + wordSearched + "' appears on line(s): ");      //This begins the output on the screen that the user will see telling them on what line the word appears.
       while(dataFile.hasNext()){       //While the file has a next line this will execute
           String line = dataFile.nextLine();       //the variable is declared as line and set equal to the next line that is found in the file
           int lineCharLength = line.length();      //lineCharLength is set to the length of 'line' found in the line above.
           char[] characters = new char[lineCharLength];        //An array of characters is initialized as the length of the line
           lineCounter++;       //the line counter will increment by one as the file begins to check the first line in the file, and so on every time this while loop runs.
           for(int i = 0; i < lineCharLength; i++){     //this for loop takes the characters in the line being read and puts them into an array
               characters[i] = line.charAt(i);      //the characters are read one by one and put into the array
               characters[i] = Character.toLowerCase(characters[i]);     //whatever character was found in the line above is set to lowercase so that it becomes uniform with the wordSearched.
           }//end of for loop
           for(int j = 0; j < lineCharLength; j++){     //this for loop takes the characters in the line being read and compares them to the characters in the word being searched.
               if(characters[j] == wordSearched.charAt(0)){     //this conditional statments checks to see if the character being compared equals the first in the word being searched.
                   if(j++ < lineCharLength-1){      //this conditional statment checks to make sure that the next character being compared isnt the past end of the line.
                       if(characters[j] == wordSearched.charAt(1)){     //this conditional statments checks to see if the character being compared equals the second in the word being searched.
                           j=((--j+(wordLength-1)));   //this line changes the character in the line being searched to the length of the word being searched to verify that the word is in fact the one being searched.
                           if(j <= lineCharLength-1){       //this conditional statment checks to make sure that the next character being compared isnt the past end of the line.
                               if(characters[j] == wordSearched.charAt(wordLength-1)){  //this conditional statment checks the character at the index of the wordLength of the word being searched.
                                   occurrences++;        //the occurrences variable increments by one to count the times the word is found in the file.
                                   System.out.print(lineCounter + ", ");     //if the word appears on the line being searched this will execute to tell the user which line contains the word.
                               }
                           }
                       }
                   }
               } 
           }//end of for loop
       }//end of while loop
       this.occurrences = occurrences;      //the occurrences variable is set to whatever occurrences total came to after the file was searched
    }
    /**
     * The toString() method sends the results back to main to be shown by the terminal.
     * 
     * @return returns the results.
     */
    public String toString(){
        return ("The word '" + wordSearched + "' appears: " + occurrences + ", time(s) in the file."); 
    }
}//end of class
