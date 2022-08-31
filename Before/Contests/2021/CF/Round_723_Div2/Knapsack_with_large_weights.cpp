#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define ld              long double
#define ll              long long int
#define pb              push_back
#define mp              make_pair
#define pll             pair<ll,ll>
#define vll             vector<ll>
#define mll             map<ll,ll>
#define all(a)          (a).begin(), (a).end()
#define setbits(x)      __builtin_popcountll(x)
#define md              1e9 +7
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define f(i,j,n)        for(ll i=j;i<n;i++)
#define f1(i,j,n)       for(ll i=j;i<=n;i++)
#define forn(i,n)       for(i=0;i<n;i++)
#define for1(i,n)       for(i=1;i<=n;i++)
#define r(i,j,n)        for(ll i=n-1;i>=j;i--)
#define endl            "\n"

void solve()
{
	ll n, k, i;
	cin >> k >> n;

	ll w[n + 1], v[n + 1];
	forn(i, n)
	cin >> v[i] >> w[i];

	ll dp[k + 1];
	memset(dp, 0, sizeof(dp));

	forn(i, n)
	{
		for (int j = k; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[k];
}


int32_t main()
{
	ios_base::sync_with_stdio(false);   cin.tie(NULL);
#ifndef ONLINE_JUDGE
#endif
//   freopen("input03.txt", "r", stdin);
//   freopen("op.txt", "w", stdout);
	// ll test_cases=1; cin>>test_cases;
	// for(ll t=1;t<=test_cases;t++)
	solve();
// cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
	return 0;
}