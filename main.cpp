#include<iostream>
#include<map>
using namespace std;

class Product {
    string productID;
    string productName;
    int stockQuantity;
    double price;

public:
    // Default constructor
    Product() : productID(""),productName(""), stockQuantity(0), price(0.0) {}

    //parameterized constructor
    Product(string id, string name, int stock, double price) 
        : productID(id), productName(name), stockQuantity(stock), price(price) {}
    
    // Getters and Setters
    string getProductID() const { return productID; }
    string getProductName() const { return productName; }
    int getStockQuantity() const { return stockQuantity; }
    double getPrice() const { return price; }
    void setStockQuantity(int quantity) { stockQuantity = quantity; }
    void setPrice(double newPrice) { price = newPrice; }

    // Print Product Information
    void displayProductInfo() const {
        cout << "ID: " << productID << ", Name: " << productName 
                  << ", Stock: " << stockQuantity << ", Price: $" << price << endl;
    }
};

class Inventory {
    map<string, Product> productList;

public:
    // Add a product to the inventory
    void addProduct(const Product& product) {
        productList[product.getProductID()] = product;
    }


    // Update stock quantity
    void updateProductStock(const string& productID, int newStock) {
        if (productList.find(productID) != productList.end()) {
            productList[productID].setStockQuantity(newStock);
        } else {
            cout << "Product not found!" << endl;
        }
    }

    // deduct quantity from stock)
    void processSale(const string& productID, int quantitySold) {
        if (productList.find(productID) != productList.end()) {
            int currentStock = productList[productID].getStockQuantity();
            if (currentStock >= quantitySold) {
                productList[productID].setStockQuantity(currentStock - quantitySold);
                cout << "Sale processed for " << quantitySold << " units of product " << productID << endl;
            } else {
                cout << "Insufficient stock!" << endl;
            }
        } else {
            cout << "Product not found!" << endl;
        }
    }
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
    string id, name, filename;
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
            cout << "Enter filename to save inventory: ";
            cin >> filename;
            break;

        case 6:
            cout << "Enter filename to load inventory: ";
            cin >> filename;
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    
}