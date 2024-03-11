#include<iostream>
using namespace std;
class Date
{
 private :
        int day;
        int month;
        int year;

 public :
        Date()
        {
            day=1;
            month=1;
            year=2000;

        }
        Date(int day, int month, int year)
        {
            this->day=day;
            this->month=month;
            this->year=year;
        }
        void acceptDate()
        {
            cout<<"Enter day : ";
            cin>>day;
            cout<<"Enter month : ";
            cin>>month;
            cout<<"Enter year : ";
            cin>>year;
        }
        void displayDate()
        {
            cout<<"Date - "<<day<<"/"<<month<<"/"<<year<<endl;
        }
};
class Employee
{
    private:
        int Id;
        float Salary;
        string Dept;
        Date doj;

    public:
    Employee()
    {
         Id=101;
         Salary=10000.0;
         Dept="Comp";
    }
     Employee(int Id,float Salary,string Dept,int day,int month,int year):doj(day,month,year)
    {
        this->Id=Id;
        this->Salary=Salary;
        this->Dept=Dept;
    }
    int getId()
    {
        return Id;
    }
     void setId(int id )
    {
        Id=id;
    }
    

    float getSalary()
    {
        return Salary;
    }
    void setSalary(float salary)
    {
       Salary=salary;
    }


    string getDept()
    {
        return Dept;
    }
    void setDept(string dept)
    {
        Dept=dept;
    }


    // date get_Joining_Date()
    // {

    // }
    // date setJoiningDate(date Joining)
    // {

    // }
   
    void accept() 
    {
        cout<<"\n\nEnter Id : ";
        cin>>Id;
        cout<<"Enter Salary : ";
        cin>>Salary;
        cout<<"Enter Dept : ";
        cin>>Dept;
         cout<<"Enter Date of joining : ";
        doj.acceptDate();


    }
    void display() 
    {
        cout<<"\n\nId     :  "<<Id<<endl;
        cout<<"Salary :  "<<Salary<<endl;
        cout<<"Dept   :  "<<Dept<<endl;
        cout<<"Joining :  "<<endl;
        doj.displayDate();

    }

};
class Person
{
    private:
        string Name;
        string Address;
        Date doj;

    public:
    Person()
    {
        Name="Sonal";
        Address="Pune";

    }
    Person(string Name ,string Address,int day,int month,int year):doj(day,month,year)
    {
        this->Name=Name;
        this->Address=Address;
        
    }

    string getName()
    {
        return Name;

    }
    void setName(string Name)
    {
        Name=Name;
    }

     string getAddress()
    {
        return Address;
        
    }
    void setAddress()
    {
        Address=Address;
    }

    void acceptPerson()
    {
        cout<<"\n\nEnter Name : ";
        cin>>Name;
        cout<<"Enter Address : ";
        cin>>Address;
        cout<<"Enter Date of Birth : ";
        doj.acceptDate();
    }
    void displayPerson()
    {
        cout<<"\n\nName     :  "<<Name<<endl;
        cout<<"Address :  "<<Address<<endl;
        cout<<"Date of Birth :  "<<endl;
        doj.displayDate();

    }



};

int main()
{
    Employee e1;
    e1.accept();
    e1.display();

    Employee e2(111,55555.5,"IT",10,10,2010);
    e2.display();

    Person p1;
    p1.acceptPerson();
    p1.displayPerson();

    Person p2("Namo","Delhi",6,6,2006);
    return 0;
}