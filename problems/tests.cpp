#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include <string>
#include "problems.h"
#include "doctest.h"

TEST_CASE("13th problem")
{
	Problems probl;
	vector <int> initial = {3, 16, 86, 45, 4, 13, 35 };

	vector <int> resulting = probl.problem_13(initial);

	REQUIRE(initial.size() == resulting.size());

	for( int i = 0; i < resulting.size() - 1 ; i++)
	{
		CHECK(resulting[i] > resulting [i + 1]); 
	}

}

TEST_CASE("14th problem")
{
	Problems probl;

	vector <int> initial = {1, 3, 4, 6, 8, 15, 16, 30};

	probl.problem_14(initial, 5);

	REQUIRE(initial.size() == 9); //initial size is 8

	for( int i = 0; i < initial.size() - 1 ; i++)
	{
		CHECK(initial[i] <= initial[i + 1]); 
	}


}

TEST_CASE("15th problem: odd amount of elements")
{
	Problems probl;
	vector <int> initial = {1, 3, 5, 6, 7, 9, 11};
	probl.problem_15(initial);

	for( int i = 0; i < initial.size() - 1 ; i++)
	{
		CHECK(initial[i] >= initial[i + 1]); 
	}
}

TEST_CASE("15th problem: even amount of elements")
{
	Problems probl;
	vector <int> initial = {1, 3, 5, 6, 7, 9};
	probl.problem_15(initial);

	for( int i = 0; i < initial.size() - 1 ; i++)
	{
		CHECK(initial[i] >= initial[i + 1]); 
	}
}

TEST_CASE("16th problem")
{
	Problems probl;
	vector <int> initial = {10, -3, 5, -6, 8, -8, 65};
	probl.problem_16(initial);
	REQUIRE(initial.size() == 4 );

	for( int i = 0; i < initial.size() - 1 ; i++)
	{
		CHECK(initial[i] <= initial[i + 1]); 
	}


}

TEST_CASE("17th problem")
{
	Problems probl;
	vector <int> initial = {10, -3, 5, -6, 8, -8, 65};
	vector<int> resulting = probl.problem_17(initial);

	REQUIRE(resulting.size() == 7);

	for( int i = 0; i < resulting.size() - 1 ; i++)
	{
		CHECK(resulting[i] <= resulting[i + 1]); 
	}


}

TEST_CASE("18th problem")
{
	Problems probl;
	vector <string> initial = {"King", "Doyle", "Martin", "Lorca", "Kingsley"};

	vector <string> resulting = probl.problem_18(initial);
	REQUIRE(resulting.size() == 5);

	CHECK(resulting[0] == "Doyle");
	CHECK(resulting[1] == "King");
	CHECK(resulting[2] == "Kingsley");
	CHECK(resulting[3] == "Lorca");
	CHECK(resulting[4] == "Martin");

}

TEST_CASE("19th problem")
{
	Problems probl;

	vector <pair <int, string>> initial = 
	{
		{380506535946, "Jim"},
		{380655797643, "Tom"},
		{380968633579, "Ann"},
		{380456566764, "Sue"},
		{380334694945, "John"}

	};

	vector <pair <int, string>> resulting = probl.problem_19(initial);
	REQUIRE(resulting.size() == 5);

	for( int i = 0; i < resulting.size() - 1 ; i++)
	{
		CHECK(resulting[i].first < resulting[i + 1].first); 
	}

}

TEST_CASE("20th problem")
{
	Problems probl;
	vector <string> initial = {"King", "Doyle", "Martin", "Lorca", "Kingsley"};
	probl.problem_20(initial);

	for( int i = 0; i < initial.size() - 1 ; i++)
	{
		CHECK(initial[i].length() <= initial[i + 1].length()); 
	}

}

TEST_CASE("21st problem")
{
	Problems probl;
	vector <int> initial = {0, 4, -5, 6, 7, -3};
	probl.problem_21(initial);

	vector <int> resulting = {7, 6, -5, 4, -3, 0};
	CHECK(resulting == initial);
}


TEST_CASE("22nd problem")
{
	Problems probl;
	vector<float> initial {-3,  0, 2.5, 3.5};

	vector<float> resulting = probl.problem_22(initial);

	CHECK(resulting.size() == initial.size()*2 - 1);

	for ( int i = 0; i < resulting.size()-1 ; i++)
	{
		CHECK(resulting[i] < resulting[i+1]);
	}
}

TEST_CASE("22nd problem: not enough elements to insert their average")
{
	Problems probl;
	vector<float> initial  {0};
	vector<float> initial1;

	initial = probl.problem_22(initial);
	initial1 = probl.problem_22(initial1);

	CHECK(initial1.size() == 0);
	CHECK(initial.size() == 1);

}