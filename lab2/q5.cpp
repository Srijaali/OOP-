#include <iostream>
#include <cstring>
using namespace std;

// MAX PRODUCTS
#define MAX 100

int i,j;

struct Product {
    int id;
    int quantity;
    char name[50];
    float price;
};

Product products[MAX];
int n = 0; 

void addProduct(int id, const char name[], float price, int quantity) {
    if (n < MAX) {

        products[n].id = id;
        strcpy(products[n].name, name);
        products[n].price = price;
        products[n].quantity = quantity;
        n++;

        cout << "Product added successfully.\n";
    } else {
        cout << "Maximum limit reached.\n";
    }
}

void display(int productId) {

    for (i = 0; i < n; i++) {
        if (products[i].id == productId) {

            cout << "Product ID: " << products[i].id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;
            cout << "Quantity in Stock: " << products[i].quantity << endl;
        }
    }
    cout << "Product not found.\n";
}

void updateProduct(int productId, float price, int quantity) {
    for (i = 0; i < n; i++) {
        if (products[i].id == productId) {
            products[i].price = price;
            products[i].quantity = quantity;
            cout << "Product information updated.\n";
        }
    }
    cout << "Product not found.\n";
}

void removeProduct(int productId) {

    for (i = 0; i < n; i++) {

        if (products[i].id == productId) {
            for (j = i; j < n - 1; j++) {
                products[j] = products[j + 1];
            }
            n--;

            cout << "Product removed successfully.\n";
        }
    }
    cout << "Product not found.\n";
}

int main() {
    int choice, id;
    float price;
    int quantity;
    char name[50];

    cout << "PRODUCT MANAGEMENT SYSTEM\n\n";

    do {
        cout << "1. Add Product." << endl;
        cout << "2. Display Product Information." << endl;
        cout << "3. Update Product Information." << endl;
        cout << "4. Remove Product." << endl;
        cout << "0. EXIT." << endl;

        cout << "Select an Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin.ignore();
                cin.getline(name, 50);
                cout << "Enter Product Price: ";
                cin >> price;
                cout << "Enter Product Quantity: ";
                cin >> quantity;
                addProduct(id, name, price, quantity);
                break;
            case 2:
                cout << "Enter Product ID to display: ";
                cin >> id;
                display(id);
                break;
            case 3:
                cout << "Enter Product ID to update: ";
                cin >> id;
                cout << "Enter new Price: ";
                cin >> price;
                cout << "Enter new Quantity: ";
                cin >> quantity;
                updateProduct(id, price, quantity);
                break;
            case 4:
                cout << "Enter Product ID to remove: ";
                cin >> id;
                removeProduct(id);
                break;
            case 0:
                cout << "Exiting Program\n";
                break;
            default:
                cout << "INVALID CHOICE\n";
        }
    } while (choice != 0);

    return 0;
}
