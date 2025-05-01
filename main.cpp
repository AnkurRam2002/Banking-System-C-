#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    Bank bank;
    int choice;
    int accountNumber;
    double amount;
    string name;

    while (true) {
        cout << "\nBank Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cin.ignore();
                cout << "Enter account holder name: ";
                getline(cin, name);
                cout << "Enter initial deposit: ";
                cin >> amount;
                bank.addAccount(accountNumber, name, amount);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                {
                    Account* acc = bank.findAccount(accountNumber);
                    if (acc) {
                        acc->deposit(amount);
                        bank.saveAccountsToFile();
                    }
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                {
                    Account* acc2 = bank.findAccount(accountNumber);
                    if (acc2) {
                        acc2->withdraw(amount);
                        bank.saveAccountsToFile();
                    }
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                {
                    Account* acc3 = bank.findAccount(accountNumber);
                    if (acc3) {
                        acc3->showAccountDetails();
                    }
                }
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
