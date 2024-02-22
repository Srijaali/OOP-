/*
Name: Rija Ali
desc: Calender management system
*/

#include <iostream>
#include <string>
using namespace std;

class weekdays{
string days[7];
int currentday;

public:
//default constructor
weekdays(){
days[0]="Sunday";
days[1]="Monday";
days[2]="Tuesday";
days[3]="Wednesday";
days[4]="Thursday";
days[5]="Friday";
days[6]="Saturday";
}
//parameterized
weekdays(int currday){
    currentday=currday%7;

days[0]="Sunday";
days[1]="Monday";
days[2]="Tuesday";
days[3]="Wednesday";
days[4]="Thursday";
days[5]="Friday";
days[6]="Saturday";
}
//currentday
string getcurrentday(){
return days[currentday];
}
//nextday
string getnextday(){
    return days[(currentday+1)%7];
}
//previousday
string getprevday(){
    return days[(currentday-1)%7];
}
//the day after Ndays
string getnday(int n){
    return days[(currentday+n)%7];
}
};

int main(){
    int currday,n;
    weekdays week;//for def constructor

    cout<<"Enter current day: ";
    cin>>currday;
    
    weekdays w2(currday);
    cout<<"\nDAYS INFO:\n";
    cout<<"Current day is: "<<w2.getcurrentday()<<endl;
    cout<<"Next day is: "<<w2.getnextday()<<endl;
    cout<<"Previous day was: "<<w2.getprevday()<<endl;

    cout<<"Enter N day(s): ";
    cin>>n;

    cout<<"After N days the day is: "<<w2.getnday(n);

    return 0;
}
