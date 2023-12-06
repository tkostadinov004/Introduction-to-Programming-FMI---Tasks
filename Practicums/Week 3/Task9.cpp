#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int day, month, year;
    cin >> day >> month >> year;

    bool isLeapYear = (year % 4 == 0) && ((year % 100 == 0) == (year % 400 == 0));

    int days = 0;
    for (int i = 1; i < month; i++)
    {
        int currentDays = 31;
        switch (i)
        {
            case 2:
                if (isLeapYear) 
                {
                    currentDays = 29;
                }
                else 
                {
                    currentDays = 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                currentDays--;
                break;
        }

        days += currentDays;
    }
    cout << days + day;
}