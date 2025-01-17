#include <iostream>

// Function that takes an integer parameter by reference
void passByReference(int &num) {
    num = 100; // This change will affect the original variable
}

int main() {
    int number = 5;
    std::cout << "Before function, number is: " << number << std::endl;
    passByReference(number);
    std::cout << "After function, number is: " << number << std::endl;
    return 0;
}