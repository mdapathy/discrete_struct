#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include"graph.h"
#include"doctest.h"

TEST_CASE("Graph initialization with amount of vertices")
{
	Graph graph1(3);

	CHECK(graph1.get_vertices() == 3);
	REQUIRE(graph1.get_graph().size() == 3);

	vector<vector<int>> graph = graph1.get_graph();

	for(int i = 0; i < 3; i++)
   	{
        CHECK(graph[i].size() == 3);
        
        for(int j = 0; j < 3; j++)
        {
            CHECK(graph[i][j] == graph[j][i]);
            CHECK(graph[i][j] == 0 );
        };
    }
}

TEST_CASE("Graph initialization with invalid amount of vertices")
{
	REQUIRE_THROWS(Graph graph1(0));
	REQUIRE_THROWS(Graph graph2(-4));
};

TEST_CASE("Graph initialization")
{
	vector<vector<int>> graph
	{
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0}
	};

	Graph graph1(graph);
	CHECK(graph1.get_vertices() == 3);
	CHECK(graph1.get_graph() == graph);
};


TEST_CASE("Graph initialization: not a square matrix")
{
	vector <vector<int>> graph
	{
		{1, 0, 0},
		{0, 0, 1}
	};
	REQUIRE_THROWS(Graph graph1(graph));
};


TEST_CASE("Graph initialization: matrix not representing graph")
{
	vector <vector<int>> graph
	{
		{1, 0, 1},
		{1, 0, 1},
		{1, 1, 0}
	};

	REQUIRE_THROWS(Graph graph1(graph));

};

TEST_CASE("Adding edge")
{	
	Graph graph1(3);
	REQUIRE_NOTHROW(graph1.add_edge(0, 2));
	REQUIRE_NOTHROW(graph1.add_edge(1, 1));

	vector<vector<int>> graph = graph1.get_graph();

	CHECK(graph[0][2] == 1);
	CHECK(graph[2][0] == graph[0][2]);
	CHECK(graph[1][1] == 1);

};

TEST_CASE("Adding edge: invalid arguments")
{
	Graph graph1(3);
	REQUIRE_THROWS(graph1.add_edge(-3, 4));
	REQUIRE_THROWS(graph1.add_edge(20, 15));
};

TEST_CASE("Adding vertix")
{
	Graph graph1(3);
	graph1.add_vertix();
	REQUIRE(graph1.get_vertices() == 4);

	vector<vector<int>> graph = graph1.get_graph();

	for(int i = 0; i < 4; i++)
    {
        CHECK(graph[i].size() == 4);
        CHECK(graph[i][3] == graph[3][i]); // added vertix
        CHECK(graph[i][3] == 0 );
    };

};

TEST_CASE("Deleting edge")
{
	Graph graph1(3);
	graph1.add_edge(1,1);
	graph1.add_edge(1,2);

	graph1.delete_edge(1,1);
	graph1.delete_edge(1,2);

	CHECK(graph1.get_graph()[1][1] == 0);
	CHECK(graph1.get_graph()[1][2] == 0);
	CHECK(graph1.get_graph()[2][1] == 0);
	
	
};


TEST_CASE("Deleting non-existing edge")
{
	Graph graph1(3);
	graph1.add_edge(1,1);
	graph1.add_edge(1,2);

	REQUIRE_THROWS(graph1.delete_edge(1, 16));
	REQUIRE_THROWS(graph1.delete_edge(-1, 5));
	REQUIRE_THROWS(graph1.delete_edge(0, 0));
};

TEST_CASE("M-numeration")
{
	vector<vector<int>> g
	{
		{1, 0, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 0, 1},
		{0, 0, 1, 0}
	};

	Graph graph1(g);

	vector <int> num = graph1.m_numeration();

	CHECK(num == vector <int> {1, 3, 2, 4});

}

TEST_CASE("M-numeration: isolated vertix")
{
	vector<vector<int>> g
	{
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{1, 1, 0, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
	};

	Graph graph1(g);

	vector <int> num = graph1.m_numeration();

	CHECK(num == vector <int> {1, 3, 2, 4, 5});

}
