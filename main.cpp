#include<iostream>
#include<map>
using namespace std;

class Product {
    string productID;
    string productName;
    int stockQuantity;
    double price;
};
class Inventory {
    map<string, Product> productList;
};

void displayMenu(){
    cout << "Inventory Management System\n";
    cout << "1. Please Add Product\n";
    cout << "2. Update Product Stock\n";
    cout << "3. Process Sale\n";
    cout << "4. Display Stock\n";
    cout << "5. Save Inventory to File\n";
    cout << "6. Load Inventory from File\n";
    cout << "7. Exit\n";
}

int main(){
    //cout <<" This a project for a store for management purpose"<<endl;
    
    int option, stock, quantity;
    string id, name;
    double price;
    
    displayMenu();

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Stock Quantity: ";
            cin >> stock;
            cout << "Enter Product Price: ";
            cin >> price;
            
            break;

        case 2:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter New Stock Quantity: ";
            cin >> stock;
            break;

        case 3:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity Sold: ";
            cin >> quantity;
            break;

        case 4:
           
            break;

        case 5:
            
            break;

        case 6:
            

        case 7:
            

        default:
            cout << "Invalid choice! Try again.\n";
        }
    return 0;
}