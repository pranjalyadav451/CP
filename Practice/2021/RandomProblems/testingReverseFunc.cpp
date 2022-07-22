// this was the problem on leetcode to rotate an array k steps to the right

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a)
{
	for (auto &i : a)
		cout << i << "  ";
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> rev = a;

		k = k % n;

		// the last k characters are going to
		// be pushed in the front part
		// I have to prove this

		reverse(a.begin(), a.begin() + n - k);
		print(a);
		reverse(a.begin() + n - k, a.end());
		print(a);
		reverse(a.begin(), a.end());
		print(a);

		cout << "------------" << endl;

		reverse(rev.end() - k, rev.end());
		print(rev);
		reverse(rev.begin(), rev.end() - k);
		print(rev);
		reverse(rev.begin(), rev.end());
		print(rev);
		cout << "------------" << endl;
	}
	return 0;
}
