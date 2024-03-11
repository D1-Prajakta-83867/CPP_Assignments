#include<iostream>
using namespace std;

 namespace NStudent
 {
    class Student
    {
    private:
 	    int Rollno;
 	    string Name;
 	    double Marks;
 	
 	public:

 	void initStudent()
 	{
 	     Rollno=101;
 	     Name="Prajakta";
 	     Marks=97.98;
 	
 	}
 	void printStudentOnConsole()
 	{
 	    cout<<"\n\nStudent Details:   "<<endl;
 	    cout<<"Rollno: "<<this->Rollno<<endl;
 	    cout<<"Name : "<<this->Name<<endl;
	    cout<<"Marks : "<<this->Marks<<"\n\n";
    }
    void acceptStudentFromConsole()
 	{
 	        cout<<"\nEnter your rollno"<<endl;
 	        cin>>Rollno;
 	        cout<<"\nEnter your name"<<endl;
 	        cin>>Name;
 	        cout<<"\nEnter your marks"<<endl;
 	        cin>>Marks;
 	}
    };
 };
 using namespace NStudent;
int main()
{

 Student s;
  int choice;
  do
  {
  
  cout<<"\n\n0.Exit"<<endl;
  cout<<"1.Init Student "<<endl;
  cout<<"2.Display Student "<<endl;
  cout<<"3.Accept details from console."<<endl;
  cout<<"Enter your Choice : "<<endl;
  cin>>choice;
  
 switch(choice)
  	{
  		case 0:
  		break;
  		
  		case 1 :
  		s.initStudent();
  		break;
  		
  		case 2 :
  		s.printStudentOnConsole();
  		break;
  		
  		
  		case 3 :
  		s.acceptStudentFromConsole();
  		break;
  		
  	        default:
                cout << "Invalid Choice ... " << endl;
                break;
  	}
  
  }
    while (choice != 0);
    		cout<<"Thank you..."<<endl;

 return 0;
}
