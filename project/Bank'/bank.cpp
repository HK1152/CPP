#include <iostream>
using namespace std;
void boo();
int size = 3;
class BankAccount
{
protected:
    long accnum;
    string holname;
    double balance;
    double overdraftLimit=10000;

public:
    BankAccount(long accnum, string holname, double balance,double overdraftLimit)
    {

        this->balance = balance;
        this->accnum = accnum;
        this->holname = holname;
        this->overdraftLimit=overdraftLimit;
    }

    double deposit(double dep)
    {
        if (dep > 0)
        {
            balance += dep;
            cout << "\nYour deposit has been completed successfully.";
            cout << "\nYour current balance is: " << balance;
        }
        else
        {
            cout << "Invalid deposit amount!";
        }
    }
    // void withdraw(double with)
    // {
    //     if (with > 0 && with <= balance)
    //     {
    //         balance -= with;
    //         cout << "\nWithdrawal successful from Savings Account. \nCurrent balance is: " << balance << endl;
    //     }
    //     else
    //     {
    //         cout << "\nInvalid withdrawal amount!.........";
    //     }
    // }
    void withdraw(double with)
    {
        if (with > 0  && balance >= with)
        {
            if(overdraftLimit >= with){
                balance -= with;
                overdraftLimit -= with;
                cout << "\nWithdrawal successful from Savings Account. Current balance is: " << balance << endl;
            }
          
        }
        else
        {
            cout << "\nInvalid withdrawal amount!.........";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void accountInfo()
    {
        cout << "Account number is: " << accnum << endl;
        cout << "Account holder name is: " << holname << endl;
        cout << "Account balance is: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
protected:
    double interestRate;

public:
    SavingsAccount(long accnum, string holname, double balance, double interestRate = 0.12)
        : BankAccount(accnum, holname, balance,overdraftLimit)
    {
        this->interestRate = interestRate;
    }



    void calculateInterest()
    {

        cout << "Calculated interest: " << balance * interestRate << endl;
    }
};

class CheckingAccount : public BankAccount
{


public:
    CheckingAccount(long accnum, string holname, double balance)
        : BankAccount(accnum, holname, balance,overdraftLimit)
    {
       
    }

    void withdraw(double with)
    {
        if (with > 0 && overdraftLimit >= with && balance >= with)
        {
            balance -= with;
            cout << "\nWithdrawal successful from Checking Account.\nCurrent balance: " << balance << endl;
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void checkOverdraft(double with)
    {
        
        overdraftLimit -= with;
        cout << "Available overdraft limit is: " <<  overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
protected:
    double interestRate = .8;
    int term;

public:
    FixedDepositAccount(long accnum, string holname, double balance, int term=1)
        : BankAccount(accnum, holname, balance,overdraftLimit)
    {
        //        this->interestRate = interestRate;
        this->term = term;
    }

    void calculateInterest(int term)
    {

        cout << "Calculated interest for term of " << term << " months is: " << (balance * interestRate * (term / 12)) << endl;
    }
};

int main()
{
    long accnu[3] = {11, 52, 44}, user_acc_num;
    string pwd[size] = {"a11", "b52", "c44"}, user_pwd;
    string acc_hol_name[size] = {"radha", "krishna", "balram"};
    double balanc[size] = {10000, 20000, 1000};
    int ch, dep,wit=0;
    cout << "welcome.......";
    cout << "\nEnter your account number:";
    cin >> user_acc_num;
    cout << "\nEnter your account password:";
    cin >> user_pwd;

    for (int i = 0; i < size; i++)
    {
        SavingsAccount user(accnu[i], acc_hol_name[i], balanc[i]);
        CheckingAccount users(accnu[i], acc_hol_name[i], balanc[i]);




        if (user_acc_num == accnu[i] && user_pwd == pwd[i])
        {
            while (1)
            {
                cout << "\n\n\n**************************************************************\n";
                cout << " \n######################";
                cout << "\n   ->SavingsAccount:-\n1.Display your account details. \n2.deposit \n3.withdraw \n4.Your Interest";
                cout << "\n5.check Overdraft";
                cout << " \n######################";
                cout << "\n\n   ->FixedDeposit(FD):-";
                cout << "\n6.calculate FD Interest ";
                cout << " \n######################";
                cout << " \n \n**************************************************************\n";
                cout << "\n\nEnter choice:-";
                cin >> ch;
                cout << " \n \n**************************************************************\n\n\n";
                switch (ch)
                {
                case 1:
                    user.accountInfo();
                    break;
                case 2:
                   
                    cout << "Enter a deposit amount:";
                    cin >> dep;
                    user.deposit(dep);
                    break;
                case 3:
                    
                    cout << "Enter a withdraw amount:";
                    cin >> wit;
                    user.withdraw(wit);
                    break;
                case 4:
                    user.calculateInterest();
                    break;
                    case 5 :
                    users.checkOverdraft(wit);
                }
            }
        }
    }

    // SavingsAccount s(446255, "Kavy", 1000);
    // user.accountInfo();
    // user.deposit(500);
    // user.withdraw(200);
    // user.calculateInterest();

    // CheckingAccount c(987654321, "Patel", 3000);
    // c.accountInfo();
    // c.withdraw(200);
    // c.checkOverdraft(200);

    // FixedDepositAccount fda(135791113, "hk", 5000, 12);
    // fda.accountInfo();
    // fda.calculateInterest();

    return 0;
}
