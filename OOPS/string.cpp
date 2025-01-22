#include<iostream>
#include<string>
using namespace std;

int main()
{
    string message="This is CPP training for beginners";
    string cut;
    cout<<message<<endl;
    cout<<"Enter string to find"<<endl;
    cin>>cut;
    
    int a=message.find(cut);
    int len= cut.length();
    cout<<a<<endl;

    message=message.substr((a+len),message.length());

    cout<<message<<endl;

}
