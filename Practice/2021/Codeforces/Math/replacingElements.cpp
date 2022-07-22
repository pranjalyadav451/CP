#include <bits/stdc++.h>

using namespace std;

string solve(int a[], int n, int d, bool areAllSmall)
{
	string ans = "NO";
	sort(a, a + n);
	if (areAllSmall or a[0] + a[1] <= d)
		ans = "YES";
	return ans;
}

int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		int n, d;
		cin >> n >> d;

		bool areAllSmall = true;

		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > d)
				areAllSmall = false;
		}
		cout << solve(a, n, d, areAllSmall) << endl;
	}
	return 0;
}