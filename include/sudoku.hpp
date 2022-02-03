#include <functional>
#include <iostream>
#include "point.hpp"
using namespace std;

class Sudoku
{
private:
    int sudoku_array[9][9]{
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // {0, 0, 0, 0, 0, 3, 0, 0, 2},
    // {0, 5, 0, 0, 0, 0, 0, 0, 0},
    // {7, 0, 4, 6, 0, 0, 1, 0, 0},
    // {0, 8, 0, 9, 0, 0, 0, 0, 0},
    // {0, 6, 0, 0, 0, 0, 5, 0, 0},
    // {9, 0, 5, 0, 2, 0, 0, 0, 1},
    // {8, 0, 0, 0, 0, 0, 0, 0, 0},
    // {0, 0, 0, 0, 6, 0, 0, 7, 0},
    // {1, 0, 9, 7, 0, 0, 4, 0, 0}}

    // {1, 2, 3, 4, 5, 6, 7, 8, 9},
    // {7, 8, 9, 1, 2, 3, 4, 5, 6},
    // {4, 5, 6, 7, 8, 9, 1, 2, 3},
    // {3, 1, 2, 6, 4, 5, 9, 7, 8},
    // {9, 7, 8, 3, 1, 2, 6, 4, 5},
    // {6, 4, 5, 9, 7, 8, 3, 1, 2},
    // {2, 3, 1, 5, 6, 4, 8, 9, 7},
    // {8, 9, 7, 2, 3, 1, 5, 6, 4},
    // {5, 6, 4, 8, 9, 7, 2, 3, 1}

    void iterator(const function<void(int &, int, int)> &fn);

    void borderCheck(int x, int y);

public:
    Sudoku();
    ~Sudoku();

    void printSudoku();

    void setCell(int x, int y, int value);
    int getCell(int x, int y);

    bool isLegal(int x, int y, int value);

    Point nextPoint(int x, int y);
};