# 🏧 C++ ATM & Banking System Simulation

This project is a fully functional, console-based ATM and Banking System simulation developed using **C++** and **Object-Oriented Programming (OOP)** principles. 

It features a robust architecture that handles user accounts, performs financial transactions, ensures data persistence via file I/O, and manages memory dynamically.

## 🚀 Technical Highlights & Features

This project demonstrates proficiency in the following Computer Science and C++ concepts:

* **OOP Architecture:** Utilizes Class design, Inheritance (`BankAccount` -> `SavingsAccount`), and Encapsulation.
* **Polymorphism:** Implements `virtual` functions to manage different account types dynamically using Base Class Pointers.
* **Memory Management:** Manual memory management using `new` and `delete` operators on the Heap. Uses `std::vector<BankAccount*>` to prevent **Object Slicing**.
* **Data Persistence:** Custom serialization and deserialization algorithms to save/load user data from `bank_database.txt` upon startup and exit.
* **Transaction Logging:** real-time logging of all financial activities (Deposit, Withdraw, Transfer) with timestamps to `transaction_log.txt`.
* **Error Handling:** Robust exception handling using `try-catch` blocks and custom throw statements to prevent runtime crashes.
* **Input Validation:** Helper functions to prevent infinite loops when invalid data types (e.g., characters instead of integers) are entered.
* **Build Automation:** Integrated `Makefile` for one-command compilation and execution.

## 📂 File Structure

* `mainATM.cpp`: Application entry point and main user interface loop.
* `Bank.cpp`: Controller class that manages account storage, authentication, and file operations.
* `BankAccount.cpp`: Base class defining standard account behaviors.
* `SavingsAccount.cpp`: Derived class with specific features like Interest Rate calculation.
* `Makefile`: Configuration file for automated building.
* `bank_database.txt`: Persistent storage for user account data.
* `transaction_log.txt`: Audit trail for transaction history.

## 🛠️ Installation & Usage

### Prerequisites
* A C++ Compiler (G++ recommended)
* Make tool (Optional, but recommended)

### How to Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/ATM-Project.git](https://github.com/YOUR_USERNAME/ATM-Project.git)
    cd ATM-Project
    ```

2.  **Compile and Run (using Makefile):**
    ```bash
    make run
    ```

3.  **Clean Build Files:**
    ```bash
    make clean
    ```

## 🎮 Usage Scenario

Upon launching, the system loads existing users from the database.

1.  **Login:** Enter Account Number and PIN (System locks after 3 failed attempts).
2.  **Menu Options:**
    * `1. Show Account Info`: Displays balance and account details.
    * `2. Deposit`: Adds funds to the account (Logged).
    * `3. Withdraw`: deducts funds with balance checks.
    * `4. Transfer`: Sends money to another valid account ID.
    * `5. Exit`: Saves all data to the text database and closes the application.

## 👤 Author

**Özge Uçar** - Computer Engineering Student
