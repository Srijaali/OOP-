/*
Name: Rija Ali
ID: 23k-0057
Desc: finding subset of a sum 
*/

#include <iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetsum) 
{
    if(size < 0)return false;

    int sum=0;

    bool check = hasSubsetSum(arr, size-1, targetsum);

    if(check)return true;

    for(int i=size; i>=0; i--){
        sum += arr[i];
        if(sum == targetsum)return true;
        else if(sum > targetsum)return false;
    }

    return false;
}

int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int targetsum;
    cout << "Enter the Integer value you want to search for in the array: " << endl;
    cin >> targetsum;

    if (hasSubsetSum(arr, size-1, targetsum)) {
        cout << "Subset with sum " << targetsum << " exists in the array" << endl;
    } else {
        cout << "Subset with sum " << targetsum << " does not exist in the array" << endl;
    }

    return 0;
}
