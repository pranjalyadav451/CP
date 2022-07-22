#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

string solve(vector<ll> &arr, int n)
{
	bool isFirst = true;
	int nOnes = 0;

	if (arr[0] == 1) {
		nOnes++;
		isFirst = false;
	}

	for (int i = 0; i < n; i++)
	{
		if (nOnes != 0 and arr[i] == 1)
		{
			nOnes++;
			isFirst = !isFirst;
		}
		else
			break;
	}

	if (nOnes == n)
		return isFirst ? "Second" : "First";
	else
		return isFirst ? "First" : "Second";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int n;
		cin >> n;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve(arr, n);
		cout << endl;
	}
}


/*
	Editorial :
		Suppose a1>1. If removing the entire first pile is winning, player 1 will do that. Otherwise, player 1 can leave exactly one stone in the first pile, forcing player 2 to remove it, leaving player 1 in the winning position. Otherwise, if a1=1, then it is forced to remove the first pile.

		So, whichever player gets the first pile with more than one stone wins. That is, let k be the maximum number such that a1=⋯=ak=1. If k is even, the first player will win. Otherwise, the second player will win. The only exception is when all piles have exactly 1 stone. In that case, the first player wins when k is odd.

		Complexity is O(n).
*/