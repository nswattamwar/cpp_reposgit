#include <iostream>
using namespace std;

class base {
public:
    virtual void print() { cout << "1print base class\n"; } // Virtual function

    virtual void show() { cout << "1show base class\n"; } // Virtual function
};

class derived : public base {
public:
    void print() override { cout << "2print derived class\n"; } // Override virtual function

    void show() override  { cout << "2show derived class\n"; } // Override virtual function
};

int main()
{
    base* bptr; // Base class pointer
    derived d;  // Derived class object
    bptr = &d;  // Base class pointer points to derived class object

    // Virtual function, binded at runtime
    bptr->print(); // Calls derived class's print function

    // Virtual function, binded at runtime
    bptr->show(); // Calls derived class's show function

    return 0;
}