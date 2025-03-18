#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for customer data
struct Customer {
    string accountNum;
    string name;
};

// Function to display all customers
void displayCustomers(const vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "No customers found.\n";
        return;
    }
    cout << "Customer List:\n";
    for (const auto& cust : customers) {
        cout << "Account: " << cust.accountNum << " - Name: " << cust.name << endl;
    }
}

// Function to insert a new customer
void insertCustomer(vector<Customer>& customers, const string& accountNum, const string& name) {
    customers.push_back({accountNum, name});
    cout << "Customer inserted: " << accountNum << " - " << name << endl;
}

// Function to update a customer's name
void updateCustomer(vector<Customer>& customers, const string& accountNum, const string& newName) {
    for (auto& cust : customers) {
        if (cust.accountNum == accountNum) {
            cust.name = newName;
            cout << "Customer updated: " << accountNum << " - " << newName << endl;
            return;
        }
    }
    cout << "Customer not found.\n";
}

// Function to delete a customer
void deleteCustomer(vector<Customer>& customers, const string& accountNum) {
    auto it = remove_if(customers.begin(), customers.end(), [&](const Customer& c) {
        return c.accountNum == accountNum;
    });

    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "Customer deleted: " << accountNum << endl;
    } else {
        cout << "Customer not found.\n";
    }
}

// Main function
int main() {
    vector<Customer> customers;

    // Insert customers
    insertCustomer(customers, "CUST001", "John Doe");

    // Display customers
    displayCustomers(customers);

    // Update a customer
    updateCustomer(customers, "CUST001", "Jane Doe");

    // Display updated customers
    displayCustomers(customers);

    // Delete a customer
    deleteCustomer(customers, "CUST001");

    // Display final customer list
    displayCustomers(customers);

    return 0;
}
