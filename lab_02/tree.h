using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;

  Node(int data):
  value(data),
  left(nullptr),
  right(nullptr)
  {}

  ~Node()
  {}

};

class Tree 
{
  private:

    int size;
    Node *root;

    public:
      Tree();
      ~Tree();

      int get_size()
      {
        return size;
      }

      Node* get_root()
      {
        return root;
      }

      void push(int);
      void clear(); 
      void delete_element(int);
      void to_array(Node* tr[]);

      int find_min_leaf();
      int find_max_leaf();
    
};
