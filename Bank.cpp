#pragma once
#include <fstream>
#include <vector>
#include "BankAccount.cpp"
#include "SavingsAccount.cpp"
class Bank{
private:
    std::vector<BankAccount*> accounts;
public:
    void addAccount(BankAccount* newAccount) {
        accounts.push_back(newAccount);
    }
    BankAccount* getAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        return nullptr; // Account not found
    }
    ~Bank() {
        for (auto& account : accounts) {
            delete account;
        }
        accounts.clear();
    }
    void saveDatabase(string filename) {
        ofstream file(filename);
        for (auto& account : accounts) {
            account->saveToFile(file);
        }
        file.close();
    }
    void loadDatabase(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return;
        }
        string type;
        while(file >> type){
            if(type == "N"){
                string name;
                int accNumber;
                double balance;
                int pinCode;
                file >> name >> accNumber >> balance >> pinCode;
                BankAccount* account = new BankAccount(name, accNumber, balance, pinCode);
                addAccount(account);
            } else if (type == "S"){
                string name;
                int accNumber;
                double balance;
                int pinCode;
                double interestRate;
                file >> name >> accNumber >> balance >> pinCode >> interestRate;
                SavingsAccount* account = new SavingsAccount(name, accNumber, balance, pinCode, interestRate);
                addAccount(account);
            }
        }
        file.close();
    }    

};