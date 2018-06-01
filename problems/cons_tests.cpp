#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include"cons.h"
#include"doctest.h"

TEST_CASE("Initial server")
{
	Consistent_Hash has;
	has.add_server();
	
	REQUIRE(has.load_size() == 1);
	REQUIRE(has.left_lim(0) == 0);
	REQUIRE(has.right_lim(0) == 1e3);
	
}

TEST_CASE("Initial push")
{
	Consistent_Hash has;
	has.add_server();
	
	string first = "string";
	int hash1 = has.get_hash(first);
	
	has.add_node(first, 66);

	REQUIRE(has.load_access(0, hash1) == 66);
	
}



TEST_CASE("Add server")
{
	Consistent_Hash has;
	has.add_server();
	
	string first = "string";
	string second = "another_string";

	has.add_node(first, 66);
	has.add_node(second, 77);
	has.add_server();

	int hash1 = has.get_hash(first);
	int hash2 = has.get_hash(second);

	CHECK(hash1>hash2);

	REQUIRE(has.load_size() == 2);

	CHECK(has.left_lim(0) == 0);
	CHECK(has.right_lim(0) == hash1);


	CHECK(has.left_lim(1) == hash1);
	CHECK(has.right_lim(1) == 1e3);

	CHECK(has.load_access(0,hash2) == 77);
	CHECK(has.load_access(1,hash1) == 66);

	
}

TEST_CASE("Look for a record")
{
	Consistent_Hash has;
	has.add_server();
	
	string first = "string";
	string second = "another_string";

	has.add_node(first, 66);
	has.add_node(second, 77);
	
	CHECK(has.search(first) == 66);
	CHECK(has.search(second) == 77);

	has.add_server();

	CHECK(has.search(second) == 77);
}

TEST_CASE("Delete record")
{
	Consistent_Hash has;
	has.add_server();
	
	string first = "string";
	string second = "another_string";

	has.add_server();

	has.add_node(first, 66);
	has.add_node(second, 77);

	has.delete_record(first);
	has.delete_record(second);
	
	CHECK_THROWS(has.search(first));
	CHECK_THROWS(has.search(second));
}

TEST_CASE("Delete server")
{
	
	Consistent_Hash has;
	has.add_server();
	
	string first = "string";
	string second = "another_string";

	has.add_node(first, 66);
	has.add_node(second, 77);
	
	has.add_server();
	has.delete_server();

	REQUIRE(has.load_size() == 1);
	REQUIRE(has.left_lim(0) == 0);
	REQUIRE(has.right_lim(0) == 1e3);
}
