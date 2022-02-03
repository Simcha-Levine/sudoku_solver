#include "include/sudoku.hpp"

Sudoku::Sudoku() {}
Sudoku::~Sudoku() {}

void Sudoku::iterator(const function<void(int &, int, int)> &fn)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fn(sudoku_array[i][j], i, j);
        }
    }
}

void Sudoku::printSudoku()
{
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "   1   2   3   4   5   6   7   8   9  \n";
    cout << "   ^   ^   ^   ^   ^   ^   ^   ^   ^  \n";
    cout << 1 << "<";

    const auto fn = [](int &value, int i, int j)
    {
        cout << " " << value << " |";

        if (j == 8)
        {
            cout << '\n';
            if (i != 8)
            {
                cout << "  ------------------------------------\n";
                cout << i + 2 << "<";
            }
            else
            {
                cout << '\n';
            }
        }
    };
    iterator(fn);
}

void Sudoku::borderCheck(int x, int y)
{
    if (x > 9 || y > 9)
    {
        cout << "size is 9\n";
        exit(3);
    }
}

void Sudoku::setCell(int x, int y, int value)
{
    borderCheck(x, y);
    sudoku_array[y][x] = value;
}

int Sudoku::getCell(int x, int y)
{
    borderCheck(x, y);
    return sudoku_array[y][x];
}

bool Sudoku::isLegal(int x, int y, int value)
{
    borderCheck(x, y);
    for (int i = 0; i < 9; i++)
    {
        if (i != x && sudoku_array[y][i] == value)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (i != y && sudoku_array[i][x] == value)
        {
            return false;
        }
    }

    int sx = x / 3 * 3;
    for (int i = 0; i < 3; i++)
    {
        int sy = y / 3 * 3;
        for (int j = 0; j < 3; j++)
        {
            if ((i != x || j != y) && sudoku_array[j + sy][i + sx] == value)
            {
                return false;
            }
        }
    }

    return true;
}

Point Sudoku::nextPoint(int x, int y)
{
    Point p;
    p.x = (x + 1) % 9;
    if (x + 1 == 9)
    {
        p.y = y + 1;
    }
    else
    {
        p.y = y;
    }
    if (p.x >= 9 || p.y >= 9)
    {
        return {-1, -1};
    }

    if (sudoku_array[p.y][p.x] != 0)
    {
        p = nextPoint(p.x, p.y);
    }
    return p;
}
