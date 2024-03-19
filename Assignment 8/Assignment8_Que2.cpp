#include <iostream>
using namespace std;

class InSufficientFunds
{
    int accid;
    double current_balance;
    double withdraw_amount;
    string error;

public:
    InSufficientFunds(string error)
    {
        this->error = error;
    }

    InSufficientFunds(int id, double current_balance, double withdraw_amount, string error)
    {
        this->accid = accid;
        this->current_balance = current_balance;
        this->withdraw_amount = withdraw_amount;
        this->error = error;
    }
    void printStackTrace()
    {
        cout << error << endl;
    }
};

enum Acc_type
{
    SAVING = 1,
    CURRENT,
    DMAT
};

class Bank
{
private:
    int id;
    Acc_type type;
    double balance;
    int typenum;

public:
    Bank()
    {
    }
    Bank(int id, Acc_type type, double balance, int typenum)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
        this->typenum = typenum;
    }
    int getId()
    {
        return id;
    }
    Acc_type getType()
    {
        return type;
    }
    double getBalance()
    {
        return balance;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setType(Acc_type type)
    {
        this->type = type;
    }
    void accept()
    {
        cout << "\tEnter ID: " << endl;
        cin >> id;
        cout << "\t1. SAVING" << endl;
        cout << "\t2. CURRENT" << endl;
        cout << "\t3. DMAT" << endl;
        cout << "\tEnter Your Account Type: " << endl;
        cin >> typenum;
        if (typenum >= 1 && typenum <= 3)
        {
            type = Acc_type(typenum);
        }
        cout << "\tEnter Balance: " << endl;
        cin >> balance;
    }
    void display()
    {
        cout << "\n\tID: " << id << endl;
        if (typenum == 1)
            cout << "\tType: Saving" << endl;
        else if (typenum == 2)
        {
            cout << "\tType: Current" << endl;
        }
        else
        {
            cout << "\tType: Dmat" << endl;
        }
        cout << "\tBalance: " << balance << endl;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (balance < amount)
        {
            throw InSufficientFunds("\tBalance is less than Amount");
        }

        balance -= amount;
    }
};

int getIndex(Bank *arr[], int id)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]->getId() == id)
        {
            return i;
        }
        else
            return -1;
    }
}

int main()
{
    int choice;

    Bank *ptr[5];
    int count = 0;
    int accid;
    double amt;

    do
    {
        cout << "\n\t0. EXIT" << endl;
        cout << "\t1. Create Account" << endl;
        cout << "\t2. Display Account" << endl;
        cout << "\t3. Deposit" << endl;
        cout << "\t4. Withdraw" << endl;
        cout << "\tEnter your choice\t";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "\nThank you\n"
                 << endl;
            break;

        case 1:
            if (count < 5)
            {
                ptr[count] = new Bank();
                ptr[count]->accept();
                count++;
                cout << "\nACCOUNT CREATED SUCCESSFULLY...\n"
                     << endl;
            }
            else
            {
                cout << "\tACCOUNT ARRAY IS FULL...\n"
                     << endl;
            }
            break;

        case 2:
            for (int i = 0; i < count; i++)
            {
                ptr[i]->display();
            }
            break;

        case 3:

            cout << "\nEnter account number: \t" << endl;
            cin >> accid;

            cout << "\nEnter Amount to add: \t" << endl;
            cin >> amt;
            if (accid != -1)
            {
                ptr[getIndex(ptr, accid)]->deposit(amt);
                cout << "\nCURRENT BALANCE IS: " << ptr[getIndex(ptr, accid)]->getBalance() << endl;
            }
            else
            {
                cout << "\nAccount Doesnt Exist." << endl;
            }
            break;

        case 4:

            cout << "\nEnter account number:\t " << endl;
            cin >> accid;

            cout << "\nEnter Amount to Withdraw: \t" << endl;
            cin >> amt;
            if (accid != -1)
            {
                try
                {
                    ptr[getIndex(ptr, accid)]->withdraw(amt);
                    cout << "\nCURRENT BALANCE IS: " << ptr[getIndex(ptr, accid)]->getBalance() << endl;
                }
                catch (InSufficientFunds &error)
                {
                    error.printStackTrace();
                }
            }
            else
            {
                cout << "\nAccount Doesnt Exist..." << endl;
            }
            break;

        default:
            cout << "\n\tWrong Choice...Enter Again..." << endl;
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++)
    {
        delete ptr[i];
    }
}
