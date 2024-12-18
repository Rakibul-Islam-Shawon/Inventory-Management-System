#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
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

    // Displaying available stock
    void displayStock() {
        for (const auto& pair : productList) {
            pair.second.displayProductInfo();
        }
    }

    // Save inventory to file
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        for (const auto& pair : productList) {
            outFile << pair.first << "," << pair.second.getProductName() << ","
                    << pair.second.getStockQuantity() << "," << pair.second.getPrice() << endl;
        }
        outFile.close();
    }

    //Load file 
    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        string line, id, name;
        int stock;
        double price;

        while (getline(inFile, line)) {
            stringstream ss(line);
            getline(ss, id, ',');
            getline(ss, name, ',');
            ss >> stock >> price;
            addProduct(Product(id, name, stock, price));
        }
        inFile.close();
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
    
    Inventory inventory;
    int option, stock, quantity;
    string id, name, filename;
    double price;
    

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
            cin >> price;
            inventory.addProduct(Product(id, name, stock, price));
           
            break;

        case 2:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter New Stock Quantity: ";
            cin >> stock;
            inventory.updateProductStock(id, stock);
            break;

        case 3:
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity Sold: ";
            cin >> quantity;
            inventory.processSale(id, quantity);
            break;

        case 4:
           
           inventory.displayStock();
            break;

        case 5:
            cout << "Enter filename to save inventory: ";
            cin >> filename;
            inventory.saveToFile(filename);
            break;
            

        case 6:
            cout << "Enter filename to load inventory: ";
            cin >> filename;
            inventory.loadFromFile(filename);
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    
}