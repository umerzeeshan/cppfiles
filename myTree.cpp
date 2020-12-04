// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#if 1
/******************************************************************************************
*******************************************************************************************
Chapter 4 Trees and Graphs

This is a class implementation of Binary Search Tree (BST), containing:

   inser(): insert a value in a BST
   isBalanced(): check if a BST is balanced, a BST is balanced if the difference of left and right subtrees height is atmost one!
   getHeight(): returns the height of a BST
   deleteBST(): deletes a BST
   inOrder():      prints a BST i in-order fashion
   preOrder(): prints a BST i pre-order fashion
   postOrder(): prints a BST i post-order fashion

By: Hamed Kiani (Sep. 18, 2015)
******************************************************************************************
******************************************************************************************/

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

// tree node, including left and right pointers, data 
struct Node {
	Node(int value) : data(value), left(NULL), right(NULL) {}
	int data;
	Node *left;
	Node *right;
};

/////////////////////////////////////////////////////////////////////////////////////////
// BST class
class BST {
private:
	Node *_root;
	void insert(Node *treeNode, int data);
	bool isBalanced(Node *treeNode);
	int  getHeight(Node *treeNode);
	void deleteBST(Node *treeNode);
	void inOrder(Node * treeNode);
	void preOrder(Node * treeNode);
	void postOrder(Node * treeNode);
	void levelOrderL(Node *treeNode, int level);

public:

	BST();  // constructor     
	~BST();     // destractor

	void insert(int data) { insert(_root, data); }

	int getHeight() { return getHeight(_root); }
	Node * getMaxNode();
	Node * getMinNode();

	void deleteBST() { deleteBST(_root); }

	bool isBalanced() { return isBalanced(_root); }

	void inOrder() { inOrder(_root); }
	void preOrder() { preOrder(_root); }
	void postOrder() { postOrder(_root); }
	void levelOrderTraversal();
	void levelOrderTraversalQ();
};

/////////////////////////////////////////////////////////////////////////////////////////
BST::BST()
{
	_root = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::insert(Node *treeNode, int data)
{
	if (!treeNode)
	{
		treeNode = new Node(data);
		_root = treeNode;
	}
	else
	{
		if (data < treeNode->data)
		{
			if (!treeNode->left)
			{
				Node *treeTemp = new Node(data);
				treeNode->left = treeTemp;
			}
			else
				insert(treeNode->left, data);
		}
		else
		{
			if (!treeNode->right)
			{
				Node *treeTemp = new Node(data);
				treeNode->right = treeTemp;
			}
			else
				insert(treeNode->right, data);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
int BST::getHeight(Node *treeNode)
{
	if (!treeNode)
		return 0;
	return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));
}

/////////////////////////////////////////////////////////////////////////////////////////
bool BST::isBalanced(Node *treeNode)
{
	if (!treeNode)
		return false;
	int leftHeight = getHeight(treeNode->left);
	int rightHeight = getHeight(treeNode->right);

	if (abs(leftHeight - rightHeight) > 1)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMaxNode()
{
	if (!_root)
	{
		cout << " the BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->right)
		treeNode = treeNode->right;
	return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMinNode()
{
	if (!_root)
	{
		cout << " the BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->left)
		treeNode = treeNode->left;
	return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::deleteBST(Node *treeNode)
{
	if (!treeNode)
		return;

	Node * curTreeNode = treeNode;
	Node * leftTreeNode = treeNode->left;
	Node * rightTreeNode = treeNode->right;
	delete(curTreeNode);
	deleteBST(leftTreeNode);
	deleteBST(rightTreeNode);
}

/////////////////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
	deleteBST();
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::inOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	inOrder(treeNode->left);
	cout << treeNode->data << " ";
	inOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::preOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	cout << treeNode->data << " ";
	preOrder(treeNode->left);
	preOrder(treeNode->right);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::postOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	postOrder(treeNode->left);
	postOrder(treeNode->right);
	cout << treeNode->data << " ";
}

void BST::levelOrderTraversal() {
	if (_root == NULL) {
		cout << "Empty Tree \n";
		return;
	}
	int h = getHeight(_root);
	for (int l = 1; l <= h; l++)
		levelOrderL(_root, l);
}
void BST::levelOrderL(Node * n, int level) {

	if (n == NULL)
		return;
	if (level == 1) {
		cout << n->data << " ";
	}
	else {
		levelOrderL(n->left, level - 1);
		levelOrderL(n->right, level - 1);
	}

}

void BST::levelOrderTraversalQ() {
	queue<Node *> q;
	if (_root == NULL) {
		return;
	}
	q.push(_root);
	cout << "\n level Order Traversal using queue" << endl;
	while (!q.empty())
	{
		Node *n = q.front();
		cout <<n->data<<" ";
		q.pop();
		
		if (n->left != NULL) {
			q.push(n->left);
		}
		if (n->right != NULL) {
			q.push(n->right);
		}
	}


}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	BST myBST;
	myBST.insert(10);
	myBST.insert(5);
	myBST.insert(12);

	myBST.insert(2);
	myBST.insert(7);
	myBST.insert(8);
	myBST.insert(20);
	myBST.insert(1);
	myBST.insert(3);
	myBST.insert(4);
	myBST.insert(9);
	myBST.insert(6);
	myBST.insert(9);
	myBST.insert(14);
	myBST.insert(30);

	int h = myBST.getHeight();
	cout << "the height of this BSt is : " << h << endl;

	Node * mx = myBST.getMaxNode();
	cout << "max value: " << mx->data << endl;

	Node * mi = myBST.getMinNode();
	cout << "min value: " << mi->data << endl;

	bool isbal = myBST.isBalanced();
	if (isbal)
		cout << "BST is balanced! " << endl;
	else
		cout << "BST is not balanced! " << endl;

	cout << " in-order traverse is : " << endl;
	myBST.inOrder(); cout << endl;
	cout << " pre-order traverse is : " << endl;
	myBST.preOrder(); cout << endl;
	cout << " post-order traverse is : " << endl;
	myBST.postOrder(); cout << endl;

	myBST.levelOrderTraversal();
	myBST.levelOrderTraversalQ();

	return 0;
}

#endif

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
