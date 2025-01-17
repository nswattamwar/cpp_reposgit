#include <iostream>
using namespace std;
int main() {
    int sum = 0;

    
    for (int i = 1; i <= 15; i += 2) {
        sum =sum + i; 
    }

    cout << "Sum of odd integers from 1 to 15: " << sum << endl;

}