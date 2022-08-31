#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define MOD 1000000007
using namespace std;

string solve(ll a, ll b, vector<pair<int, int>>&mosnters)
{

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		ll a, b;
		cin >> a >> b;
		int n;
		cin >> n;

		int mPower = 0;
		int mHealth = 0;


		ll mTotalH = 0;
		ll mTotalA = 0;

		vector<pair<int, int>>monsters(n);
		for (int i = 0; i < n; i++)
		{
			cin >> mPower;
			cin >> mHealth;

			mTotalA += mPower;
			mTotalH += mHealth;

			monsters[i] = mp(mPower, mHealth);
		}
		cout << solve(a, b, monsters) << endl;
	}
}
