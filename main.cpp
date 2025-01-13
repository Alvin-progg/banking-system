#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance)
        : accountHolderName(name), accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!" << endl;
        } else {
            cout << "Deposit failed! Invalid amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Withdrawal failed! Invalid amount or insufficient balance." << endl;
        }
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void getBalance() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void createAccount(string name, int accNum, double initialBalance) {
        BankAccount newAccount(name, accNum, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully!" << endl;
    }

    // Mark findAccount as const
    BankAccount* findAccount(int accNum) const {
        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return const_cast<BankAccount*>(&account); // Remove const-ness
            }
        }
        return nullptr; // Return nullptr if account is not found
    }

    void deposit(int accNum, double amount) {
        BankAccount* account = findAccount(accNum);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(int accNum, double amount) {
        BankAccount* account = findAccount(accNum);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void getBalance(int accNum) const {
        BankAccount* account = findAccount(accNum);
        if (account) {
            account->getBalance();
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice = 0;
    int accNum;
    string name;
    double amount;

    while (choice != 5) {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Get Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Holder Name: ";
                cin >> name;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Initial Balance: ";
                cin >> amount;
                bank.createAccount(name, accNum, amount);
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                bank.deposit(accNum, amount);
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                bank.withdraw(accNum, amount);
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                bank.getBalance(accNum);
                break;

            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}