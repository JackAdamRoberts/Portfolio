import java.util.*;
import java.io.*;
/**
 * Driver tests the Wallpaper Calculator.
 * 
 * @author Jack Roberts
 * @version 1.0
 */
public class Driver
{
    public static void main(String[] args){
        //Declaring the variables and creating the Scanner object to read input by the user.
        Scanner input = new Scanner(System.in);
        double height;
        double width;
        double nWidth;
        double nHeight;
        double nMonitors;
            
        //Prompting the user to enter the wallpaper, and display information.
            System.out.print("\n\nWallpaper Optimizer\nCreated by: Jack Roberts\nVersion: v1.0\n____________________________________\n\nEnter wallpaper width (pixels): ");
            width = input.nextDouble();
            System.out.print("Enter wallpaper height (pixels): ");
            height = input.nextDouble();
            System.out.print("Enter width of the display (pixels): ");
            nWidth = input.nextDouble();
            System.out.print("Enter height of the display (pixels): ");
            nHeight = input.nextDouble();
            System.out.print("Enter # of monitors (pixels): ");
            nMonitors = input.nextDouble();
        
        //Creating the Calculator object.
        Calculator e1 = new Calculator(width,height,nWidth,nHeight,nMonitors);
        
        //Displaying the results.
            System.out.println(e1.toString());
    }
}
