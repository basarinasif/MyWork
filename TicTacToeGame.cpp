#include <iostream>
#include <ctime>
class TicTacToe
{
public:
    // Create Board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };

    int countMove[9]; // Save the current numver positions for
    char drawChar;    // Draw X or O by Turn
    int count = 0;    // Number of move by turn

    void setTurn(char drawChar)
    {
        this->drawChar = drawChar;
    }

    void drawScreen()
    {
        std::cout << "<========================================================>" << std::endl;
        std::cout << "||             Welcome to Tic Tac Toe Games             ||" << std::endl;
        std::cout << "<========================================================>" << std::endl;
    }

    // Display Board
    void drawBoard()
    {
        for (int rows = 0; rows < 3; rows++)
        {
            for (int cols = 0; cols < 3; cols++)
            {
                std::cout << "|" << this->board[rows][cols] << "|";
            }
            std::cout << std::endl;
        }
    }

    // Draw the Positions of the board
    void drawPosition(int move)
    {

        switch (move)
        {
        case 1:
            board[0][0] = this->drawChar;
            break;
        case 2:
            board[0][1] = this->drawChar;
            break;
        case 3:
            board[0][2] = this->drawChar;
            break;
        case 4:
            board[1][0] = this->drawChar;
            break;
        case 5:
            board[1][1] = this->drawChar;
            break;
        case 6:
            board[1][2] = this->drawChar;
            break;
        case 7:
            board[2][0] = this->drawChar;
            break;
        case 8:
            board[2][1] = this->drawChar;
            break;
        case 9:
            board[2][2] = this->drawChar;
            break;
        }

        this->countMove[count] = move;
        count++;
    }

    // Checking the position if the current is being used
    bool checkPosition(int m)
    {
        for (int num = 0; num < 9; num++)
        {
            if (countMove[num] == m)
            {
                return true;
            }
        }

        return false;
    }

    bool checkWinner()
    {
        bool row1 = board[0][0] == this->drawChar && board[0][1] == this->drawChar && board[0][2] == this->drawChar ? true : false;
        bool row2 = board[1][0] == this->drawChar && board[1][1] == this->drawChar && board[1][2] == this->drawChar ? true : false;
        bool row3 = board[2][0] == this->drawChar && board[2][1] == this->drawChar && board[2][2] == this->drawChar ? true : false;

        bool col1 = board[0][0] == this->drawChar && board[1][0] == this->drawChar && board[2][0] == this->drawChar ? true : false;
        bool col2 = board[0][1] == this->drawChar && board[1][1] == this->drawChar && board[2][1] == this->drawChar ? true : false;
        bool col3 = board[0][2] == this->drawChar && board[1][2] == this->drawChar && board[2][2] == this->drawChar ? true : false;

        bool cross1 = board[0][0] == this->drawChar && board[1][1] == this->drawChar && board[2][2] == this->drawChar ? true : false;
        bool cross2 = board[2][0] == this->drawChar && board[1][1] == this->drawChar && board[0][2] == this->drawChar ? true : false;

        if (row1 || row2 || row3 || col1 || col2 || col3 || cross1 || cross2)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    const char POINT_X = 'X';
    const char POINT_O = 'O';
    TicTacToe game;
    int player; // Player
    int enemy;  // Enemy
    int count = 0;
    game.drawScreen();
    game.drawBoard();

    while (true)
    {
        do
        {
            std::cout << "Player Move (1-9): ";
            std::cin >> player;
            game.setTurn(POINT_X);
            if (!game.checkPosition(player))
            {
                game.drawPosition(player);
                count++;
                break;
            }
            std::cout << "Invalid move!" << std::endl;
        } while (true);
        game.drawBoard();
        if (game.checkWinner())
        {
            std::cout << "Player Win" << std::endl;
            break;
        }

        if (!(count < 9))
        {
            std::cout << "Draw" << std::endl;
            break;
        }

        do
        {
            srand(time(NULL));
            enemy = (rand() % (9 - 1 + 1)) + 1;

            game.setTurn(POINT_O);
            if (!game.checkPosition(enemy))
            {
                game.drawPosition(enemy);
                std::cout << "Enemy Turn: " << enemy << std::endl;
                count++;
                break;
            }
        } while (true);
        game.drawBoard();
        if (game.checkWinner())
        {
            std::cout << "Enemy Win" << std::endl;
            break;
        }
    }
    return 0;
};