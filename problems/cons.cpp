#include "cons.h"
using namespace std;

int Consistent_Hash::get_hash(string key)
{
    int hash = 0;

    for(int i = 0; i < key.length(); i++)
    {
    	hash = (hash + key[i] + 4)%med;
    }

   return hash%med;

}

void Consistent_Hash::add_server()
{
	map <int, int> new_s;
	Elem new_el({med-1, med-1, new_s});

	if((int)load.size() == 0)
	{
		new_el.left = 0;
	}

	load.push_back(new_el);

	int amount = (int)load.size();
	int range = size/amount;

	for(int i = amount - 1; i > 0; i--)
	{
		while(load[i].server.size() < range)
		{	
			load[i].server[load[i-1].server.rbegin()->first] = load[i-1].server.rbegin()->second;
			load[i].left = load[i].server.begin()->first;
            		load[i-1].right = load[i-1].server.rbegin()->first;
            		load[i-1].server.erase(load[i].server.begin()->first);
		};
	}

}

void Consistent_Hash::delete_server()
{
	int amount = (int)load.size();

	if (amount == 1)
	{
		throw out_of_range("One server in total");
	}

	load[amount-2].right = med-1;

        for(auto it:load[amount-1].server)
        {
    	        load[amount-2].server[it.first] = it.second;

        }

        load.pop_back();

}

void Consistent_Hash::add_node(string key, int data)
{
	int hash = get_hash(key);

	int left_lim = 0;
	int right_lim = load.size();
	int pos = 1;

    	while(left_lim < right_lim && load.size()-1)
    	{

    	        pos = (left_lim+right_lim)/2;

    	        if(load[pos].left < hash)
    	        {
                left_lim = pos + 1;
    	        }

                else
                {
                        right_lim = pos-1;
                }
	}

	pos--;

	size++;

	load[pos].server[hash] = data;

}

int Consistent_Hash::search(string key)
{

	int hash = get_hash(key);

	int left_lim = 0;
	int right_lim = load.size();
	int pos = 1;

        while(left_lim < right_lim && load.size()-1)
        {

    	        pos = (left_lim+right_lim)/2;

    	        if(load[pos].left < hash)
    	        {
                        left_lim = pos + 1;
    	        }

                 else
                {

                        right_lim = pos-1;
                }
        }

	pos--;

	auto it = load[pos].server.lower_bound(hash);

        if(it->first == hash)
        {
            return it->second;
        }

         throw invalid_argument("No such key present");

}

void Consistent_Hash::delete_record(string key)
{
	int hash = get_hash(key);

	int left_lim = 0;
	int right_lim = load.size();
	int pos = 1;

        while(left_lim < right_lim && load.size()-1)
        {

    	        pos = (left_lim+right_lim)/2;

    	        if(load[pos].left < hash)
    	        {
                        left_lim = pos + 1;
    	        }

                else
                {

                        right_lim = pos-1;
                }

        }

	pos--;

	auto it = load[pos].server.lower_bound(hash);

        if(it->first == hash)
        {
            load[pos].server.erase(hash);
            size--;
            return;
        }

    throw invalid_argument("Impossible to delete non-existing element");

}
