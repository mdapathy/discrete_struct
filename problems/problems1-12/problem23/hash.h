using namespace std;

class Hash_Table
{
	
public:

	struct Node
	{
		int data;
		string key;

		bool color; // true stands for black
		Node* left;
		Node* right;
		Node* parent;

	    Node(int data = 0, string key = "", Node* parent = nullptr, bool color = false, Node* left = nullptr, Node* right = nullptr ):
	   	data(data),
	   	key(key),
	    color(color),
	    left(nullptr),
	    right(nullptr),
	    parent(parent)
	   	{};

	   	~Node()
	   	{};

	};

	Node* get_root(string key)
	{
		return arr[hash(key)];
	};

	int hash(string); 
	Hash_Table(){};
	~Hash_Table(){};
	void push(string, int); 
	int get_data(string); 
	bool get_color(string);
	int rb_delete(string); 
private:

	Node* arr[100] = {nullptr};

	int med = 90;

	void insertion_fix(Node*); 
	void deletion_fix(Node*); 
	void left_rotate(Node*); 
	void right_rotate(Node*);  
};