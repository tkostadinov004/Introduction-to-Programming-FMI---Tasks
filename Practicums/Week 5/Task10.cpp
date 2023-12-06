#include <iostream>
using namespace std;

bool isLeapYear(int year) 
{
	return year % 4 == 0 && (year % 100 == 0 == year % 400 == 0);
}
bool isPrime(int n) 
{
	for (int i = 2; i <= sqrt(n); i++) 
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int getPrimesCount(int days) 
{
	int count = 0;
	for (int i = 2; i <= days; i++) 
	{
		if (isPrime(i)) 
		{
			count++;
		}
	}
	return count;
}
double getGPA(double year) 
{
	int days = isLeapYear(year) ? 29 : 28;
	int primeDays = getPrimesCount(days);

	int evenDays = days / 2 - 1;
	int oddNonPrimeDays = days - evenDays - primeDays;

	return (2.99 * evenDays + 3.00 * oddNonPrimeDays + 2 * primeDays) / days;
}
int main()
{

}