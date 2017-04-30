#include <iostream>

using namespace std;

int main()
{
	float oldSalary;
	float percentRaise;
	float newSalary;
	float amountRaise;
	float percentDecimal;
	char quit;
	cout << "How much were you making before your raise?" << endl;
	cin >> oldSalary;
	cout << "Please enter the percent raise you received: " << endl;
	cin >> percentRaise;
	percentDecimal = percentRaise * .01;
	amountRaise = oldSalary * percentDecimal;
	newSalary = amountRaise + oldSalary;
	cout << "You received a raise of, $" << amountRaise << ", bringing your current salary to $" << newSalary << endl;
	cout << "\nThank you for visiting!\nEnter 'q' to quit!" << endl;
	cin >> quit;
	return 0;
}
