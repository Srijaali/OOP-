
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
   
   int n,mark,std,math,eng,sci,i;
   int total ;
   int avg ;
   char grade; 
   
   cout<<"enter the number of students:" <<endl;
   cin>> n;
   
   for(i=0;i<n;i++){
   cout<<"enter the marks of maths:" <<endl;
   cin>> math;
   
   
   cout<<"enter the marks of english:" <<endl;
   cin>> eng;
   
   
   cout<<"enter the marks of science:" <<endl;
   cin>> sci;
   }
   
   total=math+sci+eng;

   cout<<"total marks are "<< total<<"\n";
   
   avg=total/3;
   cout<<"Average marks are "<<avg<<"\n";
   
   if(avg>=90){
       cout<<"grade is A"<<endl;
   }
   else if(avg>=80 && avg<=89 ){
       cout<<"grade is B"<<endl;
   }
    else if(avg>=70 && avg<=79 ){
       cout<<"grade is C"<<endl;
   }
    else if(avg>=60 && avg<=69 ){
       cout<<"grade is d"<<endl;
   }
   else{
       cout<<"Grade is F"<<endl;
   }
   
   
   
   
    return 0;
}
