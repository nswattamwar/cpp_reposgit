#include <iostream>

// Function that takes an integer parameter by value
void passByValue(int num) {
    num = 100; // This change will not affect the original variable
}

int main() {
    int number = 5;
    std::cout << "Before function, number is: " << number << std::endl;
    passByValue(number);
    std::cout << "After function, number is: " << number << std::endl;
    return 0;
}