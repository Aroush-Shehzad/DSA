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
    int stock; 
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

//void displayOrderReport(int orderID);
void modifyEmployee();
void deleteMenuItem();
void searchMenuItem();

void addMenuItem() {
    MenuItem* newItem = new MenuItem;
    cout << "  Enter Menu Item ID: ";
    cin >> newItem->menuItemID;

    cin.ignore(); 
    cout << "  Enter Item Name: ";
    cin >> newItem->name;

    cout << "  Enter Item Price: ";
    cin >> newItem->price;

    cin.ignore(); 
    cout << "  Enter Description: ";
    cin >> newItem->description;

    newItem->next = menuHead;
    menuHead = newItem;

    cout << "  Menu Item added successfully.\n";
}

void addCustomer() {
    Customer* newCustomer = new Customer;
    cout << "  Enter Customer ID: ";
    cin >> newCustomer->customerID;

    cin.ignore(); 
    cout << "  Enter Customer Name: ";
    cin >> newCustomer->name;

    cout << "  Enter Contact Number: ";
    cin >> newCustomer->contactNumber;

    cout << "  Enter Address: ";
    cin >> newCustomer->address;

    newCustomer->next = customerHead;
    customerHead = newCustomer;

    cout << "  Customer added successfully.\n";
}

void addOrder() {
    Order* newOrder = new Order;

    cout << "  Enter Order ID: ";
    cin >> newOrder->orderID;
    cout << "  Enter Customer ID: ";
    cin >> newOrder->customerID;
    cout << "  Enter Menu Item ID: ";
    cin >> newOrder->menuItemID;
    cout << "  Enter Quantity: ";
    cin >> newOrder->quantity;

    newOrder->status = "  Pending";
    newOrder->next = NULL;

    if (orderQueue.rear == NULL) {
        orderQueue.front = orderQueue.rear = newOrder;
    } else {
        orderQueue.rear->next = newOrder;
        orderQueue.rear = newOrder;
    }

    newOrder->next = orderHead;
    orderHead = newOrder;

    cout << "  Order added successfully.\n";
}

void addEmployee() {
    Employee* newEmployee = new Employee;
    cout << "  Enter Employee ID: ";
    cin >> newEmployee->employeeID;

    cin.ignore(); 
    cout << "  Enter Employee Name: ";
    cin >> newEmployee->name;

    cout << "  Enter Position: ";
    cin >> newEmployee->position;

    cout << "  Enter Contact Number: ";
    cin >> newEmployee->contactNumber;

    newEmployee->next = employeeHead;
    employeeHead = newEmployee;

    cout << "  Employee added successfully.\n";
}


void deductStock(int menuItemID, int quantity) {
    MenuItem* item = menuHead;
    while (item != NULL) {
        if (item->menuItemID == menuItemID) {
            if (item->stock >= quantity) {
                item->stock -= quantity;
                cout << "  Stock updated. Remaining: " << item->stock << "\n";
            } else {
                cout << "  Insufficient stock for item: " << item->name << "\n";
            }
            return;
        }
        item = item->next;
    }
    cout << "  Item not found.\n";
}

void processOrder() {
    if (orderQueue.front == NULL) {
        cout << "  No orders to process.\n";
        return;
    }

    Order* currentOrder = orderQueue.front;
    orderQueue.front = currentOrder->next;
    if (orderQueue.front == NULL) {
        orderQueue.rear = NULL;
    }

    deductStock(currentOrder->menuItemID, currentOrder->quantity);
    currentOrder->status = "  Completed";
    cout << "  Order " << currentOrder->orderID << " processed.\n";

   // displayOrderReport(currentOrder->orderID);
    delete currentOrder;
}

