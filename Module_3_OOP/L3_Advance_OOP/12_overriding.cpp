#include <assert.h>
#include <string>

class Animal
{
public:
    virtual std::string Talk() const = 0;
};

// TODO: Declare a class Dog that inherits from Animal
class Dog : public Animal
{
public:
    std::string Talk() const
    {
        return "Woof";
    }
};

int main()
{
    Dog dog;
    assert(dog.Talk() == "Woof");
}