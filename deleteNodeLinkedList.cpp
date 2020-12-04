#include "pch.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};
enum addto {
	enum_left = 0,
	enum_right = 1,
	enum_after = 2

};

class LinkedList {

private:
	node *head, *tail;
	int length = 0;
public:
	/*~LinkedList(){
		while (head!=NULL)
			delete_node(true);
		}           */
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	virtual void add_node(int n, bool right) {
		node* tmp = new node;
		tmp->data = n;
		length++;
		if (head == NULL)
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
			tail = tmp;
		}
		else if (right == true) {
			tmp->prev = tail;
			tmp->next = NULL;
			tail->next = tmp;
			tail = tail->next;
		}
		else {
			tmp->next = head;
			tmp->prev = NULL;
			head->prev = tmp;
			head = head->prev;
		}

	}
	void add_node(int d, addto right) {
		node* tmp = new node;
		tmp->data = d;
		length++;
		if (head == NULL)
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
			tail = tmp;
		}
		else if (right == true) {
			tmp->prev = tail;
			tmp->next = NULL;
			tail->next = tmp;
			tail = tail->next;
		}
		else {
			tmp->next = head;
			tmp->prev = NULL;
			head->prev = tmp;
			head = head->prev;
		}

	}
	void add_node(int d, node *n)
	{
		node *tmp = new node;
		tmp->data = d;
		if (head == NULL)
		{
			cout << "error the list is empty node is not found" << endl;
			return;
		}
		else
		{
			tmp->prev = n;
			tmp->next = n->next;
			n->next = tmp;
		}
		length++;
	}

	void delete_node(bool right)
	{
		if (head == NULL)
		{
			cout << "List is empty nothing to delete" << endl;
			return;
		}
		else if (head == tail)
		{
			node *tmp = head;
			head = NULL;
			tail = NULL;
			delete tmp;
		}
		else if (right == true) //delete from the right
		{
			node *tmp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete tmp;

		}
		else //delete from the left
		{
			node *tmp = head;
			head = head->next;
			head->prev = NULL;
			delete tmp;
		}
		length--;

	}
	void swapData(node * prevn, node * nextn)
	{
		int tmp = nextn->data;
		nextn->data = prevn->data;
		prevn->data = tmp;
	}
	void deleteNodeNoHead(node *n)
	{
		node *nextn = n->next;
		node *currn = n;
		while (nextn->next != NULL)
		{
			swapData(currn, nextn);
			currn = currn->next;
			nextn = nextn->next;

		}
		swapData(currn, nextn);
		currn->next = NULL;
		length--;
		//free nextn;
	   // Your code here
	}
	/*    static void traverseList(bool right)
		{
			node *n = head;
			if (right == true)
			{
				while (n!=NULL)
				{
					cout<<n->data<<endl;
					n=n->next;

				}
			}
			else
			{
				n = tail;
				while(n!=NULL)
				{
					cout<<n->data<<endl;
					n=n->prev;

				}
			}

		} */
	node* getHead() {
		return head;
	}
	node* getTail() {
		return tail;
	}
	int getLength() {
		return length;
	}
	static void concatenate(node *a, node *b) {
		if (a != NULL && b != NULL)
		{
			//singly linked list
			/*if(a->next == NULL)
			{
				a->next = b;
				b->prev = a;
				cout<<"Concatenation complete"<<endl;
			}
			else{
				a = a->next;
				concatenate(a, b);
			} */
			//Concatenating doubly linked list is very simple
			a->next = b;
			b->prev = a;
			//length = (LinkedList*)a->getLength() + (LinkedList*)b->getLength();
		}
		else
		{
			cout << "Error: One of the list is empty" << endl;
		}
	}
	static bool compareLists(node *n1, node *n2) {
		while (n1!= NULL)
		{
			if (n1->data == n2->data)
			{
				n1 = n1->next;
				n2 = n2->next;
				continue;
			}
			else {
				return false;
			}

		}
		return true;
	}
	static void traverseList_recursive(node *n)
	{
		if (n == NULL)
		{
			cout << "end of list" << endl;
		}
		else
		{
			cout << n->data <<" ";
			n = n->next;
			traverseList_recursive(n);

		}
	}
	void swap(node *a, node *b)
	{
		int tmp = a->data;
		a->data = b->data;
		b->data = tmp;
		//delete tmp;
	}
	/*    void quick_sort(Linkedlist l)
		{
			int pivot = l.length/2;

		} */
	static LinkedList* Addition(LinkedList *l1, LinkedList *l2) {
		LinkedList * result = new LinkedList;
		node *node1 = l1->getHead();
		node *node2 = l2->getHead();
		int carry = 0;
		int data;
		while (node1 != NULL && node2 != NULL) {
			data = (node1->data + node2->data + carry) % 10;
			carry = (node1->data + node2->data + carry) / 10;
			result->add_node(data, true); // add from left
			node1 = node1->next; node2 = node2->next;
		}
		while (node1 != NULL)
		{
			result->add_node(node1->data + carry, true);
			carry = 0;
			node1 = node1->next;
		}
		while (node2 != NULL)
		{
			result->add_node(node2->data + carry, true);
			carry = 0;
			node2 = node2->next;
		}
		return result;
	}
};

