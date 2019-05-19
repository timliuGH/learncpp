#include <iostream>

double getDouble();
char getOperation();
void outputResult(double, double, char);

int main()
{
    double dbl1 = getDouble();
    double dbl2 = getDouble();
    char operation = getOperation();

    outputResult(dbl1, dbl2, operation);

    return 0;
}

double getDouble()
{
    std::cout << "Enter a double value: ";
    double userInput;
    std::cin >> userInput;
    return userInput;
}

char getOperation()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char userInput;
    std::cin >> userInput;
    return userInput;
}

void outputResult(double d1, double d2, char c)
{
    switch (c)
    {
        case '+':
            std::cout << d1 << " + " << d2 << " is " << d1 + d2 << std::endl;
            break;
        case '-':
            std::cout << d1 << " - " << d2 << " is " << d1 - d2 << std::endl;
            break;
        case '*':
            std::cout << d1 << " * " << d2 << " is " << d1 * d2 << std::endl;
            break;
        case '/':
            std::cout << d1 << " / " << d2 << " is " << d1 / d2 << std::endl;
            break;
    }
}
