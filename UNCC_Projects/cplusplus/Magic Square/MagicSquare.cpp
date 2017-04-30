/*
Programmer: Jack Roberts
Program Title: Magic Square Generator
Date: 11/12/2015
This program uses a series of randomly generated numbers to create a 3 x 3 square of numbers in range (1-9) in which when arranged in a series that all columns and rows equal 15 when added together.
*/

//Declaring Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

//Declaring the use of name space std
using namespace std;
int n = 0;
//Function Prototypes
bool checkUnique(int a1, int a2,int a3,int a4,int a5,int a6, int a7, int a8, int a9);
int magicSquare(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

//Main Function
int main()
{
        //Allows the function to return to here if the random numbers generated are the same, or the magic square is not magic.

        Retry:

        //Declares all variables for this scope.
        int uniqueVar, magic;
        char a,b,c,d,e,f;
        int a1 = rand() % 9 + 1;
        int a2 = rand() % 9 + 1;
        int a3 = rand() % 9 + 1;
        int b1 = rand() % 9 + 1;
        int b2 = rand() % 9 + 1;
        int b3 = rand() % 9 + 1;
        int c1 = rand() % 9 + 1;
        int c2 = rand() % 9 + 1;
        int c3 = rand() % 9 + 1;

		if(checkUnique(a1,a2,a3,b1,b2,b3,c1,c2,c3) == true)
			magic = magicSquare(a1,a2,a3,b1,b2,b3,c1,c2,c3);
		else
			goto Retry;


        //If the square generated is magic it will return 0 and the function will exit. If it is not it will go to Retry:
        if(magic == 0)
            return 0;
        else if (magic == 1)
            goto Retry;

	return 0;
}


//Checks all the random numbers to see if any are the same.
bool checkUnique(int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3)
{
    //Conditional statement used to find out if any of the variables are the same.
    if (a1 != a2 && a1 != a3 && a1 != b1 && a1 != b2 && a1 != b3 && a1 != c1 && a1 != c2 && a1 != c3 && a2 != a3 && a2 != b1 && a2 != b2 && a2 != b3 && a2 != c1 && a2 != c2 && a2 != c3 && a3 != b1 && a3 != b2 && a3 != b3 && a3 != c1 && a3 != c2 && a3 != c3 && b1 != b2 && b1 != b3 && b1 != c1 && b3 != c2 && b1 != c3 && b2 != b3 && b2 != c1 && b3 != c2 && b3 != c3 && c1 != c2 && c1 != c3 && c2 != c3)
{
        return true;
}
    else{
		return false;
    }
}

//Assembles the Magic Square and checks to see if it is in fact magic.
int magicSquare(int a1, int a2, int a3, int b1, int b2, int b3, int c1, int c2, int c3)
{

		//Declares the array rows and columns.
        int a = a1 + a2 + a3;
        int b = b1 + b2 + b3;
        int c = c1 + c2 + c3;
        int d = a3 + b3 + c3;
        int e = a2 + b2 + c2;
        int f = a1 + b1 + c1;
        int g = a1 + b2 + c3;
        int h = a3 + b2 + c1;

        //2d array is declared.
        int numbers[3][3] = {{a1, a2, a3},{b1, b2, b3},{c1, c2, c3}};

        //Conditional statements that will execute if the rows and columns equal 15.
        if(a == 15 && b == 15 && c == 15 && d == 15 && e == 15 && f == 15 && g == 15 && h == 15)
        {
            cout << numbers[0][0] << " " << numbers[0][1] << " " << numbers[0][2] << "\n" << numbers[1][0] << " " << numbers[1][1] << " " <<numbers[1][2] << "\n" << numbers[2][0] << " " << numbers[2][1] << " " << numbers[2][2];
            cout << "\nThis is a magic square!" << endl;
            system("pause");
            return 0;
        }

        //If the square is not magic this will recreate more random numbers and try again.
        else if (a != 15)
        {
            cout << numbers[0][0] << " " << numbers[0][1] << " " << numbers[0][2] << "\n" << numbers[1][0] << " " << numbers[1][1] << " " <<numbers[1][2] << "\n" << numbers[2][0] << " " << numbers[2][1] << " " << numbers[2][2];
            cout << "\nThis is not a magic square!" << endl;
            return 1;
        }
}
