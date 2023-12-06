#include <iostream>
using namespace std;

bool isValidTriangle(double a, double b, double c) 
{
	return a + b > c && a + c > b && b + c > a;
}
void getPerimeterAndArea(double a, double b, double c) 
{
	if (!isValidTriangle(a, b, c)) 
	{
		cout << "Area is invalid!";
		return;
	}

	int p = a + b + c;
	cout << p << endl;
	cout << sqrt((p / 2) * (p / 2 - a) * (p / 2 - b) * (p / 2 - c)) << endl;
}
int main()
{

}