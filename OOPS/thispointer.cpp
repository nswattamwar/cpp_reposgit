
#include <iostream>

class MyClass {
private:
    int value;

public:
    
    MyClass(int value) {
        this->value = value; // Resolve name conflict using this
    }

    void setValue(int value) {
        this->value = value; // Assign argument to member variable
    }

    void showValue() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    //MyClass obj;
    MyClass obj(10);
    obj.showValue(); // Displays 10
    obj.setValue(20);
    obj.showValue(); // Displays 20

    return 0;
}
