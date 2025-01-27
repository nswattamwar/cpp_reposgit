#include<iostream>
using namespace std;

class Bank
{
    private:
    int accountNumber;
    string accountHolderName;
    float balance;

    public:

    Bank(int accountNumber, string accountHolderName, float balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void deposit(float amount)
    {
        balance += amount;
    }

    void withdraw(float amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }
    void balanceEnquiry()
    {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder Name: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

};


int main()
{   float dep_amount, wit_amount;
    int option_no;
    Bank Ac(123456, "Premalatha", 1000);   
    
        Ac.balanceEnquiry();
        
        cout<<"===Welcome to C++ Bank===\n===choose any 1 option==="<<endl;
        cout<<"1. Deposit"<<endl;
        cout<<"2. Withdraw"<<endl;
        cout<<"3. Balance Enquiry"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>option_no;
        cout<<"option selected: "<<option_no<<endl;

        switch (option_no)
        {
        case 1:
            //functionality for deposit
            cout<<"Enter the amount you want to deposit: ";
            cin>>dep_amount;
            Ac.deposit(dep_amount);
            Ac.balanceEnquiry();
            
            break;
        case 2:
            //functionality for withdraw
            cout<<"Enter the amount you want to withdraw: ";
            cin>>wit_amount;
            Ac.withdraw(wit_amount);
             Ac.balanceEnquiry();
            break;
        case 3:
            // Add functionality for balance enquiry
            Ac.balanceEnquiry();
            break;
        case 4:
            // Add functionality for exit
            cout<<"Get lost"<<endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
}