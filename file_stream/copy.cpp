#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("/home/asd/cpp_reposgit/file_stream/read.txt");
    ofstream outFile("/home/asd/cpp_reposgit/file_stream/write.txt");

    string line;
    if (inFile.is_open() && outFile.is_open()) 
    
    {
        while (getline(inFile, line)) {
            outFile << line << endl;
        }
        inFile.close();
        outFile.close();
    } 
    
    else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}