#include <iostream>
#include "singly_linked.h"
using namespace std;

int main()
{
  Singly_linked list;
  unsigned amount;

  cout << "Number of elements: ";
  cin >> amount;

  for (int i = 1; i <= amount ; i++)
  {
    int number;
    cin >> number;
    list.push(number);
  }
  
  cout << "Size before the deletion : " << list.get_size() << endl;

  list.delete_every_third();

  cout << "Size after the deletion : " << list.get_size()  << endl;
  return 0;

}
