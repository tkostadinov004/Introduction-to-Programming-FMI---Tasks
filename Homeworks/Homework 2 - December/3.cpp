#include <iostream>
using namespace std;

char SPECIAL_SYMBOL = '?';

unsigned getPowerOfTwo(unsigned n)
{
	return 1 << n;
}
bool isLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool isDigit(char c)
{
	return c >= '0' && c <= '9';
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
int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return -2;
	}

	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	return *first - *second;
}
unsigned countCharacterOccurrences(const char* str, char c)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (*(str++) == c)
		{
			count++;
		}
	}
	return count;
}
void concatCharacter(char* str, char c)
{
	if (!str)
	{
		return;
	}
	str += myStrlen(str);
	*str = c;
}
void concatCharacterAtAllVariations(char** patterns, char c, size_t size, unsigned period)
{
	if (!patterns)
	{
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (c != '%')
		{
			concatCharacter(patterns[i], c);
		}
		else
		{
			concatCharacter(patterns[i], SPECIAL_SYMBOL);
			if ((i / period) % 2 == 0)
			{
				concatCharacter(patterns[i], SPECIAL_SYMBOL);
			}
		}
	}
}
void removeIfExists(char** arr, const char* str, int start, size_t size)
{
	if (!arr || !str)
	{
		return;
	}

	for (size_t i = start; i < size; i++)
	{
		if (!myStrcmp(arr[i], str))
		{
			delete arr[i];
			arr[i] = nullptr;
		}
	}
}
void removeDuplicates(char** patterns, size_t size)
{
	if (!patterns)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		removeIfExists(patterns, patterns[i], i + 1, size);
	}
}
char** initializeArray(size_t size, size_t stringSize)
{
	char** arr = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = new char[stringSize] {0};
	}
	return arr;
}
char** getPatternVariations(const char* pattern, unsigned& patternVariationsCount)
{
	if (!pattern)
	{
		return nullptr;
	}

	size_t specialSymbolCount = countCharacterOccurrences(pattern, '%');
	size_t patternsCount = getPowerOfTwo(specialSymbolCount);
	patternVariationsCount = patternsCount;

	char** patterns = initializeArray(patternsCount, myStrlen(pattern) + specialSymbolCount + 1);

	unsigned period = patternsCount / 2;
	while (*pattern)
	{
		concatCharacterAtAllVariations(patterns, *pattern, patternsCount, period);
		if (*pattern == '%')
		{
			period /= 2;
		}
		pattern++;
	}

	removeDuplicates(patterns, patternsCount);

	return patterns;
}
bool isPrefix(const char* str, const char* pattern)
{
	if (!str || !pattern)
	{
		return false;
	}

	while (*str && *pattern)
	{
		if ((*str == *pattern) || (*pattern == '@' && isLetter(*str)) || (*pattern == SPECIAL_SYMBOL && isDigit(*str)) || *pattern == '*')
		{
			str++;
			pattern++;
		}
		else
		{
			break;
		}
	}

	return *pattern == 0;
}
unsigned countPatternOccurrencesInPrefix(const char* str, char** patternVariations, size_t patternVariationsCount)
{
	if (!str || !patternVariations)
	{
		return 0;
	}

	unsigned count = 0;
	for(size_t i = 0; i < patternVariationsCount; i++)
	{
		if (patternVariations[i] && isPrefix(str, patternVariations[i]))
		{
			count++;
		}
	}
	return count;
}
void freeMemory(char** arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	for(size_t i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
unsigned countPatternOccurrencesInString(const char* str, const char* pattern)
{
	if (!str || !pattern)
	{
		return 0;
	}

	unsigned patternVariationsCount = 0;
	char** patternVariations = getPatternVariations(pattern, patternVariationsCount);

	unsigned count = 0;
	while (*str)
	{
		count += countPatternOccurrencesInPrefix(str, patternVariations, patternVariationsCount);
		str++;
	}

	freeMemory(patternVariations, patternVariationsCount);
	return count;
}
int main()
{
	cout << countPatternOccurrencesInString("te3t zdrte44q t33t", "t*%@") << endl;
	cout << countPatternOccurrencesInString("aaaaaa", "aa") << endl;
	cout << countPatternOccurrencesInString("123", "%%") << endl;
	//cout << countPatternOccurrencesInString("yn87435t26s4nth23", "*@*@%") << endl;
}