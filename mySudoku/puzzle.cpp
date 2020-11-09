// puzzle.cpp

#include "Sudoku.h"

int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

bool solveBoard (Sudoku *** sudoku)
{
    // Find if there are any empty squares
    auto [row, column] = findEmpty(sudoku);
    if (row == 10 && column == 10)
    {
        return true;
    }
    // For loop to check possible numbers of 1 through 9 (exclusive of 10)
    for (int x = 1; x < 10; x++)
    {
        // Check numbers to see if valid
        if (validCheck (sudoku, x, row, column))
        {
            // If valid, then update the board
            sudoku[row][column]->number = x;
            // Recursively call itself to check for the next set of numbers
            if (solveBoard (sudoku))
            {
                return true;
            }
            
            // If it breaks out of the recursive call, it was false somewhere so set it back to zero
            sudoku[row][column]->number = 0;
        }
    }
    return false;
}

// Check if the provided number is valid in the given space against row, column, and box
bool validCheck (Sudoku ***sudoku, int number, int row, int column)
{
    // Check row for same number
    for (int j = 0; j < SIZE_COLUMNS; j++)
    {
        if (sudoku[row][j]->number == number && j != column)
        {
            return false;
        }
    }

    // Check column for same number
    for (int i = 0; i < SIZE_ROWS; i++) 
    {
        if (sudoku[i][column]->number == number && i != row)
        {
            return false;
        }
    }

    // Check box for same number
    int box_x = floor(column / 3);
    int box_y = floor(row / 3);
    for (int i = box_y * 3; i < box_y * 3 + 3; i++)
    {
        for (int j = box_x * 3; j < box_x * 3 + 3; j++)
        {
            if (sudoku[i][j]->number == number && i != row && j != column)
            {
                return false;
            }
        }
    }
    return true;
}

// Find empty spaces and return tuple
std::tuple<int, int> findEmpty (Sudoku *** sudoku)
{
    for (int i = 0; i < SIZE_ROWS; i++) 
    {
        for (int j = 0; j < SIZE_COLUMNS; j++) 
        {
            if (sudoku[i][j]->number == 0)
            {
                return {sudoku[i][j]->row, sudoku[i][j]->column};
            }
        }
    }
    return {10, 10};
}

// Input board into Sudoku class
Sudoku ***createSudoku ()
{
    Sudoku ***sudoku = NULL;
    int BOARD [9][9] = 
    {
        7,8,0,  4,0,0,  1,2,0,
        6,0,0,  0,7,5,  0,0,9,
        0,0,0,  6,0,1,  0,7,8,

        0,0,7,  0,4,0,  2,6,0,
        0,0,1,  0,5,0,  9,3,0,
        9,0,4,  0,6,0,  0,0,5,

        0,7,0,  3,0,0,  0,1,2,
        1,2,0,  0,0,7,  4,0,0,
        0,4,9,  2,0,6,  0,0,7
    };


    // DMA for puzzle
    sudoku = (new Sudoku** [9]);

    for (int i = 0; i < SIZE_ROWS; i++)
    {
        // DMA for each row
        sudoku[i] = (new Sudoku* [9]);
        for (int j = 0; j < SIZE_COLUMNS; j++)
        {
            sudoku[i][j] = (new Sudoku [9]);
            sudoku[i][j]->number = BOARD[i][j];
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
        }
    }
    return sudoku;
}

void printBoard (Sudoku *** sudoku)
{
    for (int i = 0; i < SIZE_ROWS; i++)
    {
        if (i % 3 == 0 || i == 9) 
        {
            std::cout << " -----------------------------" << std::endl;
        }
        for (int j = 0; j < SIZE_COLUMNS; j++) 
        {
            if (j % 3 == 0) 
            {
                std::cout << "|";
            }
            std::cout << " " << sudoku[i][j]->number << " ";
            if (j == 8) 
            {
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if (i == 8) 
        {
            std::cout << " -----------------------------" << std::endl;
        }
    }
}

// Release memory
void clearSudoku (Sudoku *** sudoku)
{
    delete [] sudoku;
}

// Find count of unsolved squares
int findUnsolved (Sudoku *** sudoku)
{
    int unsolved = 0;
    for (int i = 0; i < SIZE_ROWS; i++) 
    {
        for (int j = 0; j < SIZE_COLUMNS; j++) 
        {
            if (sudoku[i][j]->number == 0) 
            {
                unsolved++;
            }
        }
    }
    std::cout << "Unsolved squares are " << unsolved << std::endl;
    return unsolved;
}