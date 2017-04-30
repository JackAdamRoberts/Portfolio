#include <iostream>

using namespace std;

int main()
{
    int milesUsed;
    int gallonsUsed;
    int milesPergal;

    cout << "How many miles did you drive?" << endl;
    cin >> milesUsed;
    cout << "How many gallons of gas were used?" << endl;
    cin >> gallonsUsed;
    milesPergal = milesUsed / gallonsUsed;
    cout << "Your car's average MPG rating during your trip was: " << milesPergal << " MPGs" << endl;
    return 0;
}
