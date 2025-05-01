#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNo, string name, double initialDeposit);

    int getAccountNumber();
    string getAccountHolderName();
    double getBalance();

    void deposit(double amount);
    bool withdraw(double amount);
    void showAccountDetails();
    string toString();
};

#endif
