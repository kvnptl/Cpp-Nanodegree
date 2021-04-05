#include "gameMenu.h"

void GameMenu::displayUserNamePrompt()
{

    std::string userName;

    std::cout << "Please enter your name: ";
    std::cin >> userName;

    if (std::cin.fail())
    {
        userName = "<UNKNOWN>";
        std::cerr << "Wrong Input" << std::endl;
    }

    _userName = std::move(userName);
};

void GameMenu::displayUserScore(std::string name, int score, int size)
{
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Player Name: " << name << "\n";
    std::cout << "Final Score: " << score << "\n";
    std::cout << "Snake Size: " << size << "\n";
};

std::string GameMenu::getUserName()
{
    return _userName;
}