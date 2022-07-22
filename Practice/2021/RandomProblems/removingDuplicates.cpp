#include <bits/stdc++.h>
using namespace std;
vector<int> removeDuplicates(int *a, int size)
{
	vector<int> out;
	unordered_map<int, bool> seen;
	for (int i = 0; i < size; i++)
	{
		if (seen.count(a[i]) != 0)
		{
			continue;
		}
		//inserting the values in the hashmap
		//time complexity -> O(n)
		seen[a[i]] = true;
		out.push_back(a[i]);
	}
	return out;
}
int main()
{
	//Problem - we have to find the create a new array of
	//distinct elements from an array containing duplicates
	int a[] = {1, 2, 3, 4, 2, 2, 1, 3, 5};
	int size = 9;
	vector<int> print = removeDuplicates(a, size);
	for (auto i : print)
		cout << i << "  ";
}
