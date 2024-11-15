#include<iostream>
using namespace std;
class tree
{
	public:
		int data;
		tree *left;
		tree *right;
	
	tree(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
		
	void inorder(tree *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	
	void postorder(tree *temp)
	{
		
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" ";
		}
	}
	
	void preorder(tree *temp)
	{
	
		if(temp!=NULL)
		{
			cout<<temp->data<<" ";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
};
int main()
{
	tree *temp= new tree(1);
	temp->left=new tree(2);
	temp->left->left=new tree(4);
	temp->left->right=new tree(5);
	temp->right=new tree(3);
	temp->right->left=new tree(6);
	temp->right->right=new tree(7);
	cout<<"Pre Order"<<endl;
	temp->preorder(temp);
	cout<<endl;
	cout<<"In Order"<<endl;
	temp->inorder(temp);
	cout<<endl;
	cout<<"Post Order"<<endl;
	temp->postorder(temp);
	cout<<endl;
	
}
