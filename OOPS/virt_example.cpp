#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
   virtual void start() { // Virtual function
        cout << "Vehicle is starting..." << endl;
    }   
};

// Derived class: Car
class Car : public Vehicle {
public:
    void start()  { // Override the virtual function
        cout << "Car is starting with ignition key!" << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
public:
    void start()  { // Override the virtual function
        cout << "Bike is starting with a kick!" << endl;
    }
};

// Main function to demonstrate polymorphism
int main() {
    Vehicle* vehicle1 = new Car(); // Pointer to base class, points to Car
    Vehicle* vehicle2 = new Bike(); // Pointer to base class, points to Bike

    vehicle1->start(); // Calls Car's start()
    vehicle2->start(); // Calls Bike's start()

    delete vehicle1; // Clean up
    delete vehicle2;

    return 0;
}
