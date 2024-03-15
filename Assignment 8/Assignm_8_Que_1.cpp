#include <iostream>
using namespace std;
void Factorial()
{

    int num,i;
    int fact = 1;
    cout << "\nEnter a number :\n";
    cin >> num;
    if (num<0)
    {
        throw "Fact of -ve cannot be calc.\n";
    }
    
    
    for ( i = 1; i <= num; i++)
    {
        fact *= i;
    }
    cout<<"fact : "<< fact<<"\n\n";
}
int main()
{
    try
    {
        Factorial();
    }
    catch(const char*e)
    {
        cout << e<< '\n';
    }
    
  
    return 0;
}
  
