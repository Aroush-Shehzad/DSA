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
    MenuItem* newItem = new MenuItem;
    cout << "Enter Menu Item ID: ";
    cin >> newItem->menuItemID;

    cin.ignore(); 
    cout << "Enter Item Name: ";
    cin>>newItem->name;

    cout << "Enter Item Price: ";
    cin >> newItem->price;

    cin.ignore(); 
    cout << "Enter Description: ";
    cin>> newItem->description;

    newItem->next = menuHead;
    menuHead = newItem;

    cout << "Menu Item added successfully.\n";
}

void addCustomer() {
    Customer* newCustomer = new Customer;
    cout << "Enter Customer ID: ";
    cin >> newCustomer->customerID;

    cin.ignore(); 
    cout << "Enter Customer Name: ";
    cin>>newCustomer->name;

    cout << "Enter Contact Number: ";
    cin>> newCustomer->contactNumber;

    cout << "Enter Address: ";
    cin>>newCustomer->address;

    newCustomer->next = customerHead;
    customerHead = newCustomer;

    cout << "Customer added successfully.\n";
}

void addOrder() {
    Order* newOrder = new Order;

    cout << "Enter Order ID: ";
    cin >> newOrder->orderID;
    cout << "Enter Customer ID: ";
    cin >> newOrder->customerID;
    cout << "Enter Menu Item ID: ";
    cin >> newOrder->menuItemID;
    cout << "Enter Quantity: ";
    cin >> newOrder->quantity;

    newOrder->status = "Pending";
    newOrder->next = NULL;

    if (orderQueue.rear == NULL) {
        orderQueue.front = orderQueue.rear = newOrder;
    } else {
        orderQueue.rear->next = newOrder;
        orderQueue.rear = newOrder;
    }

    newOrder->next = orderHead;
    orderHead = newOrder;

    cout << "Order added successfully.\n";
}

void addEmployee() {
    Employee* newEmployee = new Employee;
    cout << "Enter Employee ID: ";
    cin >> newEmployee->employeeID;

    cin.ignore(); 
    cout << "Enter Employee Name: ";
    cin>>newEmployee->name;

    cout << "Enter Position: ";
    cin>> newEmployee->position;

    cout << "Enter Contact Number: ";
    cin>>newEmployee->contactNumber;

    newEmployee->next = employeeHead;
    employeeHead = newEmployee;

    cout << "Employee added successfully.\n";
}

void processOrder() {
    if (orderQueue.front == NULL) {
        cout << "No orders to process.\n";
        return;
    }

    Order* currentOrder = orderQueue.front;
    orderQueue.front = currentOrder->next;
    if (orderQueue.front == NULL) {
        orderQueue.rear = NULL;
    }

    currentOrder->status = "Completed";
    cout << "Order " << currentOrder->orderID << " processed.\n";

    delete currentOrder; // Free memory of processed order
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

