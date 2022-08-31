#include<bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i,n) for(i=0;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

// we have to take care of the order of the participants
// I don't knwo any approach to thins problem right now.
bool comp(std::pair<int, int>a, std::pair<int, int>b)
{
	return a.second > b.second;
}
using namespace std;
void solve(vec<pair<int, int>>&sr)
{
	sort(sr.begin(), sr.end(), comp);
	vector<int>res;
	int decide = sr[0].second;
	res.pb(sr[0].first);
	for (int i = 1; i < sr.size(); ++i)
	{
		if (decide == sr[i].second)
		{
			res.pb(sr[i].first);
		}
		else
			break;
	}
	sort(res.begin(), res.end());
	for (auto &a : res)
		cout << a << " ";
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);



	int testCase = 1;
	// cin >> testCase;
	while (testCase--)
	{
		// deb(testCase);
		int n;
		cin >> n;
		vec<pair<int, int>>sr(n, mp(0, 0));
		int swim = 0;
		int run = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> swim;
			cin >> run;
			sr[i] = mp(i + 1, swim + run);
		}
		solve(sr);
	}
}
