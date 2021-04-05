#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>

#define SCORES_FILENAME "user_scores.txt"

class User
{
public:
    User(std::string name);
    User(std::string name, int score);

    int getScore() const;
    void setScore(const int &score);
    void incrementScore();

    std::string getName() const;
    void saveScore();

private:
    std::string _name;
    int _score{0};
};
#endif