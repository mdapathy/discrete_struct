#include <iostream> 
#include "doubly_linked.h"
using namespace std;

int main(void)
{ 
  Doubly_linked list;
  unsigned number;

  cout << "Number of elements in a doubly linked list: ";
  cin >> number;
  
  for (int i = 0; i < number; i++)
  {
  	int object;
  	cin >> object;
  	list.push(object);
  }

  cout << list.to_string() << endl;
  cout << "Size before the deletion: " << list.get_size() << endl ;

  list.delete_every_third();

  cout << list.to_string() << endl;
  cout <<"Size after the deletion: "  << list.get_size() << endl;

  return 0;
}
