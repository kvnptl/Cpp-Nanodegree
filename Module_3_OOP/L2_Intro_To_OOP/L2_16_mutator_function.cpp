#include <string>
#include <cstring>
#include <iostream>

class Car
{
    // TODO: Declare private attributes
private:
    int horsepower{0};
    int weight{0};
    char *brand;
    // TODO: Declare getter and setter for brand
public:
    void SetBrand(std::string s);
    std::string GetBrand() const;
};

// Define setters
void Car::SetBrand(std::string s)
{
    Car::brand = new char[s.length() + 1];
    strcpy(Car::brand, s.c_str());
}
// Define getters
std::string Car::GetBrand() const
{
    std::string result = "Brand name: ";
    result += Car::brand;
    return result;
}

// Test in main()
int main()
{
    Car car;
    car.SetBrand("Tata");
    std::cout << car.GetBrand() << "\n";
}