#include <iostream>
using namespace std;

int main(){

    int arr[4]={2,7,11,15};
    int target,i,j;
    int sum=0;

    cout<<"Enter target: ";
    cin>>target;

    for(i=0;i<4;i++){
        sum=arr[i];

    for(j=i+1;j<4;j++){
        sum+=arr[j];
    
        if(sum==target){
            cout<<"target number is at:" << i << "and" << j << endl;
        }
    }
    }

}
