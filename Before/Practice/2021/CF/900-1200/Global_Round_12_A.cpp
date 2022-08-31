#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		string forT, other;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == 't')
				forT.push_back('t');
			else
				other.push_back(s[i]);
		}
		cout << other + forT << endl;
	}
}

/*
	-> Another great editorial -:
	 The string "trygub" is not sorted alphabetically, and a subsequence of a sorted string is necessarily sorted. So, if we sort the input string, it will be a solution. Complexity is O(n) with counting sort.
*/