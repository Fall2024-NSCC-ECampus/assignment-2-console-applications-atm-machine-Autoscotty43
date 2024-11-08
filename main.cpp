//
// Created by jared on 10/20/2024.
//

#include "atm.h"
#include <iostream>

int main() {
    try {
        std::cout << "Hi! Welcome to Jared's ATM Machine!\n\n";
        start();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }
    return 0;
}
