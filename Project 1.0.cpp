#include <iostream>
using namespace std;

struct Customer {
    int customerID;
    string name;
    string contactNumber;
    string address;
    Customer* next;
};

struct Order {
    int orderID;
    int customerID;
    int menuItemID;
    int quantity;
    string status;
    Order* next;
};

struct MenuItem {
    int menuItemID;
    string name;
    double price;
    string description;
    MenuItem* next;
};

struct Employee {
    int employeeID;
    string name;
    string position;
    string contactNumber;
    Employee* next;
};

struct OrderQueue {
    Order* front;
    Order* rear;
};

OrderQueue orderQueue = {NULL, NULL};

Customer* customerHead = NULL;
Order* orderHead = NULL;
MenuItem* menuHead = NULL;
Employee* employeeHead = NULL;

void addMenuItem() {
    
}

void addCustomer() {
    
}

void addOrder() {
    
}

void addEmployee() {
}

void processOrder() {
    
}

void displayMenuItems() {
    MenuItem* temp = menuHead;
    while (temp != NULL) {
        cout << "ID: " << temp->menuItemID
             << ", Name: " << temp->name
             << ", Price: " << temp->price << endl;
        temp = temp->next;
    }
}

void displayCustomers() {
    Customer* temp = customerHead;
    while (temp != NULL) {
        cout << "ID: " << temp->customerID
             << ", Name: " << temp->name
             << ", Contact: " << temp->contactNumber << endl;
        temp = temp->next;
    }
}

void displayOrders() {
    Order* temp = orderHead;
    while (temp != NULL) {
        cout << "Order ID: " << temp->orderID
             << ", Customer ID: " << temp->customerID
             << ", Item ID: " << temp->menuItemID
             << ", Quantity: " << temp->quantity
             << ", Status: " << temp->status << endl;
        temp = temp->next;
    }
}

void displayEmployees() {
    Employee* temp = employeeHead;
    while (temp != NULL) {
        cout << "ID: " << temp->employeeID
             << ", Name: " << temp->name
             << ", Position: " << temp->position << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\n Cafe Management System Menu:\n";
        cout << "1. Add Customer\n";
        cout << "2. Add Order\n";
        cout << "3. Add Menu Item\n";
        cout << "4. Add Employee\n";
        cout << "5. Process Order\n";
        cout << "6. Display Customers\n";
        cout << "7. Display Orders\n";
        cout << "8. Display Menu Items\n";
        cout << "9. Display Employees\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			    addCustomer(); 
			    break;
            case 2: 
			    addOrder(); 
				break;
            case 3: 
			    addMenuItem(); 
				break;
            case 4:
			    addEmployee(); 
				break;
            case 5:
			    processOrder(); 
				break;
            case 6:
			    displayCustomers();
				break;
            case 7: 
			    displayOrders(); 
				break;
            case 8: 
			    displayMenuItems(); 
				break;
            case 9: 
			    displayEmployees(); 
				break;
            case 10:
			    cout << "Exiting system.\n"; 
				break;
            default:
			    cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}

