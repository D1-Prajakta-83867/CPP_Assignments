#include<iostream>
using namespace std;
class Toolbooth
{
    private:
        int car;
        double cashTotal;
        int noPayCarTotal;
    public:
    Toolbooth()
    {
        car=0;
        cashTotal=0.0;
        noPayCarTotal=0;

    }
    int payingCar()
    {
        car++;
        cashTotal+=0.50;
        return cashTotal;
    }

    void noPayCar()
    {
       noPayCarTotal++;
    }
    void printOnConsole()
    {
        cout<<"Total number of cars : "<<noPayCarTotal+car;
        cout<<"\nNumber of Paying Cars :"<<car;
        cout<<"\nNumber of Non-Paying Cars :"<<noPayCarTotal;
        cout<<"\nCash Total = "<<cashTotal;
    }
};

int main()
{
    Toolbooth t1;
    int choice;
    do
    {

   
    cout<<"\n\n0.Exit\n";
    cout<<"1.Add Paying car :\n";
    cout<<"2.Add Non-Paying car :\n";
    cout<<"3.Display Car Total : \n";
    cout<<"4.Enter your choice : \n";
    cin>>choice;
    switch (choice)
    {
    case 0:

        break;

    case 1:
        t1.payingCar();
        break;

    case 2:
        t1.noPayCar();
        break;
    
    case 3:
        //int x=t1.payingCar();
        t1.printOnConsole();
        //cout<<"\nCash Total = "<<x;

        break;
  
    }
     } while (choice!=0);
    cout<<"Visit Again...";


}