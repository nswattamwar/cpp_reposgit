#include<iostream>
using namespace std;

class Person
{
    private:
    string name;
    int age;
    
    public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void disp_person()
    {
        cout<<"name"<<name<<endl;
        cout<<"age"<<age<<endl;
    }
};

class Student: public Person
{
    private:
    int stud_id;
    
    public:
    Student(string name, int age, int stud_id): Person(name, age)
    {
        this->stud_id = stud_id;
    }

    void stud_disp()
    {
        disp_person();
        cout<<"student id is "<<stud_id<<endl;

    }
};

int main()
{
    Student s1("name1", 10, 118 );
    s1.stud_disp();
    return 0;
}