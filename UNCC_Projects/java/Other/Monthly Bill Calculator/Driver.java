/**
 * Driver is where information is entered by the user and sent 
 * to the monthly bill calculator.
 * 
 * Jack Roberts
 * 02/08/2016
 */
import java.util.*;  //Imports java utility library which gives access to Scanner 
public class Driver   //Public driver class.
{
    public static void main(String[] args)  //Main method of Driver class.
    {
        char packageSel;
        Scanner input;              //Declaring variables within the scope
        MonthlyBill bc;             //of this particular method.
        double hours;
        int goAgain;
        
        goAgain = 1;                        //goAgain is set to 1.
        bc = new MonthlyBill();             //This sets up a new instance of the MonthlyBill class as bc for the driver to use.
        input = new Scanner(System.in);     //This expects an input from the keyboard as "input."
        
        while(goAgain == 1){         //The following will repeat until the user enters anything but 1.
        System.out.println("\n\n\n\n\n\nThere are three packages for Internet Services: \n\n");  //This line along with the four following will appear as the menu.
        System.out.println("Package A)\n- $25.99 per month \n- 25 hours of access are provided. \n- Additional hours (or part of ie: 3.6 hours) are $0.48 per hour.");
        System.out.println("\nPackage B)\n- $35.95 per month \n- 45 hours of access are provided.\n- Additional hours (or part of) are $0.65 per hour.");
        System.out.println("\nPackage C)\n- $49.00 per month \n- Unlimited access provided.");  
        System.out.println("\n\nPlease select a choice from the list: ");  //Promps the user to enter a choice from the list above.
        
        packageSel = input.next().charAt(0);  //This is where the program expects the input for the package the user selects.
        
        if(packageSel == 'a' || packageSel == 'A'){  //This will execute if the user enters characters 'a' or 'A'
        bc.setPackage('a');       //Sends the character 'c' to the MonthlyBill class to let the user know they've selected package C.
        System.out.println("\nHow many hours will be used?: ");  //This prompts the user to enter the amount of hours used.
        hours = input.nextDouble();   //User enters the amount of hours used here.
        System.out.println();     //The following two lines create a dividing line on the screen to clean things up.
        System.out.println("_________________________________________________________________");
        bc.calculate('a',hours);  //Sends the package selected along with the hours entered by the user to be calculated in the MonthlyBill class.
        }
        else if(packageSel == 'B'|| packageSel == 'b'){   //This will execute if the user enters characters 'b' or 'B'
        bc.setPackage('b');      //Sends the character 'b' to the MonthlyBill class to let the user know they've selected package B.
        System.out.println("\nHow many hours will be used?: ");  //This prompts the user to enter the amount of hours used.
        hours = input.nextDouble();   //User enters the amount of hours used here.
        System.out.println();    //The following two lines create a dividing line on the screen to clean things up.
        System.out.println("_________________________________________________________________");
        bc.calculate('b',hours); //Sends the package selected along with the hours entered by the user to be calculated in the MonthlyBill class.
        }
        else if(packageSel == 'c' || packageSel == 'C'){  //This will exectue if the user enters characters 'c' or 'C'
        bc.setPackage('c');      //Sends the character 'c' to the MonthlyBill class to let the user know they've selected package C.
        System.out.println("\nHow many hours will be used?: ");  //This prompts the user to enter the amount of hours used.
        hours = input.nextDouble();   //User enters the amount of hours used here.
        System.out.println();    //The following two lines create a dividing line on the screen to clean things up.
        System.out.println("_________________________________________________________________");
        bc.calculate('c',hours);     //Sends the package selected along with the hours entered by the user to be calculated in the MonthlyBill class.
        }
        else {
           System.out.println("ERROR: No such package exists!");  //Statement will excecute if user enters anything but a,b, or c.
        }
        System.out.println("_________________________________________________________________");  //Dividing line.
        System.out.println("\nTo continue, please enter 1:");       //The user has the chance to exit if they
                                                            //enter in a number other than 1.
        goAgain = input.nextInt();      //User inputs number.
    } //End of while loop
      System.out.println("\n\nGoodbye!"); //This is the last message the user will see.
  } //End of main method.
} //End of Driver class.