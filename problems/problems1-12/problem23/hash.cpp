#include <vector>
#include <string>
#include "hash.h"
#include <stdexcept>
#include <iostream>
using namespace std;

int Hash_Table::hash(string key)
{
	long hash = 0;

	for(int i = 0; i < key.length(); i++)
    {
    	hash = (hash + key[i] + 4);
    }

   return hash%med;

};

void Hash_Table::left_rotate(Node* node)
{

	Node* elem = node->right;
	node->right = elem->left;


	if(elem->left != nullptr)
	{
		elem->left->parent = node;
	}

	elem->parent = node->parent;

	if(node->parent == nullptr)
	{
		arr[hash(node->key)] = elem;
		elem->left = node;
		node->parent = elem;
		return;
	}

	if(node == node->parent->left)
	{
		node->parent->left = elem;
		elem->left = node;
		node->parent = elem;
		return;
	}

	node->parent->right = elem;
	elem->left = node;
	node->parent = elem;
}

void Hash_Table::right_rotate(Node* node)
{

	Node* elem = node->left;
	node->left = elem->right;

	if(elem->right != nullptr)
	{
		elem->right->parent = node;
	}

	elem->parent = node->parent;

	if(node->parent == nullptr)
	{
		arr[hash(node->key)] = elem;
		elem->right = node;
		node->parent = elem;
		return;
	}

	if(node == node->parent->right)
	{
		node->parent->right = elem;
		elem->right = node;
		node->parent = elem;
		return;
	}



	node->parent->left = elem;
	elem->right = node;
	node->parent = elem;
}

void Hash_Table::insertion_fix(Node* node)
{
	while(node != arr[hash(node->key)] && node->parent->color == false) // false stands for red
	{

		Node* uncle;

		if(node->parent == node->parent->parent->left)
		{
			uncle = node->parent->parent->right;

			if(uncle && uncle->color == false ) // first case 
			{
				node->parent->color = true;
				uncle->color = true;
				uncle->parent->color = false;
				node = node->parent->parent;
			}

			else if(node == node->parent->right)
			{
				node = node->parent;
				left_rotate(node);
			}
			else
			{
				node->parent->color = true;
				node->parent->parent->color = false;
				right_rotate(node->parent->parent);
			}
		}
		
		else // node's parent is the right son
		{
			 uncle = node->parent->parent->left;
			
			 if(uncle && uncle->color == false) // first case 
			 {
				node->parent->color = true;
				uncle->color = true;
				uncle->parent->color = false;
				node = node->parent->parent;
			}

			else if(node == node->parent->left) // second case
			{
				node = node->parent;
			 	right_rotate(node);
			}
			else
			{
				node->parent->color = true; 
				node->parent->parent->color = false;
				left_rotate(node->parent->parent);
			}

		} 
		arr[hash(node->key)]->color = true;

	}

}


void Hash_Table::push(string key, int data)
{
	Node* current = arr[hash(key)];
    Node* parent = nullptr;

	while(current != nullptr)
    {
        parent = current;

        if(current->key == key)
        {
            current->data = data;
            return;
        }

        current = (key < current->key) ? current->left : current->right;
    }

    current = new Node(data, key, parent);
 	
 	if(parent == nullptr)
    {
    	current->color = true;
        arr[hash(key)] = current;
        return;
 	}

    if(parent->key > key)
    {
      	parent->left = current;
      	insertion_fix(current);
    }
    
    else{
    parent->right = current;

    insertion_fix(current);
}
}


int Hash_Table::get_data(string key)
{
  	Node* current = arr[hash(key)];

    while(current != nullptr && current->key != key)
    {
        current = (key< current->key) ? current->left : current->right;
    }

    if(current == nullptr)
    {
    	throw invalid_argument("There is no such key.");
	}

	return current->data;
   
}


bool Hash_Table::get_color(string key)
{

  	Node* current = arr[hash(key)];

    while(current != nullptr && current->key!= key)
    {
        current = (key< current->key) ? current->left : current->right;
    }

    if(current == nullptr)
    {
    	throw invalid_argument("There is no such key.");
	}

	return current->color;
   
}

void Hash_Table::deletion_fix(Node* node)
{
    while (node != arr[hash(node->key)] && node->color == true)
    {
        if (node == node->parent->left)
        {
            Node *node2 = node->parent->right;

            if (node2->color == false)
            {
                node2->color = true;
                node->parent->color = false;

                left_rotate (node->parent);
                node2 = node->parent->right;
            }
            if (node2->left->color == true && node2->right->color == true)
            {
                node2->color = false;
                node = node->parent;
            }
            else
            {
                if (node2->right->color == true)
                {
                    node2->left->color = true;
                    node2->color = false;

                    right_rotate (node2);
                    node2 = node->parent->right;
                }

                node2->color = node->parent->color;
                node->parent->color = true;
                node2->right->color = true;

                left_rotate (node->parent);
                node = arr[hash(node->key)];
            }
        } 

        else
        {
            Node *node2 = node->parent->left;

            if (node2->color == false)
            {
                node2->color = true;
                node->parent->color = false;

                right_rotate (node->parent);
                node2 = node->parent->left;
            }

            if (node2->right->color == true && node2->left->color == true)
            {
                node2->color = false;
                node = node->parent;
            }

            else
            {
                if (node2->left->color == true)
                {
                    node2->right->color = true;
                    node2->color = false;

                    left_rotate (node2);
                    node2 = node->parent->left;
                }

                node2->color = node->parent->color;
                node->parent->color = true;
                node2->left->color = true;

                right_rotate (node->parent);
                node = arr[hash(node->key)];
            }
        }
    }
    
    node->color = true;
}


int Hash_Table::rb_delete(string key)
{
	Node* node = arr[hash(key)];

    while(node != nullptr && node->key != key)
    {
        node = (key > node->key) ?  node->right : node->left;
    }	

    if(node == nullptr)
    {
    	throw invalid_argument("There is no such key.");
	}

	if (node == arr[hash(key)] && node->left == nullptr && node->right == nullptr)
	{
		arr[hash(key)] = nullptr;

		return node->data;
	}

	Node* another_node;
	Node* node2 ;

    if (node->left == nullptr || node->right == nullptr)
    {
        another_node = node;
    } 

    else
    {
        another_node = node->right;

        while (another_node->left != nullptr) 
        {
        	another_node = another_node->left;
    	}
    }

  node2 = (another_node->left) ? another_node->left : another_node->right;

  if(node2) node2->parent = another_node->parent;

    if (another_node == another_node->parent->left)
    {
        another_node->parent->left = node2;
    }

    else
    {
        another_node->parent->right = node2;
    }
    

    if (another_node != node)
    {
    	node->data = another_node->data;
    	node->key = another_node->key;
    }

    if (another_node->color == true)
    {
       deletion_fix(node2);
    }

    return  another_node->data;
}
