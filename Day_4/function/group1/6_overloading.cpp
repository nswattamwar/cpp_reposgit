#include <iostream>

// Function to add 2 integers
int add(int a, int b) {
    int c = a + b;
    return c;
}

// Overloading, Function to add 2 doubles
double add(double a, double b) {
    double c = a + b;
    return c;
}

// Main function
int main() {
    int val1 = 10;
    int val2 = 20;
    int sum1 = add(val1, val2); // Calling the function
    std::cout << "Sum is " << sum1 << std::endl;
    
    double val3 = 1.7;
    double val4 = 2.1;
    double sum2 = add(val3, val4); // Calling the function
    std::cout << "Sum is " << sum2 << std::endl;

    return 0;
}