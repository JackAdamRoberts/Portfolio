/*
Program: Encounter at Farpoint
Author: Jack Roberts
Date: 12/03/2015
Purpose:
*/
//Libraries
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstdlib>
//Namespace
using namespace std;
//Globals
double t = static_cast<double>(time(0));
//Function Prototypes
double dollar2LatiumSlip(double usd);
double latinumSlip2Dollar(double gold, double silver);
double starDate();
double calculate(double bushels, double wheatValueUS);
int findYearlyAvg();
int findMonthlyAvg();
int printTicket(double bushels, double latinumSlipValue, double shipmentValueUS, int handlingBars, int handlingStripsR, int handlingSlipsR, int customsCharge, int shippingBars, int shippingStripsR, int shippingSlipsR, int marketBars, int marketStripsR, int marketSlipsR);
int findShipment(int month, int year);
double getWheat(int month, int year, int day);
double getGold(int month, int year, int day);
double getSilver(int month, int year, int day);
int latinumSlip(int latinumSlip);
int latinumStrip(int latinumSlip);
int latinumBar(int latinumStrip);
int menu();
//Main Function
int main(){
	int choice = 0;
	choice = menu();
	if (choice == 1){
			//Declare Variables
				int month, year, day = 0, arrayValueMonth, arrayValueYear, bushelsPurchased, handlingSlips, handlingSlipsR, handlingStrips, handlingStripsR, handlingBars, shippingSlips, shippingSlips1, shippingSlipsR, shippingStrips, shippingStripsR, shippingBars, marketLatinum, totalSlips, marketSlips, marketSlipsR, marketStrips, marketStripsR, marketBars;
				double wheatValueUS, gold, silver, latinumSlipValue, shipmentValueUS;
			Return:
			//Clears the screen to make everything look cleaner.
				if (system("CLS")) system("clear");
			//Prints the input statements
				cout << "Welcome to the USS Zippy Database\n" << endl;
				cout << "What month were you looking for?(1-12): ";
				cin >> month;
				cout << "What year were you searching for?(2005-2015): ";
				cin >> year;

				if (month > 12 || month < 0 || year < 2005 || year > 2015){
					cout << "One of your inputs was invalid, please try again!" << endl;
					goto Return;
				}
			//Allows the array to read the value correctly.
				arrayValueYear = year - 2005;
				arrayValueMonth = month - 1;
			//Gets the price of wheat, silver, and gold at a particular time.
				wheatValueUS = getWheat(arrayValueMonth, arrayValueYear, day);
				silver = getSilver(month, year, day);
				gold = getGold(month, year, day);
			//Finds the amount of bushels sold for a particular month and year.
				bushelsPurchased = findShipment(arrayValueMonth,arrayValueYear);
			//Finds the value of a latium
				latinumSlipValue = latinumSlip2Dollar(gold,silver);
			//Finds the total US value of the shipment.
				shipmentValueUS = calculate(bushelsPurchased,wheatValueUS);
			//Finds the market value in B.b.s
				totalSlips = shipmentValueUS / latinumSlipValue;
				marketStrips = totalSlips / 100;
				marketSlipsR = totalSlips % 100;
				marketBars = marketStrips / 20;
				marketStripsR = marketStrips % 20;
			//CustomsCost
				int customsCharge = 1;
			//Finds the cost of the handling in B.b.s
				handlingSlips = bushelsPurchased / 5;
				handlingSlipsR = bushelsPurchased % 5;
				handlingStrips = handlingSlips / 100;
				handlingStripsR = handlingStrips % 20;
				handlingBars = handlingStrips / 20;
			//Finds the shipping cost in B.b.s
				shippingSlips = handlingSlips * .02;
				shippingSlips1 = shippingSlips / 5;
				shippingSlipsR = shippingSlips1 % 5;
				shippingStrips = shippingSlips / 100;
				shippingStripsR = shippingStrips % 20;
				shippingBars = shippingStrips / 20;
			//Prints the ticket with all corresponding info.
				handlingSlips = bushelsPurchased / 5;
				handlingSlipsR = bushelsPurchased % 5;
				handlingStrips = handlingSlips / 100;
				handlingStripsR = handlingStrips % 20;
				handlingBars = handlingStrips / 20;
			//Prints the result of the search
				printTicket(bushelsPurchased, latinumSlipValue, shipmentValueUS, handlingBars, handlingStripsR, handlingSlipsR, customsCharge, shippingBars, shippingStripsR, shippingSlipsR, marketBars, marketStripsR, marketSlipsR);
}
	//Sends the user to view the yearly averages
	if (choice == 2){
		findYearlyAvg();
	}
	//Sends the user to view the monthly averages
	if (choice == 3){
		findMonthlyAvg();
	}
return 0;
}
int menu(){
	//Clears the screen to make everything look cleaner.
    if (system("CLS")) system("clear");
    //Declares variables
	int choice;
	//Prints the menu
	cout << "What would you like to do?" << endl;
	cout << "1) Find shipment receipt" << endl;
	cout << "2) Check yearly averages" << endl;
	cout << "3) Check monthly averages" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	//Returns the users choice.
	return choice;
}
//Searches the file for the date.
int findShipment(int month,int year){
	//Takes the values from the file into a readable array.
	ifstream file;
	file.open("ShipmentInfo.txt", ios::in | ios::out);
	int myArray[12][10];
		cout << endl << endl;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 12; j++){
			file >> myArray[j][i];
			}
		}
	file.close();
	//Returns the array.
	return myArray[month][year];

}
//Function	to	convert	dollar	to	latium	slip.
double dollar2LatiumSlip(double usd){
		//Declare Variables
		double bbsSilver, bbsGold, latinumSlip;
		//converts the ounces of silver and gold into their respective proportions.
		bbsSilver = getGold(0,0,0) / 3;
		bbsGold = getSilver(0,0,0) / 1000;
		//latinumslip is then added to the bbs values for gold and silver
		latinumSlip = bbsGold + bbsSilver;
		//Returns it so that it can be seen in the ticket.
		return latinumSlip;
}
double latinumSlip2Dollar(double gold, double silver){
		//Declare Variables
		double bbsSilver, bbsGold, usvaluelatinumSlip;
		//converts the ounces of silver and gold into their respective proportions.
		bbsSilver = getSilver(0,0,0) / 3;
		bbsGold = getGold(0,0,0)/ 1000;
		//latinumslip is then added to the bbs values for gold and silver
		usvaluelatinumSlip = bbsGold + bbsSilver;
		//Returns it so that it can be seen in the ticket.
		return usvaluelatinumSlip;
}
//Function	to	convert	current	date	to	starDate.
double starDate(){
	//Finds the stardate
	int SECS_PER_YEAR = 31556926;
	double starDate1 = t / (SECS_PER_YEAR + 1970);
	//returns the value of stardate
	return starDate1;
}
//Function	to	calculate	the	total	shipment.
double calculate(double bushels, double wheatValueUS){
	//Declares the variables.
	double bushelQuantities, costofShipment;
	//Converts bushels into bushel quantities.
	bushelQuantities = bushels / 5000;
	//Calculates the cost of the shipment based on us values of wheat.
	costofShipment = bushels * wheatValueUS;
	//Returns the shipment cost.
	return costofShipment;

}
//Function	to	determine	the	average	of	the	cost	per	year.
int findYearlyAvg(){
	//Reads all the order information into arrays that will be used to determine the US dollar and B.b.s values.
	ifstream file;
	file.open("ShipmentInfo.txt", ios::in | ios::out);
	float myArray[12][10];
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 12; j++){
			file >> myArray[j][i];
			}
		}
	file.close();
