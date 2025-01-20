#include <iostream>

// Function to add numbers and return sum
int add(int a, int b) {
    int c = a + b;
    return c;
}

// Main function
int main() {
    int val1 = 10;
    int val2 = 20;
    int sum = add(val1, val2); // Calling the function
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}