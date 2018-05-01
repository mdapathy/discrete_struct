#include <vector>
using namespace std;

class Graph
{
private:

	vector<vector<int>> adjacence ;
	int vertices;
	int DFS(int, vector <bool>&, vector <int>&, int);

public:
	Graph(int);
	Graph(vector<vector<int>>);
	~Graph();

	void add_edge(int, int);
	void add_vertix();
	void delete_edge(int, int);

	vector <int> m_numeration(int vertix = 0);

	vector <vector<int>> get_graph()
	{
		return adjacence;
	}

	int get_vertices()
	{
		return vertices;
	}
};