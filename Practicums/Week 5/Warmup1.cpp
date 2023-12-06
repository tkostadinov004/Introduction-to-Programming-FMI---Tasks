#include <iostream>
using namespace std;

bool isLeapYear(int year) {
	return year % 4 == 0 && (year % 100 == 0 == year % 400 == 0);
}
int getDaysByMonth(int month, int year) 
{
	int maxDays = 30;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxDays++;
			break;
		case 2:
			maxDays--;
			if (!isLeapYear(year)) 
			{
				maxDays--;
			}
			break;
	}
	return maxDays;
}
int enterDateArg(int max) 
{
	int arg;
	do
	{
		cin >> arg;
	} 
	while (arg < 0 && arg > max);

	return arg;
}
void increaseDate() {
	int year = enterDateArg(INT_MAX);
	int month = enterDateArg(12);

	int limit = getDaysByMonth(month, year);
	int day = enterDateArg(limit);

	if (++day > limit) 
	{
		day = 1;
		if (++month > 12) 
		{
			month = 1;
			year++;
		}
	}

	cout << year << "-" << month << "-" << day << endl;
}
int main()
{

}