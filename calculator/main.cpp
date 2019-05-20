#include <iostream>
#include <limits>

typedef std::numeric_limits<std::streamsize> limit_t;

double getDouble();
char getOperator();
void outputResult(double, double, char);

int main()
{
    double dbl1 { getDouble() };
    char op { getOperator() };
    double dbl2 { getDouble() };

    outputResult(dbl1, dbl2, op);

    return 0;
}

double getDouble()
{
    // Get double from user
    std::cout << "Enter a double value: ";
    double userInput{};
    std::cin >> userInput;

    // Check if extraction failed
    while (std::cin.fail())
    {
        std::cout << "Invalid input. Try again: ";
        std::cin.clear();                       // Clear error flag
        std::cin.ignore(limit_t::max(), '\n');  // Clear buffer
        std::cin >> userInput;                  // Get new double from user
    }
    std::cin.ignore(limit_t::max(), '\n');      // Clear buffer
    return userInput;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op{};
    std::cin >> op;

    // Check for valid input
    while (op != '+' && op != '-' && op != '*' && op != '/')
    {
        std::cout << "Invalid operator. Try again: ";
        std::cin.ignore(limit_t::max(), '\n');
        std::cin >> op;
    }
    std::cin.ignore(limit_t::max(), '\n');
    return op;
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
