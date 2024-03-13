#include<iostream>
using namespace std;
class Product
{
    protected:
    int Id;
    string Title;
    int Price;

    public:
    virtual void accept()
    {
        cout<<"\n Enter Id  :\t";
        cin>>Id;
        cout<<"\n Enter Title :\t";
        cin>>Title;
        cout<<"\n Enter Price:\t";
        cin>>Price;

    }
    virtual void display() 
    {
        cout<<"\n\tId  :\t"<<Id<<endl;
        cout<<"\tTitle :\t"<<Title<<endl;
        cout<<"\tPrice :\t"<<Price;
    }

    int getPrice()
    {
        return Price;
    }

};
class Book : public Product
{
private:
    string Author;

public:
    void accept()
    {
        Product::accept();
         cout<<"\n Enter Author :\t";
        cin>>Author;
        
    }
    void display()
    {
            Product::display();
            cout<<"\n\tAuthor :"<<Author<<endl;

    }
   
   
};
class Tape: public Product
{
private:
        string artist;
   
public:
    void accept()
    {
        Product::accept();
        cout<<"\n Enter Artist  :\t";
        cin>>artist;

    }
    void display()
    {
        cout<<"\n ";
        Product::display();

        cout<<"\tArtist of Tape :\t"<<artist<<endl;
    }
     
};

int main()
{
    float total_bill=0;
    float tape_total=0;
    float books_total=0;
    int choice,count ;
    Product *ptr[3];
 do
    {
        
        cout<<"\n0.   Exit "<<endl;
        cout<<"\n1. Accept Book Records :"<<endl;
        cout<<"\n2. Display Book Records :"<<endl;
        cout<<"\n3. Accept Tape Records :"<<endl;
        cout<<"\n4. Display Tape Records :"<<endl;
        cout<<"\n4. Display All Records :"<<endl;
        cout<<"\n5. Display price after discount:"<<endl;
        cout<<"------------------------------------\n";
        cout<<"  Enter your choice :\t";
        cin>>choice;

        switch (choice)
            {
            case 0:
                cout<<"\n \tThank you...\n\n";
                break;
            case 1:
                if(count<3)
                {
                ptr[count]=new Book();
                cout<<"\n\t---Product No. :"<<count+1<<"---\n";

                ptr[count]->accept();
                count++;
                }
                else{
                cout<<"\nOppss...You cannot buy more than three books. \n";
                }
                break;
            case 2:
                 for(int i=0;i<3;i++)
                    if(typeid(*ptr[i])==typeid(Book))
                    
                         ptr[i]->display();
                    
                break;
            case 3:
            if(count<3)
                {
                ptr[count]=new Tape();
                ptr[count]->accept();
                count++;
                }
                else{
                cout<<"\nOpss...You cannot buy more than three tapes\n";
                }
                break;
            
            case 4:
                for(int i=0;i<3;i++)
                {
                    if(typeid(*ptr[i])==typeid(Tape))
                        ptr[i]->display();

                }
                break;
            case 5:   
                for(int i=0;i<3;i++)
                {
                        ptr[i]->display();
                }
             case 6:
                 
                    for(int i=0;i<3;i++)
                    {
                        if(typeid(*ptr[i])==typeid(Book))
                            books_total=books_total+ptr[i]->getPrice();

                        if(typeid(*ptr[i])==typeid(Tape))
                            tape_total=tape_total+ptr[i]->getPrice();

                     }
                    total_bill=(books_total*0.9)+(tape_total*0.95);
                    cout<<"\n Your Total Bill : "<<total_bill<<endl;
                 
               break;
            
            default:
                cout<<"\n Invalid choice!!!!\n";
                break;
            }
         
        //     for(int i=0;i<3;i++)
        // delete ptr[i];
               
    
} while (choice!=0);
    for(int i=0;i<3;i++)
        delete ptr[i];
    return 0;
}




