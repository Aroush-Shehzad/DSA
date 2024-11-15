#include<iostream>
using namespace std;
class tree
{
	public:
		string data;
		tree *left;
		tree *right;
	
	tree(string data)
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
			cout<<temp->data<<"  ";
			inorder(temp->right);
		}
	}
	
	void postorder(tree *temp)
	{
		
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<"  ";
		}
	}
	
	void preorder(tree *temp)
	{
	
		if(temp!=NULL)
		{
			cout<<temp->data<<"  ";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
};
int main()
{
	tree *temp= new tree("aaa");
	temp->left=new tree("bbb");
	temp->left->left=new tree("ccc");
	temp->left->right=new tree("ddd");
	temp->right=new tree("eee");
	temp->right->left=new tree("fff");
	temp->right->right=new tree("ggg");
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
