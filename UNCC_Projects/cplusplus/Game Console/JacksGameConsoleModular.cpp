/*
Program: Assignment 1
Programmer: Jack Roberts
Description: This program is a console that lets the user play two different games.
The first one is Rock/Paper/Scissors, and the second game is Dice Roll.
Both games can be accessed by the initial menu choices.
*/

#include <iostream> //Initiates first library as iostream
#include <ctime>  //Allows execution of random number generator
#include <cstdlib>  //Allows execution of random number generator


using namespace std;  //Declares the namespace as std;
int menu(); //This is the starting menu function
int rpsM(); //This is the rock/paper/scissors menu
int dgM(); //This is the dice roll game menu
int dRG(); //This is where the dice roll game is played
string rpsComputer(); //This is where the rock/paper/scissors computer selects its choice
int rpsGame(); //This is where the rock/paper/scissors game is played
int main() //Where the choice of the first menu decides where to go.
{
    int choice1 = menu(); //introduces choice1 as a integer variable to match a condition in the following lines.
    if (choice1 == 1) //This executes the rock/paper/scissors menu
    {
        rpsM(); //calling the rock/paper/scissors menu
    }
    else if (choice1 == 2) //This conditional statement executes the dice roll game menu
    {
        dRG(); //calling the dice roll game menu
    }
    else if (choice1 == 3) //This conditional statement ends the program
    {
        return 0; //returns to main as 0 and ends the program
    }
}
int menu() //this is where the program starts.
{
    int choice1; //integer choice1 is declared for whatever the user chooses in the following menu.

    //Welcome menu
    cout << "Welcome to my Game Console!" << endl;
    cout << "Created by Jack Roberts" << endl;
    cout << "\nWhich game would you like to play?" << endl;
    cout << "1. Rock/Paper/Scissors" << endl;
    cout << "2. Dice Game" << endl;
    cout << "3. Exit" << endl;
    cout << "\nPlease enter your choice: ";
    cin >> choice1;
    return choice1; //returns to menu as an integer choice to be picked up by main.
}
int rpsM() //Rock/Paper/Scissors menu
{
    Replay1: //allows the user to come back to this point in the game if they wish to replay.

    int choice2; //declares the integer of this menu that will be the result of what the user chooses.

    //Rock/Paper/Scissors menu.
    cout << "\n_________________________________\n" << endl;
    cout << "\nWelcome to the Rock/Paper/Scissors Game!" << endl;
    cout << "\nThe Rules of Rock/Paper/Scissors are as follows:" << endl;
    cout << "   Rock beats scissors." << endl;
    cout << "   Scissors beats paper." << endl;
    cout << "   Paper beats rock." << endl;
    cout << "\n\nSelect a number from the following options:" << endl;
    cout << "\n1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "\nPlease enter your choice: ";
    cin >> choice2;


    if (choice2 == 1) //conditional statement stating that if the user selected 1 or "rock" from the menu this code executes.
    {
        cout << "\n_________________________________\n";
        cout << "\nResults:" << endl;
        cout << "\nYou selected: Rock!" << endl;
        cout << "\nComputer Selected: " << rpsComputer() << endl;
    }
    if (choice2 == 2)  //conditional statement stating that if the user selected 1 or "rock" from the menu this code executes.
    {
        cout << "\n_________________________________\n";
        cout << "\nResults:" << endl;
        cout << "\nYou selected: Paper!" << endl;
        cout << "\nComputer Selected: " << rpsComputer() << endl;
    }
    if (choice2 == 3)  //conditional statement stating that if the user selected 1 or "rock" from the menu this code executes.
    {
        cout << "\n_________________________________\n";
        cout << "\nResults:" << endl;
        cout << "\nYou selected: Scissors!" << endl;
        cout << "\nComputer Selected: " << rpsComputer() << endl;
    }

    //The following statements are conditional and allow the user to more easily see if they won lost or tied the computer.
    if (choice2 == 1 && rpsComputer() == "Rock!")
    {
        cout << "\nWe tied!" << endl;
    }
    if (choice2 == 1 && rpsComputer() == "Paper!")
    {
        cout << "\nPaper covers rock! You lose!" << endl;
    }
    if (choice2 == 1 && rpsComputer() == "Scissors!")
    {
        cout << "\nRock crushes scissors! You win!" << endl;
    }
    if (choice2 == 2 && rpsComputer() == "Rock!")
    {
        cout << "\nPaper covers rock! You win!" << endl;
    }
    if (choice2 == 2 && rpsComputer() == "Paper!")
    {
        cout << "\nWe tied!" << endl;
    }
    if (choice2 == 2 && rpsComputer() == "Scissors!")
    {
        cout << "\nScissors cuts paper! You lose!" << endl;
    }
    if (choice2 == 3 && rpsComputer() == "Rock!")
    {
        cout << "\nRock crushes scissors! You lose!" << endl;
    }
    if (choice2 == 3 && rpsComputer() == "Paper!")
    {
        cout << "\nScissors cuts paper! You win!" << endl;
    }
    if (choice2 == 3 && rpsComputer() == "Scissors!")
    {
        cout << "\nWe tied!" << endl;
    }

    // Allows the user to play the game again. If not it will return to as 0 and exit the program.
        int playAgain;
        cout << "\n_________________________________\n" << endl;
        cout << "\nWould you like to play again?" << endl;
        cout << "\n1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "\nPlease enter your choice: ";
        cin >> playAgain;
        if (playAgain == 1)
            {goto Replay1;}
        if (playAgain == 2)
            return 0;
}
//This is where the computer generates a number 1-3 and returns a string to be used by the rpsGame function.
string rpsComputer()
{
    unsigned seed;
    seed = time(0);
    srand(seed);

    int computer = rand () % 3 + 1; //generates a random number between 1 and 3.

    //conditional statements that if met by the random number execute and return the string used by the rpsGame function.
    if (computer == 1)
    {
        return ("Rock!");
    }
    else if (computer == 2)
    {
        return ("Paper!");
    }
    else if (computer == 3)
    {
        return ("Scissors!");
    }
}

