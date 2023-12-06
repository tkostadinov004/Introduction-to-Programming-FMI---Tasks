#include <iostream>
using namespace std;

double getBasicPrice(double price, double discount, int day, int minDay, int maxDay) 
{
	return price * (day >= minDay && day <= maxDay ? discount : 1);
}
void menu(double balance, int day)
{
	const double MEATBALL_SAUSAGE_PRICE = getBasicPrice(2, 0.9, day, 4, 5);
	const double RELISH_PRICE = getBasicPrice(2, 0.75, day, 1, 3);
	const double SALAD_PRICE = getBasicPrice(3.50, 0.75, day, 1, 3);
	const double BEER_PRICE = getBasicPrice(6.66, 0.75, day, 1, 3);

	int orderCommand;
	cin >> orderCommand;

	double price = 0;

	int warningsCount = 0;
	while (orderCommand != 0)
	{
		double currentPrice = 0;
		switch (orderCommand)
		{
			case 1:
				currentPrice += MEATBALL_SAUSAGE_PRICE;
				break;
			case 2:
				currentPrice += RELISH_PRICE;
				break;
			case 3:
				currentPrice += SALAD_PRICE;
				break;
			case 4:
				currentPrice += BEER_PRICE;
				break;
		}
		if (currentPrice > balance)
		{
			cout << "You have no money!" << endl;
			if (++warningsCount == 3)
			{
				cout << "End" << endl;
				return;
			}
		}
		else
		{
			price += currentPrice;
			balance -= currentPrice;
		}

		cin >> orderCommand;
	}

	cout << "You paid: " << price << endl;
	cout << "You have: " << balance << left;
}
int main()
{

}