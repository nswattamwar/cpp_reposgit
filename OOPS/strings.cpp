#include <iostream>
#include <string>

int main() {
    std::string name = "Nilesh";
    std::cout << "Hello, " << name << std::endl;


    //concatination
    std::string first = "Hello";
    std::string second = " World!";
    std::string result = first + second;
    std::cout << "concatinate "<<result<<std::endl;


    //length
    std::cout<<"result of concatination  " << result<<std::endl;
    std::string s = "Example";
    std::cout << s.length()<<std::endl;


    //accessing element 

    std::cout<<"Accessing element "<<s.at(1)<<std::endl;

    //append string 
    std::string str = "Hello";
    str.append(" World!");

    //replacing part of string 
    std::string str1 = "Good Morning";
    str1.replace(5, 7, "Evening"); // Changes to "Good Evening"

    std::cout<<"Final String is "<<str1<<std::endl;

    //compare strig 
    std::string a = "apple";
    std::string b = "banana";
    if (a < b) {
        std::cout << "Apple comes before Banana";
    }
    int results = a.compare(b);

    return 0;
}
