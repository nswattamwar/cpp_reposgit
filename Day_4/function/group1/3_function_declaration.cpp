#include <iostream>

// Function declaration
void myFunction();

// Main function
int main() {
    myFunction(); // Calling the function
    return 0;
}

// Function definition
void myFunction() {
    std::cout << "Hello, World from myFunction after main" << std::endl;
}