#include <iostream>

using namespace std;

class Calculator
{
private:
    int inputNum1;
    int inputNum2;
    char oper;

public:
    void setInputNum1(int inputNum1)
    {
        this->inputNum1 = inputNum1;
    }
    void setInputNum2(int inputNum2)
    {
        this->inputNum2 = inputNum2;
    }
    void setOperator(char oper)
    {
        this->oper = oper;
    }

    auto typeOfOperand()
    {
        switch (this->oper)
        {
        case '+':
            return this->inputNum1 + this->inputNum2;
        case '-':
            return this->inputNum1 - this->inputNum2;
        case 'x':
            return this->inputNum1 * this->inputNum2;
        case '/':
            return this->inputNum1 / this->inputNum2;
        case '%':
            return this->inputNum1 % this->inputNum2;
        default:
            return -1;
        }
    }

    void calculate()
    {
        if (typeOfOperand() == -1)
        {
            cout << "Invalid input Operation" << endl;
        }
        else
        {
            cout << this->inputNum1 << " " << this->oper << " " << this->inputNum2 << " = " << typeOfOperand() << endl;
        }
    }
};

int main()
{
    Calculator cal;
    int input_number, input_number_2;
    char input_operator;
    cout << "Calculator Apps" << endl;
    cout << "What Operator to Use:\n1.) +\n2.) -\n3.) x\n4.) /\n5.) %" << endl;
    cout << "INPUT OPERATOR: ";
    cin >> input_operator;
    cal.setOperator(input_operator);
    cout << "INPUT N0.1: ";
    cin >> input_number;
    cal.setInputNum1(input_number);
    cout << "INPUT N0.2: ";
    cin >> input_number_2;
    cal.setInputNum2(input_number_2);
    cal.calculate();
}