#include <iostream>
#include <vector>
using namespace std;

enum ACCOUNT_TYPE
{
    SAVINGS,
    CURRENT,
    DMAT
};

class InsufficientFundsException
{
private:
    string message;

public:
    InsufficientFundsException()
    {
        cout << "Something went Wrong " << endl;
    }

    InsufficientFundsException(string message)
    {
        this->message = message;
    }

    void printErrorMessage()
    {
        cout << message << endl;
    }
};

class Account
{

private:
    int id;
    ACCOUNT_TYPE type;
    double balance;

public:
    // Constructor Initialized

    Account() : Account(0, SAVINGS) {}

    Account(int id, ACCOUNT_TYPE type)
    {
        this->id = id;
        this->type = type;
    }

    void acceptAccountDetails()
    {
        cout << "Enter ID: ";
        cin >> id;

        int accounttype;
        cout << "\nEnter Account Type: " << endl;
        cout << "0: SAVINGS " << endl;
        cout << "1: CURRENT " << endl;
        cout << "2: DMAT \n"
             << endl;
        cin >> accounttype;

        if (accounttype == 0)
        {
            type = SAVINGS;
        }
        else if (accounttype == 1)
        {
            type = CURRENT;
        }
        else
        {
            type = DMAT;
        }
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void displayAccountDetails()
    {
        cout << "\nID           : " << id << endl;
        cout << "Account Type : " << type << endl;
        cout << "Balance      : " << balance << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setAccountType(ACCOUNT_TYPE type)
    {
        this->type = type;
    }

    int getId()
    {
        return id;
    }

    ACCOUNT_TYPE getType()
    {
        return type;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << endl;
        cout << "\"" << amount << "\" successfully Deposited" << endl;
        cout << endl;
        cout << "Balance: " << balance << " rupees" << endl;
    }

    void withdraw(double amount)
    {

        if (balance < 0)
            throw InsufficientFundsException("Insufficient Balance, Cannot Withdraw Funds");

        balance -= amount;
        cout << "\"" << amount << "\" Withdrawn Successfully" << endl;
        cout << endl;
        cout << "Balance: " << balance << " rupees" << endl;
    }
};

int main()
{

    int choice, value, id;
    vector<Account> accountList;
    Account acc;

    do
    {
        cout << "\n\t0: Exit " << endl;
        cout << "\t1: Enter Account Details " << endl;
        cout << "\t2: Display Account Details " << endl;
        cout << "\t3: Deposit Amount " << endl;
        cout << "\t4: Withdraw Amount \n\n"
             << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\nThank you.\n" << endl;
            break;

        case 1:

            if (accountList.size() < 5)
            {
                acc.acceptAccountDetails();
                accountList.push_back(acc);
            }
            else
            {
                cout << "Cannot accept more Accounts " << endl;
            }

            break;

        case 2:
            cout << "\nEnter Account ID: ";
            cin >> id;

            for (int i = 0; i < accountList.size(); i++)
            {
                // cout << endl;
                if (accountList[i].getId() == id)
                {
                    cout << "Account Details: " << endl;
                    accountList[i].displayAccountDetails();
                    break;
                }
                else
                {
                    cout << "Employee doesn't exist in Database " << endl;
                }
            }

            break;

        case 3:
            cout << "\nEnter Account ID: ";
            cin >> id;

            for (int i = 0; i < accountList.size(); i++)
            {
                cout << endl;
                if (accountList[i].getId() == id)
                {
                    try
                    {
                        cout << "Enter Amount you want to Deposit: ";
                        cin >> value;
                        if (value < 0)
                        {
                            throw InsufficientFundsException("Money to Deposit can't be Negative, Please enter a positive Value ");
                        }
                    }
                    catch (InsufficientFundsException &error)
                    {
                        error.printErrorMessage();
                    }
                    accountList[i].deposit(value);
                    break;
                }
                else
                {
                    cout << "Employee doesn't exist in Database " << endl;
                }
            }
            break;
            ;
        case 4:
            cout << "Enter Account ID: ";
            cin >> id;

            for (int i = 0; i < accountList.size(); i++)
            {
                if (accountList[i].getId() == id)
                {
                    try
                    {
                        cout << "Enter Amount you want to Withdraw: ";
                        cin >> value;
                        if (value < 0)
                        {
                            throw InsufficientFundsException("Money to Deposit can't be Negative, Please enter a positive Value ");
                        }
                    }
                    catch (InsufficientFundsException &error)
                    {
                        error.printErrorMessage();
                    }
                    accountList[i].withdraw(value);
                    break;
                }
                else
                {
                    cout << "Employee doesn't exist in Database " << endl;
                }
            }
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}