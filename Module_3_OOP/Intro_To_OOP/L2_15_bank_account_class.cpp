#include <iostream>
#include <string>

class BankAccount
{
private:
    // TODO: declare member variables
    int accNumber = 211;
    std::string accName;
    float balance{0};

public:
    // TODO: declare setters
    void SetAccNumber(int a) { accNumber = a; }
    void SetAccName(std::string s) { accName = s; }
    void AddFunds(int f);

    // TODO: declare getters
    int GetAccNumber() { return accNumber; }
    std::string GetAccName() { return accName; }
    void CheckBalance();
};

// TODO: implement setters
void BankAccount::AddFunds(int f)
{
    if (f > 0)
    {
        balance += f;
    }
}
// TODO: implement getters

void BankAccount::CheckBalance()
{
    std::cout << accName << " balance is: " << balance << "\n";
}

int main()
{
    // TODO: instantiate and output a bank account
    BankAccount b1;
    b1.SetAccNumber(3457);
    b1.SetAccName("Harshad");
    b1.AddFunds(5000);

    BankAccount b2;
    b2.SetAccNumber(9871);
    b2.SetAccName("Mehta");
    b2.AddFunds(900);

    b1.CheckBalance();
    b2.CheckBalance();

    b1.AddFunds(8000);
    b2.AddFunds(10000);

    b1.CheckBalance();
    b2.CheckBalance();
}