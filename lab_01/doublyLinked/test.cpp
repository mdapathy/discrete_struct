#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "doubly_linked.h"
using namespace std;


TEST_CASE("Properties of a new list: size, head, tail")
{
	Doubly_linked list;

	CHECK(list.get_size() == 0);

	CHECK_THROWS(*list.begin()); //list's empty
	CHECK_THROWS(*list.end());
}

TEST_CASE("Push in  empty and nonempty list") // check whether the properties are updated
{ 
    Doubly_linked list;

	REQUIRE_NOTHROW(list.push(6));
    CHECK(*list.begin() == 6);
	CHECK(*list.end() == 6);

	REQUIRE_NOTHROW(list.push(7));
    CHECK(*list.begin() == 6 );
	CHECK(*list.end() == 7 );

}

TEST_CASE("Push 0 in an empty list ") // check if 0 is treated as a usual number
{
	Doubly_linked list;

	REQUIRE_NOTHROW(list.push(0));

	CHECK(*list.begin() == 0);
	CHECK(*list.end() == 0);
	CHECK(list.get_size() == 1 );

}

TEST_SUITE_BEGIN("Removing");

TEST_CASE("Removing exceptions ") 
{    
    Doubly_linked list;

    CHECK_THROWS(list.remove(0)); // list is  empty 
	CHECK_THROWS(list.remove(-30)); 
     
    list.push(5);
    list.push(4);

	CHECK_THROWS(list.remove(1000) ); // exceeds list's size

}

TEST_CASE("Removing from list with one obj") // updating head and tail 
{
    Doubly_linked list;
    list.push(45);


    REQUIRE_NOTHROW(list.remove(0));

    REQUIRE_THROWS(*list.begin());
	REQUIRE_THROWS(*list.end()); 
	CHECK(list.get_size() == 0);

}


TEST_CASE("Removing tail")
{   
	 Doubly_linked list;

     list.push(40); // filling the list
     list.push(59); 

     REQUIRE_NOTHROW(list.remove(1));

     CHECK(*list.end() == 40);

}

TEST_CASE("Removing head")
{
	Doubly_linked list;

	list.push(3);

	REQUIRE_NOTHROW(list.remove(0));

	CHECK(list.get_size() == 0);

}

TEST_SUITE_END();


TEST_SUITE_BEGIN("Insertion");

TEST_CASE("Inserting exceptions") 
{ 
	Doubly_linked list1;

	CHECK_THROWS(list1.insert(3, -1));
	CHECK_THROWS(list1.insert(4, 20));

};

TEST_CASE("Inserting in  empty list")
{
	Doubly_linked list2;

    CHECK(list2.get_size() == 0);
	REQUIRE_NOTHROW(list2.insert(1, 0));
    CHECK(list2.get_size() == 1);
	CHECK(*list2.begin() == 1 );
	CHECK(*list2.end() == 1);


};


TEST_CASE("Inserting head")
{
   Doubly_linked list2;
   REQUIRE_NOTHROW(list2.insert(0, 0));
   CHECK(*list2.begin() == 0 );

};

TEST_CASE("Inserting tail")
{
	Doubly_linked list2;
	list2.push(6);

	REQUIRE_NOTHROW(list2.insert(20, 1));
	CHECK(*list2.end() == 20 );;

};

TEST_SUITE_END();


TEST_CASE("Turning list into string") // throwing exception if the list is empty 
{
	Doubly_linked list1, list2;
    list2.push(0);
    list2.push(1);
    list2.push(2);

	REQUIRE_THROWS(list1.to_string());
	CHECK(list2.to_string().compare("0 1 2") == 0); //returns 0 if the strings are equal
};

TEST_CASE("Delete every third: empty list")
{
	Doubly_linked list1;

	CHECK_THROWS(list1.delete_every_third());

};

TEST_CASE("Delete every third including tail") 
{
    Doubly_linked list3;

	REQUIRE_NOTHROW(list3.push(1));
	REQUIRE_NOTHROW(list3.push(2));
	REQUIRE_NOTHROW(list3.push(3));
	
	CHECK(list3.get_size() == 3);

    REQUIRE_NOTHROW(list3.delete_every_third());

    CHECK(*list3.end() == 2);

};


TEST_SUITE_BEGIN("Iterator");

TEST_CASE("Iterator begin and end") // list3 == [1,2]
{
	Doubly_linked list4;
	Doubly_linked list3;

	REQUIRE_NOTHROW(list4.begin());
	REQUIRE_NOTHROW(list4.end());

	REQUIRE_NOTHROW(list3.begin());
	REQUIRE_NOTHROW(list3.end());
};

TEST_CASE("Increment operator")
{ 
	Doubly_linked list3;
	list3.push(20);
	list3.push(15);

	Doubly_linked::List_Iterator iter = list3.begin();

    CHECK(*iter == 20);
	REQUIRE_NOTHROW(++iter);
    CHECK(*iter == 15);
};

TEST_CASE("Increment operator exceptions")
{
   Doubly_linked list;
   list.push(1);
   Doubly_linked::List_Iterator iter = list.begin();
   CHECK(*iter == 1);
  
   REQUIRE_THROWS(++iter);
};

TEST_CASE("Decrement operator")
{
   Doubly_linked list;
   list.push(14);
   list.push(19);

   Doubly_linked::List_Iterator iter = list.end();
   CHECK(*iter == 19);

   REQUIRE_NOTHROW(--iter);
   CHECK(*iter == 14);
};

TEST_CASE("Decrement operator exceptions")
{
  Doubly_linked list;
  list.push(20);

  Doubly_linked::List_Iterator iter = list.end();

  CHECK(*iter == 20);
  REQUIRE_THROWS(--iter);
};

TEST_CASE("* pointer exception") 
{
   Doubly_linked list;
   Doubly_linked::List_Iterator iter = list.end();

   REQUIRE_THROWS(*iter); 

};


TEST_SUITE_END();