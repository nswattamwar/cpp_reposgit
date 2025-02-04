#include <iostream>
#include <thread>
#include <unistd.h>

void printMessage() {
    sleep(2);
    std::cout << "Hello from thread!" << std::endl;
}
void printMessage1()
{
    sleep(2);
    std::cout << "Hello from another thread!" << std::endl;
}

int main() {
    std::thread t(printMessage); // Create a thread
    std::thread t1(printMessage1); // Create a thread
    t.join(); // Wait for thread to finish
    t1.join();
    std::cout << "Hello from MAIN thread!" << std::endl;

    return 0;
}
