#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include "problems.h"
using namespace std;

vector <int> universal {-63, -40, -12, -4, -3, -2,  1, 3, 11, 18, 28, 44, 62, 89, 99};

TEST_CASE("1st problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_1(3);

	CHECK(deleted.size() == 6);
	CHECK(prol.tree.get_size() == 9);
	CHECK(deleted == vector <int> {-63, -12, -3, 3, 18, 99});

}

TEST_CASE("2nd problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_2();

	CHECK(deleted.size() == 7);
	CHECK(prol.tree.get_size() == 8);
	CHECK(deleted == vector <int> {-63, -3, 1, 3, 11, 89, 99});
	
}

TEST_CASE("3rd problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_3(44);

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {99, 89, 62});
	
}

TEST_CASE("4th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_4(-5);

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {-63, -40, -12});
}

TEST_CASE("5th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_5(vector <int> {-63, -40, -12});

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {-63, -40, -12});
}

TEST_CASE("6th problem")
{
	vector <int> universal {-63, -40, -12, -4, -3, -2,  1, 3, 11, 18, 28, 44, 62, 89, 99};

	Problems prol(universal);

	vector <int> deleted = prol.problem_6();

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {3, 11, 89});
}

TEST_CASE("7th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_7();

	CHECK(deleted.size() == 5);
	CHECK(prol.tree.get_size() == 10);
	CHECK(deleted == vector <int> { 18, 28, 44, 62, 99});
}

TEST_CASE("8th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_8(-1, 15);

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {1, 3, 11});
}


TEST_CASE("9th problem")
{

	Problems prol(universal);

	vector <int> deleted = prol.problem_9(10);

	CHECK(deleted.size() == 2);
	CHECK(prol.tree.get_size() == 13);
	CHECK(deleted == vector <int> {89, 99});

}

TEST_CASE("10th problem")
{

	Problems prol(universal);

	vector <int> deleted = prol.problem_10(2);

	CHECK(deleted.size() == 1);
	CHECK(prol.tree.get_size() == 14);
	CHECK(deleted == vector <int> {1});

}

TEST_CASE("11th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_11(2,4);

	CHECK(deleted.size() == 3);
	CHECK(prol.tree.get_size() == 12);
	CHECK(deleted == vector <int> {-12, -3, 3});
}

TEST_CASE("12th problem")
{
	Problems prol(universal);

	vector <int> deleted = prol.problem_12();

	CHECK(deleted.size() == 2);
	CHECK(prol.tree.get_size() == 13);
	CHECK(deleted == vector <int> {-4, 1});
}
