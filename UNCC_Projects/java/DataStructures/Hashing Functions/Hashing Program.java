import java.io.*;
import java.util.*;
import java.math.*;
/**
 * Write a description of class Driver here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Driver
{
    public static void main(String [] args) throws Exception{
        BufferedReader br = new BufferedReader (new FileReader("words.txt"));
        String line = null;
        int [] hashTable1 = new int[5701];
        
            for(int i = 0; i < hashTable1.length; i++){
                hashTable1[i] = 0;
            }
            
            //Hashing Function 1
            while((line = br.readLine())!=null){
                StringBuilder concatenated = new StringBuilder();
                String[] st = line.split(" ");
                Double hashValue;
                int hashInteger=0;
                for(int i = 0; i < st[0].length(); i++){
                    int ascii = (int) st[0].charAt(i);
                    concatenated.append(Integer.toString(ascii));
                    double concatenatedDouble = Double.parseDouble(concatenated.toString());
                    hashValue = concatenatedDouble % 5071;
                    hashValue.intValue();
                    Double obj = new Double(hashValue);
                    hashInteger = obj.intValue();
                    hashTable1[hashInteger] = hashTable1[hashInteger] + 1;
                }
                System.out.println("\nLine: " + line + "\nConcatenated: " + concatenated);
            }
            
            //Declaring the variables to be used by the following loop for populating the hash table for the first function.
            int total = 0;
            int numberOverZero = 0;
            double averageChainSize = 0;
            int emptyChains = 0;
            int collisionTotal = 0;
            
            //for loop used to populate the first hash table based on the criteria described on the prompt.
            for(int i = 0; i < hashTable1.length; i++){
                if(hashTable1[i] > 1){
                    collisionTotal+=hashTable1[i] - 1;  //calculating how many collisions occur based on the number above one in any particular slot in the hash table.
                }
                if(hashTable1[i] > 0){
                    total += hashTable1[i];
                    numberOverZero++;
                    averageChainSize = total / numberOverZero;
                }
                if(hashTable1[i] == 0){
                    emptyChains++;
                }
            }
        
        //Declaring the file reader for the second function and the array for the second hash table.
        BufferedReader br2 = new BufferedReader (new FileReader("words.txt"));
        int [] hashTable2 = new int[5701];
            
            //Loop to create a hash table with 0s in all of the slots.
            for(int i = 0; i < hashTable2.length; i++){
                hashTable2[i] = 0;
            }
            
            //Hashing Function 2
            while((line = br2.readLine())!=null){
                StringBuilder concatenated = new StringBuilder();
                String[] st = line.split(" ");
                double wordValue = 0.0;
                double placement = 0.0;
                int placementInt = 0;
                for(int i = 0; i < st[0].length(); i++){
                    int ascii = (int) st[0].charAt(i);
                    double letterTotal = 0.0;
                    letterTotal = (ascii*(Math.pow(127.0,i)));
                    wordValue = letterTotal;
                    placement = wordValue%5701;
                    Double obj = new Double(placement);
                    placementInt = obj.intValue();
                    hashTable2[placementInt] = hashTable2[placementInt] + 1;
                }
                System.out.println("\nLine: " + line + "\nKey Value: " + wordValue);
            }
            
            //Declaring the variables to be used by the following loop for populating the hash table for the second function.
            int total2 = 0;
            int numberOverZero2 = 0;
            double averageChainSize2 = 0;
            int emptyChains2 = 0;
            int collisionTotal2 = 0;
            
            //for loop used to populate the second hash table based on the criteria described on the prompt.
            for(int j = 0; j < hashTable2.length; j++){
                if(hashTable2[j] > 1){
                    collisionTotal2+=hashTable2[j] - 1;
                }
                if(hashTable2[j] > 0){
                    total2 += hashTable2[j];
                    numberOverZero2++;
                    averageChainSize2 = total2 / numberOverZero2;
                }
                if(hashTable2[j] == 0){
                    emptyChains2++;
                }
            }
            
            //Printing the results of the average number of collisions, chain sizes, and empty chains.
            System.out.println("\nResults:\n\nHashing Function 1:\nAverage Chain Size: " + averageChainSize + "\nEmpty Chains: " + emptyChains + "\nCollision Total: " + collisionTotal);
            System.out.println("\nHashing Function 2:\nAverage Chain Size: " + averageChainSize2 + "\nEmpty Chains: " + emptyChains2 + "\nCollision Total: " + collisionTotal2);
            
            //Printing the conclusions of the test based on the results.
            String result = "";
            String resultWord = "";
            if(collisionTotal > collisionTotal2){
                result = "less efficient";
                resultWord = "more.";
                int amount = collisionTotal - collisionTotal2;
                System.out.println("\n\nConclusion:\nIn the comparison of the two hashing functions, it is concluded that the Hashing Function 1 (Concatenating) is " + result + ", than the Hashing Function 2.\nWe can conclude this because in order to have the most efficient hashing function there must be the least number of collisions possible.\nIn this case the number of collisions between hashing function 1 and hashing function 2 is: " + amount + " " + resultWord);
            }
            else if(collisionTotal < collisionTotal2){
                result = "more efficient";
                resultWord = "less.";
                int amount = collisionTotal2 - collisionTotal;
                System.out.println("\n\nConclusion:\nIn the comparison of the two hashing functions, it is concluded that the Hashing Function 1 (Concatenating) is " + result + ", than the Hashing Function 2.\nWe can conclude this because in order to have the most efficient hashing function there must be the least number of collisions possible.\nIn this case the number of collisions between hashing function 1 and hashing function 2 is: " + amount + " " + resultWord);
            }   
            
    }//end of main
}//end of Driver
