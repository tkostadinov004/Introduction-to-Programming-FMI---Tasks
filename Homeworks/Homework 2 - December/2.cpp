#include <iostream>
using namespace std;

void fillOccurrencesArray(unsigned* occurrences, const char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		occurrences[*str - 'a']++;
		str++;
	}
}
unsigned getOddOccurrencesCount(const unsigned* arr, size_t size)
{
	if (!arr)
	{
		return 0;
	}

	unsigned count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			count++;
		}
	}
	return count;
}
unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
char* myStrcat(const char* first, const char* second, size_t resultSize)
{
	if (!first || !second)
	{
		return nullptr;
	}

	char* result = new char[resultSize + 1];
	result[resultSize] = 0;
	unsigned index = 0;

	while (*first)
	{
		result[index++] = *(first++);
	}
	while (*second)
	{
		result[index++] = *(second++);
	}
	return result;
}
char* getPalindrome(const char* first, const char* second)
{
	if (!first || !second)
	{
		return nullptr;
	}

	unsigned occurrences[26] = { 0 };
	fillOccurrencesArray(occurrences, first);
	fillOccurrencesArray(occurrences, second);

	unsigned oddCount = getOddOccurrencesCount(occurrences, 26);
	if (oddCount > 1)
	{
		return nullptr;
	}

	size_t palindromeSize = myStrlen(first) + myStrlen(second);

	char* firstHalf = new char[palindromeSize / 2 + 2];
	char* secondHalf = new char[palindromeSize / 2 + 1];
	firstHalf[palindromeSize / 2 + 1] = 0;
	secondHalf[palindromeSize / 2] = 0;

	int index = 0;
	char odd = 0;
	for (unsigned i = 0; i < 26; i++)
	{
		if (occurrences[i] % 2 != 0)
		{
			odd = i + 'a';
		}
		for (unsigned j = 0; j < occurrences[i] / 2; j++)
		{
			firstHalf[index] = i + 'a';
			secondHalf[palindromeSize / 2 - index - 1] = i + 'a';
			index++;
		}
	}

	firstHalf[palindromeSize / 2] = odd;
	char* palindrome = myStrcat(firstHalf, secondHalf, palindromeSize);

	delete[] firstHalf;
	delete[] secondHalf;

	return palindrome;
}
int main()
{
	{
		char* result = getPalindrome("hello", "eh");
		if (result)
		{
			cout << result;
		}
		else
		{
			cout << "No palindrome can be formed";
		}
		delete[] result;
	}
	cout << endl;
	{
		char* result = getPalindrome("abc", "abd");
		if (result)
		{
			cout << result;
		}
		else
		{
			cout << "No palindrome can be formed";
		}
		delete[] result;
	}
}