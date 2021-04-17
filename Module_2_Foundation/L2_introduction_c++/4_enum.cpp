#include <iostream>
using std::cout;

int main()
{
    // Create the enum Color with fixed values.
    enum class Color
    {
        white,
        black,
        blue,
        red
    };

    // Create a Color variable and set it to Color::blue.
    Color my_color = Color::blue;

    // Test to see if my car is red.
    if (my_color == Color::red)
    {
        cout << "The color of my car is red!"
             << "\n";
    }
    else
    {
        cout << "The color of my car is not red."
             << "\n";
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // Defining enum Gender
//     enum Gender
//     {
//         Male,
//         Female
//     };

//     // Creating Gender type variable
//     Gender gender = Male;

//     switch (gender)
//     {
//     case Male:
//         cout << "Gender is Male";
//         break;
//     case Female:
//         cout << "Gender is Female";
//         break;
//     default:
//         cout << "Value can be Male or Female";
//     }
//     return 0;
// }
