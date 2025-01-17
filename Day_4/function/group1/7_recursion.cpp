#include <iostream>

// Function to find factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Main function
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl;
    return 0;
}