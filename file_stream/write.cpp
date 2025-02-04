#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data_write");
    if (outFile.is_open()) {
        outFile << "Hello, file!" << endl;
        outFile << "Hello, file!" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file";
    }
    return 0;
}