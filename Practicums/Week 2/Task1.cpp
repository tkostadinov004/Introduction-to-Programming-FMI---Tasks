#include <iostream>
#include <cmath>;
using namespace std;

int main()
{
	char sign;
	double a, b;

	cin >> sign >> a >> b;

	switch (sign)
	{
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			cout << a / b;
			break;
	}
}