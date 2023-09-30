#include <iostream>
#include <cstdlib>

class Minesweeper
{
public:
    static const int BOARD_SIZE = 10;
    const int NUM_MINES = 15;

    std::string board[BOARD_SIZE][BOARD_SIZE];
    int mine_reveal[BOARD_SIZE][BOARD_SIZE];
    int is_mine[BOARD_SIZE][BOARD_SIZE];

    Minesweeper()
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = " ";
            }
        }
    }

    void setInput(int rowInput, int colInput)
    {
        if (checkMines(rowInput, colInput))
        {

            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (is_mine[rowInput + dx][colInput + dy] == 1)
                    {
                        board[rowInput + dx][colInput + dy] = "O";
                    }
                }
            }
            board[rowInput][colInput] = "0";

            printBoard();
            std::cout << "You hit a mine!" << std::endl;
            exit(0);
        }
        else
        {
            board[rowInput][colInput] = "X";
            printBoard();
            std::cout << "You did not hit a mine!" << std::endl;
        }
    }

    void printBoard()
    {

        for (int rows = 0; rows < BOARD_SIZE; rows++)
        {
            for (int cols = 0; cols < BOARD_SIZE; cols++)
            {
                std::cout << "|" << board[rows][cols] << "|";
            }
            std::cout << std::endl;
        }
    }

    void placeMines()
    {
        srand(time(nullptr));
        int mine_count = 0;
        while (mine_count < NUM_MINES)
        {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            if (is_mine[row][col] == 0)
            {
                is_mine[row][col] = 1;
                mine_count++;
            }
        }
    }

    bool checkMines(int rowInput, int colInput)
    {

        if (is_mine[rowInput][colInput] == 1)
        {

            return true;
        }

        return false;
    }
};

int main()
{
    Minesweeper game;
    int row_input, col_input;
    game.placeMines();
    game.printBoard();
    while (true)
    {
        std::cin >> row_input;
        std::cin >> col_input;
        game.setInput(row_input, col_input);
    }

    return 0;
}