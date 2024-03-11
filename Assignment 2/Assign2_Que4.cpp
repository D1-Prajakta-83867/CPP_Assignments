#include<iostream>
using namespace std;

class Address
{
    private:
            string Building;
            string Street;
            string City;
            int pin;
    public:
    Address()
    {
            Building="Indradhanush";
            Street="Ambedkar Street";
            City="Pune";
            pin=413111;
    }
     Address(string x,string y,string z,int a)
    {
        this->Building=x;
        this->Street=y;
        this->City=z;
        this->pin=a;
    }
    void accept()
    {
        cout<<"Enter Building   :"<< endl;
        cin>>Building;
        cout<<"Enter Street     :" << endl;
        cin>>Street;
        cout<<"Enter City   :" << endl;
        cin>>City;
        cout<<"Enter Pin   :"<< endl;
        cin>>pin;


    }
    void display()
    {
        cout<<"Building : "<<this->Building<< endl;
        cout<<"Street   :"<<this->Street<< endl;
        cout<<"City     :"<<this->City<< endl;
        cout<<"Pin      :"<<this->pin<< endl;

    }

   

};

int main()
{
    Address a1;
     a1.display();
    Address a2("Sahyadri","JM Road","Delhi",431112);
     a1.display();
    a1.accept();
    a1.display();
    return 0;
}