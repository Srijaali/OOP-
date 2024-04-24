/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: 
*/

#include <iostream>
using namespace std;

class Logo{
    private:
    string logo;

    public:
    Logo(string logo) : logo(logo){}

    friend void display(Logo* logo);
    
};

class Platform{
    private:
    string platform;

    public:
    Platform(string platform) : platform(platform) {}
};

class Server{
     private:
    string server;
  public:
    Server(string server) : server(server) {}
};

void display(Logo* logo){
  cout << "Original Logo: " << logo->logo << endl;
  logo->logo = "Doge coin";
  cout << "New Logo: " << logo->logo << endl;
}

int main(){
  Logo logo("blue bird");
  
  display(&logo);
  return 0;

}
