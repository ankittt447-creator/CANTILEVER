#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};



void saveToFile(const vector<Product>& inventory) {
    ofstream file("inventory.txt");
    for (const auto& p : inventory) {
        file << p.id << " " << p.name << " " << p.quantity << " " << p.price << "\n";
    }
    file.close();
}

vector<Product> loadFromFile() {
    vector<Product> inventory;
    ifstream file("inventory.txt");
    Product p;
    while (file >> p.id >> p.name >> p.quantity >> p.price) {
        inventory.push_back(p);
    }
    file.close();
    return inventory;
}

void searchProductById(const vector<Product>& inventory, int searchId) {
    bool found = false;
    for (const auto& p : inventory) {
        if (p.id == searchId) {
            cout << "\n Product Found:\n";
            p.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n Product with ID " << searchId << " not found.\n";
    }
}

void searchProductByName(const vector<Product>& inventory, const string& searchName) {
    bool found = false;
    for (const auto& p : inventory) {
        if (p.name == searchName) {
            cout << "\n Product Found:\n";
            p.display();
            found = true;
        }
    }
    if (!found) {
        cout << "\n No product found with name \"" << searchName << "\"\n";
    }
}

// ------------------ Delete ------------------
void deleteProductById(vector<Product>& inventory, int deleteId) {
    bool found = false;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == deleteId) {
            inventory.erase(it);
            cout << "\n Product with ID " << deleteId << " deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n Product with ID " << deleteId << " not found.\n";
    }
}

// ------------------ Update ------------------
void updateProductById(vector<Product>& inventory, int updateId) {
    bool found = false;
    for (auto& p : inventory) {
        if (p.id == updateId) {
            cout << "\n Current Product Details:\n";
            p.display();

            cout << "\nEnter new quantity: ";
            cin >> p.quantity;

            cout << "Enter new price: ";
            cin >> p.price;

            cout << " Product updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n Product with ID " << updateId << " not found.\n";
    }
}


int main(){
    vector<Product>inventory=loadFromFile();
    int choice;  
do {
   
    cout << "1. Add Product\n";
    cout << "2. View Products\n";
    cout << "3. Search Product by ID\n";
    cout << "4. Search Product by Name\n";
    cout << "5. Delete Product\n";
    cout << "6. Update Product\n";
    cout << "7. Exit\n";

  
    cout << "Enter your choice (1-7): ";
    cin >> choice;  

    
    if (choice == 1) {
        Product p;        
        p.input();       
        inventory.push_back(p);  
    }
    else if (choice == 2) {
            if (inventory.empty()) {
                cout << "  No products to display.\n";
            } else {
                cout << "\n----- Product List -----\n";
                for (const auto& p : inventory) {
                    p.display();
                }
            }
        }

   

    
    else if (choice == 3) {
    int idToSearch;
    cout << "Enter Product ID to search: ";
    cin >> idToSearch;
    searchProductById(inventory, idToSearch);
    


    }else if (choice == 4) {
    string nameToSearch;
    cout << "Enter Product Name to search: ";
    cin >> nameToSearch;
    searchProductByName(inventory, nameToSearch);
    }
     else if (choice == 5) {
    int deleteId;
    cout << "Enter Product ID to delete: ";
    cin >> deleteId;
    deleteProductById(inventory, deleteId);
    }
    else if (choice == 6) {
    int updateId;
    cout << "Enter Product ID to update: ";
    cin >> updateId;
    updateProductById(inventory, updateId);
    }
    else if (choice == 7) {
    saveToFile(inventory);
    cout << "💾 Data saved. Exiting program...\n";
    }
    else {
            cout << " Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}


