#include <iostream>
#include <windows.h>  
using namespace std;

class Customer {
public:
    int customerID;
    string name;
    string contactNumber;
    string address;
    Customer* next;

    Customer() {
        next = NULL;
    }
};

class MenuItem {
public:
    int menuItemID;
    string name;
    double price;
    string description;
    int stock;
    MenuItem* next;

    MenuItem() {
        next = NULL;
    }
};

class Employee {
public:
    int employeeID;
    string name;
    string position;
    string contactNumber;
    Employee* next;

    Employee() {
        next = NULL;
    }
};

class Order {
public:
    int orderID;
    int customerID;
    int menuItemID;
    int quantity;
    string status;
    Order* next;

    Order() {
        status = "Pending";
        next = NULL;
    }
};

class OrderQueue {
public:
    Order* front;
    Order* rear;

    OrderQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(Order* order) {
        if (rear == NULL) {
            front = rear = order;
        } else {
            rear->next = order;
            rear = order;
        }
        rear->next = NULL; 
    }

    Order* dequeue() {
        if (front == NULL) return NULL;  
        Order* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;  
        return temp;
    }

    bool isEmpty() {
        return front == NULL;
    }
};
void line() {
    cout << "----------------------------------------------\n";
}

class CafeManagementSystem {
private:
    Customer* customerHead;
    MenuItem* menuHead;
    Employee* employeeHead;
    Order* orderHead;
    OrderQueue orderQueue;

public:
	CafeManagementSystem() {
	    customerHead = NULL;
	    menuHead = NULL;
		employeeHead = NULL;
		orderHead = NULL;
		Sample();
		}
	 void Sample() {
        Customer* c1 = new Customer;
        c1->customerID = 101;
        c1->name = "Fizza";
        c1->contactNumber = "1234567890";
        c1->address = "123 St";
        c1->next = customerHead;
        customerHead = c1;

        Customer* c2 = new Customer;
        c2->customerID = 102;
        c2->name = "Isha";
        c2->contactNumber = "0987654321";
        c2->address = "456 Ave";
        c2->next = customerHead;
        customerHead = c2;
        
        Customer* c3 = new Customer;
        c3->customerID = 102;
        c3->name = "AAA";
        c3->contactNumber = "0987654321";
        c3->address = "456 Ave";
        c3->next = customerHead;
        customerHead = c3;

        MenuItem* m1 = new MenuItem;
        m1->menuItemID = 201;
        m1->name = "Cappuccino";
        m1->price = 3.99; 
        m1->description = "Espresso with steamed milk";
        m1->stock = 50;
        m1->next = menuHead;
        menuHead = m1;

        MenuItem* m2 = new MenuItem;
        m2->menuItemID = 202;
        m2->name = "Latte";
        m2->price = 4.49;
        m2->description = "Espresso with vanilla";
        m2->stock = 40;
        m2->next = menuHead;
        menuHead = m2;

        Employee* e1 = new Employee;
        e1->employeeID = 301;
        e1->name = "Sara";
        e1->position = "Employee";
        e1->contactNumber = "1122334455";
        e1->next = employeeHead;
        employeeHead = e1;

        Employee* e2 = new Employee;
        e2->employeeID = 302;
        e2->name = "Amna";
        e2->position = "Manager";
        e2->contactNumber = "2233445566";
        e2->next = employeeHead;
        employeeHead = e2;

        Order* o1 = new Order;
        o1->orderID = 401;
        o1->customerID = 101;
        o1->menuItemID = 201;
        o1->quantity = 2;
        o1->next = NULL;  
        orderQueue.enqueue(o1);

        Order* o2 = new Order;
        o2->orderID = 402;
        o2->customerID = 102;
        o2->menuItemID = 202;
        o2->quantity = 1;
        o2->next = NULL;  
        orderQueue.enqueue(o2);
        o1->next = o2;  
        orderHead = o1;  
        
    }
    bool checkDuplicateCustomer(int id) {
        Customer* temp = customerHead;
        while (temp) {
            if (temp->customerID == id) return true;
            temp = temp->next;
        }
        return false;
    }

    bool checkDuplicateMenuItem(int id) {
        MenuItem* temp = menuHead;
        while (temp) {
            if (temp->menuItemID == id) return true;
            temp = temp->next;
        }
        return false;
    }

    bool checkDuplicateEmployee(int id) {
        Employee* temp = employeeHead;
        while (temp) {
            if (temp->employeeID == id) return true;
            temp = temp->next;
        }
        return false;
    }

