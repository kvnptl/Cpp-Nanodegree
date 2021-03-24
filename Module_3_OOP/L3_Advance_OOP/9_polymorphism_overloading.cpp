//My code without class

// #include <iostream>
// #include <string>

// using std::cout;

// void hello() { cout << "Hi I am taking 0 arg\n"; }
// void hello(int a) { cout << "Hi I am taking " << a << " args\n"; }
// void hello(std::string s) { cout << "Hi I am " << s << " \n"; }

// int main()
// {
//     hello();
//     hello(5);
//     hello("Amrut");
// }

// TODO: Write hello() function

// TODO: Overload hello() three times

// TODO: Call hello() from main()
//official code

#include <iostream>

class Human
{
};
class Dog
{
};
class Cat
{
};

// TODO: Write hello() function
void hello() { std::cout << "Hello, World!\n"; }

// TODO: Overload hello() three times
void hello(Human human) { std::cout << "Hello, Human!\n"; }
void hello(Dog dog) { std::cout << "Hello, Dog!\n"; }
void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }

// TODO: Call hello() from main()
int main()
{
    hello();
    hello(Human());
    hello(Dog());
    hello(Cat());
}