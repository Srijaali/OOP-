/*
Name: Rija Ali
Desc: stationary management system
*/
#include <iostream>
#include <string>
using namespace std;

class stationaryshop {
    string items[50]; 
    float prices[50];
    int n;

public:
    stationaryshop()
        {
            n = 0;//constructor setting default value to zero
        }
        
        void additems(string item, float price)
        {
		        items[n] = item;
                prices[n] = price;
                n++;
                cout << item<< " added successfully.\n";
            }

    void fetchitems() {
        cout << "\nLIST OF ITEMS\n";
        for (int i = 0; i < 50; i++) {
            if (items[i] != "") // skipping empty spaces in the total items array
            {
                cout << "Item" << i + 1 << ": " << items[i] << endl;
            }
        }
    }

    void editprice(string item, float newprice) {
        for (int i = 0; i < 50; i++) {
            if (items[i] == item) {
                prices[i] = newprice;
                break; // to optimize code
            }
        }
    }

    void viewall() {
        cout << "\n ITEM LIST WITH PRICES \n";
        for (int i = 0; i < 50; i++) {
            if (items[i] != "" && prices[i] != 0.0) {
                cout << "Item " << i + 1 << ": " << items[i] << " Price: PKR " << prices[i] << endl;
            }
        }
    }

    void receipt(int bought[], int quantities[]) {
    float total = 0.0;
    cout << "Receipt: \n";
    
    for (int i = 0; i < 50; i++) {
    	
        if (bought[i] != 0 && bought[i] <= n) {
		 
            cout << "Item: " << items[bought[i]-1] << " Quantity: " << quantities[i] << "\n";
            total += prices[bought[i] - 1] * quantities[i];
        }
        else if (bought[i] != 0 && bought[i] > n) { 
            cout << "Invalid item index: " << bought[i] << "\n";
        }
    }
    cout << "Total Amount = PKR" << total << "\n";
}

};

int main() {

    stationaryshop shop;
    int choice;
    int bought[50] = {0};
    int quantities[50] = {0};
    
    cout<<"\nSTATIONARY SHOP MANAGEMENT SYSTEM\n";

    do {
        cout << "1. Add Items\n";
        cout << "2. Display List of Items\n";
        cout << "3. Edit Price of an Item\n";
        cout << "4. Display Items with Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "0. Exit shop.\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                float price;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter price: ";
                cin >> price;
                shop.additems(item, price);
                break;
            }
            case 2: {
                shop.fetchitems();
                break;
            }
            case 3: {
                string item;
                float newprice;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter new price: ";
                cin >> newprice;
                shop.editprice(item, newprice);
                break;
            }
            case 4: {
                shop.viewall();
                break;
            }
            case 5: {
                 int index, quantity;
            
            while(true)
            {
                cout << "Enter item index number: ";
                cin >> index;
                if (index == 0)
                {
                    break;
                }
                cout << "Enter quantity of item: ";
                cin >> quantity;
                bought[index - 1] = index;
                quantities[index - 1] = quantity;
            }

            shop.receipt(bought, quantities);
            break;
            }
            case 0:
                cout << "Exiting shop.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
