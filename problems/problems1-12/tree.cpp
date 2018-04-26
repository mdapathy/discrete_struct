#include <vector>
#include <stdexcept>
#include <iostream>
#include "tree.h"
using namespace std;

Tree::Tree():
size(0), root(nullptr)
{}


void Tree::push_helper(Node* element, int data)
{
	if(element->value == data)
	{
		throw invalid_argument("Pushing existing element");
	}

	if(element->value > data)
	{
		if(element->left == nullptr)
		{
			element->left = new Node(data);
			return;

		}

		push_helper(element->left, data);
		return;
	}

	if(element->right == nullptr)
	{
		element->right = new Node(data);
		return;
	}

	push_helper(element->right, data);


}

void Tree::push(int data)
{
	size++;
	
	if(!root)
	{
		root = new Node(data);
      		return;
	}


	push_helper(root, data);

}

void Tree::clear_helper(Node *elem)
{
	if(elem->left)
	{
		clear_helper(elem->left);
	}

	if(elem->right)
	{
		clear_helper(elem->right);
	}

	delete elem;

}

void Tree::clear()
{
	if (root == nullptr)
	{
		throw invalid_argument("Clearing an empty tree.");
	}

	clear_helper(root);

	root = nullptr;
	size = 0;
}

void Tree::to_array_helper(Node* element, int current, Node* tree[])
{
   int temp = current;

  
	if (element->value)
	{
		tree[temp] = element;
		
		if (element->left)
		{
			to_array_helper(element->left, current*2+1, tree);
		}
		
		if (element->right)
		{
			to_array_helper(element->right,current*2+2, tree);
		}
	}
}


void Tree::to_array(Node* tr[])
{
	to_array_helper(root, 0, tr);
}



bool Tree::find(Node* elem, int key)
{
    if (key < elem->value && elem->left)
    {
    	return find(elem->left, key);
    }

    if (key > elem->value && elem->right) 
    {	
    	return find(elem->right, key);
    }

    if (key == elem->value)
    {
    	return true;
    }

    return false;

}


int Tree::delete_element(int key)
{
	if(get_size() == 0)
	{
		throw out_of_range("Deleting an element from an empty tree");
	}

	if(find(root, key) == false)
	{
		throw out_of_range("Deleting non-existing element");
	}
	
	size--;
	Node* prev = nullptr;
	Node* current = root;

	while(true)
	{
		if(current->value == key)
		{
			break;
		}

		prev = current;
		current = (key > (current->value)) ? current->right : current->left;
	}

	// removing node with 2 children

	if(current->left && current->right)
	{
		Node* tmp = current->right;
		prev = current;
		
		while (tmp->left != nullptr) 
		{
		      prev = tmp;
		      tmp = tmp->left;
		}
		
		current->value = tmp->value;
	    

	    if(!tmp->right) // replaced with a leaf node
	    {
	    	delete tmp;
	    	tmp = nullptr;
	    	return key;
	    }

	    if (prev->left == current)
	    {
	      	prev->left = tmp->right;
	    }

	    else 
	    {
		prev->right = tmp->right;
		
	    }
		delete tmp;

		return key;
	}


	// node has 1 child or less

	Node* child = (current->right) ? current-> right : current->left;

	if(prev != nullptr)
	{
		if(prev->right == current)
		{
			prev->right = child;
			delete current;
			return key;
		}

	prev->left = child;
	
	}
	else 
	{
		root = child;
	}
	
	delete current;

	return key;

}
void Tree::get_values(vector <int>& storage, Node* root)
{
	if(!root) return;
	get_values(storage, root->left);
	storage.push_back(root->value);
	get_values(storage, root->right);
}


Tree::~Tree()
{
	if(root)
	{
		clear_helper(root);
	}

	root = nullptr;
	size = 0;
}
