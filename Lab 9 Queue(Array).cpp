#include <iostream>
using namespace std;

int queue [10];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == 9) {
        cout << "Queue is Full" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void dequeue() {
    if (front == -1 ) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Dequeue: " << queue[front] << endl;
    front++;
}

void empty() {
    if (front == -1 ) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "Queue is not Empty" << endl;
    }
}

void display() {
    if (front == -1 ) {
        cout << "Queue is Empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
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

