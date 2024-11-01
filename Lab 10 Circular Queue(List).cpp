#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedQueue
{
private:	
	Node * front;
	Node * rear;
public:
	LinkedQueue();
	void Enqueue(int);
	void Dequeue();
	int Front();
	void Display();
};
LinkedQueue::LinkedQueue(){
	front = NULL;
	rear = NULL;
}
void LinkedQueue::Display() { 
	Node* temp = front; 
	while(temp != NULL) 
	{ 
		cout<<temp->data<<"  "; 
		temp = temp->next; 
	} 
	cout<<endl;
}
void LinkedQueue:: Enqueue(int x) {
	Node* temp = new Node; 
	temp->data =x; 
	temp->next = NULL; 
	if(front == NULL && rear == NULL){ 
		front = rear = temp; 
		return; 
	}
	rear->next = temp; 
	rear = temp;
}
void LinkedQueue:: Dequeue() {
	Node* temp = front; 
	if(front == NULL) { 
		cout<<"Queue is Empty\n"; return; 
	} 
	if(front == rear) { 
		front = rear = NULL; 
	} 
	else 
		front = front->next; 
	delete temp;
}
int LinkedQueue::Front() { 
	if(front == NULL) { 
		cout<<"Queue is empty\n"; 
		return -1; 
	} 

	return front->data;
}
int main() {
    LinkedQueue q;
	q.Enqueue(10);
    q.Display();
    
    q.Enqueue(20);
    q.Display();
    
    q.Enqueue(30);
    q.Display();
    
    q.Dequeue();
    q.Display();
    
    
    
    return 0;
}

