#include "include/sudoku.hpp"
#include <fstream>
using namespace std;

bool fill(int x, int y);
bool setSudoku(const char *file_name);

Sudoku sudoku;

int main(int, char const *argv[])
{
    if (!setSudoku(argv[1]))
    {
        return 0;
    }
    sudoku.printSudoku();

    bool y = fill(-1, 0);
    cout << y << '\n';
    if (!y)
    {
        cout << "sudoku not possible\n";
    }
    sudoku.printSudoku();
}

bool fill(int x, int y)
{
    Point p = sudoku.nextPoint(x, y);
    // cout << p.x << " , " << p.y << '\n';

    // when next point gets to the end
    if (p.x == -1)
    {
        return true;
    }

    for (int i = 1; i < 10; i++)
    {
        if (sudoku.isLegal(p.x, p.y, i))
        {
            sudoku.setCell(p.x, p.y, i);
            if (fill(p.x, p.y))
            {
                return true;
            }
            sudoku.setCell(p.x, p.y, 0);
        }
    }
    return false;
}

bool setSudoku(const char *file_name)
{
    string line;
    ifstream file(file_name);

    if (file.is_open())
    {
        for (int i = 0; i < 9; i++)
        {
            if (getline(file, line))
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j < (int)line.length())
                    {
                        sudoku.setCell(j, i, line[(size_t)j] - '0');
                    }
                    else
                    {
                        cout << "not enough arguments\n";
                        return false;
                    }
                }
            }
            else
            {
                cout << "not enough arguments\n";
                return false;
            }
        }
    }
    else
    {
        cout << "file doesin't work\n";
        return false;
    }
    return true;
}