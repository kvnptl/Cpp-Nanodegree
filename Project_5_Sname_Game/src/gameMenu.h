#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <iomanip>
#include <iostream>
#include <string>

class GameMenu
{
public:
    GameMenu(){};
    ~GameMenu(){};
    void displayUserNamePrompt();
    void displayUserScore(std::string name, int score, int size);
    std::string getUserName();

private:
    std::string _userName;
};

#endif