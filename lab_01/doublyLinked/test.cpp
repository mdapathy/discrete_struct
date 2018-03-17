#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "doubly_linked.h"
using namespace std;

Doubly_linked list,
              list1,
              list2,
              list3; 

TEST_CASE("Properties of a new list: size, head, tail")
{
	CHECK(list.get_size() == 0);
	REQUIRE_THROWS(list.get_head());
	REQUIRE_THROWS(list.get_tail()); 

}

TEST_CASE("Push: empty and nonempty list") // check whether the properties are updated
{ 
	REQUIRE_NOTHROW(list.push(6));
        CHECK(list.get_head() == 6);
	CHECK(list.get_tail() == 6);

	REQUIRE_NOTHROW(list.push(7));
        CHECK(list.get_head() == 6 );
	CHECK(list.get_tail() == 7 );

	REQUIRE_NOTHROW(list.clear());

}


TEST_CASE("Push 0 in an empty list ") // check if 0 is treated as a usual number
{
	REQUIRE_NOTHROW(list1.push(0));

	CHECK(list1.get_head() == 0);
	CHECK(list1.get_tail() == 0);
	CHECK(list1.get_size() == 1 );

}

TEST_SUITE_BEGIN("Removing");

TEST_CASE("Removing: exceptions") 
{    
	CHECK(list.get_size() == 0);

    CHECK_THROWS(list.remove(0)); // list is  empty 
	CHECK_THROWS(list.remove(-2));
	CHECK_THROWS(list1.remove( list1.get_size() + 1 ) );

}

TEST_CASE("Removing: list with one obj") // updating head and tail 
{
        REQUIRE_NOTHROW(list1.remove(0));

        REQUIRE_THROWS(list1.get_head());
	REQUIRE_THROWS(list1.get_tail()); 
	CHECK(list1.get_size() == NULL);

}


TEST_CASE("Removing: tail")
{   
        list1.push(1); // filling the list
        list1.push(2); 

        REQUIRE_NOTHROW(list1.remove(1));

        CHECK(list1.get_tail() == 1);

}

TEST_CASE("Removing: head")
{
	REQUIRE_NOTHROW(list1.remove(0));

	CHECK(list1.get_size() == 0);

}

TEST_SUITE_END();


TEST_SUITE_BEGIN("Insertion");

TEST_CASE("Insertion: exceptions") 
{ 
	CHECK_THROWS(list1.insert(3, -1));
	CHECK_THROWS(list1.insert(4, 20));

};

TEST_CASE("Insertion: empty list")
{
    CHECK(list2.get_size() == 0);
	REQUIRE_NOTHROW(list2.insert(1, 0));
    CHECK(list2.get_size() == 1);
	CHECK(list2.get_head() == 1 );
	CHECK(list2.get_tail() == 1);


};


TEST_CASE("Insertion: head")
{
	REQUIRE_NOTHROW(list2.insert(0, 0));
        CHECK(list2.get_head() == 0 );

};

TEST_CASE("Insertion: tail")
{
	REQUIRE_NOTHROW(list2.insert(2, 2));
	CHECK(list2.get_tail() == 2 );;

};

TEST_SUITE_END();


TEST_CASE("Turning list into string") // throwing exception is the list is empty 
{
	REQUIRE_THROWS(list3.to_string());
	CHECK(list2.to_string() == "0 1 2");
};

TEST_CASE("Delete every third: empty list")
{
	CHECK_THROWS(list1.delete_every_third());

};

TEST_CASE("Delete every third: tail") 
{

	REQUIRE_NOTHROW(list3.push(1));
	REQUIRE_NOTHROW(list3.push(2));
	REQUIRE_NOTHROW(list3.push(3));
	
	CHECK(list3.get_size() == 3);

    REQUIRE_NOTHROW(list3.delete_every_third());

    CHECK(list2.get_tail() == 2);

};