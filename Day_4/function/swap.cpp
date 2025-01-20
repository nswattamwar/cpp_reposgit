#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    //int temp = a;
    //a = b;
    //b = temp;



    a = a + b;
    b = a - b;
    a = a - b;

    //a = a * b;
    //b = a / b;
    //a = a / b;

    //a = a ^ b;
    //b = a ^ b;
    //a = a ^ b;

    //a = a + b - (b = a);
    
    //a = a * b / (b = a);
    //a = a ^ b ^ (b = a);
    //a = a + b ^ (b = a);



}

int main() {
    int a = 10, b = 20;
    cout << "Before swapping: a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "After swapping: a = " << a << " b = " << b << endl;
    return 0;
}