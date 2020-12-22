#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue
{
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		counter = 0;
	}
	~Queue()
	{
		if (counter > 0)
		{
			while (head->next != NULL)
			{
				queue* current = head;
				head = head->next;
				delete current;
			}
			delete head;
		}
	}
	void add_in_queue(T element) // adding a new item to the queue
	{
		queue* current = new queue; 
		current->data = element;
		current->next = NULL;
		if (counter == 0) //if the queue is empty
		{
			head = current;
			tail = current;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
		counter++;
	}
	// returning an item from the queue
	T removing_from_the_queue()
	{
		if (counter == 0)//if the queue is empty
			return 0; 
		queue* current = head;
		head = head->next;
		T element = cur->data; 
		delete current; //deleting an item in the queue
		counter--;
		return element;//output of the element
	}
	// checking for emptiness of the queue
	bool Empty()
	{
		if (counter == 0) 
			return 0;
	}
private:
	struct queue // node of queue
	{
		T data;
		queue* next;
	};
	int counter;
	queue* head;
	queue* tail;
};
template <class type>
class Stack
{
public:
	Stack()
	{
		node_top = NULL;
		counter = 0;
	}
	~Stack()
	{
		if (counter > 0)
		{
			while (node_top->prev != NULL)
			{
				stack* current = node_top;
				node_top = node_top->prev;
				delete current;
			}
			delete node_top;
		}
	}
	void add_in_stack(type element) //adding to the stack
	{
		stack* current = new stack; // creating a new node
		current->data = element;
		current->prev = NULL;
		if (counter == 0)
		{
			node_top = current; //inserting a new element
			counter++;
		}
		else
		{
			current->prev = node_top; //inserting a new element
			node_top = current;
			counter++;
		}
	}
	// // returning an item from the stack
	type return_from_stack()
	{ 
		if (counter == 0) return 0; // if the stack is empty
		stack* current = node_top;
		node_top = node_top->prev;
		type element = current->data;
		delete current; //deleting an item in the stack 
		counter--;
		return element; ////output of the element
	}
	// check for the emptiness of the stack
	bool Empty()
	{
		if (counter == 0) return 1;
		else return 0;
	}
private:
	struct stack // node of stack
	{
		type data;
		stack* prev;
	};
	stack* node_top;
	int counter;
};

class Branch_tree
{
private:
	struct node // the branch node
	{
		int data;
		node* previous;
		node* Right_Branch;
		node* left_Branch;
	};
	node* root;
	void deleter(node* point); 
public:
	Branch_tree(int);
	~Branch_tree(); 
	void insert(int); // adding an element to the tree by key
	void remove(int); // deleting a tree element by key
	bool contains(int);// search for an element in the tree by key
	Iterator* create_dft_iterator(); // creating an iterator that implements one of the depth-first traversal methods
	class dft_iterator :
		public Iterator
	{
	public:
		dft_iterator(node* start);
		int intnext() override;
		bool boolnext() override;
	private:
		node* current;
		Stack <node*> stack;
	};
	Iterator* create_bft_iterator(); // creating an iterator that implements breadth-first traversal methods
	class bft_iterator :
		public Iterator
	{
	public:
		bft_iterator(node* start);
		int intnext() override;
		bool boolnext() override;
	private:
		node* current;
		Queue <node*> queue;
	};

};

class Iterator
{
public:
	virtual int intnext() = 0;
	virtual bool boolnext() = 0;
};