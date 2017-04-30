/*
Program: Banking Program
Programmer: Jack Roberts
Date: 11/17/2015
Description: This program is an ATM system that can store a users banking info by creating an account
and setting up their initial fund as 0. After which the user can deposit money into his/her account
withdraw money from their account, and display the balance of their account.
*/

//Including all the libraries that the program will use.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#ifdef __cplusplus__
#-
#endif


//Declaring the use of namespace std.
using namespace std;

//Declaring the global variables to be used throughout the program.
char choice, choice2;

//Function Prototypes
char mainMenu();
int createAccount();
int Login();
int LoginValidation(string, string);
int bankingMenu(string);
int deposit(string);
int withdraw(string);
int displayBalance(string);

//Main function of the program.
int main()
{
    //Allows the user to return to this point if they accidentally typed something incorrectly.
    Retry:

    //Clears Screen
    if (system("CLS")) system("clear");

    //Declares choice as whatever main m
    char choice = mainMenu();

    //Reading the user's input.
    if (choice == 'c'){
            createAccount();
            goto Retry;
            return 0;
        }
    else if (choice == 'l'){
            Login();
            return 0;
        }
    else if (choice == 'q'){
            cout << "_______________________________________________________________\n" << endl;
            cout << "\n                 Thanks for stopping by!\n" << endl;
            return 0;
        }
    else {
            cout << "\n    ********************* ERROR! ************************" << endl;
            cout << "    *                                                   *" << endl;
            cout << "    *       Invalid Selection! Please Try Again!        *" << endl;
            cout << "    *                                                   *" << endl;
            cout << "    *****************************************************\n" << endl;
            system("pause");
            goto Retry;
        }

    return 0;
}

//Displays the menu.
char mainMenu()
{

    //Declare choice entered.
    char choice;


    //Displays main menu.
    cout << "     Welcome to Future Computer Programmers ATM Machine! " << endl;
    cout << "                 Created by: Jack Roberts" << endl;
    cout << "_______________________________________________________________" << endl;
    cout << "\n        Please select an option from the following:" << endl;
    cout << "\n                     c -> Create User" << endl;
    cout << "                     l -> Login" << endl;
    cout << "                     q -> Quit Program" << endl;
    cout << "\n                  Please enter choice: ";
    cin >> choice;

    cin.clear();

    return choice;
}
//Creates a user account.
int createAccount()
{
    //Declaring the variables to be used by the function.
    bool uservalid = false;
    int a=0, b=0;

    //Declaring/Opening the file to be both written to and read from.
    ifstream file;
    ofstream newuser;
    string username, password, user, pass, passwordconfirm;
    file.open("UsernamePassword.txt", ios::app);
    newuser.open("UsernamePassword.txt", ios::app);

    //Allows the user to enter in their desired account data.
    while (!uservalid){
            if (system("CLS")) system("clear");
            cout << "                  Create An Account                  " << endl;
            cout << "_____________________________________________________" << endl;
            cout << "\n           Set Username: ";
            cin >> username;
            cout << "           Set Password: ";
            cin >> password;
            cout << "       Confirm Password: ";
            cin >> passwordconfirm;

    //Searches to see if a user with the same username already exists.
    while (file >> user >> pass){
            a++;

                if (username != user)

                    b++;
        }

    if(a==b && password == passwordconfirm)
{
        uservalid = true;
        cout << "________________________________________________________" << endl;
        cout << "\n      Thank you! Your account has been created!\n" << endl;
        system("Pause");
}
    else if (a!=b)
        {
            cout << "\n********************* ERROR! ************************" << endl;
            cout << "*                                                   *" << endl;
            cout << "*     There is already a user with this username.   *" << endl;
            cout << "*                                                   *" << endl;
            cout << "*****************************************************\n" << endl;
            b++;
            system("pause");
        }


    //If the password confirmation is not the same as the initial password entered, this will display.
    else
        {
            cout << "\n********************* ERROR! ************************" << endl;
            cout << "*                                                   *" << endl;
            cout << "*         Passwords entered do not match.           *" << endl;
            cout << "*                                                   *" << endl;
            cout << "*****************************************************\n" << endl;
        system("Pause");
        }

    }

    //Writing the new User info into the file.
    newuser << username << " " << password << endl;
    file.close();
    newuser.close();

    //Putting the user information into a map then inserting it into the file with an initial balance of 0.
    fstream newU;
    double amount;
    newU.open("UserAmount.txt", ios::in | ios::out | ios::app);
    map<string, double> accountMap;
    accountMap[username] = 0;
    newU << "\n";
    newU << username;
    newU << " ";
    newU << accountMap[username];
    newU.close();
}

