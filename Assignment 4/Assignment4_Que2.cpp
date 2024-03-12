#include<iostream>
using namespace std;

int i,j,temp;
 int ind ;      
class Student
{
 public:
        string Name;
        string gender;
        int rollNumber;
        int Marks[3];
        float Percentage;

 public :
       
        void calculatePercentage()
        {
            
             Percentage = (Marks[0] + Marks[1] + Marks[2]) / 3.0f;
        }

        
        void displayStudentDetails()
        {
            
                 cout<<"\n\nStudent Details :\n";

                 cout<<"Name :\t"<<Name<<endl;
           
                 cout<<"Gender :\t"<<gender<<endl;
           
                 cout<<"Roll Number :\t"<<rollNumber<<endl;
            
                 cout<<"Percentage :\t"<<Percentage<<"%"<<endl;

            
        }
};

void sortRecords(Student arr[],int n)
{
     Student temp;
   for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i].Percentage >arr[j].Percentage)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

    } 
}

int searchRecords(Student arr[], int size, int searchRollNumber) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].rollNumber == searchRollNumber) {
            return i; // Found, return index
        }
    }
    return -1; // Not found
}


// int searchRecords(Student arr[]){

// }
void acceptStudentDetails(Student arr[],int n)
        {
         for (int i = 0; i < n; ++i)
        {
            cout<<"\n\nEnter your name :\t";
            cin>>arr[i].Name;
            cout<<"\nEnter your gender :\t";
            cin>>arr[i].gender;
            cout<<"\nEnter your Roll Number :\t";
            cin>>arr[i].rollNumber;
            cout<<"\nEnter Marks of  your three subjects :\t";
            for(int j=0;j<3;j++)
            {
                 cin>>arr[i].Marks[j];
            }
            arr[i].calculatePercentage();

        }
        }

    void printRecords(Student arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i].displayStudentDetails();
    }
}
int main()
{
    // Student *arr = new Student[2];
    // cout<<"Enter how many students you want to enter : ";
    //        cin>>n;

    const int n = 5;
      Student students[n];
        
    
    int choice;
    do{
        cout<<"\n 1.Accept student Details. ";
        cout<<"\n 2.Display student Details. ";
        cout<<"\n 3.Search student Details.";
        cout<<"\n 4.Sort student Details.";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            //   cout<<"Enter how many students you want to enter : ";
            //   cin>>n;
            //   acceptStudentDetails(students, n);
            acceptStudentDetails(students, n);

         break;
        case 2:
            printRecords(students, n);
            break;
        case 3:
         int searchRollNumber;
                cout << "Enter Roll Number to search: ";
                cin >> searchRollNumber;
                ind = searchRecords(students, n, searchRollNumber);
                if (ind != -1) 
                {
                   cout << "Student found at " << ind << ":" << endl;
                     students[ind].displayStudentDetails();
                }
                 else
                 {
                    cout << "Student not found." <<endl;
  
                }
            break;
            
        case 4 :
            sortRecords(students, n);
            break;
       
        }


    } while (choice!=0);

    return 0;
}