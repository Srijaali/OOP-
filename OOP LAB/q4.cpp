#include <iostream>
using namespace std;

int main() {
  

     int height[] = {1,8,6,2,5,4,8,3,7};
    int i = 0;
    int length;
    int j = 9 - 1;
    int max_water = 0;

    while (i < j) {
        if (j == i + 1) {
            j = 9 - 1;
            i++;
        }
        int base = j - i;
        if (height[i] < height[j]) {
           length = height[i];
        }
        if (height[i] > height[j]) {
            length = height[j];
        }
        if (height[i] == height[j]) {
            length = height[i];
        }
        if (max_water < (length * base)) {
            max_water = length * base;
        }
        j--;
    }
    cout << "The max amount of water the container can hold is " << max_water << endl;
    return 0;
}
