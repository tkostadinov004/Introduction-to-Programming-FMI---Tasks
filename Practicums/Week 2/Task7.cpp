#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
    int year;
    cin >> year;

    bool isLeap = year % 4 == 0 && ((year % 100 == 0) == (year % 400 == 0));
    cout << "The year is " << (isLeap ? "" : "not ") << "leap.";
}