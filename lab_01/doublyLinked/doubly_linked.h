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
  
  int get_tail();
  int get_head();

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

};
