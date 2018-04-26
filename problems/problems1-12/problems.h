#include "tree.h"
#include <vector>
using namespace std;

class Problems
{
public:
	Tree tree;

	Problems();
	Problems(vector<int>&);
	~Problems();

	vector <int> problem_1(int);
	vector <int> problem_2();
	vector <int> problem_3(int);
	vector <int> problem_4(int);
	vector <int> problem_5(vector <int>);
	vector <int> problem_6();
	vector <int> problem_7();
	vector <int> problem_8(int, int);
	vector <int> problem_9(int);
	vector <int> problem_10(int);
	vector <int> problem_11(int, int);
	vector <int> problem_12();

};