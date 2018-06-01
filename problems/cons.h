using namespace std;

#include <vector>
#include <map>
#include <stdexcept>
#include <string>

class Consistent_Hash
{

public:

	struct Elem
	{
		int left;
		int right;
		map <int, int> server;

		Elem(int l, int r, map<int,int> serv):
		left(l),
		right(r),
		server(serv)
		{};
	};
private:
	int size;
	
	vector<Elem> load;

	int med = 1e3+1;
public:

	Consistent_Hash():
	size(0),
	load({})
	{};

	int get_size()
	{
		return size;
	}

	int load_size()
	{
		return load.size();
	}
	
	int left_lim (int x)
	{	
		return load[x].left;
	}
	
	int right_lim (int x)
	{	
		return load[x].right;
	}

	int load_access(int x, int y)
	{	
		return load[x].server.lower_bound(y)->second;
	}

	int get_hash(string);

	void add_server();
	void delete_server();
	
	void add_node(string, int);
	int search(string);
	void delete_record(string);

	~Consistent_Hash()
	{
		load.clear();
	};
		
};
