#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include "problems.h"
using namespace std;

TEST_SUITE("Tree's basic methods")
{

TEST_CASE("Initial properties")
{
	Tree tr;
	CHECK(tr.get_size() == 0);
	CHECK(tr.get_root() == nullptr);
};

TEST_CASE("Pushing in an empty tree")
{
	Tree tr;
	tr.push(30);
	CHECK(tr.get_size() == 1);
	CHECK(tr.get_root()->value == 30);
	CHECK(tr.get_root()->left == nullptr);
	CHECK(tr.get_root()->right == nullptr);

};

TEST_CASE("Pushing in non-empty tree")
{
	Tree tr;
	tr.push(20);
	Node* root = tr.get_root();

	tr.push(24); // right child of 20
	tr.push(13); // left child of 20
	

	tr.push(10); // left chiild of 13

	CHECK(tr.get_size() == 4);
	CHECK(root->value == 20);
	CHECK(root->left->value == 13);
	CHECK(root->right->value == 24);
	CHECK(root->left->left->value == 10);

};

TEST_CASE("Clear an empty tree")
{
	Tree tr;
	REQUIRE_THROWS(tr.clear());
}

TEST_CASE("Clearing a non-empty tree")
{
	Tree tr;

	for(int i = 0; i < 5;i++)
	{
		tr.push(i);
	}

	REQUIRE_NOTHROW(tr.clear());
	CHECK(tr.get_size() == 0);
	CHECK(tr.get_root() == nullptr);

}

TEST_CASE("Deleting exceptions: empty tree, non-existing elements")
{
	Tree tr;
	REQUIRE_THROWS(tr.delete_element(0));

	tr.push(2);
	REQUIRE_THROWS(tr.delete_element(3));
};

 TEST_CASE("Deleting root")
{
	Tree tr;
	tr.push(2);

	REQUIRE_NOTHROW(tr.delete_element(2));
	CHECK(tr.get_root() == nullptr);
	CHECK(tr.get_size() == 0);
};

 TEST_CASE("Deleting a leaf")
{
	Tree tr;
	tr.push(2);
	tr.push(3);
	REQUIRE_NOTHROW(tr.delete_element(3));
	CHECK(tr.get_root()->right == nullptr);

};

 TEST_CASE("Deleting a node with 1 child")
{
	Tree tr;
	tr.push(2);
	tr.push(3);
	tr.push(4);
	REQUIRE_NOTHROW(tr.delete_element(3));
	CHECK(tr.get_root()->right->value == 4);

};

TEST_CASE("Deleting a node with 2 children")
{
	Tree tr;
	tr.push(2);
	tr.push(3);
	tr.push(6);
	tr.push(4);

	REQUIRE_NOTHROW(tr.delete_element(3));

	CHECK(tr.get_root()->right->value == 6);
	CHECK(tr.get_root()->right->left->value == 4);

};

};
