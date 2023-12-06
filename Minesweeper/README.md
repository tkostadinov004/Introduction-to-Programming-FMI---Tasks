# Minesweeper
Minesweeper course project for my Introduction to Programming course at FMI, Sofia University

### ℹ️ The game's purpose

There are a few rules, worthy of reading:
1. First, you should enter a board size (between 3 and 10).
2. Then, you should enter the amount of mines (between 1 and 3 * n, where n is the size of your board).
3. You play the game by entering commands in the following format: <i>**"[command] [x coordinate] [y coordinate]"**</i>, where <i>command</i> should be one of the following:
     * 3.1 **open** - you open the cell at the given x and y coordinates. If the cell contains a mine, you lose!
     * 3.2 **mark** - you mark the cell at the given x and y coordinates. This means that you suppose this cell has a mine. You cannot open a cell while it is marked.
     * 3.3 **unmark** - you unmark the cell at the given x and y coordinates.
5. You win the game after opening all cells, which don't contain mines.

### 🈯️ Symbols

* <i>"o"</i> - an unopened cell
* <i>"-"</i> - an opened cell, which has no mines in its vicinity
* <i>"M"</i> - a cell you marked as a mine
* <i>"*"</i> - a cell that contains a mine
* <i>"1"</i> to <i>"9"</i> - the amount of mines around a given cell
* <i>RMM</i> - the amount of remaining mines you have to mark

**That's it! Have fun!**
