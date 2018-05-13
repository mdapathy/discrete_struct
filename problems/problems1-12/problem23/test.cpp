#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <stdexcept>
#include <string>
#include "hash.h"

TEST_CASE("Pushing elements")
{
	Hash_Table hash_t;


	hash_t.push("abc", 9);
	hash_t.push("fkr", 6);


	CHECK(hash_t.get_data("abc") == 9);
	CHECK(hash_t.get_data("fkr") == 6);

};

TEST_CASE("Getting elements")
{
	Hash_Table hash_t;

    string init = "string";

    for(int i = 0; i < 4; i++)
    {
        hash_t.push(init, i);
        init[1]++;
    }
	
	init = "string";

    for(int i = 0; i < 4; i++)
    {
        REQUIRE_NOTHROW(hash_t.get_data(init));
        CHECK(hash_t.get_data(init) == i);
        init[1]++;
    }

}


TEST_CASE("Getting non-existing elements")
{
	Hash_Table hash_t;

	hash_t.push("key", 777);

	REQUIRE_THROWS(hash_t.get_data("wrongkey"));

}

TEST_CASE("Pushing elements with identical hash ")
{
	Hash_Table hash_t;

	hash_t.push("ba", 66);
	hash_t.push("ab", 5);

	REQUIRE(hash_t.hash("ab") == hash_t.hash("ba"));

	CHECK(hash_t.get_data("ba") == 66);
	CHECK(hash_t.get_data("ab") == 5);

	CHECK(hash_t.get_color("ba") == true);
	CHECK(hash_t.get_color("ab") == false);
}



TEST_CASE("Insertion fixup: red parent")
{
	SUBCASE("Node's parent is the right son")
	{	
		Hash_Table hash_t;

		REQUIRE(hash_t.hash("abc") == hash_t.hash("cab"));
	
		SUBCASE("Red uncle")
		{
			hash_t.push("acb", 15);
			hash_t.push("abc", 5);
			hash_t.push("bca", 20);
			hash_t.push("cba", 25);

			CHECK(hash_t.get_root("acb")->key == "acb");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == true);
			CHECK(hash_t.get_color("abc") == true);
			CHECK(hash_t.get_color("cba") == false);

		};

		SUBCASE("The uncle is black/does not exist. Node is  the right son")
		{
			hash_t.push("abc", 5);
			hash_t.push("acb", 15);
			hash_t.push("bca", 20);

			CHECK(hash_t.get_root("acb")->key == "acb");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == false);
			CHECK(hash_t.get_color("abc") == false);
			
		};

		SUBCASE("The uncle is black/does not exist. Node is the left son")
		{
			hash_t.push("abc", 5);
			hash_t.push("bca", 20);
			hash_t.push("acb", 15);


			CHECK(hash_t.get_root("acb")->key == "acb");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == false);
			CHECK(hash_t.get_color("abc") == false);
			

		};

	};

	SUBCASE("Node's parent is the left son")
	{
		Hash_Table hash_t;

		SUBCASE("Red uncle")
		{	
			hash_t.push("bca", 20);
			hash_t.push("cba", 25);
			hash_t.push("acb", 15);
			hash_t.push("abc", 5);


			CHECK(hash_t.get_root("acb")->key == "bca");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == true);
			CHECK(hash_t.get_color("abc") == false);
			CHECK(hash_t.get_color("cba") == true);

		};

		SUBCASE("The uncle is black/does not exist. Node is  the right son")
		{
			hash_t.push("bca", 20);
			hash_t.push("abc", 5);
			hash_t.push("acb", 15);

			CHECK(hash_t.get_root("acb")->key == "acb");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == false);
			CHECK(hash_t.get_color("abc") == false);

		};

		SUBCASE("The uncle is black/does not exist. Node is the left son")
		{
			hash_t.push("bca", 20);
			hash_t.push("acb", 15);
			hash_t.push("abc", 5);

			CHECK(hash_t.get_root("acb")->key == "acb");

			CHECK(hash_t.get_color("acb") == true);
			CHECK(hash_t.get_color("bca") == false);
			CHECK(hash_t.get_color("abc") == false);
		};
	};
}

TEST_CASE("Insertion fixup: black parent")
{
	Hash_Table hash_t;

	REQUIRE(hash_t.hash("ab") == hash_t.hash("ba"));
	hash_t.push("ba", 10);

	REQUIRE(hash_t.get_color("ba") == true);
	hash_t.push("ab", 4);

	CHECK(hash_t.get_color("ab") == false);
}

TEST_CASE("Deletin non-existing element")
{
	Hash_Table hash_t;

	hash_t.push("bca", 20);
	hash_t.push("abc", 5);
	hash_t.push("acb", 15);

	REQUIRE_THROWS(hash_t.rb_delete("fgd"));

}

TEST_CASE("Deletion")
{
	Hash_Table hash_t;

	hash_t.push("abc", 5);
	hash_t.push("bca", 20);

	CHECK(hash_t.rb_delete("bca") == 20);
}



TEST_CASE("Deleting root")
{
	Hash_Table hash_t;

	hash_t.push("abc", 5);

	CHECK(hash_t.rb_delete("abc") == 5);
	CHECK(hash_t.get_root("abc") == nullptr);

}

TEST_CASE("Deleting element with one or less sons")
{
	Hash_Table hash_t;

	hash_t.push("abc", 6);
	hash_t.push("bac", 5);
	hash_t.push("cab", 7);


	hash_t.rb_delete("bac");


	CHECK(hash_t.get_root("abc")->key == "cab");
	CHECK(hash_t.get_color("abc") == false);
	CHECK(hash_t.get_color("cab") == true);

};

TEST_CASE("Deleting element with two sons")
{
	Hash_Table hash_t;

	hash_t.push("bac", 5);
	hash_t.push("abc", 6);
	hash_t.push("cab", 7);


	hash_t.rb_delete("bac");

	CHECK(hash_t.get_root("abc")->key == "cab");
	CHECK(hash_t.get_color("abc") == false);
	CHECK(hash_t.get_color("cab") == true);
};