//Allows a currently registered user to login to their account.
int Login()
{
    //Opening the files to be read from for the Login validation;
    ifstream userfile;
    userfile.open("UsernamePassword.txt");

    string user, pass;

    //If the file fails to open, this will display.
    if(!userfile.is_open()){
        cout << "\n     ********************* ERROR! ************************" << endl;
            cout << "     *                                                   *" << endl;
            cout << "     *         Issue Opening The Desired File            *" << endl;
            cout << "     *                                                   *" << endl;
            cout << "     *****************************************************\n" << endl;
            system("Pause");
            main();
    }

    //Sends the user to the banking menu if the login data was correct. If not it will tell the user to try again!
    else{
        while(LoginValidation(user,pass)==0){
            if (system("CLS")) system("clear");
            cout << "                  Login Terminal                     " << endl;
            cout << "_____________________________________________________" << endl;
            cout << "\n             Enter Username: ";
            cin >> user;
            cout << "             Enter Password: ";
            cin >> pass;
            cin.clear();
            if(LoginValidation(user, pass)!=0){
                bankingMenu(user);
                }
            else{
            cout << "\n********************* ERROR! ************************" << endl;
            cout << "*                                                   *" << endl;
            cout << "*       Invalid Login Data! Please Try Again!       *" << endl;
            cout << "*                                                   *" << endl;
            cout << "*****************************************************\n" << endl;
                system("Pause");
            }
            userfile.close();
        }

    }
}

//Checks to see if the login data that the user entered is true, if it is not it will return to the previous login function as a number other than 0 and will prompt the user to try again.
int LoginValidation(string user, string pass)
{

//Initiates the file to be read from.
ifstream file;

//Declares variables for this function
string username, password;
int n=0;

//Opens file to be read from.
file.open("UsernamePassword.txt");

//Begins searching for the username and corresponding password.
if(file.is_open()){
    while(!file.eof()){
        file >> username >> password;
        n++;
        if(user == username && pass == password)
            return n;
        }
}

//Lets the user know that there was an issue opening the file to be checked for login data.
        else{
            cout << "\n********************* ERROR! ************************" << endl;
            cout << "*                                                   *" << endl;
            cout << "*         Issue Opening The Desired File            *" << endl;
            cout << "*                                                   *" << endl;
            cout << "*****************************************************\n" << endl;
        }
    return 0;
}

//This is the banking menu where the user can select what he/she wants to do.
int bankingMenu(string user)
{
    //Allows the user to return to this point if their selection was invalid.
    Retry:
    //Clears the screen to make everything look cleaner.
    if (system("CLS")) system("clear");

    //Declares the variables in this function.
    char choice;

    //Shows the menu.
    cout << "\n                         Access Granted!" << endl;
    cout << "                         Welcome " << user << "!" << endl;
    cout << "\n_________________________________________________________________________\n" << endl;
    cout << "                          Banking Menu                                  " << endl;
    cout << "\n                    What would you like to do?\n" << endl;
    cout << "                       d -> Deposit Money" << endl;
    cout << "                       w -> Withdraw Money" << endl;
    cout << "                       r -> Request Balance" << endl;
    cout << "                       q -> Quit" << endl;

    //User enters choice.
    cout << "\n                    Please enter your choice: ";
    cin >> choice;

    //Determines which menu option was selected by the user.
    if (choice == 'd'){
        deposit(user);
        return 0;
    }
    if (choice == 'w'){
        withdraw(user);
        return 0;
    }
    if (choice == 'r'){
        displayBalance(user);
        return 0;
    }
    if (choice == 'q'){
        return 0;
    }
    else{
        cout << "\n        ********************* ERROR! ************************" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *       Invalid Selection! Please Try Again!        *" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *****************************************************\n" << endl;
            system("Pause");
        goto Retry;
    }

    return 0;
}

