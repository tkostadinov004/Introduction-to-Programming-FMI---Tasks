#include <iostream>
using namespace std;

void menu(double balance, int day)
{
	const double MEATBALL_SAUSAGE_PRICE = 2 * (day == 4 || day == 5 ? 0.9 : 1);
	const double RELISH_PRICE = 2 * (day >= 1 && day <= 3 ? 0.75 : 1);
	const double SALAD_PRICE = 3.50 * (day >= 1 && day <= 3 ? 0.75 : 1);
	const double BEER_PRICE = 6.66 * (day >= 1 && day <= 3 ? 0.75 : 1);

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