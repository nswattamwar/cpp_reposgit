
//You are designing a simple software system for an automotive company to manage different types of vehicles.
// Each vehicle should have a function to calculate fuel efficiency and display details. 
//The base class Vehicle will provide common functionality, and derived classes (like Car and Truck) will override these functions to provide specific behaviors.

#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
public:
    virtual double fuelEfficiency() = 0; // Pure virtual function
    virtual void displayDetails() = 0;  // Pure virtual function
};

// Derived class: Car
class Car : public Vehicle {
private:
    double distance;     // Distance traveled in km
    double fuelConsumed; // Fuel consumed in liters
public:
    Car(double d, double f) : distance(d), fuelConsumed(f) {}

    double fuelEfficiency() override {
        return distance / fuelConsumed; // Efficiency in km/l
    }

    void displayDetails() override {
        cout << "Car Details: " << endl;
        cout << "  Distance: " << distance << " km" << endl;
        cout << "  Fuel Consumed: " << fuelConsumed << " liters" << endl;
    }
};

// Derived class: Truck
class Truck : public Vehicle {
private:
    double distance;     // Distance traveled in km
    double fuelConsumed; // Fuel consumed in liters
    double loadFactor;   // Load factor (efficiency modifier)
public:
    Truck(double d, double f, double lf) : distance(d), fuelConsumed(f), loadFactor(lf) {}

    double fuelEfficiency() override {
        return (distance / fuelConsumed) * loadFactor;
    }

    void displayDetails() override {
        cout << "Truck Details: " << endl;
        cout << "  Distance: " << distance << " km" << endl;
        cout << "  Fuel Consumed: " << fuelConsumed << " liters" << endl;
        cout << "  Load Factor: " << loadFactor << endl;
    }
};

// Function to demonstrate polymorphism
void printFuelEfficiency(Vehicle* v) {
    v->displayDetails();
    cout << "  Fuel Efficiency: " << v->fuelEfficiency() << " km/l" << endl;
    cout << "--------------------------------------" << endl;
}

int main() {
    Car car(500, 25);        // A car that traveled 500 km with 25 liters of fuel
    Truck truck(300, 50, 0.8); // A truck that traveled 300 km, consumed 50 liters, and has a load factor of 0.8

    cout << "Vehicle Fuel Efficiency Report:\n";
    printFuelEfficiency(&car);
    printFuelEfficiency(&truck);

    return 0;
}
