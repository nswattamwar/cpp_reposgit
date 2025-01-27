/*Write a class ObjectTracker that has the following:
•
•A static data member count to track the number of objects created.
•A static member function getCount() to return the value of count.
•A constructor that increments count each time an object is created.
•A destructor that decrements count each time an object is destroyed.
 
Write a main() function to demonstrate:
 
•Creating multiple objects of ObjectTracker.
•Displaying the count using getCount().
•Destroying objects and observing how the count changes.*/

#include <iostream>
using namespace std;

class ObjectTracker 
{
    private:
        static float count;
    public:
        ObjectTracker()
        {
            count=count+0.1;
            cout << "Object created. Total objects: " << count << endl;
        }
        ~ObjectTracker()
        {
            count=count-0.1;
            cout << "Object destroyed. Total objects: " << count << endl;
        }
        static int getCount()
        {
            return count;
        }
};

int main()
{
    cout << "Initial number of objects: " << ObjectTracker::getCount() << endl;
    ObjectTracker obj1;
    ObjectTracker obj2;
    cout << "Current number of objects: " << ObjectTracker::getCount() << endl;
    {
        ObjectTracker obj3;
        cout << "Current number of objects (inside block): " << ObjectTracker::getCount() << endl;
    }
    cout << "Current number of objects: " << ObjectTracker::getCount() << endl;
    return 0;
}
