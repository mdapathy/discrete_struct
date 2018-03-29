using namespace std;

class Doubly_linked 
{ 
private:
  
  struct Node
  {
    int data;
    Node *prev;
    Node *next;
  };
  
  Node *head;
  Node *tail;
  int size;

public:

  Doubly_linked();
  ~Doubly_linked();
  
  int get_size()
  {
    return size;
  }

  string to_string(); 
  
  void push(int data);
  void insert(int data, int position);
  void remove(int position);
  void delete_every_third();
  void clear();

  class List_Iterator
  {

  private:

    const Doubly_linked &list;
    Node* current;  
    int index;

  public:

    List_Iterator(const Doubly_linked &obj): list(obj), index(0)
    {
      current = list.head;
    }

    List_Iterator(const Doubly_linked &obj, int size):list(obj),index(size)
    {
      current = list.tail;
    }

    List_Iterator(const List_Iterator &another):list(another.list),index(another.index)
    {}

    void operator++()
    {
      if(current->next == nullptr)
      {
        throw length_error("Accessing non-existing element via ++");
      }

      current = current->next;
      index++;
    }

    void operator--()
    {
      if(current->prev == nullptr)
      {
        throw length_error("Accessing non-existing element via --");
      }

      current = current->prev;
      index--;
    }

    int operator*()
    {
      if(current == nullptr)
      {
        throw length_error ("Accessing non-existing element via *");
      } 

      return current->data;
    }

    bool operator!= (const List_Iterator &another)
    {
      return index != another.index;
    }

    bool operator== (const List_Iterator &another)
    {
      return index == another.index;
    }
  };

  List_Iterator begin()
  {
    List_Iterator iter(*this);
    return iter;
  }

  List_Iterator end()
  {
    List_Iterator iter(*this, get_size());
    return iter;
  }

};