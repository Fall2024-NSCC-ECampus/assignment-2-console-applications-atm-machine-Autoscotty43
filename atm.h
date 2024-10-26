//
// Created by jared on 10/20/2024.
//

#ifndef ATM_H
#define ATM_H

#include <string>
#include <unordered_map>

// Store user details
struct BankAccount {
    std::string password;
    double balance = 0.0;
};

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

// Global variables
extern std::unordered_map<std::string, BankAccount> accounts;
extern char menuInput;

#endif

