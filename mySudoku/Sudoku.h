// Sudoku.h

#ifndef Sudoku_h
#define Sudoku_h

#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

class Sudoku
{
public:
    int row;
    int column;
    int number;
};

// Function prototypes to create Sudoku class
Sudoku ***createSudoku ();

// Function prototypes to set up game
void printBoard (Sudoku *** sudoku);
void clearSudoku (Sudoku *** sudoku);
int findUnsolved (Sudoku *** sudoku);

// Function prototypes to update game
bool solveBoard (Sudoku *** sudoku);
bool validCheck (Sudoku ***sudoku, int number, int row, int column);
static std::tuple<int, int> findEmpty (Sudoku *** sudoku);

#endif /* Sudoku_h */