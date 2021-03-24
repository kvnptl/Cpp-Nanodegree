#include <iostream>
using std::cout;
using std::string;

// Define base class Animal
class Animal
{
public:
    string color;
    string name;
    int age;
};

// Declare derived class Snake
class Snake : public Animal
{
public:
    int length;
    void MakeSound() { cout << "Hiss...\n"; }
};

// Declare derived class Cat
class Cat : public Animal
{
public:
    int height;
    void MakeSound() { cout << "Meow....\n"; }
};

// Test in main()
int main()
{
    Snake snake;
    snake.age = 15;
    snake.color = "brown";
    snake.length = 10;
    snake.MakeSound();

    Cat cat;
    cat.name = "ajfks";
    cat.age = 20;
    cat.height = 5;
    cout << "My name is " << cat.name << " and Age is: " << cat.age << "\n";
    cat.MakeSound();
}