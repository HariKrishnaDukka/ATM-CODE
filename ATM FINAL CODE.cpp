#include <iostream>   // for input/output
#include <vector>     // for vector container
#include <string>     // for string type
using namespace std;  // use standard namespace
class Account {
private:
    string accNo;   // account number
    string name;    // account holder name
    int pin;        // pin number
    double balance; // account balance
public:
    Account(string a, string n, int p, double b)
    {
        accNo = a;
        name = n;
        pin = p;
        balance = b;
    }
    string getAccNo(){return accNo; }
    string getName(){return name; }
    bool checkPin(int entered) 
    {
        if (entered == pin)
            return true;
        return false;
    }
    void showBalance() 
    {
        cout<<"Your balance is: Rs."<<balance<<endl;
    }
    void deposit(double amt) 
    {
        if (amt > 0) 
        {
            balance += amt;
            cout <<"Deposited: Rs."<<amt<<endl;
        } 
        else 
        {
            cout <<"Invalid amount!"<<endl;
        }
    }
    void withdraw(double amt) 
    {
        if (amt <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        } 
        else if (amt > balance)
        {
            cout<<"Insufficient funds!"<<endl;
        }
        else 
        {
            balance -= amt;
            cout<<"Withdrawn: Rs."<<amt<<endl;
        }
    }
};

class ATM 
{
private:
    vector<Account> users; // list of accounts

public:
    ATM() 
    {
        users.push_back(Account("1001","Hari",1234,10000));
        users.push_back(Account("1002","Krishna",5678,7500));
        users.push_back(Account("1003","Dukka",4321,5000));
    }

    Account* getAccount(string num) {
        for (int i = 0; i<users.size(); i++) 
        {
            if (users[i].getAccNo() == num) 
            {
                return &users[i];
            }
        }
        return nullptr;
    }
    void run() 
    {
        cout<<"=== Welcome to ATM ==="<<endl;
        string num;
        int enteredPin;
        cout<<"Enter Account Number: ";
        cin>>num;
        Account* acc = getAccount(num);
        if(acc == nullptr) 
        {
            cout<<"Account not found!"<<endl;
            return;
        }
        cout<<"Enter PIN: ";
        cin>>enteredPin;
        if(!acc->checkPin(enteredPin)) 
        {
            cout<<"Wrong PIN!"<<endl;
            return;
        }

        cout<<"Hello,"<< acc->getName()<<endl;

        int choice;
        double amt;

        do {
            cout<<"\n--- Menu ---"<<endl;
            cout<<"1. Balance"<<endl;
            cout<<"2. Deposit"<<endl;
            cout<<"3. Withdraw"<<endl;
            cout<<"4. Exit"<<endl;
            cout<<"Enter option: ";
            cin>>choice;

            switch (choice) {
                case 1:
                    acc->showBalance();
                    break;
                case 2:
                    cout<<"Enter deposit amount: ";
                    cin>>amt;
                    acc->deposit(amt);
                    break;
                case 3:
                    cout<<"Enter withdrawal amount: ";
                    cin>>amt;
                    acc->withdraw(amt);
                    break;
                case 4:
                    cout<<"Thank you!"<<endl;
                    break;
                default:
                    cout<<"Invalid option."<<endl;
            }
        }
        while(choice != 4);
    }
};
int main() {
    ATM atm;
    atm.run();
    return 0;
}

/* 
================ EXPLANATION OF VARIABLES USED =================

accNo → Stores account number of a user (string).
name  → Stores account holder’s name (string).
pin   → Stores secret PIN for authentication (int).
balance  → Stores the amount of money in account (double).
users → A vector (list) that stores all Account objects inside ATM.
num   → Stores account number entered by user at login (string).
enteredPin → Stores the PIN entered by the user (int).
acc   → A pointer to the Account object that matches the entered account number.
choice → Stores menu option chosen by the user (int).
amt    → Stores the money entered by user for deposit or withdrawal (double).
atm    → Object of ATM class, created in main() to run the program.

TEST CASES:
Test Case 1: Correct Login & Balance Check

Input

Account Number: 1001
PIN: 1234
Choice: 1
Choice: 4


Expected Output

=== Welcome to ATM ===
Enter Account Number: 1001
Enter PIN: 1234
Hello, Hari

--- Menu ---
1. Balance
2. Deposit
3. Withdraw
4. Exit
Enter option: 1
Your balance is: Rs.10000

--- Menu ---
Enter option: 4
Thank you!

✅ Test Case 2: Invalid Account Number

Input

Account Number: 9999


Expected Output

=== Welcome to ATM ===
Enter Account Number: 9999
Account not found!

✅ Test Case 3: Wrong PIN

Input

Account Number: 1002
PIN: 1111


Expected Output

=== Welcome to ATM ===
Enter Account Number: 1002
Enter PIN: 1111
Wrong PIN!

✅ Test Case 4: Deposit Money

Input

Account Number: 1003
PIN: 4321
Choice: 2
Deposit Amount: 2000
Choice: 1
Choice: 4


Expected Output

=== Welcome to ATM ===
Enter Account Number: 1003
Enter PIN: 4321
Hello, Dukka

--- Menu ---
Enter option: 2
Enter deposit amount: 2000
Deposited: Rs.2000

--- Menu ---
Enter option: 1
Your balance is: Rs.7000

--- Menu ---
Enter option: 4
Thank you!

✅ Test Case 5: Withdraw Money (Sufficient Balance)

Input

Account Number: 1002
PIN: 5678
Choice: 3
Withdraw Amount: 2000
Choice: 1
Choice: 4


Expected Output

=== Welcome to ATM ===
Enter Account Number: 1002
Enter PIN: 5678
Hello, Krishna

--- Menu ---
Enter option: 3
Enter withdrawal amount: 2000
Withdrawn: Rs.2000

--- Menu ---
Enter option: 1
Your balance is: Rs.5500

--- Menu ---
Enter option: 4
Thank you!

✅ Test Case 6: Withdraw Money (Insufficient Balance)

Input

Account Number: 1003
PIN: 4321
Choice: 3
Withdraw Amount: 10000
Choice: 4


Expected Output

=== Welcome to ATM ===
Enter Account Number: 1003
Enter PIN: 4321
Hello, Dukka

--- Menu ---
Enter option: 3
Enter withdrawal amount: 10000
Insufficient funds!

--- Menu ---
Enter option: 4
Thank you!


================================================================
*/
