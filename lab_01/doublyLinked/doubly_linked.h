using namespace std;

class Doubly_linked 
{ 
  struct Node
  {
    int data;
    Node *prev;
    Node *next;
  };

private:
  Node *head;
  Node *tail;
  int size;

public:
  Doubly_linked();
  ~Doubly_linked();
  
  int get_size(void);
  int get_tail(void);
  int get_head(void);

  int *display();
  
  void push(int data);
  void insert(int data, int position);
  void remove(int position);
  void delete_every_third();
  void clear();

};