void modifyEmployee() {
    int id;
    cout << "  Enter Employee ID to modify: ";
    cin >> id;

    Employee* temp = employeeHead;
    while (temp != NULL) {
        if (temp->employeeID == id) {
            cout << "  Enter new name (current: " << temp->name << "): ";
            cin >> temp->name;
            cout << "  Enter new position (current: " << temp->position << "): ";
            cin >> temp->position;
            cout << "  Enter new contact number (current: " << temp->contactNumber << "): ";
            cin >> temp->contactNumber;

            cout << "  Employee updated successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "  Employee not found.\n";
}

void deleteMenuItem() {
    int id;
    cout << "  Enter Menu Item ID to delete: ";
    cin >> id;

    MenuItem* temp = menuHead;
    MenuItem* prev = NULL;
    while (temp != NULL) {
        if (temp->menuItemID == id) {
            if (prev == NULL) {  // Head node
                menuHead = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "  Menu Item deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "  Menu Item not found.\n";
}

void searchMenuItem() {
    int id;
    cout << "  Enter Menu Item ID to search: ";
    cin >> id;

    MenuItem* temp = menuHead;
    while (temp != NULL) {
        if (temp->menuItemID == id) {
            cout << "  Menu Item Found: " << temp->name << ", " << temp->price << ", " << temp->description << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "  Menu Item not found.\n";
}

void generateOrderReport() {
    Order* temp = orderHead;
    double totalSales = 0;
    int totalOrders = 0;
    
    while (temp != NULL) {
        MenuItem* item = menuHead;
        while (item != NULL && item->menuItemID != temp->menuItemID) {
            item = item->next;
        }

        if (item) {
            double orderTotal = item->price * temp->quantity;
            totalSales += orderTotal;
            totalOrders++;

            cout << "Order ID: " << temp->orderID
                 << ", Customer ID: " << temp->customerID
                 << ", Item: " << item->name
                 << ", Quantity: " << temp->quantity
                 << ", Price: " << item->price
                 << ", Total: " << orderTotal << "\n";
        }
        temp = temp->next;
    }

    cout << "\nTotal Orders: " << totalOrders << ", Total Sales: " << totalSales << "\n";
}

void line() {
    cout << endl;
    cout << "------------------------------------------";
    cout << endl;
}

void displayMenuItems() {
    MenuItem* temp = menuHead;
    while (temp != NULL) {
        cout << "  ID: " << temp->menuItemID
             << ", Name: " << temp->name
             << ", Price: " << temp->price << endl;
        temp = temp->next;
    }
    line();
}

void displayCustomers() {
    Customer* temp = customerHead;
    while (temp != NULL) {
        cout << "  ID: " << temp->customerID
             << ", Name: " << temp->name
             << ", Contact: " << temp->contactNumber << endl;
        temp = temp->next;
    }
    line();
}

void displayOrders() {
    Order* temp = orderHead;
    while (temp != NULL) {
        cout << "  Order ID: " << temp->orderID
             << ", Customer ID: " << temp->customerID
             << ", Item ID: " << temp->menuItemID
             << ", Quantity: " << temp->quantity
             << ", Status: " << temp->status << endl;
        temp = temp->next;
    }
    line();
}

void displayEmployees() {
    Employee* temp = employeeHead;
    while (temp != NULL) {
        cout << "  Employee ID: " << temp->employeeID
             << ", Name: " << temp->name
             << ", Position: " << temp->position
             << ", Contact: " << temp->contactNumber << endl;
        temp = temp->next;
    }
    line();
}

int main() {
    int choice;
    cout<<"\n  *********  Welcome to Margalla Cafe Management System  ********"<<endl;
    cout<< "                   Bringing Joy One Cup At A Time      "<<endl;
    line();
    do {
        cout << "  ----- Cafe Management System -----\n";
        cout << "  1.  Add Menu Item\n";
        cout << "  2.  Add Customer\n";
        cout << "  3.  Add Order\n";
        cout << "  4.  Add Employee\n";
        cout << "  5.  Process Order\n";
        cout << "  6.  Display Orders\n";
        cout << "  7.  Display Menu Items\n";
        cout << "  8.  Display Customers\n";
        cout << "  9.  Display Employees\n";
        cout << "  10. Generate Order Report\n";
        cout << "  11. Modify Employee\n";
        cout << "  12. Delete Menu Item\n";
        cout << "  13. Search Menu Item\n";
        cout << "  0. Exit\n";
        cout << "  Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                addCustomer();
                break;
            case 3:
                addOrder();
                break;
            case 4:
                addEmployee();
                break;
            case 5:
                processOrder();
                break;
            case 6:
                displayOrders();
                break;
            case 7:
                displayMenuItems();
                break;
            case 8:
                displayCustomers();
                break;
            case 9:
                displayEmployees();
                break;
            case 10:
                generateOrderReport();
                break;
            case 11:
                modifyEmployee();
                break;
            case 12:
                deleteMenuItem();
                break;
            case 13:
                searchMenuItem();
                break;
            case 0:
                cout << "  Exiting system...\n";
                break;
            default:
                cout << "  Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

