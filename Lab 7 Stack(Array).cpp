#include <iostream>
using namespace std;
int stack[10];
int top = 0;
void pop(){
    if(top==0){
        cout<<"Stack empty"<<endl;
        return;
    }
    top--;
    cout<<"Pop "<<stack[top]<<endl;
}
void push(int data){
    if(top==10){
        cout<<"Stack full"<<endl;
        return;
    } 
    stack[top]=data;
    top++;
    return;
}
void peek(){
	if(top==0){
        cout<<"Stack empty"<<endl;
        return;
    }
    cout<<"Top element "<<stack[top]<<endl;
}
void display(){
    if(top==0){
        cout<<"Stack empty"<<endl;
        return;
    }    
    for(int i=0;i<top;i++){
    	cout<<stack[i]<<endl;
	}
	cout<<endl;
    
}
  

int main(){
	push(10);
	push(20);
	push(30);
	display();
	pop();
	display();
	push(40);
	display();
	pop();
	display();
	
    
    
    return 0;
}
