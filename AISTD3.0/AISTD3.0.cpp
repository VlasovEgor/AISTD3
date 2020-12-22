#include <iostream>
#include"AISTD3.0.h"
using namespace std;
int tmp;
void Branch_tree::insert(int element)
{	
	if (root == NULL)
	{
		node* Insert_Node = new node; //creating a new node
		Insert_Node->data = element;
		Insert_Node->previous = NULL;
		Insert_Node->left_Branch = NULL;
		Insert_Node->Right_Branch = NULL;
	}
	else //finding a place for a node
	{
		node* current = root;
		if (element > current->data) 
		{
			if (current->Right_Branch != NULL)
				current = current->Right_Branch;
		}
		else
		{
			if (current->left_Branch != NULL)
				current = current->left_Branch;
		}
	}
}
void Branch_tree::remove(int element)
{
	if (root == NULL) return;
	node* current = root;
	//search for the item to delete
	if (current->data > element)
	{
		if (current->left_Branch != NULL)
			current = current->left_Branch;
		else return;
	}
	else
	{
		if (current->Right_Branch != NULL)
			current = current->Right_Branch;
		else return;
	}
	if (current->data == element) //if we found the item to delete
	{
		
		if (current->left_Branch == NULL && current->Right_Branch == NULL) //if the element has no children
		{
			if (current->previous->left_Branch == current)
				current->previous->left_Branch = NULL;
			else current->previous->Right_Branch = NULL;
			delete current;
			return;
		}
		// if the element has one child
		else if (current->left_Branch == NULL || current->Right_Branch == NULL)
		{
			if (current->left_Branch != NULL) //if there is a left child
			{
				tmp = current->data;
				current->data = current->left_Branch->data;
				current->left_Branch->data = tmp;
				delete current->left_Branch;
				current->left_Branch = NULL;
			}
			else //if there is a right child
			{
				tmp = current->data;
				current->data = current->Right_Branch->data;
				current->left_Branch->data = tmp;
				delete current->Right_Branch;
				current->Right_Branch = NULL;
			}
			return;
		}
	}
}
bool Branch_tree::contains(int element) // To find element in tree
{
	if (root == NULL) 
		return false;
	node* current = root;
	while (true)
	{

		// search for an item
		if (element > current->data)
		{
			if (current->Right_Branch != NULL)
				current = current->Right_Branch;
			else return false;
		}
		else
		{
			if (current->left_Branch != NULL)
				current = current->left_Branch;
			else return false;
		}
		// if item is found
		if (current->data == element) 
			return true;
	}
}

Iterator* Branch_tree::create_dft_iterator()
{
	if (root == NULL) return 0;
	return new dft_iterator(root);
}
Branch_tree::dft_iterator::dft_iterator(node* start)
{
	current = start;
	stack.add_in_stack(current);
}
Iterator* Branch_tree::create_bft_iterator()
{
	if (root == NULL) return 0;
	return new bft_iterator(root);
}
Branch_tree::bft_iterator::bft_iterator(node* start)
{
	current = start;
	queue.add_in_queue(current);
}
bool Branch_tree::dft_iterator::boolnext()
{
	return !stack.Empty();
}
int Branch_tree::dft_iterator::intnext()
{
	if (!boolnext()) return 0;
	current = stack.return_from_stack(); // to get from the stack
	if (current->Right_Branch != NULL)
		stack.add_in_stack(current->Right_Branch); //to insert in stack
	if (current->left_Branch != NULL)
		stack.add_in_stack(current->left_Branch); 
}
bool Branch_tree::bft_iterator::boolnext()
{
	return !queue.Empty();
}
int Branch_tree::bft_iterator::intnext()
{
	if (!boolnext()) return 0;
	current = queue.removing_from_the_queue(); // to get from the queue
	if (current->left_Branch != NULL)
		queue.add_in_queue(current->left_Branch); //to insert in queue
	if (current->Right_Branch != NULL)
		queue.add_in_queue(current->Right_Branch);
	return current->data;
}

void Branch_tree::deleter(node* current) // deleting a tree
{
	if (current == NULL) return;
	if (current->left_Branch != NULL) //remove the left side
	{
		node* Left_Node = current->left_Branch;
		deleter(Left_Node);
	}
	if (current->Right_Branch != NULL) //remove the right side
	{
		node* Right_Node = current->Right_Branch;
		deleter(Right_Node);
	}
	delete current;
}
Branch_tree::Branch_tree(int Data_Branch)
{
	root = new node;
	root->left_Branch = NULL;
	root->Right_Branch = NULL;
	root->previous = NULL;
	root->data = Data_Branch;

}
Branch_tree::~Branch_tree()
{
	deleter(root);
}