//Dice Roll Game
int dRG()
{
    //Declaring the variables in teh dice roll game.
    int dice;
    int i = 0;

    //This is the main menu of the dice roll game, the rules are displayed here.

    cout << "\n____________________________________\n\n" << endl;
    cout << "Welcome to the Dice Roll Game!\n" << endl;
    cout << "\nThe rules are:" << endl;
    cout << "The program randomly generates a number between 1 and 6 (Numbers on a Die)\n   You get 10 points if you roll two dice and get a 7.\n   You get 5 points if you roll two dice and get identical numbers.\n   You get 3 points if you roll one die and get a 4" << endl;
    Retry2:
    cout << "\nGame Choices:" << endl;
    cout << "   1. Roll only one die." << endl;
    cout << "   2. Roll two dice." << endl;
    cout << "   3. Exit" << endl;
    cout << "Please enter your choice: ";
    cin >> dice;

    srand((int)time(0)); //This is the random number generator for the dice that will be rolled.

    if (dice == 1) //Executes if the user wants to roll only one die creating one random number between 1-6.

        {while (i++ < 1)
        {
            int r = (rand() % 6) + 1; //creates a random number between 1 and 6 that gets stored as r which stands for roll 1.
            cout << "\n_________________________________\n";
            cout << "\nResults\n";
            cout << "\nYou've rolled a: " << r << endl;
        if (r == 4)
        {
            cout << "\nYou scored 3 points!" << endl;
        }
    }

    //Allows user to play Dice Roll game again!
    int playAgain;

    cout << "\n_________________________________\n" << endl;
    cout << "\nWould you like to play again?" << endl;
    cout << "\n1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "\nPlease enter your choice: ";
    cin >> playAgain;
    if (playAgain == 1)
        {goto Retry2;}
    if (playAgain == 2)
        return 0;
    }

    else if (dice == 2) //Executes if the user wants to roll only one die creating one random number between 1-6.

        {while (i++ < 1)
        {

            int r = (rand() % 6) + 1; //creates a random number between 1 and 6 that gets stored as r standing for roll 1.
            cout << "\n_________________________________\n";
            cout << "\nResults:\n";
            cout << "\nYou've rolled a " << r; //displays the first die value rolled.
            int r2 = (rand() % 6) + 1; //creates a random number between 1 and 6 that gets stored as r2 standing for roll 2.
            cout << ", and a " << r2 << "." << endl; //displays the dice that the user rolled.
            int res = r2 + r; //adds the results together to see if the user scored any points.
        if(r2 == r) //Lets user know that they scored points by rolling doubles!
        {
            cout << "\nYou scored 5 points, by rolling doubles!" << endl;
        }

        else if (res == 7) //Lets user know that they scored points by rolling dice that added to get 7!
        {
            cout << "\nYou scored 10 points, by rolling two dice for a total of 7!" << endl;
        }

//Allows the user to play the Dice Roll game again!

    int playAgain;

    cout << "\n_________________________________\n" << endl;
    cout << "\nWould you like to play again?" << endl;
    cout << "\n1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "\nPlease enter your choice: ";
    cin >> playAgain;
    if (playAgain == 1)
        {goto Retry2;}
    if (playAgain == 2)
        return 0;
        }

        }

    else if (dice == 3) //Exits the Dice Roll game.
        {
            return 0;
        }

    else //Executes if the user picks something other than 1-3.
        {
            cout << "\nI'm sorry, but thats not an available option. Please try again!" << endl;
            goto Retry2;
        }
}
