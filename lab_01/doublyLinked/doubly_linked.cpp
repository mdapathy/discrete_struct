#include <stdexcept>
#include <string>
#include"doubly_linked.h"
using namespace std;

Doubly_linked::Doubly_linked():
  head(nullptr),
  tail(nullptr),
  size(0)
  {}

Doubly_linked::~Doubly_linked()
{
  clear();
}

string Doubly_linked::to_string()
{
  if(size == 0)
  {
    throw length_error("Turning an empty list into string "); 
  }

  Node* temp = head;
  string list = "";

  for(int i = 0; i < size; i++)
  { 
    list += std::to_string(temp->data) + " ";
    temp = temp->next;
  }

  list.pop_back(); 

  return list;

}

void Doubly_linked::push(int data)
{
  Node *obj = new Node;
  obj->data = data;
  obj->prev = nullptr;
  obj->next = nullptr;
  size++;

  if(head == nullptr)
  {
    head = obj;
    tail = obj;
    return;
 }
    Node *tmp = tail;
    tail->next = obj;
    tail = tail->next;
    tail->prev = tmp;

}

void Doubly_linked::delete_every_third()
{
  Node *inuse = head;

  if(inuse == nullptr)
  {
    throw length_error("Deleting every third element from an empty list"); 
  }

  for(int counter = 1; inuse->next != nullptr; counter++)
  {
    if( ((counter+1)%3) == 0) // find the element before the one to be deleted
    { 
      Node *tmp = inuse->next;
      inuse->next = inuse->next->next;
      size--;

      if(tmp == tail)
      {
        tail = inuse;
        delete tmp;
        break;
      }

      inuse->next->prev = inuse ; 
      counter++;
      delete tmp;
    }

    inuse = inuse->next;
  
  }
}


void Doubly_linked::remove(int position)
{ 

  if(size == 0 || position >= size || position < 0)
  {
    throw length_error("Removing elements with non-existing positions from a list");
  }

  Node *tmp = head;
  size--;

  if(size == 0) // the list consists of 1 elem.
  {
    head = nullptr;
    tail = nullptr;
    delete tmp;
    return;
  }

  for (int i = 0; i < position ; i++)
  {
    tmp = tmp->next;
  }

  if (position == size)
  {
    tail = tmp->prev;
    tail->next = nullptr;
    delete tmp;
    return;
  }

  if (position == 0)
  { 
    head = tmp->next;
    head->prev = nullptr;
    delete tmp;
    return;
  }

  tmp->next->prev = tmp->prev; 
  tmp->prev->next = tmp->next;

  delete tmp;  
}

void Doubly_linked::insert(int data, int position)
{
  if( position > size || position < 0)
  {
    throw length_error("Accessing non-existing objects during insertion"); 
  }

  Node *object = new Node();
  object->data = data;
  object->next = nullptr;
  object->prev = nullptr;

  if(head == nullptr)
  {
    head = object;
    tail = object;
    size++;
    return;
  }

  Node *temp = head;
  size++;

  for (int i = 0; i < (position - 1); i++)  // the element before the one to be inserted
  {
    temp = temp->next;
  }
  
  object->next = (position == 0) ? head : temp->next;
   
  if( position == 0 )
  {
    temp->prev = object;
    head = object;
    return;
  }
  
  temp->next = object; //linking with the previous element
  object->prev = temp;
  
  if( position == (size-1))
  {
    tail = object;
    return;
  } 

  temp->next->prev = object; //linking with the next element

}

void Doubly_linked::clear()
{
  Node *current = head;
  while(current != nullptr)
  {
    Node *tmp = current->next;
    delete current;
    current = tmp;
    size--;
  }
}
