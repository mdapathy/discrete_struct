#include <vector>
using namespace std;

class Problems
{
private:
    template <class parameter>

    void shell_sort(vector<parameter> &sequence, bool (*compare)(parameter, parameter));

public:
    vector<int> problem_13(vector <int>&);

    void problem_14(vector <int>&, int);
    void problem_15(vector<int>& );
    void problem_16(vector <int>& );

    vector<int> problem_17(vector <int>& );
    vector<string> problem_18(vector <string>& );
    vector<pair <int, string>> problem_19(vector <pair <int, string> >&);

    void problem_20(vector <string> &);
    void problem_21(vector<int>& );

    vector<float> problem_22(vector <float>&);

};