    bool checkDuplicateOrder(int id) {
        Order* temp = orderHead;
        while (temp) {
            if (temp->orderID == id) return true;
            temp = temp->next;
        }
        return false;
    }

    void addCustomer() {
        int id;
        cout << "Enter Customer ID: ";
        cin >> id;
        if (checkDuplicateCustomer(id)) {
            cout << "Customer ID already exists!\n";
            return;
        }

        Customer* newCustomer = new Customer;
        newCustomer->customerID = id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newCustomer->name);
        cout << "Enter Contact Number: ";
        getline(cin, newCustomer->contactNumber);
        cout << "Enter Address: ";
        getline(cin, newCustomer->address);

        newCustomer->next = customerHead;
        customerHead = newCustomer;

        cout << "Customer added successfully!\n";
    }

    void addMenuItem() {
        int id;
        cout << "Enter Menu Item ID: ";
        cin >> id;
        if (checkDuplicateMenuItem(id)) {
            cout << "Menu Item ID already exists!\n";
            return;
        }

        MenuItem* newItem = new MenuItem;
        newItem->menuItemID = id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newItem->name);
        cout << "Enter Price: ";
        cin >> newItem->price;

        cin.ignore();
        cout << "Enter Description: ";
        getline(cin, newItem->description);
        cout << "Enter Stock Quantity: ";
        cin >> newItem->stock;

        newItem->next = menuHead;
        menuHead = newItem;

        cout << "Menu item added successfully!\n";
    }

    void addEmployee() {
        int id;
        cout << "Enter Employee ID: ";
        cin >> id;
        if (checkDuplicateEmployee(id)) {
            cout << "Employee ID already exists!\n";
            return;
        }

        Employee* newEmployee = new Employee;
        newEmployee->employeeID = id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newEmployee->name);
        cout << "Enter Position: ";
        getline(cin, newEmployee->position);
        cout << "Enter Contact Number: ";
        getline(cin, newEmployee->contactNumber);

        newEmployee->next = employeeHead;
        employeeHead = newEmployee;

        cout << "Employee added successfully!\n";
    }

