#include <iostream.h>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;

void initDate(struct Date *ptrDate)
{
 ptrDate->day=07;
   ptrDate->month=03;
   ptrDate->year=2024;
}

void acceptDateFormConsole(struct Date *tptr)
{
    cout<<"Enter day,month and year - "<<"\n";
    cin>>tptr->day>>tptr->month>>tptr->year;
}

void printDateOnConsole(struct Date t)
{
    cout<<"Date -"<<t.day<<"/"<< t.month<<"/"<<t.year;
}
};
int main()
{
    struct Date ptrDate;
    
    int choice;
    do
    {
        cout << "0. EXIT" << endl;
        cout << "1. Date :" << endl;
        cout << "2.Print Date : " << endl;
        cout << "3.Acccept Date From User :" << endl;
        cout << "Enter your choice - ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thank you..." << endl;
            break;
        case 1:
            ptrDate.initDate();
            break;
        case 2:
            ptrDate.printDateOnConsole();
            break;
        case 3:
            ptrDate.acceptDateFormConsole();
            break;
        default:
            cout << "Invalid Choice ... " << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
