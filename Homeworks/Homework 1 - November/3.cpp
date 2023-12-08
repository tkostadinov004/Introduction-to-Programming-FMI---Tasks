#include <iostream>
using namespace std;

constexpr unsigned ARRAY_CAPACITY = 1000000;
bool guesses[ARRAY_CAPACITY];

unsigned power(unsigned n, int pow)
{
	unsigned result = 1;
	for (int i = 0; i < pow; i++)
	{
		result *= n;
	}
	return result;
}
void fillArray(unsigned num, char numAsArray[], size_t digitsCount)
{
	bool shouldThereBeLeadingZero = num < power(10, digitsCount - 1);
	while (num > 0)
	{
		numAsArray[--digitsCount] = '0' + (num % 10);
		num /= 10;
	}
	if (shouldThereBeLeadingZero)
	{
		numAsArray[0] = '0';
	}
}
unsigned getBulls(const char currentNum[], const char guessNum[], size_t digitsCount)
{
	unsigned bulls = 0;
	for (int i = 0; i < digitsCount; i++)
	{
		if (currentNum[i] == guessNum[i])
		{
			bulls++;
		}
	}
	return bulls;
}
unsigned getDigitOccurrences(char digit, const char numberArray[], size_t length)
{
	unsigned count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numberArray[i] == digit)
		{
			count++;
		}
	}
	return count;
}
unsigned getBullsAndCowsSum(const char currentNum[], const char guessNum[], size_t digitsCount)
{
	unsigned bullsCowsCount = 0;
	for (int i = 0; i < digitsCount; i++)
	{
		bullsCowsCount += getDigitOccurrences(guessNum[i], currentNum, digitsCount);
	}
	return bullsCowsCount;
}
bool areAllDistinctDigits(const char numberArr[], size_t digitsCount)
{
	for (int i = 0; i <= 9; i++)
	{
		if (getDigitOccurrences(i + '0', numberArr, digitsCount) > 1)
		{
			return false;
		}
	}
	return true;
}
void filterPossibleNumbers(bool current[], const char numberToGuessAsArray[], unsigned minBoundary, unsigned maxBoundary, size_t digitsCount, unsigned targetBulls, unsigned targetCows)
{
	for (unsigned num = minBoundary; num < maxBoundary; num++)
	{
		char currentNumAsArray[6];
		fillArray(num, currentNumAsArray, digitsCount);

		unsigned currentBulls = getBulls(currentNumAsArray, numberToGuessAsArray, digitsCount);
		unsigned currentCows = getBullsAndCowsSum(currentNumAsArray, numberToGuessAsArray, digitsCount) - currentBulls;
		if (areAllDistinctDigits(currentNumAsArray, digitsCount) && currentBulls == targetBulls && currentCows == targetCows)
		{
			current[num] = true;
		}
	}
}
void filterCommon(const bool curr[], unsigned end)
{
	for (int i = 0; i < end; i++)
	{
		guesses[i] = guesses[i] && curr[i];
	}
}
unsigned userInput(unsigned minValue, unsigned maxValue)
{
	unsigned n = 0;
	cin >> n;
	while (n < minValue || n > maxValue)
	{
		cout << "Number should be between " << minValue << " and " << maxValue << ". Try again!" << endl;
		cin >> n;
	}

	return n;
}
void fillBoolArray(bool arr[], bool value, size_t length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = value;
	}
}
void printResult(unsigned digitsCount, unsigned end)
{
	int leadingZeroBoundary = power(10, digitsCount - 1);
	for (int i = 0; i < end; i++)
	{
		if (guesses[i])
		{
			cout << (i < leadingZeroBoundary && i > 0 ? "0" : "") << i << " ";
		}
	}
	cout << endl;
}
int main()
{
	unsigned digitsCount = userInput(1, 6);
	unsigned n = userInput(1, 4294967295);
	fillBoolArray(guesses, true, ARRAY_CAPACITY);

	unsigned minBoundary = power(10, digitsCount - 2);
	unsigned maxBoundary = power(10, digitsCount);

	if (digitsCount == 1)
	{
		minBoundary--;
	}
	for (int i = 0; i < n; i++)
	{
		char userNumberArr[7]; //The length of the array is 7, instead of 6, since we have to leave space for the null character ('\0')
		cin >> userNumberArr;

		unsigned bulls, cows;
		cin >> bulls >> cows;
		if (!areAllDistinctDigits(userNumberArr, digitsCount))
		{
			cout << "Enter a number with distinct digits!" << endl;
			i--;
			continue;
		}
		bool current[ARRAY_CAPACITY] = { 0 };

		filterPossibleNumbers(current, userNumberArr, minBoundary, maxBoundary, digitsCount, bulls, cows);
		filterCommon(current, maxBoundary);
	}

	printResult(digitsCount, maxBoundary);
}

