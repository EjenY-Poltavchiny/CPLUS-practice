#include "hash.h"
#include <iostream>
#include <utility>
#pragma once

bool find(int x, std::vector<std::vector<int>> hash_table)
{
	int size = hash_table.size();
	for (auto& elem : hash_table[x % size])
	{
		if (elem == x)
		{
			return true;
		}
	}
	return false;
}

void add(int x, std::vector<std::vector<int>>& hash_table)
{
	int position = x % hash_table.size();
	if (!(find(x, hash_table)))
	{
		hash_table[position].push_back(x);
	}
	// rehash
	if (hash_table[position].size() > 2)	
	{
		rehash(hash_table);
	}
}

void del(int x, std::vector<std::vector<int>>& hash_table)
{
	int position = x % hash_table.size();
	if (hash_table[position].size() == 0)
	{
		std::cout << "There is no such element" << std::endl;
	}
	for (auto& elem : hash_table[position])
	{
		if (elem == x)
		{
			std::swap(hash_table[position].back(), elem);
			hash_table[position].pop_back();
			break;
		}
		// if there was no element to delete
		if (elem == hash_table[position].back())
		{
			std::cout << "There is no such element" << std::endl;
		}
	}
}

void rehash(std::vector<std::vector<int>>& hash_table)
{
	int old_size = hash_table.size();
	hash_table.resize(hash_table.size()*2);
	int counter = 1;
	int helper = 0;
	for (auto& pos : hash_table)
	{
		if (counter > old_size)
		{
			break;
		}
		for (size_t i = 0; i < pos.size(); ++i)
		{
			// if the same pos - leave hash_table without changing
			if (pos[i] % old_size == pos[i] % hash_table.size())
			{
				continue;
			}
			// delete from position
			helper = pos[i];
			std::swap(pos.back(), pos[i]);
			pos.pop_back();
			// add to new position
			add(helper, hash_table);
			
		}
		++counter;
	}
}