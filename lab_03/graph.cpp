#include <vector>
#include <stdexcept>
#include "graph.h"
using namespace std;

Graph::Graph(int amount)
{
	if(amount < 1)
	{
		throw invalid_argument("Unable to create graph with less than 1 vertix");
	}

	vertices = amount;
	adjacence = vector<vector<int>>(amount, vector<int>(amount));
};

Graph::Graph(vector<vector<int>> graph)
{
    for(int i = 0; i < graph.size(); i++)
    {
        if(graph[i].size() != graph.size())
        {
             throw invalid_argument("Passed argument is not a square matrix");
        }
            for(int j = 0; j < graph[i].size(); j++)
            {
                if(graph[i][j] != graph[j][i] || graph[i][j] < 0 )
                {
                    throw invalid_argument("The matrix doesn't represent graph");
                }
            }
    }

    vertices = graph.size();
    adjacence = graph;

};

Graph::~Graph()
{}

void Graph::add_edge(int v1, int v2)
{

	if(v1 < 0 || v2 < 0 || v1 >= vertices || v2 >= vertices)
	{
		throw invalid_argument("Non-existing vertix");
	}


	adjacence[v1][v2]++;

	if(v1 != v2) adjacence[v2][v1]++;
}

void Graph::add_vertix()
{
	vertices++;
	
	adjacence.resize(vertices);

	for(int i = 0; i < vertices; i++)
	{
       		adjacence[i].resize(vertices);
	}

	
}

void Graph::delete_edge(int v1, int v2)
{

	if(v1 >= vertices || v2 >= vertices || v1 < 0 || v2 < 0 )
	{
		throw invalid_argument("Non-existing vertix");
	}

	if(adjacence[v1][v2] == 0)
	{
		throw out_of_range("Non-existing edge");
	}


	adjacence[v1][v2]--;
	
	if(v1 != v2) adjacence[v2][v1]--;
}


vector <int> Graph::m_numeration(int vertix)
{
	vector <int> numeration(vertices);
	vector<bool> used(vertices);
	int counter = 1;

	counter = DFS(vertix, used, numeration, counter);

    for (int i = 0; i < vertices; i++)
    {

        if(used[i] == false)
        {
            DFS(i, used, numeration, counter);
        }
    }

	return numeration;

}

int Graph::DFS(int pos, vector <bool>& used, vector <int>& numeration, int counter)
{
    int count = counter;
    used[pos] = true;

    if(numeration[pos] == 0)  numeration[pos] = count;

    for(int i = 0 ; i < vertices; ++i)
    {
       
        if ( adjacence[pos][i] && used[i] == 0)
        {
            DFS(i, used, numeration, ++count);
        }
    }
	
    return ++count;
}        
