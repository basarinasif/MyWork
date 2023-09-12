#include <iostream>
#include <ctime>

class HandGame
{
public:
    std::string rock = "\n    _______\n---'   ____)\n      (_____)\n      (_____)\n      (____)\n---.__(___)";
    std::string paper = "\n    _______\n---'    ____)____\n           ______)\n          _______)\n         _______)\n---.__________)";
    std::string scissor = "\n    _______\n---'   ____)____\n          ______)\n       __________)\n      (____)\n---.__(___)";
    int player;
    std::string enemy;
    void playerHand(int player)
    {
        this->player = player;
    }

    void enemyHand(std::string enemy)
    {
        this->enemy = enemy;
    }

    void drawScreen()
    {
        std::cout << "<==========================================================>" << std::endl;
        std::cout << "||         Welcome to Rock / Paper / Scissors Games       ||" << std::endl;
        std::cout << "<==========================================================>" << std::endl;
        std::cout << "Press Start (Y/N):" << std::endl;
    }

    void drawGameStart()
    {
        std::cout << "<==========================================================>" << std::endl;
        std::cout << "||              ROCK / PAPER / SCISSORS START             ||" << std::endl;
        std::cout << "<==========================================================>" << std::endl;
        std::cout << "Choose:\n1.) ROCK\n2.) PAPER\n3.) SCISSORS\nPlayer Turn: ";
    }

    void drawPlayerHand()
    {
        if (this->player == 1)
        {
            std::cout << rock << std::endl;
        }
        else if (this->player == 2)
        {
            std::cout << paper << std::endl;
        }
        else
        {
            std::cout << scissor << std::endl;
        }
    }

    void drawEnemyHand()
    {
        std::cout << "Enemy Turn\n";
        if (this->enemy == "ROCK")
        {
            std::cout << rock << std::endl;
        }
        else if (this->enemy == "PAPER")
        {
            std::cout << paper << std::endl;
        }
        else
        {
            std::cout << scissor << std::endl;
        }
    }

    void rockHand()
    {
        if (this->enemy == "SCISSOR")
        {
            std::cout << "YOU WIN!" << std::endl;
        }
        else if (this->enemy == "ROCK")
        {
            std::cout << "DRAW!" << std::endl;
        }
        else
        {
            std::cout << "YOU LOSE!" << std::endl;
        }
    }

    void paperHand()
    {
        if (this->enemy == "ROCK")
        {
            std::cout << "YOU WIN!" << std::endl;
        }
        else if (this->enemy == "PAPER")
        {
            std::cout << "DRAW!" << std::endl;
        }
        else
        {
            std::cout << "YOU LOSE!" << std::endl;
        }
    }
    void scissorHand()
    {
        if (this->enemy == "PAPER")
        {
            std::cout << "YOU WIN!" << std::endl;
        }
        else if (this->enemy == "SCISSOR")
        {
            std::cout << "DRAW!" << std::endl;
        }
        else
        {
            std::cout << "YOU LOSE!" << std::endl;
        }
    }
};

int main()
{
    const std::string ENEMY[] = {"ROCK", "PAPER", "SCISSOR"};
    int playerTurn;
    char input;
    srand(time(NULL));
    int ran_numbers = (rand() % (3 - 1 + 1)) + 1;
    HandGame game;
    game.drawScreen();
    std::cin >> input;
    if (input == 'y')
    {
        game.drawGameStart();
        std::cin >> playerTurn;
        game.playerHand(playerTurn);
        game.enemyHand(ENEMY[ran_numbers]);
        game.drawPlayerHand();
        game.drawEnemyHand();
        if (playerTurn == 1)
        {
            game.rockHand();
        }
        else if (playerTurn == 2)
        {
            game.paperHand();
        }
        else
        {
            game.scissorHand();
        }
    }
    else
    {
        std::cout << "Terminated" << std::endl;
    }

    return 0;
};