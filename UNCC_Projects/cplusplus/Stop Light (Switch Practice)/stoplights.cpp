#include <iostream>
#include <cstdlib>
using namespace std;
main()
{
    int number;
    cout<< " choose a color by entering the related number: 1- Red , 2- Orange , 3- Green" << endl;
    cin >> number;

    switch (number)
     {
case 1:
    cout << "driver should stop" << endl;
    break;
case 2:
    cout << "driver should drive slowly" << endl;
    break;
case 3:
    cout << "driver should go" << endl;
    break;
    }
    system("pause");
    return 0;
}

