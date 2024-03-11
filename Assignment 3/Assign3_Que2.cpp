#include<iostream>
using namespace std;
class Stack
{
    private:
        int* arr;
        int top;
        int size;
    public:
         Stack(int stackSize = 5) : size(stackSize), top(-1)
         {
           arr = new int[size];
         }
         ~Stack() 
          {
            delete[] arr;
          }
         void push(int x)
         {
            if(isFull())
            {
                cout<<"\nStack is full ...!!! cannot push."<<"\n";
                return ;
            }
            arr[++top] = x;
            cout<<x<<"\npushed on stack.\n";

         }


        void pop()
        {
            if(isEmpty())
            {
            cout << "\nStack Underflow! stack is empty.\n";
            return;
            }
            else{
               cout << arr[top--] << " popped from the stack.\n";

            }
        }
        void peek() const 
        {
        if (isEmpty()) 
        {
            cout << "\nThe stack is empty. Cannot peek.\n";
            return;
        }
        cout << "\nTop element: " << arr[top] << endl;
       }

        bool isEmpty() const 
        {
           return top == -1;
        }
    
      bool isFull() const
       {
             return top == size - 1;
       }
         void print() const 
         {
            if (isEmpty())
             {
                    cout << "\nThe stack is empty.\n";
                    return;
             }
             cout << "\nStack elements:  ";
             for (int i = 0; i <= top; ++i)
           {
                  cout << arr[i] << " ";
           }
                 cout << endl;
       }
       
};
int main()
{
    int x;
    Stack myStack;
    int choice;
    do {
        cout<<"\n\n";
        cout<<"  0. Exit \n";
        cout<<"  1. Push on stack :\n";
        cout<<"  2. Pop from stack :\n";
        cout<<"  3. Print stack elements :\n";
        cout<<"  4. Peek element of stack :\n";
        cout<<"  Enter your choice :\n";
        cin>>choice;

    switch (choice)
    {
    case 0:
       cout<<"\nThank you.\n\n";
        break;
    case 1:
        cout<<"Enter element to push";
        cin>>x;
        myStack.push(x);
      break;
    case 2:
        myStack.pop();

        break;
    case 3:
         myStack.print();
        break;
    case 4:
         myStack.peek();
        break;
           
    default:
     cout<<"Invalid choice !!!\n ";
        break;
    }

    }while(choice !=0);
    return 0;
}