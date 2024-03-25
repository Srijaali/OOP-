/*
Name: Syeda Rija Ali
ID: 23K-0057
desc:a program that calculates the batting average and strike rate for a cricket player.
*/

#include <iostream>

using namespace std;

inline int batting_avg(int total_runs, int dismissals){
  
   int batting_average;
    if(dismissals==0){
        return 0;
    }
    else{
        batting_average = total_runs/dismissals;
        return batting_average;
        }
}

inline int strike_rate(int total_runs, int total_balls){
    int strikerate;
    strikerate = total_runs/total_balls*100;
    return strikerate;
}

int main(){
    cout << "The Batting average is: "<< batting_avg(100,50) << endl;
    cout << "The Strike rate is: " << strike_rate(100,20) << endl;

      return 0;
}
