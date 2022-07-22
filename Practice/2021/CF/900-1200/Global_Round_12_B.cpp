#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;
bool comp(pair<int, int>a, pair<int, int>b)
{
	return (a.ff + a.ss < b.ff + b.ss);
}

const int N = 1e2 + 1;
int T[N];

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}



string solve(vector<pair<int, int>> &pnts, int n, int k)
{
	int fwd = 0, bwd = 0, reach = 0, diff = 0;
	for (int i = 0; i < n; i++)
	{
		fwd = i + 1; bwd = i;
		reach = 0;
		while (fwd < n)
		{
			diff = abs(pnts[i].ff - pnts[fwd].ff) + abs(pnts[i].ss - pnts[fwd].ss);
			if (diff <= k)
				reach++;
			else
				break;
			fwd++;
		}
		while (bwd >= 0)
		{
			if (abs(pnts[i].ff - pnts[bwd].ff) + abs(pnts[i].ss - pnts[bwd].ss) <= k)
				reach++;
			else
				break;
			bwd--;

		}
		T[i] = reach;
	}

	for (int i = 0; i < n; i++)
		if (T[i] == n)
			return "1";


	return "-1";
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
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>>pnts(n);
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			pnts[i] = {x, y};
		}
		// sort(pnts.begin(), pnts.end(), comp);
		memset(T, 0, sizeof(T));
		cout << solve(pnts, n, k) << endl;

	}
}



/*
* ->Editorial -:
	We claim the answer is always −1 or 1. **the main point of

	In fact, suppose in the first operation of a solution we select a point p. If we aren't done, there will at least one point with distance more than k from p. However, there will be no point within distance k of p, no matter how we perform future operations. So it is impossible for p to merge with a new point, and a solution with more than 1 operation will be impossible.

	To see if the answer is 1, we should check if there is some point p within distance k from all other points. Otherwise, the answer is −1. Complexity is O(n2) to compute pairwise distances.
*/


/* -> 1gon's Code -:

while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(n);
		for (auto &i : a)
			cin >> i.first >> i.second;
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			int mx = 0;
			for (int j = 0; j < n; ++j) {
				mx = max(mx, abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
			}
			if (mx <= k) ans = 1;
		}
		cout << ans << "\n";
*/