void addOrder() {
    int id;
    cout << "Enter Order ID: ";
    cin >> id;
    if (checkDuplicateOrder(id)) {
        cout << "Order ID already exists!\n";
        return;
    }

    Order* newOrder = new Order;
    newOrder->orderID = id;
    cout << "Enter Customer ID: ";
    cin >> newOrder->customerID;
    cout << "Enter Menu Item ID: ";
    cin >> newOrder->menuItemID;
    cout << "Enter Quantity: ";
    cin >> newOrder->quantity;

    
    if (orderHead == NULL) {
        orderHead = newOrder;
    } else {
        
        Order* temp = orderHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newOrder; 
    }

    orderQueue.enqueue(newOrder);  

    cout << "Order added successfully and queued for processing!\n";
}
void debugOrderList() {
    Order* temp = orderHead;
    while (temp) {
        cout << "Order ID: " << temp->orderID << "\n";
        temp = temp->next;
    }
}
void displayOrders() {
    Order* temp = orderHead;
    if (!temp) {
        cout << "No orders available.\n";
        return;
    }

    while (temp != NULL) {
        line();
        cout << "Order ID: " << temp->orderID << ", Customer ID: " << temp->customerID
             << ", Menu Item ID: " << temp->menuItemID << ", Quantity: " << temp->quantity
             << ", Status: " << temp->status << "\n";
        temp = temp->next;  
    }
}

    void processOrder() {
        if (orderQueue.isEmpty()) {
            cout << "No orders to process.\n";
            return;
        }

        Order* processedOrder = orderQueue.dequeue();
        Order* temp = orderHead;

        while (temp) {
            if (temp->orderID == processedOrder->orderID) {
                temp->status = "Completed";
                break;
            }
            temp = temp->next;
        }
        cout << "Order ID " << processedOrder->orderID << " has been processed.\n";
    }
    
    void displayMenuItems() {
        MenuItem* temp = menuHead;
        if (!temp) {
            cout << "No menu items available.\n";
            return;
        }
        while (temp) {
            line();
            cout << "ID: " << temp->menuItemID << ", Name: " << temp->name
                 << ", Price: $" << temp->price << ", Stock: " << temp->stock << "\n";
            temp = temp->next;
        }
    }

    void displayCustomers() {
        Customer* temp = customerHead;
        if (!temp) {
            cout << "No customers found.\n";
            return;
        }
        while (temp) {
            line();
            cout << "ID: " << temp->customerID << ", Name: " << temp->name
                 << ", Contact: " << temp->contactNumber << ", Address: " << temp->address << "\n";
            temp = temp->next;
        }
    }

    void searchCustomer(int id) {
        Customer* temp = customerHead;
        while (temp) {
            if (temp->customerID == id) {
                line();
                cout << "Customer found! Name: " << temp->name << ", Contact: "
                     << temp->contactNumber << ", Address: " << temp->address << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Customer not found.\n";
    }

    void searchMenuItem(int id) {
        MenuItem* temp = menuHead;
        while (temp) {
            if (temp->menuItemID == id) {
                line();
                cout << "Menu Item found! Name: " << temp->name << ", Price: $" << temp->price
                     << ", Stock: " << temp->stock << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Menu item not found.\n";
    }

    void searchEmployee(int id) {
        Employee* temp = employeeHead;
        while (temp) {
            if (temp->employeeID == id) {
                line();
                cout << "Employee found! Name: " << temp->name << ", Position: "
                     << temp->position << ", Contact: " << temp->contactNumber << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found.\n";
    }

    void searchOrder(int id) {
        Order* temp = orderHead;
        while (temp) {
            if (temp->orderID == id) {
                line();
                cout << "Order found! Customer ID: " << temp->customerID << ", Menu Item ID: "
                     << temp->menuItemID << ", Quantity: " << temp->quantity
                     << ", Status: " << temp->status << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Order not found.\n";
    }
};
void SetConsoleAttributes(int attributes) {   //back and foreground colour
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
}
int main() {
    CafeManagementSystem cms;
    int choice;
    SetConsoleAttributes(FOREGROUND_INTENSITY | FOREGROUND_GREEN|FOREGROUND_BLUE); 
    cout<<"\n        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    cout<<"\n        *     Welcome to Margalla Coffee House Management System      *";
    cout<<"\n        *               Bringing Joy One Cup At A Time                *";
    cout<<"\n        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
    SetConsoleAttributes(FOREGROUND_INTENSITY); 
    string username, password;
    string pass="1122";
    cout<<endl;
    cout << "  Please enter your username: ";
    cin >> username;
    cout << "  Please enter your password: ";
    cin >> password;
     if(password==pass){
	
		SetConsoleAttributes(FOREGROUND_INTENSITY | FOREGROUND_GREEN);  
			cout<<"  USER LOGIN SUCCESSFUL "<<endl;
                     SetConsoleAttributes(FOREGROUND_INTENSITY); 
	cout<<endl;
    do {
	    SetConsoleAttributes(FOREGROUND_INTENSITY | FOREGROUND_GREEN|FOREGROUND_BLUE); 
        cout << "\n----- Cafe Management System -----\n";
        cout << " 1. Add Menu Item\n";
        cout << " 2. Add Customer\n";
        cout << " 3. Add Order\n";
        cout << " 4. Add Employee\n";
        cout << " 5. Process Order\n";
        cout << " 6. Display Menu Items\n";
        cout << " 7. Display Customers\n";
        cout << " 8. Display Orders\n";
        cout << " 9. Search Customer\n";
        cout << "10. Search Menu Item\n";
        cout << "11. Search Employee\n";
        cout << "12. Search Order\n";
        cout << " 0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			    cms.addMenuItem(); 
			    break;
            case 2: 
			    cms.addCustomer(); 
				break;
            case 3: 
			    cms.addOrder(); 
			    cms.debugOrderList();
				break;
            case 4: 
			    cms.addEmployee(); 
				break;
            case 5: 
			    cms.processOrder(); 
				break;
            case 6: 
			    cms.displayMenuItems(); 
				break;
            case 7: 
			    cms.displayCustomers(); 
				break;
            case 8: 
			    cms.displayOrders(); 
				break;
            case 9: {
                int id;
                cout << "Enter Customer ID: ";
                cin >> id;
                cms.searchCustomer(id);
                break;
            }
            case 10: {
                int id;
                cout << "Enter Menu Item ID: ";
                cin >> id;
                cms.searchMenuItem(id);
                break;
            }
            case 11: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;
                cms.searchEmployee(id);
                break;
            }
            case 12: {
                int id;
                cout << "Enter Order ID: ";
                cin >> id;
                cms.searchOrder(id);
                break;
            }
            case 0: 
			    cout<<"  Thank You For Visiting Margalla Coffee House Management System"<<endl;
				cout << "Exiting system...Goodbye!\n";
			    break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}
else{
	 SetConsoleAttributes(FOREGROUND_INTENSITY | FOREGROUND_RED);  
        cout << "  Invalid Login Attempt";
        SetConsoleAttributes(FOREGROUND_INTENSITY); 
}
    return 0;
}

