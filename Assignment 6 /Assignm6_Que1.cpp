#include<iostream>
using namespace std;
class Employee
{
private:
        int Id;
        float Sal;

   
public:
    Employee()
     {
        cout<<"Inside Employee Parameterless Ctor.\n";

        Id=0;
        Sal=0;
     }
     Employee(int Id , float Sal)
    {
        cout<<"Inside Employee Parameterized Ctor.\n";
        
        this->Id=Id;
        this->Sal=Sal;
    }
        int getId()
        {
            return Id;
        }
        void setId(int Id)
        {
            this->Id=Id;
        }
        float getSal()
        {
            return Sal;
        }
        void setSal(float Sal)
        {
            this->Sal=Sal;

        }


    virtual void accept()
    {
        cout<<"\nEnter Id :\t";
        cin>>Id;
        cout<<"\nEnter Salary :\t";
        cin>>Sal;
    }
    virtual void display()
    {
        cout<<"\n\tId is  : \t"<<Id<<endl;
        cout<<"\n\tSalary is : \t"<<Sal<<endl;

    }
    ~Employee()
    {
        cout<<"Inside Employee Dtor\n";
    }
    
};
class Manager : virtual public Employee
{
   private:
    double Bonus;

  
   protected:
     void acceptManager()
     {
            cout<<"Enter Bonus :\t";
            cin>>Bonus;
     }
      void displayManager()
      {
             cout<<"\n\tBonus :\t"<<Bonus<<endl;
    
      }
   public:
    Manager()
    {
        cout<<"Inside Parameterless Ctor.\n";
        Bonus=0;

    }
    Manager(int Id,double Sal,double Bonus):Employee(Id ,Sal)
    {
        cout<<"Inside Parameterized Ctor.\n";
        this->Bonus=Bonus;
        
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }
    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout<<"\n Manager Dtor\n";

    }
    
   
        double getBonus()
        {
            return Bonus;
        }
        void setBonus(double Bonus)
        {
            this->Bonus=Bonus;
            
        }
    
};
class Salesman: virtual public Employee
{

private:
        double comm;

protected:
         void acceptSalesman()
         {
            cout<<"\nEnter Commission :\t";
            cin>>comm;
         }
         void displaySalesman()
         {
              cout<<"\n\t Commission :\t"<<comm<<endl;
    
         }

public:
    Salesman()
    {
         cout<<"Inside Parameterless Ctor of Salesman.\n";
         comm=0;

    }
    Salesman(int Id,double Sal,double comm):Employee(Id,Sal)
    {
         cout<<"Inside Parameterized Ctor of Salesman.\n";
         this->comm=comm;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();

    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
     float getcomm()
    {
            return comm;
    
    }
       
     void setcomm(float comm)
    {
            this->comm=comm;
    }
    
};
class Sales_Manager : public Manager,public Salesman
{   
public:
    Sales_Manager()
    {
        cout<<"\nInside Parameterless Ctor of Sales_Manager\n";
    }
    Sales_Manager(int Id,double Sal,double Bonus,double comm)
    {
                cout<<"\nInside Parameterized Ctor of Sales_Manager\n";
                 this->setId(Id);
                 this->setSal(Sal);
                 this->setBonus(Bonus);
                 this->setcomm(comm);
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();

    }
     void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
    
    ~Sales_Manager()
    {
            cout << "\nSales_Manager Destructor" << endl;
    }

};

int main()
{
            // Employee ob;
            //Manager ob;
            //Salesman ob;
            //Sales_Manager ob;
            // Sales_Manager ob(1,100000,1000,2000);
            // //ob.accept();
            // ob.display();

            //Employee *ptr=new Employee();
            // Employee *ptr=new Manager();
             //Employee *ptr=new Salesman();
            Employee *ptr=new Sales_Manager();

            ptr->accept();
            ptr->display();
            // delete ptr;
            // ptr=NULL;

   return 0;
}
