#include <cmath>
#include <string>
#include "problems.h"
using namespace std;

template <class parameter>

void Problems::shell_sort(vector<parameter> &sequence, bool (*compare)(parameter, parameter))
{ 
    int length = sequence.size(),
        in_gap = length/2;

    for(int gap = in_gap; gap >= 1; gap = gap/2)
    {
        for(int i = gap; i < length; i++)
        {
            for(int j = i; j >= gap && (compare)(sequence[j], sequence[j-gap]); j -= gap)
            {
                swap(sequence[j], sequence[j-gap]);
            }
        }
    }             
}

vector<int> Problems::problem_13(vector<int>& initial)
{
	vector<int> resulting = initial;

	bool (*comparison)(int x, int y) = [](int x, int y){ return x >= y;};
	
	shell_sort(resulting, comparison);

	return resulting;
}

void Problems::problem_14(vector <int> &initial, int int_to_insert)
{
    std::vector<int>::iterator iter = initial.begin();

    while ( iter != initial.end() && *iter < int_to_insert)
    {
        iter++;
    }

    initial.insert(iter, int_to_insert);

}

void Problems::problem_15(vector<int> &initial)
{
    int half = floor(initial.size()/2);
    for(int i = 0; i < half; i++)
    {
        swap(initial[i], initial[initial.size()- 1 - i]);
    }

    //reverse(initial.begin(), initial.end()); - another possible solution
}


void Problems::problem_16(vector<int> &initial)
{
    bool (*comparison)(int x, int y) = [](int x, int y){ return x <= y;};
    shell_sort(initial, comparison);

    std::vector<int>::iterator iter = initial.begin();

    while (*iter < 0)
    {
        iter++;
    }

    initial.erase(initial.begin(), iter);
}

vector <int> Problems::problem_17(vector<int> &initial)
{
    vector <int> resulting(initial.size());

    resulting[0] = initial[0];

    for(int i = 1; i < initial.size();i++)
    {
        int tmp = initial[i];
        std::vector<int>::iterator iter = resulting.begin();

        while (*iter < initial[i] && iter != resulting.end())
        {
            iter++;
        }

        resulting[iter - resulting.begin()] = tmp;

    }

    return resulting;

}

vector <string> Problems::problem_18(vector<string> &initial)
{
    bool (*comparison)(string x, string y) = [](string x, string y)
    {
        for(int i = 0; i < min(x.length(), y.length()); i++)
        {
            if(x[i] != y[i])
            {
                return x[i] < y[i];
            }

            return x.length() < y.length();
        }
    };
    
    shell_sort(initial, comparison);

    return initial;
}

vector<pair <int, string>> Problems::problem_19(vector <pair <int, string> >& initial)
{
    bool (*comparison)(pair <int, string> x, pair <int, string> y) = [](pair <int, string> x , pair <int, string> y)
    {
        return x.first < y.first;
    };

    shell_sort(initial, comparison);

    return initial;
}

void Problems::problem_20(vector <string> &initial)
{
    bool (*comparison)(string x, string y) = [](string x, string y)
    {
        return x.length() < y.length();
    };

    shell_sort(initial, comparison);
}

void Problems::problem_21(vector<int>& initial)
{
   bool (*comparison)(int x, int y) = [](int x, int y){ return abs(x) >= abs(y);}; 
// bool (*comparison)(int x, int y) = [](int x, int y){ return abs(x) <= abs(y);}; - ascending order
   shell_sort(initial, comparison);
}


vector<float> Problems::problem_22(vector <float> &initial)
{
    if(initial.size() < 2)
    {
        return initial;
    }

    vector<float> resulting;

    for (int i = 0; i < initial.size() - 1 ; i++)
    {
        double to_insert = (initial[i+1]  + initial[i])/2 ; // inserting arithmetical mean
        resulting.push_back(initial[i]);
        resulting.push_back(to_insert);
    }

   resulting.push_back(initial[initial.size()-1]);

   return resulting;
}
