#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};
Node * top=NULL;

void push(int data){
    Node* node=new Node;
	node->data=data;
	node->next=top;
	top=node;
	cout<<"Add "<<data<<endl;
}
void pop(){
    if(top==NULL){
    	cout<<" Stack empty"<<endl;
    	return;
	}
	Node *temp=top;
	cout<<"POP "<<top->data<<endl;
	top=top->next;
    delete temp;
}
void peek(){
	if(top==NULL){
        cout<<" Stack empty"<<endl;
    	return;	
	}
	cout<<"Top = "<<top->data<<endl;
}
void display(){
	if(top==NULL){
        cout<<" Stack empty"<<endl;
    	return;	
	}
	Node *temp =top;
    while(temp!=NULL){
    	
    	cout<<temp->data<<endl;
    	temp=temp->next;  	
	}
    
}
  

int main(){
	cout<<endl;
	push(10);
	push(20);
	push(30);
	display();
	cout<<endl;
	
	pop();
	display();
	cout<<endl;
	
	push(40);
	display();
	cout<<endl;
	
	pop();
	display();
	
    
	
	return 0;
}
