#pragma once
#include <ctime>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class BankAccount {
    protected:
        string name;
        int accountNumber;
        double balance;
        int pinCode;
        void logTransaction(const string& type, double amount) {
            ofstream file("transaction_log.txt", ios::app);
            if (file.is_open()) {
                time_t now = time(0);
                tm* ltm = localtime(&now);
                file << "[" << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " "
                     << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] ";
                file << name <<" - " << type << " - " << amount << " $ " << endl;
                file.close();
            }
            
        }
    public:
        BankAccount(string accName, int accNumber, double initialBalance, int pinCode){
            name = accName;
            accountNumber = accNumber;
            balance = initialBalance;
            this->pinCode = pinCode;
        }
        BankAccount(string accName, int accNumber, int pinCode){
            name = accName;
            accountNumber = accNumber;
            this->pinCode = pinCode;
        }

        bool verifyPin(int inputPin) {
            return inputPin == pinCode;
        }
        virtual void showInfos() {
            cout << "Account Holder: " << name << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
            logTransaction("Deposit", amount);
        }
        void withdraw(double amount) {
            if (amount > balance) {
               throw runtime_error("Insufficient funds for withdrawal!");
            }
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
            logTransaction("Withdrawal", amount);
        }

        void transfer(BankAccount& target, double amount){
            if(balance < amount){
                throw runtime_error("Insufficient funds for transfer!");
            } 
            if (amount<=0) {
                throw runtime_error("Transfer amount must be positive!");
            }
            balance -= amount;
            target.deposit(amount);
            cout << "Transferred: $" << amount << " to " << target.name << endl;
            cout << "New Balance: $" << balance << endl;
            logTransaction("Transfer to " + target.name, amount);
            
        }
        int getAccountNumber() const {
            return accountNumber;
        }

        virtual void saveToFile(ofstream& file) {
            file <<  "N" <<endl;
            file << name << endl;
            file << accountNumber << endl;
            file << balance << endl;
            file << pinCode << endl;
        }
};

