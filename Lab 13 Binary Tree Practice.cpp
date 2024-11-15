#include<iostream>
using namespace std;
struct tree {
	int data;
	tree *left;
	tree *right;
	tree(int val) : data(val), left(NULL), right(NULL) {}
};

void insert(tree*& temp, int data) {
    if (temp == NULL) {
        temp = new tree(data);
        return;
    }
    if (data < temp->data) {
        insert(temp->left, data);
    } else if (data > temp->data) {
        insert(temp->right, data);
    }
}

void display(tree* temp) {
	if (temp != NULL) {
		display(temp->left);
		cout << temp->data << " ";
		display(temp->right);
	}
}

int main() {
	tree* root = new tree(10);
	insert(root, 5);
	insert(root, 15);
	display(root);
	cout << endl;
	insert(root, 2);
	insert(root, 7);
	insert(root, 12);
	insert(root, 18);
	display(root);
	cout << endl;
	return 0;
}
