/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: Daraz Loyalty Program System
*/

#include <iostream>
#include <string>
using namespace std;

class DarazPersonData{
    private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

    public:

    DarazPersonData(string fName, string lName , string add, string c, string s, string z, string p) : firstName(fName) , lastName(lName) , address(add) , city(c) , state(s) , zip(z) , phone(p) {}

   string getFname(){
    return firstName;
   }

   string getLname(){
    return lastName;
   }

   string getAddress(){
    return address;
   }

   string getCity(){
    return city;
   }

   string getState(){
    return state;
   }

   string getZip(){
    return zip;
   }

   string getPhone(){
    return phone;
   }
    
    void setFname(string fName){
       firstName = fName;
    }

    void setLname(string lName){
        lastName = lName;
    }

    void setAddress(string add){
        address = add;
    }

    void setCity(string c){
        city = c;
    }

    void setState(string s){
        state = s;
    }

    void setZip(string z){
        zip = z;
    }

    void setPhone(string p){
        phone = p;
    }

};

class DarazCustomerdata : public DarazPersonData{
    protected:
    int customerNumber; //unique integer for each customer
    int loyaltyPoints; //points earned by customer
    static int totalCustomers;
    public:
    DarazCustomerdata(string fName , string lName , string add, string c , string s, string z, string p) : DarazPersonData(fName,lName,add,c,s,z,p), customerNumber(totalCustomers++) , loyaltyPoints(0) {}

    int getCustomerNum(){
        return customerNumber;
    }

    int getLoyaltyPts(){
        return loyaltyPoints;
    }

    void setCustomernum(int cm){
        customerNumber = cm;
    }

    void setLoyaltyPts(int lPs){
       if(lPs>=0){
        loyaltyPoints = lPs;
    }
    else{
        cout << "Invalid loyalty points!" << endl;
        }
    }
};

int DarazCustomerdata::totalCustomers = 0;

class DarazLoyaltyProgram{
   DarazCustomerdata* customer;
    
    public:
    DarazLoyaltyProgram(DarazCustomerdata* cust) : customer(cust) {}

    void addLoyalPts(int points){
        if(customer){
             customer -> setLoyaltyPts(customer->getLoyaltyPts()+points);
        }
        else{
            cout << "Invalid customer!" << endl;
        }
    }

    float redeemLoyalPts(int points){
             int loyalty_points = customer->getLoyaltyPts();
        if (loyalty_points - points < 0 || points < 0) {
		return -1.f;
		}
		else{
		
       return 0.75f;
        }
    }

    void displayLoyaltyPoints(){
        cout << "Total Loyalty Points: " << customer->getLoyaltyPts() << endl;
    }
};

    void displayInfo(DarazCustomerdata& customer){
        cout << "Customer ID: " << customer.getCustomerNum() <<endl;
    cout << "Name: " << customer.getFname() + " " + customer.getLname() <<endl;
    cout << "Address: " << customer.getAddress() <<endl;
    cout << "City: " << customer.getCity() <<endl;
    cout << "State: " << customer.getState() <<endl;
    cout << "Phone: " << customer.getPhone() <<endl;
    cout << "Zip: " << customer.getZip() <<endl;
   
}

int main(){

    cout << "Name: Syeda Rija Ali" << endl;
    cout << "ID: 23K-0057" << endl;
    cout << endl;
    
    int loyalty_points;
    float itemprice;

    DarazCustomerdata customer ("Haider" , "Rizvi" , "Gulshan" , "Karachi" , "9033456" , "7460" , "street");

    displayInfo(customer);

    DarazLoyaltyProgram dlp(&customer);
    dlp.addLoyalPts(100);
    dlp.displayLoyaltyPoints();

    cout << "Enter item price: ";
    cin >> itemprice;

    cout << "Enter amount of points to redeem: ";
    cin >> loyalty_points;

    cout << "Original Price: " << itemprice << "\n";
    float discount = dlp.redeemLoyalPts(loyalty_points);

    if (discount == -1){return 1;}
	 
    cout << "Discounted Price: " << itemprice * discount << "\n";

    return 0;
}
