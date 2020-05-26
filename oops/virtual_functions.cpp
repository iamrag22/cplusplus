#include <iostream>
#include <string>

using namespace std;

class Account{
protected:
    double _balance {0.0};
    int _id;

public:
    
    Account(double balance, int id): _balance(balance),_id(id){

    }

    // This won't work. It requires a definition
    //virtual void PrintBalance();

    virtual void PrintBalance(){
        cout << "Base Account balance is "<< _balance << endl;
    }

    // Pure virtual function
    virtual void PrintAccountId() = 0; 
};

class CheckingAccount:public Account{
public:
    CheckingAccount(double d, int id ): Account(d, id){}

    void PrintBalance(){
        cout << "Checking Account balance is "<< _balance << endl;
    }

    void PrintAccountId(){
        cout << "Checking Account Id is  "<< _id << endl;
    }
};

class SavingsAccount:public Account{
public:
    SavingsAccount(double d, int id ): Account(d, id){}

    void PrintBalance(){
        cout << "Savings Account balance is "<< _balance << endl;
    }

    void PrintAccountId(){
        cout << "Savings Account Id is  "<< _id << endl;
    }
};


int main(){
    // After adding a pure virtual function, Account is abstract. So can't be instantiated.
    // Account a{100.0};
    // a.PrintBalance();

    CheckingAccount chAccount = CheckingAccount{200, 1};
    chAccount.PrintBalance();
    chAccount.PrintAccountId();


    SavingsAccount saAccount = SavingsAccount {300,2};
    saAccount.PrintBalance();
    saAccount.PrintAccountId();

    // Reference types can have polymorphism and virtual functions
    Account *a1 = &chAccount;
    cout<< "Polymorphism: Will call Checking Account version of PrintBalance "<<endl;
    a1->PrintBalance();
    

    Account *a2 = &saAccount;
    cout<< "Polymorphism: Will call Savings Account version of PrintBalance "<<endl;
    a2->PrintBalance();
    
    return 0;
}