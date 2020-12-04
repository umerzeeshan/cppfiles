#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

struct Node {
	Node(int a): val(a), left(NULL), right(NULL) {}
	int val;
	Node *left;
	Node *right;
};
class Tree {
private: Node* root = NULL;
void deleteTree() {}
public:
Node* makeNode(int n) {
	Node *tmp = new Node(n);
	return tmp;
}
	Tree(){}
	Tree(int n) { root = makeNode(n); }
	~Tree() { deleteTree(); }
	void insert(int data) { insert(root, data); }
	//Inserting as a Binary search tree
	Node * getRoot() { return root; }
	void inOrder() { inOrder(root); }
	void getMin() { getMin(root); }
	void getMax() { getMax(root); }
	void swap(Node **a, Node** b)
	{
		Node* tmp = *a;
		*a = *b;
		*b = tmp;
	}
	bool find(int data) { Node *rVal = findNode(root, data); if (rVal) return true; else return false; }
	Node* findNode(Node * anode, int data) {
		if (anode == NULL)
			return 0;
		if (data > anode->val)
			findNode(anode->right, data);
		else if (data < anode->val)
			findNode(anode->left, data);
		else
			return anode;
		return NULL;
	}
	//Node*findNodeItr(Node *anode, int data) {
	//	if (anode->val < data)
	//	{
	//		while (anode!=NULL && anode->left->val != data)
	//		{
	//			anode = anode->left;
	//		}
	//	}
	//	while (anode->left);
	//}
	Node * getMin(Node *current) {
		while (current && current->left != NULL)
		{
			current = current->left;
		}
		cout << "Minumum of the BST is " << current->val<<endl;
		return current;
	}
	Node * getMax(Node *current) {
		while (current && current->right != NULL)
		{
			current = current->right;
		}
		cout << "Maximum of the BST is " << current->val<<endl;
		return current;
	}
	void deleteNode(int n) {
		if (root == NULL) {
			cout << "Empty tree \n";
			return;
		}
		Node* tbd = findNode(root, n);

	}
	void inOrder(Node* anode) {
		if (!anode)
		{
			return;
		}
		else
		{
			inOrder(anode->left);
			cout<< "In Order traversal ->" << anode->val<<endl;
			inOrder(anode->right);
		}
	}

	void postOrder() { postOrder(root); }
	void postOrder(Node* anode) {
		if (!anode)
		{
			return;
		}
		else
		{
			postOrder(anode->left);
			postOrder(anode->right);
			cout << "Post Order traversal ->" << anode->val << endl;
		}
	}

	int getHeight() { getHeight(root); }
	int getHeight(Node* anode) {
		if (!anode)
		{
			return 0;
		}
		else {
			// return 1 + getHeight(anode->left) + getHeight(anode->right);
            int lheight = getHeight(anode->left);
            int rheight = getHeight(anode->right);
            if(lheight>rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
		}
	}
	void insert(Node *anode, int data) {
		if (!root)
		{
			root = makeNode(data);
		}
		else if (data < anode->val)
		{
			if (!anode->left) {

				anode->left = makeNode(data);
			}
			else
			{
				insert(anode->left, data);
			}
		}
		else
		{
			if (!anode->right)
			{
				anode->right = makeNode(data);
			}
			else
			{
				insert(anode->right, data);

			}

		}
	}

	int maxLevelSum(Node * root)
	{
		//Your code here
		if (root == NULL)
			return 0;
		int result = root->val;
		int sumlevel = 0;
		int count;
		queue<Node*> q;
		q.push(root);
			while (!q.empty())
			{
				count = q.size();
				sumlevel = 0;
				while (count--) 
				{
					Node* tmp = q.front();
					sumlevel = sumlevel + tmp->val;
					q.pop();
					if (tmp->left != NULL) {
						q.push(tmp->left);
					}
					if (tmp->right != NULL) {
						q.push(tmp->right);
					}
				}
				result = max(result, sumlevel);
			}

		return result;
	}
	bool isValidBST(Node* root) {
		if (root == NULL)
			return true;
		int min = getMin(root)->val;
		int max = getMax(root)->val;
		if (root->left != NULL)
			if ((root->left->val >= root->val) || (min >= root->val))
				return false;
		if (root->right != NULL)
			if ((root->right->val <= root->val) || (max <= root->val))
				return false;
		return (isValidBST(root->right) && isValidBST(root->left));

	}
	void invertBST(Node* root) {
		if (!root)
			return;
		swap(&root->left, &root->right);
		invertBST(root->left);
		invertBST(root->right);
	}
};


int main()
{
	Tree t1;
    int height;
	t1.insert(80);
	t1.insert(40);
	t1.insert(100);
	t1.insert(30);
	t1.insert(50);

	t1.insert(90);

	t1.insert(110);
	cout << "\ninOrder traversal\n";
	// t1.inOrder();
	// t1.postOrder();

	// cout << "\nmax level " << t1.maxLevelSum(t1.getRoot()) << endl;
	t1.getMax();
	t1.getMin();

    height = t1.getHeight();
    cout<<"Height of tree is: "<<height<<endl;
	//int input;
	//cout << "check if data exist in the tree "; cin >> input;
	//if (t1.find(input))
	//	cout << endl << input << " is found \n";
	//else
	//	cout << endl << input << " is not found \n";
	
	cout<<"The BST is validity: "<<t1.isValidBST(t1.getRoot());
	cout << "\ninverted BST" << endl;
    Tree t2;
	t2.insert(4);
	t2.getRoot()->left = t2.makeNode(2);
	t2.getRoot()->right = t2.makeNode(7);
	t2.getRoot()->left->left = t2.makeNode(1);
	t2.getRoot()->left->right = t2.makeNode(3);
	t2.getRoot()->right->left = t2.makeNode(6);
	t2.getRoot()->right->right = t2.makeNode(9);
	
	t2.inOrder();
	t2.invertBST(t2.getRoot());
	t2.inOrder();


	return 0;
}