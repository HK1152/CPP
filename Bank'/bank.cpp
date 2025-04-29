#include <iostream>
using namespace std;
int size=3;
class bankaccount
{
protected:
    long accnum;
    string holname;
    double balance, overdraftLimit = 10000;

public:
    bankaccount(long accnum, string holname, double balance)
    {
        this->balance = balance;
        this->accnum = accnum;
        this->holname = holname;
    }

    void deposit(double dep)
    {
        if (dep > 0)
        {
            balance = dep+balance;
            cout << "\nYour deposit has been completed successfully.";
            cout << "\nYour current balance is: " << balance;
        }
        else
        {
            cout << "Invalid deposit amount!";
        }
    }

    void withdraw(double with)
    {
        if (with > 0 && (balance + overdraftLimit) >= with && with <= balance)
        {
            balance -= with;
            overdraftLimit -= with;
            cout << "\nWithdrawal successful from Checking Account.\nCurrent balance: " << balance << endl;
        }
        else
        {
            cout << "withdraw failed please check your balance !" << endl;
        }
    }

    double getbalance()
    {
        return balance;
    }

    void accountinfo()
    {
        cout << "Account number: " << accnum << endl;
        cout << "Account holder name: " << holname << endl;
        cout << "Account balance: " << balance << endl;
    }
};

class savingsaccount : public bankaccount
{
protected:
    double interestrate;

public:
double balance;
    savingsaccount(long accnum, string holname, double balance, double interestrate = 0.12)
        : bankaccount(accnum, holname, balance)
    {
        this->interestrate = interestrate;
    }

    void calculateinterest()
    {
        cout << "Calculated interest: " << balance * interestrate << endl;
    }
};

class checkingaccount : public bankaccount
{
protected:
    int with = 0;

public:
    checkingaccount(long accnum, string holname, double balance)
        : bankaccount(accnum, holname, balance) {}

 void deposit(double dep)
    {
        if (dep > 0)
        {
            balance = dep+balance;
            cout << "\nYour deposit has been completed successfully.";
            cout << "\nYour current balance is: " << balance;
        }
        else
        {
            cout << "Invalid deposit amount!";
        }
    }
    void withdraw(double with)
    {
        if (with > 0 && (balance + overdraftLimit) >= with && with <= balance)
        {
            balance -= with;
            overdraftLimit -= with;
            cout << "\nWithdrawal successful from Checking Account.\nCurrent balance: " << balance << endl;
        }
        else
        {
            cout << "withdraw failed please check your balance !" << endl;
        }
    }

    void checkoverdraft()
    {
        this->overdraftLimit -= with;
        cout << "Available overdraft limit is: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public bankaccount
{
protected:
    double interestrate = 0.08;
    int term;

public:
    FixedDepositAccount(long accnum, string holname, double balance, int term = 1)
        : bankaccount(accnum, holname, balance)
    {
        this->term = term;
    }

    void calculateinterest(int term)
    {
        cout << "Calculated interest for term of " << term << " months is: " << (balance * interestrate * (term / 12.0)) << endl;
    }
};

int main()
{
    long accnu[3] = {11, 52, 44}, user_acc_num;
    string pwd[3] = {"a11", "b52", "c44"}, user_pwd;
    string acc_hol_name[3] = {"radha", "krishna", "balram"};
    double balanc[size] = {10000, 20000, 1000};
    int ch, dep, wit = 0;

    cout << "Welcome.......";
    cout << "\nEnter your account number: ";
    cin >> user_acc_num;
    cout << "\nEnter your account password: ";
    cin >> user_pwd;

    for (int i = 0; i < 3; i++)
    {
        if (user_acc_num == accnu[i] && user_pwd == pwd[i])
        {
            savingsaccount user(accnu[i], acc_hol_name[i], balanc[i]);
            checkingaccount users(accnu[i], acc_hol_name[i], balanc[i]);
            FixedDepositAccount userss(accnu[i], acc_hol_name[i], balanc[i]);

            while (true)
            {
                cout << "\n\n**************************************************************\n";
                cout << " \n###############->SavingsAccount<-###############";
                cout << "\n\n1.Display your account details. \n2.Deposit \n3.Withdraw \n4.Calculate Interest";
                cout << "\n5.Check Overdraft";
                cout << " \n##############################";
                cout << " \n###############->FixedDeposit(FD)<-###############";
                cout << "\n6.Calculate FD Interest ";
                cout << " \n###############->Exit<-###############";
                cout << "\n7.Log out";
                cout << " \n##############################";
                cout << " \n \n**************************************************************\n";
                cout << "\n\nEnter choice: ";
                cin >> ch;
                cout << " \n \n**************************************************************\n\n\n";

                switch (ch)
                {
                case 1:
                    user.accountinfo();
                    break;
                case 2:
                    cout << "Enter a deposit amount: ";
                    cin >> dep;
                    users.deposit(dep);
                   
                    break;
                case 3:
                    cout << "Enter a withdraw amount: ";
                    cin >> wit;
                    users.withdraw(wit);
                    break;
                case 4:
                    user.calculateinterest(); // saving ka interest hai
                    break;
                case 5:
                    users.checkoverdraft();
                    break;
                case 6:
                    int term;
                    cout << "Enter term month:";
                    cin >> term;

                    userss.calculateinterest(term); // FD ka interest hai
                    break;
                case 7:
                    exit(0);
                default:
                    cout << "wrong choice.......!" << endl;
                }
            }
        }
    }
    return 0;
}
