/**
 * Monthly bill calculator class calculate the monthly bill based on the package
 * selected and the amount of hours used.
 * 
 * Jack Roberts 
 * 02/08/2016
 */
public class MonthlyBill //Beginning of the MonthlyBill class.
{
   private double cHsaved;             
   private double bill;                         //Declaring the fields 
   private double hoursEx = 0;                  //to be used by the
   private double overageFee = 0;               //MonthlyBill calculator.
   private double packageA = 25.99;
   private double packageB = 35.95;
   private double packageC = 49.00;
   private double ratePA = .48;
   private double ratePB = .65;
   public void setPackage(char packageSel){
       if(packageSel == 'a' || packageSel == 'A'){
          System.out.println("_________________________________________________________________");
          System.out.println("\nPackage A Selected!");                                                  //A series of if statements
       }                                                                                                //will let the user know
       else if(packageSel == 'b' || packageSel == 'B'){                                                 //which package they selected
          System.out.println("_________________________________________________________________");      //based on the incoming char
          System.out.println("\nPackage B Selected!");                                                  //parameter from main.
       }                                                    
       else if(packageSel == 'c' || packageSel == 'C'){
          System.out.println("_________________________________________________________________");
          System.out.println("\nPackage C Selected!");
       }
   }
   public void calculate(char packageSel, double hoursUsed){    //This is where the Driver class sends it's values.
       
       if(packageSel == 'a' || packageSel == 'A'){      //This if statement series calculates the bill for the customer based on the
                                                        //selected package and hours entered by the user.
          
          if(hoursUsed <= 25){                                          //If they use the hours allowed or less
             System.out.println("\n\nYour bill will be $25.99!");       //the customer will see this message.
          }
          else if(hoursUsed > 25 && hoursUsed <= 45.7495){              //If they use more than the hours allowed
             hoursEx = hoursUsed - 25;                                  //the program will calculate the monthly
             overageFee = (hoursEx * ratePA);                           //bill by taking the excess time and multiplying
             bill = overageFee + packageA;                              //it by the overage rate.
             System.out.println("\nExtra fees have been applied for overage: $" + overageFee + "\nYour bill will be: $" + bill);
          }
          else if(hoursUsed > 45.7495 && hoursUsed <= 73){
              hoursEx = hoursUsed - 25;
              overageFee = (hoursEx * ratePB);            //If the customer used over 45.75 and less than 73 hours they will 
              bill = overageFee + packageA;               //be paying over the value of the next package this will let them know just how much.
              cHsaved = bill - packageB;     
              System.out.println("\nExtra fees have been applied for overage: $" + overageFee + "\nYour bill will be: $" + bill);
              System.out.println("You could have saved $" + cHsaved + " if you purchased Package B w/ 45 hours of data.");
          }
          else if(hoursUsed >= 73){               //If the customer used over 73 hours of data the total bill would be
                 cHsaved = bill - packageC;       //more expensive than package C and this will tell them how much they would have saved.
                 System.out.println("You could have saved $" + cHsaved + " if you purchased Package C /w unlimited data.");
             }    
       }
       
       else if(packageSel == 'b' || packageSel == 'B'){      //This if statement series calculates the bill for the customer based on the                           
                                                             //selected package and hours entered by the user.
          
          if(hoursUsed <= 25){                           //If the customer used less than 25 hours and purchased this package they could have
              cHsaved = packageB - packageA;            //saved money by purchasing package A in the first place.
              System.out.println("You would have saved $" + cHsaved + " if you bought Package A.");
          }
          else if(hoursUsed > 25 && hoursUsed < 45){                        
              hoursEx = hoursUsed - 25;                                     
              overageFee = (hoursEx * ratePA);                                 //If they used less than the hours allowed
              bill = overageFee + packageA;                                 //the will be told how much they could have saved by purchasing package A.
              cHsaved = packageB - bill;
              System.out.println("Your bill is $" + packageB + ".");
              System.out.println("You could have saved $" + cHsaved + " if you purchased package A w/ 25 hours of data.");       
          }
          else if(hoursUsed == 45){
              System.out.println("Your bill is $" + packageB + ".");    //If the customer used the hours allowed by the package it will tell them this.
          }
          else if(hoursUsed > 45){                                           //If they use more than the hours allowed
             hoursEx = hoursUsed - 45;                                       //the program will calculate the monthly
             overageFee = (hoursEx * ratePB);                                  //bill by taking the excess time and multiplying
             bill = overageFee + 35.95;                                      //it by the overage rate.
             System.out.println("\nExtra fees have been applied for overage: $" + overageFee + "\nYour bill will be: $" + bill);
             if(hoursUsed >= 65.077){        
                 cHsaved = bill - packageC; //If the customer used over 65.08 hours they will be paying over the value of the next package.
                 System.out.println("\n\nYou could have saved $" + cHsaved + " if you purchased Package C w/ unlimited data.");
             }
          }                                                                             
       }
       
       else if(packageSel == 'c' || packageSel == 'C'){  //If package C was selected the following conditional statments will execute.
           System.out.println("\nYour bill will be $49.00.");   //This will be their bill.
           
           if(hoursUsed > 0 && hoursUsed < 25){     //If the hours used are less than 25 the program will let them know that the customer could have 
               cHsaved = packageC - packageA;       //saved the difference between the price of package A and package B.
               System.out.println("You would could have saved $" + cHsaved + " if you purchased Package A w/ 25 hours of data."); 
           }
           
           else if(hoursUsed >= 25 && hoursUsed < 45.75){
               hoursEx = hoursUsed - 25;                
               overageFee = (hoursEx * ratePA);            //This will tell the customer they could have saved x amount of dollars
               bill = overageFee + packageA;            //if they would have purchased package B at the same amount of hours.
               cHsaved = packageC - bill;
               System.out.println("You could have saved $" + cHsaved + " if you purchased package A w/ 25 hours of data."); 
           }
           
           else if(hoursUsed > 45.75 && hoursUsed < 65.08){  
               hoursEx = hoursUsed - 45;
               overageFee = (hoursEx * ratePB);                 //If they used less than the hours allowed before Package B becomes more expensive than package C
               bill = overageFee + packageB;                 //this will execute to show them how much they could have saved by purchasing Package B in the first place.
               cHsaved = packageC - bill;          
               System.out.println("\nYou could have saved $" + cHsaved + " if you purchased Package B w/ 45 hours of data.");
           }
       }                                                                                  
   }
}