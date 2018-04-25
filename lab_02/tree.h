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
  
    void push_helper(Node* element, int data);
    void clear_helper(Node *elem);
    void to_array_helper(Node* element, int current, Node* tree[]);
  
    int find_max_leaf_helper(Node* elem);
    int find_min_leaf_helper(Node* elem);
  
    bool find(Node* elem, int key);


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
