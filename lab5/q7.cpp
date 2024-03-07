/*
Name:Syeda Rija Ali
id:23k-0057
dsc: restaurant management system
*/

#include <iostream>
#include <string>

using namespace std;


class MenuItem {
private:
    string name;
    double price;

public:
	
    MenuItem() : name(""), price(0.0) {}  
    MenuItem(const string& aName, double aPrice) : name(aName), price(aPrice) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};


class Menu {
private:
	//static so all restaurant menus have same value and constant so it cannot be changed
    static const int MAX_ITEMS = 10;
    MenuItem items[MAX_ITEMS];
    int item_Count;

public:
	
    Menu() : item_Count(0) {}
    // functions to change menu items
    void addMenuItem(const MenuItem& item) {
        if (item_Count < MAX_ITEMS) {
            items[item_Count++] = item;
        } else {
            cout<<"Menu is full. No more items can be added!"<<endl;
        }
    }

    void removeMenuItem(const string& itemName) {
        for (int i = 0; i < item_Count; ++i) {
            if (items[i].getName() == itemName) {
                for (int j = i; j < item_Count - 1; ++j) {
                    items[j] = items[j + 1];
                }
                item_Count--;
                break;
            }
        }
    }

    void displayMenu() const {
        cout << "Menu:\n";
        for (int i = 0; i < item_Count; ++i) {
            cout << items[i].getName() << " - Rs." << items[i].getPrice() << endl;
        }
    }
};


class Payment {
private:
    double amount;

public:
    Payment(double paymentAmount) : amount(paymentAmount) {}

    double getAmount() const {
        return amount;
    }
};

class Order {
private:
    static const int MAX_ITEMS = 10;
    MenuItem items[MAX_ITEMS];
    int item_Count;
    Payment payment;

public:
    Order(const MenuItem* orderItems, int item_Count, const Payment& orderPayment) : item_Count(item_Count), payment(orderPayment) {
        for (int i = 0; i < item_Count; ++i) {
            items[i] = orderItems[i];
        }
    }

    void displayOrder() const {
        cout << "Ordered Items:\n";
        for (int i = 0; i < item_Count; ++i) {
            cout << items[i].getName() << " - Rs." << items[i].getPrice() << endl;
        }
        cout << "Total Amount: Rs." << payment.getAmount() << endl;
    }
};


class Restaurant{
private:
    Menu menu;

public:
    void addMenuItemToMenu(const MenuItem& item) {
        menu.addMenuItem(item);
    }

    void removeMenuItemFromMenu(const string& itemName) {
        menu.removeMenuItem(itemName);
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    void placeOrder(const MenuItem* items, int item_Count, const Payment& payment) {
        Order order(items, item_Count, payment);
        order.displayOrder();
    }
};

int main() {

    Restaurant r1;

    MenuItem item1("Biryani", 180);
    MenuItem item2("Pizza", 700);
    r1.addMenuItemToMenu(item1);
    r1.addMenuItemToMenu(item2);
    r1.displayMenu();

    const MenuItem orderItems[] = {item1, item2};
    Payment payment(880);
    r1.placeOrder(orderItems, 2, payment);

    return 0;
}
