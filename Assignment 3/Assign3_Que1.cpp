#include<iostream>
using namespace std;
class Time
{
    private:
        int hour;
        int minute;
        int seconds;

    public:
        Time() :hour(0), minute(0), seconds(0) {}
       
       // Time(int h,int m,int s):hour(h), minute(m), seconds(s) {}
       Time(int h,int m,int s)
        {

             this->hour=h;
             this->minute=m;
             this->seconds=s;

        }
       int getHour() 
        {
               return hour;
        }
        int getMinutes()
         {
               return minute;
        }
        int getSeconds()
        {
            return seconds;
        }
         void printTime() const
         {
            cout << hour << ":" << minute << ":" << seconds << endl;

         }
         
        void setHour(int h)
        {
             hour=h;
        }
        void setMinute(int Min) 
        {
            minute=Min;
        }
        void setSeconds(int Sec) 
        {
               seconds=Sec;
        }

};

int main()
{

   
    
    Time *arr=new Time[5]{Time(12,45,50),Time(5,10,18),Time(),Time(3,25,28),Time()};
    
    for(int i = 0; i<5;i++)
    arr[i].printTime();
    delete[]arr;
    return 0;

}