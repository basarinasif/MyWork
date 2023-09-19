/*
 * @Emulate N Dice roller. Given N, the task is to create a C++
 * @Program which outputs N random numbers where each number
 * @Range 1 to 6 inclusive.
 */
#include <iostream>
#include <cstdlib>

class Dice
{
public:
    int numOfDices;

    void setNumOfDices(int numOfDices)
    {
        this->numOfDices = numOfDices;
    }

    void drawScreen()
    {
        std::cout << "<=================================================>" << std::endl;
        std::cout << "||             Welcome to Dice Games             ||" << std::endl;
        std::cout << "<=================================================>" << std::endl;
        std::cout << "Enter your Number of Dice: ";
    }

    void roll()
    {
        int total = 0;
        srand(time(NULL));
        int ran_numbers = (rand() % (6 - 1 + 1)) + 1;
        std::cout << "Your Rolled:  ";
        for (int count = 0; count < this->numOfDices; count++)
        {

            std::cout << ran_numbers << " ";
            total += ran_numbers;
            ran_numbers = (rand() % (6 - 1 + 1)) + 1;
        }
        std::cout << std::endl;
        std::cout << "Total:" << total << std::endl;
    }
};

int main()
{
    Dice dice;
    int input;

    dice.drawScreen();
    std::cin >> input;
    dice.setNumOfDices(input);
    dice.roll();
    return 0;
};