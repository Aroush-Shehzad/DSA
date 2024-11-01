#include<iostream>
using namespace std;
const int QUEUE_CAPACITY = 4;
class Queue
{
    private:
		int myArray[QUEUE_CAPACITY];
		int front, rear, count;
    public:
		Queue();
		bool isEmpty();
		bool isFull();
		void enqueue(int value);
		int getFront(); 
		int dequeue();
		void display();  
}; 
Queue::Queue()
{
	front = rear = count =0;
}
bool Queue::isEmpty()
{
	return (count==0);
}
bool Queue::isFull()
{
	return(count==QUEUE_CAPACITY);
}
void Queue::enqueue(int value)
{
	if (! isFull()){
		myArray[rear] = value;
		rear = (rear + 1) % QUEUE_CAPACITY;
		count++;
	}
}
int Queue::dequeue()
{
	if (! isEmpty())	{
	    int val= myArray[front] ;
	    front = (front + 1) % QUEUE_CAPACITY;
	    cout<<val<<" Dequeued"<<endl;
         count--;
         return val;}
	else
           return -1;
}
void Queue::display(){
    if (front == -1 ) {
        cout << "Queue is Empty" << endl;
        return;
    }
    int index=front;
    for (int i = 0; i < count; i++) {
        cout << myArray[i] << "  ";
        index=(index+1)%QUEUE_CAPACITY;
    }
    cout << endl;
}
int main() {
	Queue q;
    q.enqueue(10);
    q.display();
    
    q.enqueue(20);
    q.display();
    
    q.enqueue(30);
    q.display();
    
    q.dequeue();
    q.display();
    
    q.enqueue(40);
    q.display();
    
    q.dequeue();
    q.display();
    
    q.enqueue(50);
    q.display();
    
    q.isEmpty();
    
    return 0;
}

