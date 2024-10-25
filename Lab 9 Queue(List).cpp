#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    
    if (rear == NULL) {  
        front = rear = newNode;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
        return;
    }
    
    Node* temp = front;
    cout << "Dequeue: " << front->data << endl;
    front = front->next;

    if (front == NULL) {  
        rear = NULL;
    }

    delete temp;
}

void empty() {
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue is not Empty" << endl;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is Empty" << endl;
        return;
    }
    
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    display();
    
    enqueue(20);
    display();
    
    enqueue(30);
    display();
    
    dequeue();
    display();
    
    empty();
    
    return 0;
}

