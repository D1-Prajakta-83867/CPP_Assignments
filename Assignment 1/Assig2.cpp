#include <iostream>
using namespace std;
namespace NSStructDate
{
struct Date
{
    int day;
    int month;
    int year;

void initDate()
{
  day=7;
   month=3;
   year=2024;
}

void acceptDateFormConsole()
{
    cout<<"\n\nEnter day,month and year - "<<"\n";
    cin>>day>>month>>year;
}

void printDateOnConsole()
{
    cout<<"\n\nDate -"<<day<<"/"<< month<<"/"<<year<<"\n\n";
}
bool isLeapYear(int year)
{
    if (year % 400 == 0) {
        return true;
    }

    else if (year % 100 == 0) {
        return false;
    }

    else if (year % 4 == 0) {
        return true;
    }
 
    else {
        return false;
    }
}

};
}

namespace NSClassDate
{
class Date
{
    private:
    int day;
    int month;
    int year;
 public:
void initDate()
{
	day=8;
	month=3;
	year=2024;
}

void acceptDateFormConsole()
{
    cout<<"\n\nEnter day,month and year - "<<"\n";
    cin>>day>>month>>year;
}

void printDateOnConsole()
{
    cout<<"\n\nDate -"<<day<<"/"<<month<<"/"<<year<<"\n\n";
}
};
}
using namespace NSStructDate;
//using namespace NSClassDate;
int main()
{
    struct Date d1;
    //Date d1;
    int choice;
    int year;
    do
    {
    
        cout << "\n0. EXIT" << endl;
        cout << "1. Date :" << endl;
        cout << "2.Print Date : " << endl;
        cout << "3.Acccept Date From User :" << endl;
        cout << "4.Year is leap or not :"<<endl;
        cout << "\nEnter your choice - ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\n\nThank you..." << endl;
            break;
        case 1:
            d1.initDate();
            break;
        case 2:
            d1.printDateOnConsole();
            break;
        case 3:
            d1.acceptDateFormConsole();
            break;
         case 4:
         	cout<<"Enter year to check leap/not :";
         	cin>>year;
            
             d1.isLeapYear(year) ? cout << "Leap Year\n": cout << "Not a Leap Year\n";
            break;
        default:
            cout << "\n\nInvalid Choice ... \n" << endl;
            break;
        }

    } while (choice != 0);
    return 0;
}
