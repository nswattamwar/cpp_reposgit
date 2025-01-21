#include <iostream>

class MyClass {
public:
    bool isSameObject(const MyClass& other) const {
        return this == &other; // Compare this with the address of another object
    }
};


class MyClass1 {
private:
    std::string name;

public:
    MyClass1(const std::string& name) : name(name) {}

    void printSelf() {
        std::cout << "Object Name: " << (*this).name << std::endl; // Dereference this to access the object
    }

    void printDirectly() {
        std::cout << "Object Name: " << this->name << std::endl; // Access directly using this
    }
};

int main() {
    MyClass obj1, obj2;

    std::cout << std::boolalpha;
    std::cout << "obj1 is the same as obj1: " << &obj1 << std::endl; // true
    std::cout << "obj1 is the same as obj2: " << &obj2 << std::endl; // false


    MyClass1 obj("MyObject");
    obj.printSelf();      // Access via dereferencing
    obj.printDirectly();  // Access directly via this pointer

    return 0;
}
