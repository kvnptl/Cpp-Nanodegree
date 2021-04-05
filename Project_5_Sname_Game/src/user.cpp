#include "user.h"

User::User(std::string name) : _name(name)
{
    _score = 0;
}

User::User(std::string name, int score) : _name(name), _score(score) {}

int User::getScore() const { return _score; }
void User::setScore(const int &score)
{
    _score = score;
}

void User::incrementScore()
{
    _score += 1;
}

std::string User::getName() const { return _name; }

void User::saveScore()
{

    std::vector<User> users;

    bool isNewUser{true};
    int score;
    std::string line;
    std::string name;

    std::ifstream f;
    f.open(SCORES_FILENAME);

    if (f)
    {
        while (getline(f, line))
        {
            std::istringstream lineStream(line);
            lineStream >> name;
            if (name == this->_name)
            {
                score = this->_score;
                isNewUser = false;
            }
            else
            {
                lineStream >> score;
            }
            users.push_back(User(name, score));
        }

        f.close();
    }

    if (isNewUser)
    {
        users.push_back(User(this->_name, this->_score));
    }

    //sort top score
    std::sort(users.begin(), users.end(), [](const User a, const User &b) -> bool {
        return a._score > b._score;
    });

    // Update scores
    std::ofstream fout;
    fout.open(SCORES_FILENAME, std::ofstream::trunc);
    for (auto &user : users)
    {
        fout << user._name << " " << std::to_string(user._score) << std::endl;
    }
    fout.close();
}