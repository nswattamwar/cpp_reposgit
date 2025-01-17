#include <iostream>
using namespace std;
int main() {
    int num; 
    int counter = 1; 
    cout << "Enter a positive integer: ";
    cin >> num;

    cout << "Integers from 1 to " << num << ":\n";
    while (counter <= num) {
        cout << counter << " ";
        counter++;
    }

    cout <<endl;

}