#include<iostream>
using namespace std;

class Node
{
 public:
   int data;
   Node * next;
   Node * prev;
   };
class DoublyList
{
public:
	Node * start; 
	DoublyList(){start = 0;}
	void insert( int data);
	void add_end(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void delete_start();
    void delete_between(int pos);
    void delete_end();
	void reverse(); 
	
	void displayList();       
};
void DoublyList :: displayList(){
        Node* current = start;
        cout << "Displaying List : ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
}  
void  DoublyList::add_begin(int value){

	Node * node = new Node;
    	node->prev = NULL;
    	node->data = value;
	
	if (start == NULL)
    	{
        	start = node;
		node->next=NULL;
        	return;
    	}
    
    	node->next = start;
    	start->prev = node;
    	start = node;
 }
void  DoublyList::add_after(int value, int position){
    
	Node * node = new Node;
    Node *tmp = start;
    
	//Empty	
    if (start == NULL)
    {
        cout<<"First create the list."<<endl;
        return;
    }
    
    int i = 1;
    while (i < position && tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    
    if (tmp == NULL)
    {
        cout<<"There are less than "<< position <<" elements."<<endl;
        return;
    }
   
    node->data = value;
    if (tmp->next == NULL)
    {
        tmp->next = node;
        node->next = NULL;
        node->prev = tmp;      
    }
    else
    {
        node->next = tmp->next;
        node->prev = tmp;
        node->next->prev = node;
        tmp->next = node;
    }
    
}
void DoublyList::add_end(int value){
    Node * tmp = start;
    Node * node = new Node;
    node->data = value;
    node->next = NULL;
    
    if (start == NULL)
    {
        node->prev = NULL;
        start = node;
    }
    
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next =  node;
        node->prev = tmp;
    }
}
void  DoublyList::delete_start(){
	Node * ptr = start;
	start=ptr->next;
	start->prev = NULL;
	delete ptr;
}
void  DoublyList::delete_between(int pos){
    	Node*ptr=new Node;
    	Node*pre=new Node;
		while(ptr->data!=pos){
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=ptr->next;
		ptr->next->prev=pre;
		delete ptr;
}
void  DoublyList::delete_end(){
	    Node*ptr=new Node;
	    Node*pre=new Node;
	    while(ptr->next!=NULL){
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=NULL;
		delete ptr;
}

void DoublyList::reverse(){
    Node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List Reversed"<<endl; 
}

//void  DoublyList::delete_element(int value){
//	Node *p = start; 
//	Node *q = 0;
//	
//	while (p!=0 && p->data != value){
//		q = p;
//		p = p->next;
//	}
//	if (p == 0){
//		cout << "Value not found.";
//		cout<<endl;
//		return;
//	}
//	if (q == 0){ 
//
//		start = start->next;  
//	      start->prev = NULL;
//		delete p;
//		return;
//}
//    if(p->next==0){ 
//	q->next=0;
//	delete p;
//	return;
//	}
//	q->next = p->next;
//	p->next->prev = q;
//	delete p;      
//}

int main(){
	DoublyList list ;
    list.add_end(10);
	list.add_end(30);
    list.add_end(20);

    list.displayList();
    cout<<endl;
    
    list.add_begin(40);
    list.displayList();
    cout<<endl;
    
    list.add_after(50,2);
    list.displayList();
    cout<<endl;
    
    list.add_end(60);
    list.displayList();
    cout<<endl;
    
    list.delete_start();
    list.displayList();
    cout<<endl;
    
    list.delete_end();
    list.displayList();
    cout<<endl;
    
    list.delete_between(30);
    list.displayList();
    cout<<endl;
    
    list.reverse();
    list.displayList();
    cout<<endl;
    
    return 0;
}