//Allows the user to deposit whatever amount they wish to into their account.
int deposit(string user)
{
    //Declaring the variables for this function.
    string name;
    float amount, newamount, deposit;

    //Declares the file that we will be editing.
    fstream file;

    //Opens the file.
    file.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //File to be read.
    fstream fileread;

    //Opens the file.
    fileread.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //Checking to see if the file is open.
    if(fileread.is_open()){

        //Declares the arrays that we will be reading from the file into.
        string myArray[15];
        float myArray1[15];
        int x = 0;

    //Reads the users and their associated balances into arrays to be edited.
    {
        for(int i = 0; i < 15; ++i){
        fileread >> myArray[i] >> myArray1[i];
        }

        //Finds the user that is currently logged in.
        while (x < 15){
            if(myArray[x] == user){

                //Displays current balance and asks how much user wants to deposit.
                cout << "\n__________________________________________________________________________" << endl;
                cout << "\n                              Deposit                                       " << endl;
                cout << "__________________________________________________________________________\n" << endl;
                cout << "\n                      Available Balance: $" << myArray1[x] << endl;
                cout << "\n                    Amount to be Deposited: $";
                cin >> deposit;

                //Adds the deposit amount to the current balance and stores in newamount.
                newamount = myArray1[x] + deposit;

                //newamount then overwrites the current amount in the array and becomes the new balance.
                myArray1[x] = newamount;

                //Displays the new balance.
                cout << "\n                    Balance After Deposit: $" << myArray1[x];
                cout << "\n\n                 Thank you for your deposit, " << myArray[x] << "!";
                break;
            }
            else{
                ++x;
            }
        }
    }

    //Opens the file to be written to.
    ofstream newfile;
    newfile.open("UserAmount.txt", ios::ate);

            //Puts the array back into the file with the edited balance for the user thats logged in.
            for(int i = 0; i < 15; ++i){
            newfile << myArray[i] << " " << myArray1[i] << endl;
            }


    //Closes the files.
    file.close();
    fileread.close();
}

    //Secondary menu allows the user to go back to the banking menu if they wish to do more, or quit if they are finished.
    int choice;

    //Allows the user to come back to this point if invalid entry occurs.
    Retry:
    cout << "\n\n__________________________________________________________________________" << endl;
    cout << "\n\n                     What would you like to do?: " << endl;
    cout << "\n                     1 -> Return to Banking Menu" << endl;
    cout << "                     2 -> Logout of Account" << endl;

    //User enters choice.
    cout << "\n                     Please enter your Choice: ";
    cin >> choice;

        //Program checks choice.
        if (choice == 1){
        bankingMenu(user);
        }
        else if (choice == 2){
        main();
        }
        else{
        cout << "\n        ********************* ERROR! ************************" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *       Invalid Selection! Please Try Again!        *" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *****************************************************\n" << endl;
        goto Retry;
        }

}

