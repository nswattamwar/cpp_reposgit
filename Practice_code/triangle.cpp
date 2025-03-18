#include<iostream>
//C++ program to create a class called Triangle that has private member variables for the lengths of its three sides. Implement member functions to determine if the triangle is equilateral, isosceles, or scalene.
using namespace std;


class Triangle {
    private:
        double side1;
        double side2;
        double side3;
    
    public:
        // Constructor to initialize the sides of the triangle
        Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    
        // Function to check if the triangle is equilateral
        bool isEquilateral() {
            return (side1 == side2 && side2 == side3);
        }
    
        // Function to check if the triangle is isosceles
        bool isIsosceles() {
            return (side1 == side2 || side2 == side3 || side1 == side3);
        }
    
        // Function to check if the triangle is scalene
        bool isScalene() {
            return (side1 != side2 && side2 != side3 && side1 != side3);
        }
    
        // Function to display the type of triangle
        void displayType() {
            if (isEquilateral()) {
                cout << "The triangle is equilateral." << endl;
            } else if (isIsosceles()) {
                cout << "The triangle is isosceles." << endl;
            } else if (isScalene()) {
                cout << "The triangle is scalene." << endl;
            } else {
                cout << "The triangle type is undefined." << endl;
            }
        }
    };
    
    int main() {
        // Create a Triangle object
        Triangle t1(3.0, 3.0, 3.0);
        t1.displayType(); // Output: The triangle is equilateral.
    
        Triangle t2(3.0, 4.0, 4.0);
        t2.displayType(); // Output: The triangle is isosceles.
    
        Triangle t3(3.0, 4.0, 5.0);
        t3.displayType(); // Output: The triangle is scalene.
    
        return 0;
    }
