#include <iostream>

// Function to add numbers
void add(int a, int b) {
    int c = a + b;
    std::cout << "Sum is " << c << std::endl;
}

// Main function
int main() {
    int val1 = 10;
    int val2 = 20;
    add(val1, val2); // Calling the function
    return 0;
}