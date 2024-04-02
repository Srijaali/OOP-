/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: a cybersecurity framework that has many layers of protection.
*/

#include <iostream>
#include <string>
using namespace std;

class SecurityTool{
    protected:
    string securityLevel; // high , medium or low
    int cost; // cost>0
    int no_devices;

    public:
    SecurityTool(string securityLevel,int cost,int no_devices){
        if(securityLevel == "low" || securityLevel == "medium" || securityLevel == "high"){
            this -> securityLevel = securityLevel;
        }
        else{
            cout << "Invalid security level input. Making it LOW by default!" << endl;
            securityLevel = "low";
        }

        if(cost > 0) {
            this -> cost = cost;
        }
        else {
            cout << "Invalid cost input..Re-enter the value!" << endl;
        }
    }

    void performScan(){
        cout << "GENERIC SECURITY SCAN IS BEING PERFORMED... " << endl;
    }
};

class FirewallTool : public SecurityTool{
    private:
        int ports[23]=  {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,28};
        string protocols[6];
    public:
        FirewallTool(string securityLevel,int cost,int no_devices,int new_port) : SecurityTool(securityLevel,cost,no_devices){
            for(int i=0; i<24; i++)
        {
            ports[0]=new_port+i;
        }
        protocols[0] = "HTTPS";
        protocols[1] = "FTP";
        protocols[2] = "UDP";
        protocols[3] = "ICMP";
        protocols[4] = "SSH";
        protocols[5] = "SNMP";
        }

        void generateList() {
        
        cout << "Allowed Port Numbers: ";
        for (int port : ports) {
            cout << port << " ";
        }
        cout << endl;
    }

        void performScan(){
            if(securityLevel == "high"){
                cout << "Only traffic from the port list and protocol list is allowed!" << endl;
            }

            else if(securityLevel == "medium") {
                cout << "Traffic from port and protocol list along with the next two ports in sequence is allowed!" << endl;
            }

            else if(securityLevel == "low"){
                cout << "Traffic from port and protocol list along with the next 5 ports in sequence and from TCP and DNS protocol is allowed!" << endl;
            }
        }
};

int main() {

    cout << "Name: Syeda Rija Ali" << endl;
    cout << "ID: 23K-0057" << endl;

    cout << endl; 
    
    int new_port = 3;
    
    FirewallTool ft("medium" , 250 , 9 , new_port);
    ft.performScan();

    return 0;
}