class Stack : public LinkedList {
private:
	//int length = 0;
public:
	void push(int d)
	{
		LinkedList::add_node(d, false); //add node to the left
		//length++;
	}
	int pop()
	{
		int retVal = LinkedList::getHead()->data;
		LinkedList::delete_node(false); // pop will move head and delete from the left
		//length--;
		return retVal;
	}
	int peek()
	{
		return LinkedList::getHead()->data;
	}
	bool isEmpty()
	{
		return (LinkedList::getLength() == 0);
	}
	static bool compare(Stack s1, int * sequence, int numCards) 
	{
		if (s1.getLength() != numCards)
		{
			cout << "Unequal length " << endl;
			return false;
		}
		node * tmp = s1.getHead();
		int i = 0;
		while (tmp != NULL) 
		{
			if (tmp->data == sequence[i])
			{
				tmp = tmp->next;
				i++;
				continue;
			}
			else
			{
				return false;
			}

		}
		return true;
		
	}	

};

class Queue : public Stack {
public:
	int pop() {
		int retVal = LinkedList::getTail()->data;
		LinkedList::delete_node(true);
		return retVal;
	}
};

int DeckShuffle(Stack input, int numCards) {
	Queue q;
	Stack output, emptyStk;
	int *sequence = new int[numCards];
	node *tmp = input.getHead();
	//memcpy(&check, &input, sizeof(Stack));
	for (auto i = 0; i<numCards; i++ )
	{
		sequence[i] = tmp->data;
		tmp = tmp->next;
	}
	int rounds = 0;
	int inLength = input.getLength();
	int head = input.getHead()->data;
	int tail = input.getTail()->data;
	do
	{
		//char getch;
		//cin >> getch;
		output = emptyStk;
		for (auto i = 0; i <= inLength/2; i++)
		{
			
			if (!input.isEmpty())
				output.push(input.pop());
			if (!input.isEmpty())
				q.push(input.pop());
		}
		while (!q.isEmpty())
		{
			output.push(q.pop());
			if(!q.isEmpty())
				q.push(q.pop());
		}
		rounds++;
		input = output;
		//input.traverseList_recursive(input.getHead());
		if (Stack::compare(output, sequence, numCards))
			break;
	} while (1);//output.getLength() != inLength && (rounds > 0) );
	return rounds;
}
int main()
{
	//LinkedList ll, l2;
	//Stack s1;
	////int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	////int b[5] = { 11, 12, 13, 14, 15};
	//for (auto i = 0; i < 10; i++)
	//{
	//	ll.add_node(rand() % 20, 1);
	//}
	//for (auto i = 0; i < 5; i++)
	//{
	//	l2.add_node(rand() % 10, 1);
	//}
	//for (auto i = 0; i < 10; i++)
	//{
	//	s1.push(rand() % 20);
	//}
	//cout << "popData =" << s1.pop() << endl;
	//s1.traverseList_recursive(s1.getHead());
	////ll.traverseList(1);
	//l2.add_node(9999, l2.getHead()->next->next->next);
	//ll.traverseList_recursive(ll.getHead());
	//l2.traverseList_recursive(l2.getHead());
	////LinkedList::concatenate(ll.getTail(), l2.getHead());
	////LinkedList::traverseList_recursive(ll.getHead());
	//cout << "l1 list of length " << ll.getLength() << endl;
	//ll.traverseList_recursive(ll.getHead());
	//cout << "l2 list" << endl;
	//ll.traverseList_recursive(l2.getHead());
	//cout << "LinkedList list l1 length " << ll.getLength() << endl;
	//LinkedList::traverseList_recursive(ll.getHead());
	//cout << "LinkedList list l2 length " << l2.getLength() << endl;
	//LinkedList::traverseList_recursive(l2.getHead());

	//cout << "delete the 2nd in l2 node without head" << endl;
	//l2.deleteNodeNoHead(l2.getHead()->next);
	//cout << "LinkedList list l2 head " << l2.getLength() << endl;
	//LinkedList::traverseList_recursive(l2.getHead());

	//int numCards;
	//int numRounds[100];
	//int max = 0;
	//pair <int , int > ans;
	//for (numCards = 1; numCards<=100; numCards++ )
	//{
	//	Stack s1;
	//
	//	//cout << "Enter the number of cards in deck: \n";
	//	//cin >> numCards;
	//	for (int i = numCards; i >= 1; i--)
	//		s1.push(i);
	//	numRounds[numCards-1] = DeckShuffle(s1, numCards);
	//	if (max <= numRounds[numCards - 1])
	//	{
	//		max = numRounds[numCards - 1];
	//		ans.first = max;
	//		ans.second = numCards;
	//	}
	//		
	//	cout << "\nThe number of rounds for schuffling back to original position for "<<numCards <<" cards="<< numRounds[numCards-1];
	//}
	//	cout << "\nMax iterations is taken by numCards " << ans.second << " iterations: " << ans.first;


	//Linked list to add nodes 1 number each

	LinkedList l1, l2, *result;
	l1.add_node(3, 1);
	l1.add_node(0, 1);
	l1.add_node(5, 1);
	l1.traverseList_recursive(l1.getHead());
	l2.add_node(9, 1);
	l2.add_node(9, 1);
	l2.add_node(9, 1);
	l2.add_node(1, 1);
	l2.add_node(3, 1);
	l2.traverseList_recursive(l2.getHead());

	result = LinkedList::Addition(&l1, &l2);

	result->traverseList_recursive(result->getHead());


	return 0;
}






