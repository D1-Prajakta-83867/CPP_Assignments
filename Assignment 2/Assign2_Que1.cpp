#include<iostream>
using namespace std;
class Volume
{
    private:
        int length;
        int width;
        int heigth;
        int boxVolume;
    public:

    Volume()
    {
        length=100;
        width=50;
        heigth=20;

    }
     Volume(int value)
     {
        length=value;
        width=value;
        heigth=value;
    }
    Volume(int x,int y,int z)
    {
        length=x;
        width=y;
        heigth=z;
    }
    void calculateVolume()
    {
        boxVolume=length*width*heigth;
        cout<<"Box Volume = "<<boxVolume<<endl;
    }

};
int main()
{
    int choice;
    do
    {
        cout<<"\n\n1.Calculate Volume by using Parameterless Ctor "<<endl;
        cout<<"\n2.Calculate Volume by using Parameterized Ctor "<<endl;
        cout<<"\n2.Calculate Volume by using Parameterized Ctor "<<endl;

        cout<<"\n3.Exit. "<<endl;
        cout<<"\nEnter your choice: "<<endl;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            Volume v1;
            v1.calculateVolume();

            break;

        case 2:
            Volume v1(25);
            v1.calculateVolume();

            break;
        case 3:
            Volume v1(20,40,50);
            v1.calculateVolume();
            break;
        }

    } while (choice!=0);
    cout<<"Thank you....";
    return 0;

}