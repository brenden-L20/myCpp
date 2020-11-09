// sudoku.cpp

// Implementing my version of Sudoku

#include "Sudoku.h"

// Board game

int main () {
    Sudoku *** sudoku;
    
    sudoku = createSudoku ();
    
    printBoard (sudoku);
    
    findUnsolved (sudoku);
    
    solveBoard (sudoku);
    
    printBoard (sudoku);
    
    findUnsolved (sudoku);
    
    clearSudoku (sudoku);
    
    return 0;
}