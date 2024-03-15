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
        //cout<<"Inside Employee Parameterless Ctor.\n";

        Id=0;
        Sal=0;
     }
     Employee(int Id , float Sal)
    {
        //cout<<"Inside Employee Parameterized Ctor.\n";
        
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
       // cout<<"Inside Employee Dtor\n";
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
      //  cout<<"Inside Parameterless Ctor.\n";
        Bonus=0;

    }
    Manager(int Id,double Sal,double Bonus):Employee(Id ,Sal)
    {
        //cout<<"Inside Parameterized Ctor.\n";
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
        // cout<<"Inside Parameterless Ctor of Salesman.\n";
         comm=0;

    }
    Salesman(int Id,double Sal,double comm):Employee(Id,Sal)
    {
        // cout<<"Inside Parameterized Ctor of Salesman.\n";
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
      //  cout<<"\nInside Parameterless Ctor of Sales_Manager\n";
    }
    Sales_Manager(int Id,double Sal,double Bonus,double comm)
    {
               // cout<<"\nInside Parameterized Ctor of Sales_Manager\n";
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
    Employee *arr[10];
    int choice,count;
    do
    {
        int ManagerCount=0,SalesmanCount=0,Sales_ManagerCount=0;
      cout<<"\n0 : Exit.\n";
      cout<<"\n1 : Accept Manager.\n";
      cout<<"\n2 : Accept Salesman.\n";
      cout<<"\n3 : Accept Sales Manager.\n";
      cout<<"\n4 : Display the count of employees w.r.t. designation\n";
      cout<<"\n5 : Display All Managers \n";
      cout<<"\n6 : Display All Salesman \n";
      cout<<"\n7 : Display All SalesManagers \n";
      cout<<"\n Enter your choice \n";
      cin>>choice;

    switch (choice)
    {
    case 0:
        cout<<"\nThank you.\n";

        break;
     case 1:
        if(count<10)
        {
            arr[count]=new Manager();
            //cout<<"----Employee No . "<<count+1<<"----\n";
            arr[count]->accept();
            count++; 

        }
        else{
            cout<<"\nYou cannot enter more than 10 employee\n";
        }
        
        break;
      case 2:
        if(count<10)
        {
            arr[count]=new Salesman();
            //cout<<"----Employee No . "<<count+1<<"----\n";
            arr[count]->accept();
            count++;
        }
        else{
            cout<<"\nYou cannot enter more than 10 employee\n";
        }  
        
        break;
       case 3:
       if(count<10)
        {
             arr[count]=new Sales_Manager();
            //cout<<"----Employee No . "<<count+1<<"----\n";
            arr[count]->accept();
            count++;
            
        }
        else{
            cout<<"\nYou cannot enter more than 10 employee\n";
        }
        
        break;
        case 4:
            for(int i=0;i<count;i++)
            {
                if(typeid(*arr[i])==typeid(Manager))
                    ManagerCount+=1;
               
            //}
            cout<<"\nManager Count:\t"<<ManagerCount<<endl;

            //   for(int i=0;i<count;i++)
            // {
                if(typeid(*arr[i])==typeid(Salesman))
                    SalesmanCount+=1;

               
           // }
             cout<<"\nSalesman Count:\t"<<SalesmanCount<<endl;
            //  for(int i=0;i<count;i++)
            // {
                if(typeid(*arr[i])==typeid(Sales_Manager))
                    Sales_ManagerCount+=1;
            }  
            
              cout<<"\nSales Manager Count:\t"<<Sales_ManagerCount<<endl;

        break;
        case 5:
            for(int i=0;i<count;i++)
            {
                if(typeid(*arr[i])==typeid(Manager))
                arr[i]->display();
            }
        break;
        case 6:
              for(int i=0;i<count;i++)
            {
                if(typeid(*arr[i])==typeid(Salesman))
                arr[i]->display();
            }
        
        break;
        
         case 7:
              for(int i=0;i<count;i++)
            {
                if(typeid(*arr[i])==typeid(Sales_Manager))
                arr[i]->display();
            }
        
        break;
        
    
    default:
        cout<<"\n You entered wrong choice.\n";
        break;
    }
    } while (choice!=0);

   return 0;
}
