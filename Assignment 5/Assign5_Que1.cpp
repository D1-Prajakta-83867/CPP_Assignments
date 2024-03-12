#include<iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day=1;
        month=1;
        year=2001;

    }
    Date(int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;

    }
    void acceptDate()
    {
        cout<<"\nEnter Day :\t";
        cin>>day;
        cout<<"Enter Month :\t";
        cin>>month;
        cout<<"Enter Year :\t";
        cin>>year;
    }
    void displayDate()
    {
        cout<<"Date -\t"<<day<<"/"<<month<<"/"<<year<<endl;
    }

    ~Date(){

    }
};
class Person
{
private:
        string Name;
        string Address;
        Date dob;
public:
    Person()
    {
        Name="Geeta";
        Address="Pune";

    }
    Person(string Name,string Address,int day,int month,int year):dob(day,month,year)
    {
        this->Name=Name;
        this->Address=Address;

    }
    void acceptPerson()
    {
        cout<<"\nEnter Name of Person:\t";
        cin>>Name;
        cout<<"Enter Address of Person :\t";
        cin>>Address;
        cout<<"Enter Date of Birth :\t";
        dob.acceptDate();
    }
    void displayPerson()
    {
        cout<<"\n\tName of Person :\t"<<Name<<endl;
        cout<<"\tAddress of Person :\t"<<Address<<endl;
        cout<<"\tBirth:\t";
        dob.displayDate();

    }
    ~Person()
    {

    }
};

class Employee :public Person
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
    void acceptEmployee()
    {
        cout<<"\nEnter Id of Employee:\t";
        cin>>Id;
        cout<<"Enter Salary of Employee :\t";
        cin>>Salary;
        cout<<"Enter Dept of Employee :\t";
        cin>>Dept;
        cout<<"Enter Employee Joining Date ";
        doj.acceptDate();

    }
    void displayEmployee()
    {
        cout<<"\n\tId of Employee :\t"<<Id<<endl;
        cout<<"\tSalary of Employee :\t"<<Salary<<endl;
        cout<<"\tDept of Employee :\t"<<Dept<<endl;
        cout<<"\t Employee Joining:\t"<<endl;
        doj.displayDate();

    }
    ~Employee()
    {

    }
};


int main()
{
    Person *ptr=new Employee();
    ptr->acceptPerson();
    ptr->displayPerson();

    Employee *eptr= (Employee*)ptr;
    eptr->acceptEmployee();
    eptr->displayEmployee();

    delete eptr;
    eptr=NULL;

    return 0;
}