//Finds the US dollar value for all the months of each year.
float a2005 = ((myArray[0][0] * getWheat(0,0,0)) + (myArray[0][1] * getWheat(0,0,0)) + (myArray[0][2] * getWheat(0,0,0))  + (myArray[0][3] * getWheat(0,0,0))  + (myArray[0][4] * getWheat(0,0,0))  + (myArray[0][5] * getWheat(0,0,0))  + (myArray[0][6] * getWheat(0,0,0))  + (myArray[0][7] * getWheat(0,0,0))  + (myArray[0][8] * getWheat(0,0,0))  + (myArray[0][9] * getWheat(0,0,0))  + (myArray[0][10] * getWheat(0,0,0))  + (myArray[0][11] * getWheat(0,0,0)) )/12;
float a2006 = ((myArray[1][0] * getWheat(0,0,0)) + (myArray[1][1] * getWheat(0,0,0)) + (myArray[1][2] * getWheat(0,0,0))  + (myArray[1][3] * getWheat(0,0,0))  + (myArray[1][4] * getWheat(0,0,0))  + (myArray[1][5] * getWheat(0,0,0))  + (myArray[1][6] * getWheat(0,0,0))  + (myArray[1][7] * getWheat(0,0,0))  + (myArray[1][8] * getWheat(0,0,0))  + (myArray[1][9] * getWheat(0,0,0))  + (myArray[1][10] * getWheat(0,0,0))  + (myArray[1][11] * getWheat(0,0,0)))/12;
float a2007 = ((myArray[2][0] * getWheat(0,0,0)) + (myArray[2][1] * getWheat(0,0,0)) + (myArray[2][2] * getWheat(0,0,0)) + (myArray[2][3] * getWheat(0,0,0)) + (myArray[2][4] * getWheat(0,0,0)) + (myArray[2][5] * getWheat(0,0,0)) + (myArray[2][6] * getWheat(0,0,0)) + (myArray[2][7] * getWheat(0,0,0)) + (myArray[2][8] * getWheat(0,0,0)) + (myArray[2][9] * getWheat(0,0,0)) + (myArray[2][10] * getWheat(0,0,0)) + (myArray[2][11] * getWheat(0,0,0)))/12;
float a2008 = ((myArray[3][0] * getWheat(0,0,0)) + (myArray[3][1] * getWheat(0,0,0)) + (myArray[3][2] * getWheat(0,0,0)) + (myArray[3][3] * getWheat(0,0,0)) + (myArray[3][4] * getWheat(0,0,0)) + (myArray[3][5] * getWheat(0,0,0)) + (myArray[3][6] * getWheat(0,0,0)) + (myArray[3][7] * getWheat(0,0,0)) + (myArray[3][8] * getWheat(0,0,0)) + (myArray[3][9] * getWheat(0,0,0)) + (myArray[3][10] * getWheat(0,0,0)) + (myArray[3][11] * getWheat(0,0,0)))/12;
float a2009 = ((myArray[4][0] * getWheat(0,0,0)) + (myArray[4][1] * getWheat(0,0,0)) + (myArray[4][2] * getWheat(0,0,0)) + (myArray[4][3] * getWheat(0,0,0)) + (myArray[4][4] * getWheat(0,0,0)) + (myArray[4][5] * getWheat(0,0,0)) + (myArray[4][6] * getWheat(0,0,0)) + (myArray[4][7] * getWheat(0,0,0)) + (myArray[4][8] * getWheat(0,0,0)) + (myArray[4][9] * getWheat(0,0,0)) + (myArray[4][10] * getWheat(0,0,0)) + (myArray[4][11] * getWheat(0,0,0)))/12;
float a2010 = ((myArray[5][0] * getWheat(0,0,0)) + (myArray[5][1] * getWheat(0,0,0)) + (myArray[5][2] * getWheat(0,0,0)) + (myArray[5][3] * getWheat(0,0,0)) + (myArray[5][4] * getWheat(0,0,0)) + (myArray[5][5] * getWheat(0,0,0)) + (myArray[5][6] * getWheat(0,0,0)) + (myArray[5][7] * getWheat(0,0,0)) + (myArray[5][8] * getWheat(0,0,0)) + (myArray[5][9] * getWheat(0,0,0)) + (myArray[5][10] * getWheat(0,0,0)) + (myArray[5][11] * getWheat(0,0,0)))/12;
float a2011 = ((myArray[6][0] * getWheat(0,0,0)) + (myArray[6][1] * getWheat(0,0,0)) + (myArray[6][2] * getWheat(0,0,0)) + (myArray[6][3] * getWheat(0,0,0)) + (myArray[6][4] * getWheat(0,0,0)) + (myArray[6][5] * getWheat(0,0,0)) + (myArray[6][6] * getWheat(0,0,0)) + (myArray[6][7] * getWheat(0,0,0)) + (myArray[6][8] * getWheat(0,0,0)) + (myArray[6][9] * getWheat(0,0,0)) + (myArray[6][10] * getWheat(0,0,0)) + (myArray[6][11] * getWheat(0,0,0)))/12;
float a2012 = ((myArray[7][0] * getWheat(0,0,0)) + (myArray[7][1] * getWheat(0,0,0)) + (myArray[7][2] * getWheat(0,0,0)) + (myArray[7][3] * getWheat(0,0,0)) + (myArray[7][4] * getWheat(0,0,0)) + (myArray[7][5] * getWheat(0,0,0)) + (myArray[7][6] * getWheat(0,0,0)) + (myArray[7][7] * getWheat(0,0,0)) + (myArray[7][8] * getWheat(0,0,0)) + (myArray[7][9] * getWheat(0,0,0)) + (myArray[7][10] * getWheat(0,0,0)) + (myArray[7][11] * getWheat(0,0,0)))/12;
float a2013 = ((myArray[8][0] * getWheat(0,0,0)) + (myArray[8][1] * getWheat(0,0,0)) + (myArray[8][2] * getWheat(0,0,0)) + (myArray[8][3] * getWheat(0,0,0)) + (myArray[8][4] * getWheat(0,0,0)) + (myArray[8][5] * getWheat(0,0,0)) + (myArray[8][6] * getWheat(0,0,0)) + (myArray[8][7] * getWheat(0,0,0)) + (myArray[8][8] * getWheat(0,0,0)) + (myArray[8][9] * getWheat(0,0,0)) + (myArray[8][10] * getWheat(0,0,0)) + (myArray[8][11] * getWheat(0,0,0)))/12;
float a2014 = ((myArray[9][0] * getWheat(0,0,0)) + (myArray[9][1] * getWheat(0,0,0)) + (myArray[9][2] * getWheat(0,0,0)) + (myArray[9][3] * getWheat(0,0,0)) + (myArray[9][4] * getWheat(0,0,0)) + (myArray[9][5] * getWheat(0,0,0)) + (myArray[9][6] * getWheat(0,0,0)) + (myArray[9][7] * getWheat(0,0,0)) + (myArray[9][8] * getWheat(0,0,0)) + (myArray[9][9] * getWheat(0,0,0)) + (myArray[9][10] * getWheat(0,0,0)) + (myArray[9][11] * getWheat(0,0,0)))/12;
float a2015 = ((myArray[10][0] * getWheat(0,0,0)) + (myArray[10][1] * getWheat(0,0,0)) + (myArray[10][2] * getWheat(0,0,0)) + (myArray[10][3] * getWheat(0,0,0)) + (myArray[10][4] * getWheat(0,0,0)) + (myArray[10][5] * getWheat(0,0,0)) + (myArray[10][6] * getWheat(0,0,0)) + (myArray[10][7] * getWheat(0,0,0)) + (myArray[10][8] * getWheat(0,0,0)) + (myArray[10][9] * getWheat(0,0,0)) + (myArray[10][10] * getWheat(0,0,0)) + (myArray[10][11] * getWheat(0,0,0)))/12;
//Converts US dollars to latinum slips to be converted into official B.b.s values.
int latinumSlip1 = a2005 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip2 = a2006 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip3 = a2007 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip4 = a2008 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip5 = a2009 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip6 = a2010 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip7 = a2011 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip8 = a2012 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip9 = a2013 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip10 = a2014 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip11 = a2015 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
//Declares the variables that will be used to convert US dollars to B.b.s
int latinumStrips1, latinumStrips2, latinumStrips3, latinumStrips4, latinumStrips5, latinumStrips6, latinumStrips7, latinumStrips8, latinumStrips9, latinumStrips10, latinumStrips11;
int latinumSlip1R,  latinumSlip2R, latinumSlip3R, latinumSlip4R, latinumSlip5R, latinumSlip6R, latinumSlip7R, latinumSlip8R, latinumSlip9R, latinumSlip10R, latinumSlip11R;
int latinumStrips1R,  latinumStrips2R, latinumStrips3R, latinumStrips4R, latinumStrips5R, latinumStrips6R, latinumStrips7R, latinumStrips8R, latinumStrips9R, latinumStrips10R, latinumStrips11R;
int latinumBars1, latinumBars2, latinumBars3, latinumBars4, latinumBars5, latinumBars6, latinumBars7, latinumBars8, latinumBars9, latinumBars10, latinumBars11;
//Converts latinum slips to latinum strips.
latinumStrips1 = latinumSlip1 / 100;
latinumStrips2 = latinumSlip2 / 100;
latinumStrips3 = latinumSlip3 / 100;
latinumStrips4 = latinumSlip4 / 100;
latinumStrips5 = latinumSlip5 / 100;
latinumStrips6 = latinumSlip6 / 100;
latinumStrips7 = latinumSlip7 / 100;
latinumStrips8 = latinumSlip8 / 100;
latinumStrips9 = latinumSlip9 / 100;
latinumStrips10 = latinumSlip10 / 100;
latinumStrips11 = latinumSlip11 / 100;
//Displays the yearly average for the orders of wheat in US dollars and B.b.s currencies.
cout << "Year               Average(USD)        Latinum Value (B.b.s)" << endl;
cout << "_____________________________________________________________" << endl;
cout << "2005                 $" << a2005 << "                   " << latinumBar(latinumStrips1) << "." << latinumStrip(latinumSlip1) << "." << latinumSlip(latinumSlip1) << endl;
cout << "2006                 $" << a2006 << "                  " << latinumBar(latinumStrips2) << "." << latinumStrip(latinumSlip2) << "." << latinumSlip(latinumSlip2) << endl;
cout << "2007                 $" << a2007 << "                   " << latinumBar(latinumStrips3) << "." << latinumStrip(latinumSlip3) << "." << latinumSlip(latinumSlip3) << endl;
cout << "2008                 $" << a2008 << "                  " << latinumBar(latinumStrips4) << "." << latinumStrip(latinumSlip4) << "." << latinumSlip(latinumSlip4) << endl;
cout << "2009                 $" << a2009 << "                   " << latinumBar(latinumStrips5) << "." << latinumStrip(latinumSlip5) << "." << latinumSlip(latinumSlip5) << endl;
cout << "2010                 $" << a2010 << "                  " << latinumBar(latinumStrips6) << "." << latinumStrip(latinumSlip6) << "." << latinumSlip(latinumSlip6) << endl;
cout << "2011                 $" << a2011 << "                  " << latinumBar(latinumStrips7) << "." << latinumStrip(latinumSlip7) << "." << latinumSlip(latinumSlip7) << endl;
cout << "2012                 $" << a2012 << "                   " << latinumBar(latinumStrips8) << "." << latinumStrip(latinumSlip8) << "." << latinumSlip(latinumSlip8) << endl;
cout << "2013                 $" << a2013 << "                 " << latinumBar(latinumStrips9) << "." << latinumStrip(latinumSlip9) << "." << latinumSlip(latinumSlip9) << endl;
cout << "2014                 $" << a2014 << "                   " << latinumBar(latinumStrips10) << "." << latinumStrip(latinumSlip10) << "." << latinumSlip(latinumSlip10) << endl;
cout << "2015                 $" << a2015 << "                 " << latinumBar(latinumStrips11) << "." << latinumStrip(latinumSlip11) << "." << latinumSlip(latinumSlip11) << endl;
}
//Function	to	determine	the	average	of	the	cost	for	each	month	for	all	10	years.
int findMonthlyAvg(){

ifstream file;
	file.open("ShipmentInfo.txt", ios::in | ios::out);
	float myArray[12][10];
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 12; j++){
			file >> myArray[j][i];
			}
		}
	file.close();
