#include <iostream>
#include <windows.h>
using namespace std;

constexpr size_t MIN_BOARD_SIZE = 3;
constexpr size_t MAX_BOARD_SIZE = 10;
constexpr size_t MAX_COMMAND_LENGTH = 7;

const int DEFAULT_CONSOLE_COLOR = 0x07;
const int MINE_COLOR = 0x0C;

const char MINE_SYMBOL = '*';
const char DEFAULT_SYMBOL = '-';
const char MARKED_MINE_SYMBOL = 'M';
const char UNVISITED_CELL_SYMBOL = 'o';

const unsigned directions[8][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1} }; //resp - up, right, down, left, top-left, top-right, bottom-right, bottom-left

char field[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
bool visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = { false };
bool markedAsMines[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = { false };

bool shouldClearConsole = true;

void setColor(char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
unsigned getColor(char digit)
{
	unsigned digitValue = digit - '0' + 1;

	return digitValue == 7 ? 0x0E : digitValue;
}
unsigned getRandomValueInRange(unsigned start, unsigned end)
{
	return start + (rand() % (int)(end - start + 1));
}
bool areValidIndices(int x, int y, size_t size)
{
	return x >= 0 && y >= 0 && x < size && y < size;
}
unsigned userInput(unsigned min, unsigned max)
{
	int n;
	cin >> n;
	while (n < min || n > max)
	{
		cout << "Entered value should be between " << min << " and " << max << " Try again!" << endl;
		cin >> n;
	}
	return n;
}
bool validateInput(char command[], unsigned x, unsigned y, size_t size)
{
	bool isValid = true;
	if (strcmp(command, "open") != 0 && strcmp(command, "mark") && strcmp(command, "unmark"))
	{
		cout << "Enter a valid command (open, mark, unmark)!" << endl;
		isValid = false;
	}
	if (x < 0 || x >= size)
	{
		cout << "Value of x should be between 0 and " << size << endl;
		isValid = false;
	}
	if (y < 0 || y >= size)
	{
		cout << "Value of y should be between 0 and " << size << endl;
		isValid = false;
	}
	return isValid;
}

void initializeField()
{
	for (size_t i = 0; i < MAX_BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < MAX_BOARD_SIZE; j++)
		{
			field[i][j] = DEFAULT_SYMBOL;
		}
	}
}
void populateWithMines(size_t size, unsigned mineCount, unsigned playerRow, unsigned playerCol)
{
	for (unsigned i = 0; i < mineCount; i++)
	{
		unsigned row = getRandomValueInRange(0, size - 2);
		unsigned col = getRandomValueInRange(0, size - 2);

		if (field[row][col] == MINE_SYMBOL || (playerRow == row && playerCol == col))
		{
			i--;
			continue;
		}
		field[row][col] = MINE_SYMBOL;
	}
}
unsigned getSurroundingMinesCount(size_t size, unsigned row, unsigned col)
{
	if (field[row][col] == MINE_SYMBOL)
	{
		return 0;
	}

	unsigned count = 0;
	for (int i = 0; i < 8; i++)
	{
		int currentRow = row + directions[i][0];
		int currentCol = col + directions[i][1];
		if (areValidIndices(currentRow, currentCol, size) && field[currentRow][currentCol] == MINE_SYMBOL)
		{
			count++;
		}
	}
	return count;
}
void setProximities(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			unsigned count = getSurroundingMinesCount(size, i, j);
			if (count > 0)
			{
				field[i][j] = '0' + count;
			}
		}
	}
}
void printField(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (!visited[i][j])
			{
				if (markedAsMines[i][j])
				{
					cout << MARKED_MINE_SYMBOL;
				}
				else
				{
					cout << UNVISITED_CELL_SYMBOL;
				}
			}
			else
			{
				if (field[i][j] >= '1' && field[i][j] <= '9')
				{
					setColor(getColor(field[i][j]));
				}
				else if (field[i][j] == MINE_SYMBOL)
				{
					setColor(MINE_COLOR);
				}
				cout << field[i][j];
				setColor(DEFAULT_CONSOLE_COLOR);
			}
			cout << " ";
		}
		cout << endl;
	}
}
void openAdjacentFree(size_t size, unsigned row, unsigned col, unsigned& remainingUnvisitedCount)
{
	if (!areValidIndices(row, col, size) || visited[row][col])
	{
		return;
	}
	if (!markedAsMines[row][col])
	{
		visited[row][col] = true;
		remainingUnvisitedCount--;
	}
	if (getSurroundingMinesCount(size, row, col) > 0)
	{
		return;
	}
	for (unsigned i = 0; i < 8; i++)
	{
		unsigned currentRow = row + directions[i][0];
		unsigned currentCol = col + directions[i][1];
		openAdjacentFree(size, currentRow, currentCol, remainingUnvisitedCount);
	}
}
void uncoverAllMines(size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (field[i][j] == MINE_SYMBOL)
			{
				visited[i][j] = true;
			}
		}
	}
}
void handleCommand(const char command[], size_t size, unsigned row, unsigned col, bool& isLoser, unsigned& remainingUnvisitedCount)
{
	if (strcmp(command, "open") == 0)
	{
		if (markedAsMines[row][col])
		{
			cout << "You cannot open this cell because it's marked as a mine! Try again!" << endl;
			shouldClearConsole = false;
			return;
		}
		if (visited[row][col])
		{
			cout << "This cell is already opened!" << endl;
			shouldClearConsole = false;
			return;
		}
		if (field[row][col] == MINE_SYMBOL)
		{
			isLoser = true;
			uncoverAllMines(size);
			return;
		}
		openAdjacentFree(size, row, col, remainingUnvisitedCount);
	}
	else if (strcmp(command, "mark") == 0)
	{
		if (markedAsMines[row][col])
		{
			cout << "The cell you selected is marked as a mine, therefore you can't open it! Unmark it in order to open it" << endl;
			return;
		}
		markedAsMines[row][col] = true;
	}
	else if (strcmp(command, "unmark") == 0)
	{
		if (!markedAsMines[row][col])
		{
			cout << "The cell you selected is not marked as a mine!" << endl;
			return;
		}
		markedAsMines[row][col] = false;
	}
}
int main()
{
	srand(time(0));
	initializeField();

	cout << "Enter a field size (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << " inclusive): ";
	unsigned size = userInput(MIN_BOARD_SIZE, MAX_BOARD_SIZE);

	cout << "Enter the amount of mines (between 1 and " << size * 3 << " inclusive): ";
	unsigned mineCount = userInput(1, size * 3);

	system("cls");
	printField(size);

	bool isLoser = false;
	bool hasPlayedFirstTurn = false;
	unsigned remainingUnvisitedCount = size * size;
	while (remainingUnvisitedCount > mineCount && !isLoser)
	{
		char command[MAX_COMMAND_LENGTH];
		unsigned x, y;
		cin >> command >> x >> y;
		if (!validateInput(command, x, y, size))
		{
			continue;
		}

		if (!hasPlayedFirstTurn)
		{
			populateWithMines(size, mineCount, y, x);
			setProximities(size);
			hasPlayedFirstTurn = true;
		}
		handleCommand(command, size, y, x, isLoser, remainingUnvisitedCount);
		if (remainingUnvisitedCount <= mineCount)
		{
			uncoverAllMines(size);
		}

		if (shouldClearConsole)
		{
			system("cls");
			printField(size);
		}
		shouldClearConsole = true;
	}

	cout << endl;
	cout << (isLoser ? "You lost!" : "You won!");
}