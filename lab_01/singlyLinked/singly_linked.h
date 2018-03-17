using namespace std;

class Singly_linked 
{
private:
  
  struct Node
  {
    int data;
    Node *next;
  };
  
  Node *head;
  Node *tail;
  int size;

public:
  Singly_linked();
  ~Singly_linked();

  int get_tail(void);
  int get_head(void);

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
