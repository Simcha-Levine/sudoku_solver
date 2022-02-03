if g++ main.cpp sudoku.cpp -o sudoku.linux \
    -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion; then
    echo "compiled successfully"
    ./sudoku.linux
fi
