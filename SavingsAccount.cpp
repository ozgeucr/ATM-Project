#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "BankAccount.cpp"
using namespace std;

class SavingsAccount: public BankAccount{
private:
    double interestRate; // as a percentage
public:
    SavingsAccount(string accName, int accNumber, double initialBalance, int pinCode, double rate) : BankAccount(accName, accNumber, initialBalance, pinCode){
        this->interestRate = rate;

    }
    double calculateInterest(){
        double interest = (balance * interestRate) / 100.0;
        balance += interest;
        cout << "Interest added: $" << interest << endl;
        cout << "New Balance after interest: $" << balance << endl;
        return balance;
    }
    void showInfos() override {
        BankAccount::showInfos();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
    void saveToFile(ofstream &file) override{
        file << "S" << endl;
        file << name << endl;
        file << accountNumber << endl;
        file << balance << endl;
        file << pinCode << endl;
        file << interestRate << endl;
    }
};