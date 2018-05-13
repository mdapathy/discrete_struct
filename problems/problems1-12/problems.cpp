#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include "problems.h"
using namespace std;

Problems::Problems()
{
	srand(time(0));
    for(int i = 0; i < 15; i++)
    {
        tree.push(rand()%199-99);
    }
}

Problems::Problems(vector <int>& values)
{
	for (int i = 0; i < 15;i++)
	{
		tree.push(values[i]);
	}
}

Problems::~Problems()
{
}

vector <int> Problems::problem_1(int n)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		if(abs(values[i])%n == 0)
		{
			removed.push_back(tree.delete_element(values[i]));	
		}
	}

	return removed;

}

vector <int> Problems::problem_2()
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		if(abs(values[i])%2 == 1)
		{
			removed.push_back(tree.delete_element(values[i]));	
		}
	}

	return removed;

}

vector <int> Problems::problem_3(int n)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = tree.get_size()-1; i >= 0 && values[i] > n ; i--)
	{
		removed.push_back(tree.delete_element(values[i]));	
	}

	return removed;
}

vector <int> Problems::problem_4(int n)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i <= tree.get_size() && values[i] < n ; i++)
	{
		removed.push_back(tree.delete_element(values[i]));	

	}

	return removed;
}


vector <int> Problems::problem_5(vector <int> to_del)
{
	vector <int> removed;

	for(int i = 0; i < to_del.size(); i++)
    {
        removed.push_back(tree.delete_element(to_del[i]));

    }
    
    return removed;
}


vector <int> Problems::problem_6()
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
    {
        int tmp = values[i];

        if(tmp < 2)
        {
            continue;
        }
        
        int root = sqrt(tmp);

        bool prime = true;

        for(int i = 2; i <= root; i++)
        {
            if(tmp%i == 0)
            {
                prime = false;
            }
        }
        if(prime)
            removed.push_back(tree.delete_element(values[i]));
    	
    }

    return removed;
}

vector <int> Problems::problem_7()
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
    {
        int tmp = values[i];

        if(tmp < 2)
        {
            continue;
        }
        
        int root = sqrt(tmp);

        bool composite = false;

        for(int i = 2; i <= root; i++)
        {
            if(tmp%i == 0)
            {
                composite = true;
            }
        }
        if(composite)
            removed.push_back(tree.delete_element(values[i]));
    	
    }

    return removed;
}


vector <int> Problems::problem_8(int beg, int end)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		if(values[i] > beg && values[i] < end)
		{
			removed.push_back(tree.delete_element(values[i]));
		}
	}

	return removed;
}	

vector <int> Problems::problem_9(int more_than)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		int sum = values[i]/10 + values[i]%10;
		if (sum > more_than)
		{
			removed.push_back(tree.delete_element(values[i]));
		}
	}

	return removed;

}

vector <int> Problems::problem_10(int less_than)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		int sum = abs(values[i])/10 + abs(values[i])%10;
		if (sum < less_than)
		{
			removed.push_back(tree.delete_element(values[i]));
		}
	}

	return removed;

}

vector <int> Problems::problem_11(int more_than, int less_than)
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		int sum = abs(values[i])/10 + abs(values[i])%10;
		if (sum < less_than && sum > more_than)
		{
			removed.push_back(tree.delete_element(values[i]));
		}
	}

	return removed;
}


vector <int> Problems::problem_12()
{
	vector <int> values;
	vector <int> removed;

	tree.get_values(values, tree.get_root());

	for(int i = 0; i < 15; i++)
	{
		float root = sqrt(abs(values[i]));

		if(root == (int)root)
		{
			removed.push_back(tree.delete_element(values[i]));
		}
	}

	return removed;
}
