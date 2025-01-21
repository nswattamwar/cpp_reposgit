#include <iostream>
#include <string>

class MyClass {
private:
    std::string name;

public:
    // Constructor
    MyClass(const std::string& name) : name(name) {}

    // Copy Constructor
    MyClass(const MyClass& other) {
        std::cout << "Copy constructor called." << std::endl;
        this->name = other.name; // Use `this` to set the member of the current object
    }

    // Method to clone the current object
    MyClass clone() const {
        return MyClass(*this); // Pass the current object to the copy constructor
    }

    void display() const {
        std::cout << "Object Name: " << name << std::endl;
    }
};

int main() {
    MyClass obj1("OriginalObject");
    obj1.display();

    MyClass obj2 = obj1.clone(); // Clone the object using `this`
    obj2.display();

    return 0;
}