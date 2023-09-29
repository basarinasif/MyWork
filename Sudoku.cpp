#include <iostream>

class Sudoku
{
public:
    static const int MAX = 4;
    int board[MAX][MAX];

    void setBoard(int board[MAX][MAX])
    {
        for (int rows = 0; rows < MAX; rows++)
        {
            for (int cols = 0; cols < MAX; cols++)
            {
                this->board[rows][cols] = board[rows][cols];
            }
        }
    }

    void inputNumber(int row, int col)
    {
        for (int count = 1; count <= MAX; count++)
        {
            if (check(this->board, row, col, count))
            {
                this->board[row][col] = count;
                solve();
            }
        }
    }

    bool solve()
    {

        for (int rows = 0; rows < MAX; rows++)
        {
            for (int cols = 0; cols < MAX; cols++)
            {
                if (this->board[rows][cols] == 0)
                {
                    inputNumber(rows, cols);
                }
            }
        }

        return true;
    }

    bool check(int grid[MAX][MAX], int rows, int cols, int n)
    {

        for (int i = 0; i < MAX; i++)
        {
            if (grid[rows][i] == n)
            {
                return false;
            }
        }

        for (int i = 0; i < MAX; i++)
        {
            if (grid[i][cols] == n)
            {
                return false;
            }
        }

        return true;
    }
    void display()
    {
        for (int rows = 0; rows < MAX; rows++)
        {
            for (int cols = 0; cols < MAX; cols++)
            {
                std::cout << "|" << this->board[rows][cols] << "|";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Sudoku sudoku;
    int grid[4][4] = {{0, 4, 3, 0},
                      {1, 3, 0, 2},
                      {3, 0, 2, 4},
                      {0, 0, 0, 3}};

    /*
        {2, 4, 3, 1},
        {1, 3, 4, 2},
        {3, 1, 2, 4},
        {4, 2, 1, 3};
    */

    sudoku.setBoard(grid);
    if (sudoku.solve())
    {
        sudoku.display();
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }
    return 0;
}