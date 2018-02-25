using namespace std;

class Singly_linked 
{
  struct Node
  {
    int data;
    Node *next;
  };

private:
  Node *head;
  Node *tail;
  int size;

public:
  Singly_linked();
  ~Singly_linked();
  
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