#include <iostream>
#include "constants.hpp"

double getTowerHeight();
double getDistFallen(int);
double getBallHeight(double h, int t);
void printBallHeight(double h, int t);

int main()
{
    // Get height of tower in meters
    double height{ getTowerHeight() };

    // Output height in 1-second intervals over 5 seconds
    printBallHeight(height, 5);

    return 0;
}

double getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    double userInput{};
    std::cin >> userInput;
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

void printBallHeight(double h, int t)
{
    for (int i = 0; i <= t; i++)
    {
        std::cout << "At " << i << " seconds, the ball is ";

        double curHeight{ getBallHeight(h, i) };

        // Check if ball has reached the ground
        if (curHeight <= 0)
            std::cout << "on the ground." << std::endl;
        else
            std::cout << "at height " << curHeight << " meters" << std::endl;
    }
}
