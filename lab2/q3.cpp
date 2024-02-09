/*
Name: Rija Ali
ID: 23k-0057
Desc: finding subset of a sum 
*/

#include <iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetsum, int currentsum = 0, int arrindex = 0) {
    if (currentsum == targetsum) {
        return true;
    }

    if (arrindex == size) {
        return false;
    }

    // Including current element in the subset sum
    if (hasSubsetSum(arr, size, targetsum, currentsum + arr[arrindex], arrindex + 1)) {
        return true;
    }

    // Excluding current element from the subset sum
    return hasSubsetSum(arr, size, targetsum, currentsum, arrindex + 1);
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

    if (hasSubsetSum(arr, size, targetsum)) {
        cout << "Subset with sum " << targetsum << " exists in the array" << endl;
    } else {
        cout << "Subset with sum " << targetsum << " does not exist in the array" << endl;
    }

    return 0;
}
