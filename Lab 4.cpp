#include<iostream>
using namespace std;
////Singly
struct nodeType{
	int data;	
	nodeType * next;
	
};
class List{
	private:
		nodeType * head;
	public:
		List(){
			head=NULL;
		}
		void insertStart(int data){
			nodeType * node=new nodeType;
			node->data=data;
			node->next=head;
			head=node;
		}
		void insertBetween(int data,int next){
			nodeType* node= new nodeType;
			nodeType * ptr = head;
			nodeType * pre = NULL;
		while(ptr!=NULL&& ptr->data!=next){
				pre=ptr;
				ptr=ptr->next;
		}
			node->data=data;
			node->next=ptr->next;
			ptr->next=node;
			
		}
		void insertEnd(int data) {
        nodeType *node = new nodeType;
        nodeType *ptr = head;
        node->data = data;
        node->next = NULL;
        
        if (head == NULL) {
            head = node;
        } else {
            
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = node;
        }
    }
		void deleteStart(){
			nodeType* ptr = head;
			head=head->next;
			
			delete ptr;
		}
		void deleteBetween(int next){
			nodeType* ptr = head;
			nodeType* pre =NULL;
			while(ptr!=NULL && ptr->data!=next){
				pre=ptr;
				ptr=ptr->next;
			}
			if (pre==NULL){
				head = ptr->next;
			}
			else{
				pre->next=ptr->next;
			}
			delete ptr;
		}
		void deleteEnd(){
			nodeType* ptr = head;
			nodeType* pre = NULL;
			if(ptr->next==NULL)
			{
				delete head;
				head= NULL;
				return;
			}
			
			while (ptr->next != NULL){
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=NULL;
			delete ptr;
        }
		void displayList(){
			nodeType * p = head;
			
			while(p!=NULL){
				cout<<p->data<<endl;
				
				p=p->next;
			}
		}			
};

int main(){
    List list ;
    list.insertStart(10);
	list.insertStart(30);
    list.insertStart(20);

    list.displayList();
    cout<<endl;
    
    list.insertStart(40);
    list.displayList();
    cout<<endl;
    
    list.insertBetween(50,30);
    list.displayList();
    cout<<endl;
    
    list.insertEnd(60);
    list.displayList();
    cout<<endl;
    
    list.deleteStart();
    list.displayList();
    cout<<endl;
    
    list.deleteBetween(30);
    list.displayList();
    cout<<endl;
    
    list.deleteEnd();
    list.displayList();
    cout<<endl;
    
    return 0;
}





