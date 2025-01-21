// employee details using class

#include <iostream>
using namespace std;

class Employee
{
   public:
    int id;
    string name;
    float salary;

    void details(int i, string name1, float salary1)
    {
        id = i;
        name = name1;
        salary = salary1;
    }

    void Display()
    {
        cout << "Employee id: " << id << endl;
        cout << "Employee name: " << name << endl;
        cout << "Employee salary: " << salary << endl;
    }
};

int main()
{
    Employee e1;
    e1.details(1001, "ram", 11.72);
    e1.Display();

    Employee e2;
    e2.details(1002, "shyam", 12.34);
    e2.Display();
    
    Employee e3;
    e3.details(1003, "mohan", 43.45);
    e3.Display();
    
    
    return 0;


}