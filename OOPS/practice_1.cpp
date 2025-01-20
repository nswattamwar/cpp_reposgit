#include<iostream>
using namespace std;

struct certificate
{
    int student_rollno=21;
    int maths;
    int history;
    int english;
};

int main()
{

    struct certificate student1;
    student1.maths=90;
    student1.history=80;
    student1.english=100;

    int sum;

    sum= student1.maths =student1.history + student1.english;

    if (sum>150)
    {
        cout<<"Student is passed";
    }
    else
    {
        cout<<"Student is failed";
    }

    
}