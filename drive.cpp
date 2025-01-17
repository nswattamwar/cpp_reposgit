#include<iostream>
using namespace std;
 
void exercise1(int age, bool car) {
    if(age>16)
    { 
        if(car==1)
        { 
            cout<<("Yes - you can drive!");
        }

        else
        {
            cout<<("No - Buy a car!");
        }
    }
    else
    
        cout<<("age is less than 16");
    
 
}
 
 
int main() {
    int age=52;
    bool car=0;
 exercise1(age, car); 

return 0;
}