#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
class CircularDoublyList {
public:
    Node* head;
    CircularDoublyList() {
        head = NULL;
    }

    void add_begin(int data) {
        Node* node = new Node;
        node->data = data;

        if (head == NULL) {
            node->next = node;
            node->prev = node;
            head = node;
        } else {
            Node* tail = head->prev;

            node->next = head;
            node->prev = tail;
            tail->next = node;
            head->prev = node;

            head = node;
        }
    }
    void add_end(int data) {
        Node* node = new Node;
        node->data = data;

        if (head == NULL) {
            node->next = node;
            node->prev = node;
            head = node;
        } else {
            Node* tail = head->prev;

            node->next = head;
            node->prev = tail;
            tail->next = node;
            head->prev = node;
        }
    }
    void add(int data, int pos) {
        if (pos == 1) {
            add_begin(data);
            return;
        }
        Node* temp = head;
        Node* node = new Node;
        node->data = data;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        node->prev = temp;

        temp->next->prev = node;
        temp->next = node;
    }

    void del_beg() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* tail = head->prev;

        if (head == head->next) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            head = head->next;

            tail->next = head;
            head->prev = tail;

            delete temp;
        }
    }

    void del_end() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* tail = head->prev;

        if (head == head->next) {
            delete head;
            head = NULL;
        } else {
            Node* temp = tail;

            tail = tail->prev;
            tail->next = head;
            head->prev = tail;

            delete temp;
        }
    }

    void del(int pos) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 1) {
            del_beg();
            return;
        }
        Node* temp = head;

        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    
    void displayList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Displaying List: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularDoublyList list;

    cout << "Circular Doubly Linked List" << endl;
    list.add_end(10);
    list.add_end(30);
    list.add_end(20);

    list.displayList();
    cout<<endl;
    
    list.add_begin(40);
    list.displayList();
    cout<<endl;
    
    list.add(50,2);
    list.displayList();
    cout<<endl;
    
    list.add_end(60);
    list.displayList();
    cout<<endl;
    
    list.del_beg();
    list.displayList();
    cout<<endl;
    
    list.del(3);
    list.displayList();
    cout<<endl;
    
    list.del_end();
    list.displayList();
    cout<<endl;
    
}
