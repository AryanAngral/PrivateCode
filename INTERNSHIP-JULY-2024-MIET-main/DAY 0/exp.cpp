#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class account
{
public:
    int acc_no;
    string name;
    float balance;
    account(int acc_no, string name, float balance)
    {
        this->acc_no = acc_no;
        this->name = name;
        this->balance = balance;
    }
    void deposit(float amount)
    {
        balance += amount;
    }
    void withdraw(float amount)
    {
        if (balance - amount < 0)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            balance -= amount;
        }
    }
};
int main()
{
    account a(1234, "Rahul", 1000);
    a.deposit(500);
    a.withdraw(200);
    return a.balance;
}
