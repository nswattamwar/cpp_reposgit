#include <iostream>

// Function to add numbers
int add(int a, int b) {
    a=100;
    int c = a + b;
    return c;
}

// Main function
int main() {
    int val1 = 10, d=0;
    int val2 = 20;
    d=add(val1, val2); // Calling the function
    std::cout << "Sum is " << d << std::endl;

    std::cout <<" a is " << val1 << std::endl;


    return 0;
}