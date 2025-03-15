#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/stat.h>

using namespace std;

class inventory {
public:
    string item;
    int price, quantity;
    
    void Add_Item() {
        string Iid, item;
        double price;
        int quantity;
    
        cout << "To Add Item to Inventory, please enter the following details: " << endl;
        cout << "Item ID: ";
        cin >> Iid;
    
        cin.ignore();
        cout << "Item Name: ";
        getline(cin, item);
    
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
    
        ofstream file("inventory.csv", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        file << Iid << "," << item << "," << price << "," << quantity << "\n";
        file.close();
        cout << "Item Added Successfully." << endl;
    }

    void Display_Item(string filename, string search_id) {
        cout << "Enter Item ID to search: ";
        cin >> search_id;

        ifstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        bool found = false;
        string Iid, item, price, quantity; 

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, Iid, ',');
            getline(ss, item, ',');
            getline(ss, price, ',');
            getline(ss, quantity, ',');

            if (Iid == search_id) {
                cout << "Item Found!" << endl;
                cout << "ID: " << Iid << endl;
                cout << "Name: " << item << endl;
                cout << "Price: " << price << endl;
                cout << "Quantity: " << quantity << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in inventory." << endl;
        }

        file.close();
    }

    void Update_Item(string filename) {
        string search_id;
        cout << "Enter Item ID to update: ";
        cin >> search_id;

        ifstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        ofstream tempFile("temp.csv");
        string line, Iid, item, price, quantity;
        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, Iid, ',');
            getline(ss, item, ',');
            getline(ss, price, ',');
            getline(ss, quantity, ',');

            if (Iid == search_id) {
                cout << "Enter new price: ";
                cin >> price;
                cout << "Enter new quantity: ";
                cin >> quantity;
                tempFile << Iid << "," << item << "," << price << "," << quantity << "\n";
                found = true;
            } else {
                tempFile << line << "\n";
            }
        }

        file.close();
        tempFile.close();
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());

        if (found) {
            cout << "Item updated successfully!" << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }

    void Delete_Item(string filename) {
        string search_id;
        cout << "Enter Item ID to delete: ";
        cin >> search_id;

        ifstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        ofstream tempFile("temp.csv");
        string line, Iid, item, price, quantity;
        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, Iid, ',');
            getline(ss, item, ',');
            getline(ss, price, ',');
            getline(ss, quantity, ',');

            if (Iid == search_id) {
                found = true;
                continue;
            }
            tempFile << line << "\n";
        }

        file.close();
        tempFile.close();
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());

        if (found) {
            cout << "Item deleted successfully!" << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }
};

bool fileExists(const string &filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

int main() {
    inventory inv;
    string filename = "inventory.csv";

    if (!fileExists(filename)) {
        ofstream file(filename);
        file << "Iid,Name,Price,Quantity\n";
        file.close();
    }

    int choice;
    while (true) {
        cout << "\nWelcome to Inventory Management System" << endl;
        cout << "1. Add item to inventory" << endl;
        cout << "2. Update item in inventory" << endl;
        cout << "3. Delete item from inventory" << endl;
        cout << "4. Display item details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inv.Add_Item();
                break;
            case 2:
                inv.Update_Item(filename);
                break;
            case 3:
                inv.Delete_Item(filename);
                break;
            case 4: {
                string search_id;
                inv.Display_Item(filename, search_id);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}