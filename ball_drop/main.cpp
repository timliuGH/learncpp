#include <iostream>
#include <limits>
#include "constants.hpp"

double getTowerHeight();
double getDistFallen(int);
double getBallHeight(double h, int t);
void printBallHeight(double h);

int main()
{
    // Get height of tower in meters
    double height{ getTowerHeight() };

    // Output height in 1-second intervals over 5 seconds
    printBallHeight(height);

    return 0;
}

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double userInput{};
    std::cin >> userInput;
    
    // Check if extraction failed
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: ";
        std::cin >> userInput;
    }
    return userInput;
}

double getDistFallen(int t)
{
    return myConstants::gravity * t * t / 2;
}

double getBallHeight(double h, int t)
{
    return h - getDistFallen(t);
}

void printBallHeight(double h)
{
    int time = 0;
    double curHeight { getBallHeight(h, time) };
    while (curHeight >= 0)
    {
        std::cout << "At " << time << " seconds, the ball is at height "
            << curHeight << " meters" << std::endl;
        time++;
        curHeight = getBallHeight(h, time);
    }
    std::cout << "At " << time << " seconds, the ball is on the ground.\n";
}
