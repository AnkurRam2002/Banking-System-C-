#include "Account.h"
#include <iostream>
#include <sstream>
using namespace std;

Account::Account(int accNo, string name, double initialDeposit)
    : accountNumber(accNo), accountHolderName(name), balance(initialDeposit) {}

int Account::getAccountNumber() {
    return accountNumber;
}

string Account::getAccountHolderName() {
    return accountHolderName;
}

double Account::getBalance() {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::showAccountDetails() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Holder Name: " << accountHolderName << endl;
    cout << "Balance: " << balance << endl;
}

string Account::toString() {
    stringstream ss;
    ss << "Account No: " << accountNumber << ", Name: " << accountHolderName << ", Balance: " << balance;
    return ss.str();
}