//Finding the averages for the months in US dollars.
double usdAverage1 = ((myArray[0][0] * getWheat(0,0,0)) + (myArray[1][0] * getWheat(0,0,0)) + (myArray[2][0] * getWheat(0,0,0)) + (myArray[3][0] * getWheat(0,0,0)) + (myArray[4][0] * getWheat(0,0,0)) + (myArray[5][0] * getWheat(0,0,0)) + (myArray[6][0] * getWheat(0,0,0)) + (myArray[7][0] * getWheat(0,0,0)) + (myArray[8][0] * getWheat(0,0,0)) + (myArray[9][0] * getWheat(0,0,0)) + (myArray[10][0] * getWheat(0,0,0))) / 10;
double usdAverage2 = ((myArray[0][1] * getWheat(0,0,0)) + (myArray[1][1] * getWheat(0,0,0)) + (myArray[2][1] * getWheat(0,0,0)) + (myArray[3][1] * getWheat(0,0,0)) + (myArray[4][1] * getWheat(0,0,0)) + (myArray[5][1] * getWheat(0,0,0)) + (myArray[6][1] * getWheat(0,0,0)) + (myArray[7][1] * getWheat(0,0,0)) + (myArray[8][1] * getWheat(0,0,0)) + (myArray[9][1] * getWheat(0,0,0)) + (myArray[10][1] * getWheat(0,0,0))) / 10;
double usdAverage3 = ((myArray[0][2] * getWheat(0,0,0)) + (myArray[1][2] * getWheat(0,0,0)) + (myArray[2][2] * getWheat(0,0,0)) + (myArray[3][2] * getWheat(0,0,0)) + (myArray[4][2] * getWheat(0,0,0)) + (myArray[5][2] * getWheat(0,0,0)) + (myArray[6][2] * getWheat(0,0,0)) + (myArray[7][2] * getWheat(0,0,0)) + (myArray[8][2] * getWheat(0,0,0)) + (myArray[9][2] * getWheat(0,0,0)) + (myArray[10][2] * getWheat(0,0,0))) / 10;
double usdAverage4 = ((myArray[0][3] * getWheat(0,0,0)) + (myArray[1][3] * getWheat(0,0,0)) + (myArray[2][3] * getWheat(0,0,0)) + (myArray[3][3] * getWheat(0,0,0)) + (myArray[4][3] * getWheat(0,0,0)) + (myArray[5][3] * getWheat(0,0,0)) + (myArray[6][3] * getWheat(0,0,0)) + (myArray[7][3] * getWheat(0,0,0)) + (myArray[8][3] * getWheat(0,0,0)) + (myArray[9][3] * getWheat(0,0,0)) + (myArray[10][3] * getWheat(0,0,0))) / 10;
double usdAverage5 = ((myArray[0][4] * getWheat(0,0,0)) + (myArray[1][4] * getWheat(0,0,0)) + (myArray[2][4] * getWheat(0,0,0)) + (myArray[3][4] * getWheat(0,0,0)) + (myArray[4][4] * getWheat(0,0,0)) + (myArray[5][4] * getWheat(0,0,0)) + (myArray[6][4] * getWheat(0,0,0)) + (myArray[7][4] * getWheat(0,0,0)) + (myArray[8][4] * getWheat(0,0,0)) + (myArray[9][4] * getWheat(0,0,0)) + (myArray[10][4] * getWheat(0,0,0))) / 10;
double usdAverage6 = ((myArray[0][5] * getWheat(0,0,0)) + (myArray[1][5] * getWheat(0,0,0)) + (myArray[2][5] * getWheat(0,0,0)) + (myArray[3][5] * getWheat(0,0,0)) + (myArray[4][5] * getWheat(0,0,0)) + (myArray[5][5] * getWheat(0,0,0)) + (myArray[6][5] * getWheat(0,0,0)) + (myArray[7][5] * getWheat(0,0,0)) + (myArray[8][5] * getWheat(0,0,0)) + (myArray[9][5] * getWheat(0,0,0)) + (myArray[10][5] * getWheat(0,0,0))) / 10;
double usdAverage7 = ((myArray[0][6] * getWheat(0,0,0)) + (myArray[1][6] * getWheat(0,0,0)) + (myArray[2][6] * getWheat(0,0,0)) + (myArray[3][6] * getWheat(0,0,0)) + (myArray[4][6] * getWheat(0,0,0)) + (myArray[5][6] * getWheat(0,0,0)) + (myArray[6][6] * getWheat(0,0,0)) + (myArray[7][6] * getWheat(0,0,0)) + (myArray[8][6] * getWheat(0,0,0)) + (myArray[9][6] * getWheat(0,0,0)) + (myArray[10][6] * getWheat(0,0,0))) / 10;
double usdAverage8 = ((myArray[0][7] * getWheat(0,0,0)) + (myArray[1][7] * getWheat(0,0,0)) + (myArray[2][7] * getWheat(0,0,0)) + (myArray[3][7] * getWheat(0,0,0)) + (myArray[4][7] * getWheat(0,0,0)) + (myArray[5][7] * getWheat(0,0,0)) + (myArray[6][7] * getWheat(0,0,0)) + (myArray[7][7] * getWheat(0,0,0)) + (myArray[8][7] * getWheat(0,0,0)) + (myArray[9][7] * getWheat(0,0,0)) + (myArray[10][7] * getWheat(0,0,0))) / 10;
double usdAverage9 = ((myArray[0][8] * getWheat(0,0,0)) + (myArray[1][8] * getWheat(0,0,0)) + (myArray[2][8] * getWheat(0,0,0)) + (myArray[3][8] * getWheat(0,0,0)) + (myArray[4][8] * getWheat(0,0,0)) + (myArray[5][8] * getWheat(0,0,0)) + (myArray[6][8] * getWheat(0,0,0)) + (myArray[7][8] * getWheat(0,0,0)) + (myArray[8][8] * getWheat(0,0,0)) + (myArray[9][8] * getWheat(0,0,0)) + (myArray[10][8] * getWheat(0,0,0))) / 10;
double usdAverage10 = ((myArray[0][9] * getWheat(0,0,0)) + (myArray[1][9] * getWheat(0,0,0)) + (myArray[2][9] * getWheat(0,0,0)) + (myArray[3][9] * getWheat(0,0,0)) + (myArray[4][9] * getWheat(0,0,0)) + (myArray[5][9] * getWheat(0,0,0)) + (myArray[6][9] * getWheat(0,0,0)) + (myArray[7][9] * getWheat(0,0,0)) + (myArray[8][9] * getWheat(0,0,0)) + (myArray[9][9] * getWheat(0,0,0)) + (myArray[10][9] * getWheat(0,0,0))) / 10;
double usdAverage11 = ((myArray[0][10] * getWheat(0,0,0)) + (myArray[1][10] * getWheat(0,0,0)) + (myArray[2][10] * getWheat(0,0,0)) + (myArray[3][10] * getWheat(0,0,0)) + (myArray[4][10] * getWheat(0,0,0)) + (myArray[5][10] * getWheat(0,0,0)) +(myArray[6][10] * getWheat(0,0,0)) + (myArray[7][10] * getWheat(0,0,0)) + (myArray[8][10] * getWheat(0,0,0)) + (myArray[9][10] * getWheat(0,0,0)) + (myArray[10][10] * getWheat(0,0,0))) / 10;
double usdAverage12 = ((myArray[0][0] * getWheat(0,0,0)) + (myArray[1][0] * getWheat(0,0,0)) + (myArray[2][0] * getWheat(0,0,0)) + (myArray[3][0] * getWheat(0,0,0)) + (myArray[4][0] * getWheat(0,0,0)) + (myArray[5][0] * getWheat(0,0,0)) + (myArray[6][0] * getWheat(0,0,0)) + (myArray[7][0] * getWheat(0,0,0)) + (myArray[8][0] * getWheat(0,0,0)) + (myArray[9][0] * getWheat(0,0,0)) + (myArray[10][11] * getWheat(0,0,0))) / 10;
//Then converts the US dollars to Latinum Slips.
int latinumSlip1 = usdAverage1 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip2 = usdAverage2 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip3 = usdAverage3 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip4 = usdAverage4 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip5 = usdAverage5 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip6 = usdAverage6 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip7 = usdAverage7 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip8 = usdAverage8 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip9 = usdAverage9 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip10 = usdAverage10 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip11 = usdAverage11 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
int latinumSlip12 = usdAverage12 / (getGold(0,0,0)/1000 + getSilver(0,0,0)/3);
//Declaration of the variables that will be used to split the latinum slips into B.b.s currency.
int latinumStrips1, latinumStrips2, latinumStrips3, latinumStrips4, latinumStrips5, latinumStrips6, latinumStrips7, latinumStrips8, latinumStrips9, latinumStrips10, latinumStrips11, latinumStrips12;
int latinumSlip1R,  latinumSlip2R, latinumSlip3R, latinumSlip4R, latinumSlip5R, latinumSlip6R, latinumSlip7R, latinumSlip8R, latinumSlip9R, latinumSlip10R, latinumSlip11R, latinumSlip12R;
int latinumStrips1R,  latinumStrips2R, latinumStrips3R, latinumStrips4R, latinumStrips5R, latinumStrips6R, latinumStrips7R, latinumStrips8R, latinumStrips9R, latinumStrips10R, latinumStrips11R, latinumStrips12R;
int latinumBars1, latinumBars2, latinumBars3, latinumBars4, latinumBars5, latinumBars6, latinumBars7, latinumBars8, latinumBars9, latinumBars10, latinumBars11, latinumBars12;
//Converting latinum slips to strips so that the following functions can use them.
latinumStrips1 = latinumSlip1 / 100;
latinumStrips2 = latinumSlip2 / 100;
latinumStrips3 = latinumSlip3 / 100;
latinumStrips4 = latinumSlip4 / 100;
latinumStrips5 = latinumSlip5 / 100;
latinumStrips6 = latinumSlip6 / 100;
latinumStrips7 = latinumSlip7 / 100;
latinumStrips8 = latinumSlip8 / 100;
latinumStrips9 = latinumSlip9 / 100;
latinumStrips10 = latinumSlip10 / 100;
latinumStrips11 = latinumSlip11 / 100;
latinumStrips12 = latinumSlip12 / 100;
//Displays the average prices for each month for all 10 years.
cout << "\n\nMonth(2005-2015)       Average(USD)          Latinum Value(B.b.s)" << endl;
cout << "_____________________________________________________________________" << endl;
cout << "January                  $" << usdAverage1 << "                   " << latinumBar(latinumStrips1) << "." << latinumStrip(latinumSlip1) << "." << latinumSlip(latinumSlip1) << endl;
cout << "February                 $" << usdAverage2 << "                   " << latinumBar(latinumStrips2) << "." << latinumStrip(latinumSlip2) << "." << latinumSlip(latinumSlip2) << endl;
cout << "March                    $" << usdAverage3 << "                    " << latinumBar(latinumStrips3) << "." << latinumStrip(latinumSlip3) << "." << latinumSlip(latinumSlip3) << endl;
cout << "April                    $" << usdAverage4 << "                   " << latinumBar(latinumStrips4) << "." << latinumStrip(latinumSlip4) << "." << latinumSlip(latinumSlip4) << endl;
cout << "May                      $" << usdAverage5 << "                   " << latinumBar(latinumStrips5) << "." << latinumStrip(latinumSlip5) << "." << latinumSlip(latinumSlip5) << endl;
cout << "June                     $" << usdAverage6 << "                   " << latinumBar(latinumStrips6) << "." << latinumStrip(latinumSlip6) << "." << latinumSlip(latinumSlip6) << endl;
cout << "July                     $" << usdAverage7 << "                  " << latinumBar(latinumStrips7) << "." << latinumStrip(latinumSlip7) << "." << latinumSlip(latinumSlip7) << endl;
cout << "August                   $" << usdAverage8 << "                  " << latinumBar(latinumStrips8) << "." << latinumStrip(latinumSlip8) << "." << latinumSlip(latinumSlip8) << endl;
cout << "September                $" << usdAverage9 << "                   " << latinumBar(latinumStrips9) << "." << latinumStrip(latinumSlip9) << "." << latinumSlip(latinumSlip9) << endl;
cout << "October                  $" << usdAverage10 << "                   " << latinumBar(latinumStrips10) << "." << latinumStrip(latinumSlip10) << "." << latinumSlip(latinumSlip10) << endl;
cout << "November                 $" << usdAverage11 << "                   " << latinumBar(latinumStrips11) << "." << latinumStrip(latinumSlip11) << "." << latinumSlip(latinumSlip11) << endl;
cout << "December                 $" << usdAverage12 << "                  " << latinumBar(latinumStrips12) << "." << latinumStrip(latinumSlip12) << "." << latinumSlip(latinumSlip12) << endl;
}
//Finds the remainder of the latinum slips.
int latinumSlip(int latinumSlip){
	int latinumSlip1R;
	latinumSlip1R = latinumSlip % 100;
	return latinumSlip1R;
}
//Finds the remainder of the latinum strips.
int latinumStrip(int latinumSlip){
	int latinumStrips, latinumStripsR;
	latinumStrips = latinumSlip / 100;
	latinumStripsR = latinumStrips % 20;
	return latinumStripsR;
}
//Finds the latinum bars left from the conversion.
int latinumBar(int latinumStrip){
	int latinumBar = 0;
	latinumBar = latinumStrip / 20;
	return latinumBar;
}
//Since WebWorks was not operating correctly, I created this random number generator that creates a random double integer in a range of recent real world prices of a bushel of wheat.
double getWheat(int month, int year, int day){
	double f = (double)rand() / RAND_MAX;
    return 5 + f * (15 - 3);
}
//Since WebWorks was not operating correctly, I created this random number generator that creates a random double integer in a range of recent real world prices of an ounce gold.
double getGold(int month, int year, int day){
	double f = (double)rand() / RAND_MAX;
    return 1200 + f * (1323 - 1200);
}
//Since WebWorks was not operating correctly, I created this random number generator that creates a random double integer in a range of recent real world prices of an ounce silver.
double getSilver(int month, int year, int day){
	double f = (double)rand() / RAND_MAX;
    return 15 + f * (20 - 15);
}
//Prints out the results of the inquiry.
int printTicket(double bushels, double latinumSlipValue, double shipmentValueUS, int handlingBars, int handlingStripsR, int handlingSlipsR, int customsCharge, int shippingBars, int shippingSlipsR, int shippingStripsR, int marketBars, int marketStripsR, int marketSlipsR){
	//Clears the screen to make everything look cleaner.
    if (system("CLS")) system("clear");
    //Prints the ticket.
	cout << "------------------------------------------" << endl;
	cout << "Stardate " << starDate() << endl;
	cout << "Quadrotriticale estimate, USS Zippy" << endl;
	cout << "------------------------------------------" << endl;
	cout << setprecision(10) << "Bushels Purchased                  " << bushels << endl;
	cout << "Market Price                US$ " << setprecision(8) << shipmentValueUS << endl;
	cout << "Value, Latinum Slip            US$  " << setprecision(3) << latinumSlipValue << endl;
	cout << "------------------------------------------" << endl;
	cout << "Market Price                     " << marketBars << " ." << marketStripsR << " ." << marketSlipsR << endl;
	cout << "Customs                          " << "0. " << customsCharge << ". 0" << endl;
	cout << "Handling                         " << handlingBars << ". " << handlingStripsR << ". " << handlingSlipsR << endl;
	cout << "Shipping                         " << shippingBars << ". " << shippingStripsR << ". " << shippingSlipsR << endl;
	cout << "                                ----------" << endl;
	cout << "Total                           " << (marketBars + handlingBars + shippingBars) << " ." << (marketStripsR + handlingStripsR + shippingStripsR) << " ." << (marketSlipsR + handlingSlipsR + shippingSlipsR) << endl;
}
