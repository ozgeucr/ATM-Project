#include <iostream>
#include <limits>
#include "Bank.cpp"
double getValidDouble(string message) {
    double value;
    while (true) {
        std::cout << message;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
int getValidInt(string message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
int main() {



    Bank bank;
    bank.loadDatabase("bank_database.txt");
/*
    BankAccount* ozge = new BankAccount("Ozge", 12345, 5000.0, 1453);
    bank.addAccount(ozge);

    // 2. Emirhan (Normal Hesap)
    BankAccount* emirhan = new BankAccount("Emirhan", 67890, 80000.0, 2003);
    bank.addAccount(emirhan);

    // 3. Çınar (Vadeli Hesap - Savings)
    SavingsAccount* cınar = new SavingsAccount("Çınar", 11223, 3000.0, 3210, 2.5);
    bank.addAccount(cınar);
*/
    int accNumber;
    cout << "Welcome to the ATM System!" << endl;
    cout << "Please log in to your account." << endl;
    BankAccount* userAccount = nullptr;
    while (true) {
        accNumber= getValidInt("Enter Account Number: ");
        userAccount = bank.getAccount(accNumber);
        if (userAccount != nullptr) {
            break;
        } else {
            cout << "Account not found. Please try again." << endl;
        }
    }
    
    int attempts = 0;
    int maxAttempts = 3;
    while (true) {
        int inputPin= getValidInt("Enter PIN: ");
        if (userAccount->verifyPin(inputPin)) {
            cout << "Login successful!" << endl;
            break;
        } else {
            attempts++;
            int remainingAttempts = maxAttempts - attempts;
            if (attempts==maxAttempts) {
                cout << "Maximum PIN attempts exceeded. Exiting..." << endl;
                return 0;
            }
            else {
                cout << "Incorrect PIN! You have " << remainingAttempts << " attempt(s) left." << endl;
            }
        }
    }    


    int choice;
    double amount;
    while (true){
            std::cout << "1. Show Account Info\n2. Deposit\n3. Withdraw\n4. Transfer Money\n5. Exit" << std::endl;
            choice = getValidInt("Choose an option");

            if (choice == 1) {
                userAccount->showInfos();
            }
            
            else if (choice == 2) {
                try {
                    amount= getValidDouble("Enter amount to deposit: ");
                    userAccount->deposit(amount);
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
            } 
            
            else if (choice == 3) {
                try {
                    amount= getValidDouble("Enter amount to withdraw: ");
                    userAccount->withdraw(amount);
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                } 

            }

            else if (choice==4) {
                try {
                    cout << "Enter Target Account Number: ";
                    int targetAccNumber;
                    cin >> targetAccNumber;
                    BankAccount* targetAccount = bank.getAccount(targetAccNumber);
                    if (targetAccount == nullptr) {
                        cout << "Target account not found!" << endl;
                        continue;
                    }
                    else {
                        amount= getValidDouble("Enter amount to transfer: ");
                        userAccount->transfer(*targetAccount, amount);
                   }
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                
                }
            }

            else if (choice == 5) {
                std::cout << "Exiting... Thank you for using the ATM System!" << std::endl;
                 bank.saveDatabase("bank_database.txt");
                break;
            } else {
               std::cout << "Invalid option. Please try again." << std::endl;
            }
    }
    return 0;
}