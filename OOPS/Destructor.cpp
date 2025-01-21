#include <iostream>
#include <string>

class MyClass {
private:
    std::string* data;

public:
    // Constructor
    MyClass(const std::string& value) {
       // data = new std::string(value); // Dynamically allocate memory
      std::cout << "Constructor: Resource allocated for data = " << *data << std::endl;
    }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor: Cleaning up resources for data = " << *data << std::endl;
       // delete data; // Free dynamically allocated memory
    }
};

int main() {
    {
        MyClass obj("Hello, World!"); // Constructor is called here
    } // Destructor is called here, as obj goes out of scope

    std::cout<<"END"<<std::endl;

    return 0;
}
