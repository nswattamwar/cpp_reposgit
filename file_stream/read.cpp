#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("/home/jeevan/session/files/data_read.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}