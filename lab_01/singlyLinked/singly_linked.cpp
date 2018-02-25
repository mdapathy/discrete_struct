#include <stdexcept>
#include "singly_linked.h"
using namespace std;

Singly_linked::Singly_linked():
  head(nullptr),
  tail(nullptr),
  size(0)
  {};

Singly_linked::~Singly_linked()
{
  Node *current = head;
  while(head != nullptr)
  {
    Node *tmp = head->next;
    delete head;
    head = tmp;
  }
}

int Singly_linked::get_size()
{
  return size;
}

int Singly_linked::get_tail()
{
  if (tail == nullptr )
  {
    throw ("An empty list");
  } 

  return tail->data ;
}

int Singly_linked::get_head()
{
  if (head == nullptr ) 
  {
    throw ("An empty list");
  }
  
  return head->data ;
}

int* Singly_linked::display()
{
  if(size == 0)
  {
    throw invalid_argument("Nothing to show.");
  }

  int *array = new int[size]; 
  Node *tmp = head;

  for (int i = 0; i < size; i++)
  { 
    array[i] = tmp->data;
    tmp = tmp->next;
  }

  return array;
}

void Singly_linked::push(int data)
{
  Node *obj = new Node;
  obj->data = data;
  obj->next = nullptr;

  size++;

  if(head == nullptr)
  {
    head = obj;
    tail = obj;
    return;
  }

  tail->next = obj;
  tail = tail->next;
}

void Singly_linked::delete_every_third() 
{
  Node *inuse = head;

  if(inuse == nullptr)
  {
    throw invalid_argument("An empty list.");
  }

  for (int counter = 0; inuse->next != nullptr ; counter++)
  {
    if( (counter+2)%3 == 0)
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

      delete tmp;
      counter++;
    } 

    inuse = inuse->next;
  } 
}

void Singly_linked::remove(int position)
{
  if(size == 0 || position >= size || position < 0  )
  {
    throw invalid_argument("Not possible to execute");
  }

  Node *inuse = head; // the element before the one to be deleted
  size--;

  if(size == 0) // 1 element in total
  {
    head = nullptr;
    tail = nullptr;
    delete inuse;
    return;
  }

  for (int i = 0; i < (position - 1); i++)
  {
    inuse = inuse->next;
  }

  Node *temp = inuse->next;

  if(position == size)
  {
    tail = inuse;
    tail->next = nullptr;
    delete temp;
    return;
  }

  if(position == 0)
  { 
    head = temp;
    delete inuse;
    return;
  }

  inuse->next = temp->next;
  delete temp;  

}

void Singly_linked::insert(int data, int position) 
{
  if( position > size || position < 0)
  {
    throw invalid_argument("Impossible to execute.");
  }

  Node *object = new Node;
  object->data = data;
  object->next = nullptr;

  if(head == nullptr)
  {
    head = object;
    tail = object;
    size++;
    return;
  }

  Node *inuse = head;
  size++;

  for (int i = 0; i < (position - 1); i++)  // the element before the one to be inserted
  {
    inuse = inuse->next;
  }

  object->next = (position == 0) ? head : inuse->next;   

  if ( position == 0 )
  {
    head = object;
    return;
  }

  if( position == (size-1))
  {
    tail = object;
  } 
 
  inuse->next = object;
}

void Singly_linked::clear()
{
  Node *current = head;

  while(head != nullptr)
  {
    Node *tmp = head->next;
    delete head;
    head = tmp;
  }

  size = 0;
}
