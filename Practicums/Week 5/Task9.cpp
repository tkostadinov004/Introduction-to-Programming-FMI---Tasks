#include <iostream>
using namespace std;

void guessNumber() 
{
	int numberToGuess = rand() % 9000 + 1000;

	int n;
	int tries = 0;
	cin >> n;
	while (n != numberToGuess)
	{
		if (n < numberToGuess) 
		{
			cout << "Try with a bigger number" << endl;
		}
		else 
		{
			cout << "Try with a smaller number" << endl;
		}
		tries++;
		cin >> n;
	}

	cout << "Jackpot! ";
	if (++tries == 1) 
	{
		cout << "You are really good at this";
	}
	else 
	{
		cout << "It took you " << tries << " tries";
	}
}
int main()
{

}