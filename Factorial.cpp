#include <iostream>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    std::cout << "The Factorial of " << input << "! is " << factorial(input) << std::endl;
    return 0;
};