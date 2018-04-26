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
      int delete_element(int);
      void to_array(Node* tr[]);

      void get_values(vector <int>&, Node* );
    
};
