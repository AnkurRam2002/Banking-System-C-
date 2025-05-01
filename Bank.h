#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
using namespace std;

class Bank {
private:
    vector<Account> accounts;

public:
    Bank();

    void addAccount(int accNo, string name, double initialDeposit);
    Account* findAccount(int accNo);
    void saveAccountsToFile();
    void loadAccountsFromFile();
};

#endif
