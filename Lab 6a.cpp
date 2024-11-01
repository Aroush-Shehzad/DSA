#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * next;
};
class CircularList{
	public:
		Node * head;
		CircularList()
		{
		    head = 0;
		}
		void add_begin(int data)
		{
		    Node * node = new Node;
		    Node * temp = head;
		    node->data = data;
            node->next = head;
			if (head != NULL){
				while (temp->next != head)
                    temp = temp->next;
                    temp->next = node;
			}
		    else
                node->next = node; 
            head = node;
		}
		void add_end(int data){
			Node *temp=new Node;
			Node * ptr = new Node;
            temp->data=data;
            if(head==NULL){
                head=temp;
                temp->next=head;
            }
            else{
                ptr=head;
            while(ptr->next!=head)
                ptr=ptr->next;
            temp->next=head;
            ptr->next=temp;
            }
		}
		void add(int data,int pos){
			Node *temp = head;
            Node * t = new Node;
            for (int i = 1;i < pos;i++)
            {
                temp = temp->next; 
            }
            
            t->data=data;
            t->next=temp->next;
            temp->next=t; 
			
		}
		void del_beg(){
			Node *temp,*temp1;
            temp=head;
            temp1=head;
            while(temp1->next!=head)
                temp1=temp1->next;
            head=temp->next;
            temp1->next=head;
            delete temp; 
		}
		void del_end(){
			Node *temp,*t;
	        temp=head;
	        t=head->next;
            while(t->next!=head){
                t=t->next;
                temp=temp->next;
            }
	        temp->next=head;
            delete t;
		}
		void del(int pos){
			Node *temp = head;
            Node *prev =0;
            for (int i = 1;i < pos ;i++) {
 	            prev=temp;
                temp = temp->next;
            }
            prev->next=temp->next;            
            delete temp; 
        } 
		void displayList(){
			Node* current = head;
            cout << "Displaying List: ";
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
			
		}
};

int main(){
	CircularList list ;
	cout<<"Circular List"<<endl;
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
