#include "Bank.h"
#include <fstream>
#include <iostream>
using namespace std;

Bank::Bank() {
    loadAccountsFromFile();
}

void Bank::addAccount(int accNo, string name, double initialDeposit) {
    Account newAccount(accNo, name, initialDeposit);
    accounts.push_back(newAccount);
    saveAccountsToFile();
    cout << "Account created successfully.\n";
}

Account* Bank::findAccount(int accNo) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    cout << "Account not found.\n";
    return nullptr;
}

void Bank::saveAccountsToFile() {
    ofstream outFile("accounts.txt");
    for (auto &acc : accounts) {
        outFile << acc.toString() << "\n";
    }
    outFile.close();
}

void Bank::loadAccountsFromFile() {
    ifstream inFile("accounts.txt");
    if (inFile.is_open()) {
        int accNo;
        string name;
        double balance;
        while (inFile >> accNo >> ws) {
            getline(inFile, name);
            inFile >> balance;
            accounts.push_back(Account(accNo, name, balance));
        }
        inFile.close();
    }
}
