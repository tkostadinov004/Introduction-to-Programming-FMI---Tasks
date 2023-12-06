#include <iostream>
#include <windows.h>
using namespace std;

constexpr size_t MIN_BOARD_SIZE = 3;
constexpr size_t MAX_BOARD_SIZE = 10;
constexpr size_t MAX_COMMAND_LENGTH = 7;

const unsigned DEFAULT_CONSOLE_COLOR = 0x07;
const unsigned MINE_COLOR = 0x0C;
const unsigned MARKED_MINE_COLOR = 0x0B;

const char MINE_SYMBOL = '*';
const char OPENED_FREE_CELL_SYMBOL = '-';
const char MARKED_MINE_SYMBOL = 'M';
const char UNVISITED_CELL_SYMBOL = 'o';

const int directions[8][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1} }; //resp - up, right, down, left, top-left, top-right, bottom-right, bottom-left

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

	return digitValue == DEFAULT_CONSOLE_COLOR ? 0x0E : digitValue;
}
void printMenu()
{
	cout << "----------Minesweeper----------" << endl << endl;
	cout << "Welcome to this C++ implementation of the classic Minesweeper game!" << endl << endl;
	cout << "There are a few rules, worthy of reading: " << endl;
	cout << "1. First, you should enter a board size (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << ")." << endl;
	cout << "2. Then, you should enter the amount of mines (between 1 and 3 * n, where n is the size of your board)." << endl;
	cout << "3. You play the game by entering commands in the following format: \"[command] [x coordinate] [y coordinate]\", where command should be one of the following: " << endl;
	cout << "\t3.1 open - you open the cell at the given x and y coordinates. If the cell contains a mine, you lose!" << endl;
	cout << "\t3.2 mark - you mark the cell at the given x and y coordinates. This means that you suppose this cell has a mine. You cannot open a cell while it is marked." << endl;
	cout << "\t3.3 unmark - you unmark the cell at the given x and y coordinates." << endl;
	cout << "4. You win the game after opening all cells, which don't contain mines." << endl << endl;
	cout << "-----------Symbols-----------" << endl << endl;
	cout << "\"" << UNVISITED_CELL_SYMBOL << "\"" << " - this shows an unopened cell" << endl;
	cout << "\"" << OPENED_FREE_CELL_SYMBOL << "\"" << " - this shows a cell an opened cell, which has no mines in its vicinity" << endl;
	cout << "\"" << MARKED_MINE_SYMBOL << "\"" << " - this shows a cell you marked as a mine" << endl;
	cout << "\"" << MINE_SYMBOL << "\"" << " - this shows a cell that contains a mine" << endl;
	cout << "\"1\" to \"9\" - this shows the amount of mines around a given cell" << endl;
	cout << "RMM - this shows the amount of remaining mines to mark" << endl << endl;
	cout << "-----------Colors-----------" << endl << endl;
	setColor(MINE_COLOR);
	cout << "This color is reserved for mines. You will see it if you step on a mine." << endl;
	setColor(MARKED_MINE_COLOR);
	cout << "This color is reserved for marked mines. If you have guessed the location of a mine, this mine will be colored like this." << endl;
	setColor(DEFAULT_CONSOLE_COLOR);
	cout << endl;
	cout << "That's it! Have fun!" << endl;
	cout << endl;
}
unsigned getRandomValueInRange(unsigned start, unsigned end)
{
	return start + (rand() % (int)(end - start + 1));
}
bool areValidIndices(int x, int y, size_t size)
{
	return x >= 0 && y >= 0 && x < size && y < size;
}
bool isDigit(char c)
{
	return c >= '1' && c <= '9';
}
unsigned userInput(unsigned min, unsigned max)
{
	int n;
	cin >> n;
	while (n < min || n > max)
	{
		cout << "Entered value should be between " << min << " and " << max << " Try again! ";
		cin >> n;
	}
	return n;
}
int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return -2;
	}

	while (*first && *second && (*first) == (*second))
	{
		first++;
		second++;
	}

	int diff = (*first - *second);
	return diff != 0 ? diff / abs(diff) : 0;
}
bool validateInput(const char* command, unsigned x, unsigned y, size_t size)
{
	bool isValid = true;
	if (myStrcmp(command, "open") && myStrcmp(command, "mark") && myStrcmp(command, "unmark"))
	{
		cout << "Enter a valid command (open, mark, unmark)!" << endl;
		isValid = false;
	}
	if (x < 0 || x >= size)
	{
		cout << "Value of x should be between 0 and " << size << "!" << endl;
		isValid = false;
	}
	if (y < 0 || y >= size)
	{
		cout << "Value of y should be between 0 and " << size << "!" << endl;
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
			field[i][j] = OPENED_FREE_CELL_SYMBOL;
		}
	}
}
bool isInVicinity(size_t size, unsigned playerRow, unsigned playerCol, unsigned row, unsigned col)
{
	if (size < 4)
	{
		return false; //if the field's size is less than 4, we cannot find any optimal solution in some cases
	}

	unsigned count = 0;
	for (int i = 0; i < 8; i++)
	{
		int currentRow = playerRow + directions[i][0];
		int currentCol = playerCol + directions[i][1];
		if (currentRow == row && currentCol == col)
		{
			return true;
		}
	}
	return false;
}
void populateWithMines(size_t size, unsigned mineCount, unsigned playerRow, unsigned playerCol)
{
	for (unsigned i = 0; i < mineCount; i++)
	{
		unsigned row = getRandomValueInRange(0, size - 1);
		unsigned col = getRandomValueInRange(0, size - 1);

		if (field[row][col] == MINE_SYMBOL || (playerRow == row && playerCol == col) || isInVicinity(size, playerRow, playerCol, row, col))
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
void printField(size_t size, int remainingMinesToMark)
{
	cout << "    RMM: " << remainingMinesToMark << endl << endl;

	cout << "    ";
	for (size_t i = 0; i < size; i++)
	{
		cout << i << " ";
	}
	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		cout << i << "   ";
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
				if (isDigit(field[i][j]))
				{
					setColor(getColor(field[i][j]));
				}
				else if (field[i][j] == MINE_SYMBOL)
				{
					if (markedAsMines[i][j])
					{
						setColor(MARKED_MINE_COLOR);
					}
					else
					{
						setColor(MINE_COLOR);
					}
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
void handleCommand(const char* command, size_t size, unsigned row, unsigned col, bool& isLoser, unsigned& remainingUnvisitedCount, int& remainingMinesToMark)
{
	if (myStrcmp(command, "open") == 0)
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
	else if (myStrcmp(command, "mark") == 0)
	{
		if (markedAsMines[row][col])
		{
			cout << "This cell is already marked!" << endl;
			shouldClearConsole = false;
			return;
		}
		if (visited[row][col])
		{
			cout << "You cannot mark an opened cell!" << endl;
			shouldClearConsole = false;
			return;
		}
		markedAsMines[row][col] = true;
		remainingMinesToMark--;
	}
	else if (myStrcmp(command, "unmark") == 0)
	{
		if (!markedAsMines[row][col])
		{
			cout << "The cell you selected is not marked as a mine!" << endl;
			shouldClearConsole = false;
			return;
		}
		markedAsMines[row][col] = false;
		remainingMinesToMark++;
	}
}
unsigned calculateScore(size_t size)
{
	unsigned score = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (field[i][j] == MINE_SYMBOL && markedAsMines[i][j])
			{
				score++;
			}
		}
	}
	return score;
}
int main()
{
	printMenu();
	srand(time(0));
	initializeField();

	cout << "Enter a field size (between " << MIN_BOARD_SIZE << " and " << MAX_BOARD_SIZE << " inclusive): ";
	unsigned size = userInput(MIN_BOARD_SIZE, MAX_BOARD_SIZE);

	cout << "Enter the amount of mines (between 1 and " << size * 3 << " inclusive): ";
	unsigned mineCount = userInput(1, size * 3);
	int remainingMinesToMark = mineCount;

	system("cls");
	printField(size, remainingMinesToMark);

	bool isLoser = false;
	bool hasPlayedFirstTurn = false;

	unsigned remainingUnvisitedCount = size * size;
	while (remainingUnvisitedCount > mineCount && !isLoser)
	{
		char* command = new char[MAX_COMMAND_LENGTH];
		unsigned x, y;
		cin >> command >> x >> y;
		if (!validateInput(command, x, y, size))
		{
			continue;
		}
		if (!hasPlayedFirstTurn && myStrcmp(command, "open") == 0)
		{
			populateWithMines(size, mineCount, y, x);
			setProximities(size);
			hasPlayedFirstTurn = true;
		}
		handleCommand(command, size, y, x, isLoser, remainingUnvisitedCount, remainingMinesToMark);
		if (remainingUnvisitedCount <= mineCount)
		{
			uncoverAllMines(size);
		}

		if (shouldClearConsole)
		{
			system("cls");
			printField(size, remainingMinesToMark);
		}
		shouldClearConsole = true;
	}

	cout << endl;
	cout << (isLoser ? "You lost!" : "You won!") << endl;
	cout << "Score: " << calculateScore(size) << endl;
}