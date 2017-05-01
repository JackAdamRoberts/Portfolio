import java.util.*;
import java.io.*;
/**
 * Calculator is a class that takes an input of wallpaper height, and width as well as display height, width, and number of displays
 * to calculate the largest area of the image that can be cropped to fit the display(s).
 * 
 * @author Jack Roberts 
 * @version v1.0
 */
public class Calculator
{
    //Declaring the global variables to be used by the Calculator class.
    double height;
    double width;
    double nWidth;
    double nHeight;
    double nMonitors;
    double screensRatio;
    double wallpaperRatio;
    /**
     * Overloaded constructor to set the variables equal to the ones the user entered in the driver.
     * 
     * @param width  the width of the image in pixels
     * @param height  the height of the image in pixels
     * @param nWidth  the native width of the display in pixels
     * @param nHeight the native height of the display in pixels
     * @param nMonitors  the number of monitors the user wishes to fill with the image
     * 
     */
    public Calculator(double width, double height, double nWidth, double nHeight, double nMonitors){
        this.height = height;
        this.width = width;
        this.nMonitors = nMonitors;
        this.nHeight = nHeight;
        this.nWidth = nWidth;
        ratioCalc();
        largestSize();
    }
    /**
     * Calculates the ratio of the wallpaper and the screen. ratioCalc() is called multiple times by the largestSize() method 
     * to continuously update the ratio for the conditional statements within largestSize().
     */
    public void ratioCalc(){
        this.screensRatio = (nWidth*nMonitors)/nHeight;
        this.wallpaperRatio = width/height;
    }
    /**
     * Calculates the largest area that can be cropped from the image to fit the display(s) of the user.
     */
    public void largestSize(){
        boolean found = false;
        //do-while loop scales the image down based on the ratio of the image and the required ratio of the displays, until they match.
        do{
            if(wallpaperRatio > screensRatio){
               this.width = width-1;
               ratioCalc();
            }
            if(wallpaperRatio < screensRatio){
               this.height = height-1;
               ratioCalc();
            }
            if(wallpaperRatio == screensRatio){
               found = true;
            }
        }while(found == false);
    }
    /**
     * Returns the results of the calculation.
     * @return      the required area to fill the displays
     */
    public String toString(){
        return ("\n\nResults\n_________________\nWallpaper Dimensions: " + width + " x " + height);
    }
}