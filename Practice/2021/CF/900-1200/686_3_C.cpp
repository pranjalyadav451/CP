#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;


		vector<int> res(n + 1, 1);
		/* For Keeping only one of the consecutive equal elements. */
		vector<int>unique;
		int prev = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != prev)
				unique.push_back(a[i]);
			prev = a[i];
		}
		n = unique.size();

		for (int i = 0; i < n; ++i) {
			res[unique[i]] += 1;
		}


		/**
		-> The left segment of a[0] does not exist and similarly,the right segment of a[n-1] doesn't exist.
		*/

		res[unique[0]] -= 1;
		res[unique[n - 1]] -= 1;


		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, res[unique[i]]);
		}
		cout << ans << endl;
	}

	return 0;
}

/*
	-> Was able to understand the problem and grasp the concept used
	-> Couldn't implement.

	**Notes
	-> Try to reduce the in a mathematical statement.
		- In this problem :
		-> Only one of the equal consecutive elements contributes to segment formation.
		-> No. of segments = n(Elements contributing to segment formation) + 1
		-> The left segment of a[0] does not exist and similarly,the right segment of a[n-1] doesn't exist.
*/