//Allows the user to withdraw money from their account.
int withdraw(string user)
{
    //Declares the variables to be used by this function.
    string name;
    float amount, newamount, withdraw;

    //Declares the file that we will be editing.
    fstream file;

    //Opens the file.
    file.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //File to be read.
    fstream fileread;

    //Opens the file.
    fileread.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //Checking to see if the file is open.
    if(fileread.is_open()){

        //Declares the arrays that we will be reading from the file into.
        string myArray[15];
        float myArray1[15];
        int x = 0;

        //Reads the users and their associated balances into arrays to be edited.
        {
        for(int i = 0; i < 15; ++i){
            fileread >> myArray[i] >> myArray1[i];
        }

        //Finds the user that is currently logged in.
        while (x < 15){
            if(myArray[x] == user){

                //Displays current balance and asks how much user wants to withdraw.
                cout << "\n__________________________________________________________________________" << endl;
                cout << "\n                              Withdraw                                       " << endl;
                cout << "__________________________________________________________________________\n" << endl;
                cout << "\n                      Available Balance: $" << myArray1[x] << endl;
                cout << "\n                    Amount to be Withdrawn: $";
                cin >> withdraw;
                newamount = myArray1[x] - withdraw;

                //This is a functionality I wanted to add to prevent the user from over-drafting from their account.
                if(newamount < 0)
                {
                    cout << "\n       *********************** ERROR! ***************************" << endl;
            cout << "       *                                                        *" << endl;
            cout << "       *  Withdraw amount exceeds the balance. Cannot withdraw! *" << endl;
            cout << "       *                                                        *" << endl;
            cout << "       **********************************************************\n" << endl;

                    system("Pause");
                    bankingMenu(user);
                }

                //Displays the new balance.
                else
                {
                    cout << "\n                   The balance will become: $" << newamount;
                    cout <<"\n\n                 Thank you for your withdraw " << myArray[x] << "!";
                    myArray1[x] = newamount;
                }
                break;
            }
            else{
                ++x;
            }
        }
    }

    //Opens the file to be written to.
    ofstream newfile;
    newfile.open("UserAmount.txt", ios::ate);

            //Puts the array back into the file with the edited balance for the user thats logged in.
            for(int i = 0; i < 15; ++i){
            newfile << myArray[i] << " " << myArray1[i] << endl;
            }


    //Closes both files.
    file.close();
    fileread.close();
}

    //Secondary menu allows the user to go back to the banking menu if they wish to do more, or quit if they are finished.
    int choice;
    Retry:
    cout << "\n\n__________________________________________________________________________" << endl;
    cout << "\n\n                     What would you like to do?: " << endl;
    cout << "\n                     1 -> Return to Banking Menu" << endl;
    cout << "                     2 -> Logout of Account" << endl;

    //User enters choice.
    cout << "\n                     Please enter your Choice: ";
    cin >> choice;

    //Determines what the user selected.
    if (choice == 1)
    {
        bankingMenu(user);
    }
    else if (choice == 2)
    {
        main();
    }
    else{
        cout << "\n        ********************* ERROR! ************************" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *       Invalid Selection! Please Try Again!        *" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *****************************************************\n" << endl;
        goto Retry;
        }

}
int displayBalance(string user)
{
    //Declares all variables to be used by the function.
    int choice;
    string name;
    float amount, newamount, deposit;

    //Declares the file that we will be editing.
    fstream file;

    //Opens the file.
    file.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //File to be read.
    fstream fileread;

    //Opens the file.
    fileread.open("UserAmount.txt", ios::in | ios::out | ios::app);

    //Checking to see if the file is open.
    if(fileread.is_open()){

        //Declares the arrays that we will be reading from the file into.
        string myArray[15];
        float myArray1[15];
        int x = 0;

        //Reads the users and their associated balances into arrays to show the current balance of just the user logged in.
        {
        for(int i = 0; i < 15; ++i){
            fileread >> myArray[i] >> myArray1[i];
        }

        //Finds the user that is currently logged in and displays their balance.
        while (x < 15){
            if(myArray[x] == user){

                cout << "\n__________________________________________________________________________" << endl;
                cout << "\n             Current available balance for " << user <<  " is: $" << myArray1[x];
                break;
            }
            else{
                ++x;
            }
        }
        }


    //Closes both files.
    file.close();
    fileread.close();

    //Secondary menu allows the user to go back to the banking menu if they wish to do more, or quit if they are finished.
    cout << "\n\n__________________________________________________________________________" << endl;
    cout << "\n\n                     What would you like to do?: " << endl;
    cout << "\n                     1 -> Return to Banking Menu" << endl;
    cout << "                     2 -> Logout of Account" << endl;

	Return:
    //User enters choice.
    cout << "\n                     Please enter your Choice: ";
    cin >> choice;

    cin.clear();

    //Determines what the user selected.
        if (choice == 1){
            bankingMenu(user);
        }
        else if (choice == 2){
            main();
        }
        else if(choice != 1 || choice != 2){
            cout << "\n        ********************* ERROR! ************************" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *       Invalid Selection! Please Try Again!        *" << endl;
            cout << "        *                                                   *" << endl;
            cout << "        *****************************************************\n" << endl;
        }

        goto Return;
    }
}
