#include <iostream>
#include <algorithm>
#include <string>
// Given an integer input, return true if x is a palindrome of first and last digits
// and false otherwise.

int main()
{
    int input;
    std::cin >> input;
    std::string value = std::to_string(input);
    std::reverse(value.begin(), value.end());
    if (value[0] == std::to_string(input)[0] && value[value.length() - 1] == std::to_string(input)[value.length() - 1])
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    return 0;
}