#include <iostream>
using namespace std;

int main() {
    int num = 5;
    int counter = 1;

    cout << "Multiplication table of 5:\n";
    do {
        cout << num * counter << endl;
        counter++;
    } while (counter <= 10);

}