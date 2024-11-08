//
// Created by jared on 10/20/2024.
//

#include "atm.h"
#include <iostream>
#include <stdexcept>
#include <limits>

// Define global variables
std::unordered_map<std::string, BankAccount> accounts;
char menuInput;

// Introduction menu
void printIntroMenu() {
    std::cout << "\nPlease select an option from the menu below:\n";
    std::cout << "l  -> Login\n";
    std::cout << "c -> Create New Account\n";
    std::cout << "q -> Quit\n";
    std::cout << "> ";
    std::cin >> menuInput;
}

// Main banking menu
void printMainMenu() {
    std::cout << "\nd  -> Deposit Money\n";
    std::cout << "w -> Withdraw Money\n";
    std::cout << "r  -> Request Balance\n";
    std::cout << "q  -> Quit\n";
    std::cin >> menuInput;
}

// Helper function for numeric input validation
double getValidatedAmount() {
    double amount;
    while (true) {
        std::cin >> amount;
        if (std::cin.fail() || amount < 0) {
            std::cout << "Invalid amount. Please enter a positive number: $";
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        } else {
            break;
        }
    }
    return amount;
}

// Create a new account
void createAccount() {
    std::string userID, password;

    std::cout << "Please enter your user id: ";
    std::cin >> userID;

    if (accounts.contains(userID)) {
        std::cout << "User ID already exists. Please try another one.\n";
        return;
    }

    std::cout << "Please enter your password: ";
    std::cin >> password;

    accounts[userID] = {password, 0.0};
    std::cout << "Thank You! Your account has been created!\n";
}

// Login process
void login() {
    std::string userID, password;

    std::cout << "Please enter your user id: ";
    std::cin >> userID;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if (accounts.contains(userID) && accounts[userID].password == password) {
        std::cout << "Access Granted!\n";
        BankAccount &account = accounts[userID];
        bool loggedIn = true;
        while (loggedIn) {
            printMainMenu();
            switch (menuInput) {
                case 'd': {
                    std::cout << "Amount of deposit: $";
                    double depositAmount = getValidatedAmount();
                    account.balance += depositAmount;
                    std::cout << "Deposit successful!\n";
                    break;
                }
                case 'w': {
                    std::cout << "Amount of withdrawal: $";
                    double withdrawAmount = getValidatedAmount();
                    try {
                        if (withdrawAmount > account.balance) {
                            throw std::runtime_error("Insufficient balance!");
                        }
                        account.balance -= withdrawAmount;
                        std::cout << "Withdrawal successful!\n";
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << "\n";
                    }
                    break;
                }
                case 'r': {
                    std::cout << "Your balance is $" << account.balance << "\n";
                    break;
                }
                case 'q': {
                    std::cout << "Thanks for stopping by!\n";
                    loggedIn = false;
                    break;
                }
                default:
                    std::cout << "Invalid option! Please try again.\n";
            }
        }
    } else {
        std::cout << "******** LOGIN FAILED! ********\n";
    }
}

// Program process
void start() {
    bool running = true;
    while (running) {
        printIntroMenu();
        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                std::cout << "Thank you for using Jared's ATM Machine. Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid option! Please try again.\n";
        }
    }
}
