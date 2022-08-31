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
#define fo(i,n) for(int i=0;i<n;i++)
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


using namespace std;
string s;
void pattern(int n, int i = 0)
{
	if (n == 1)
		cout << "x " << endl ;
	else
	{
		if (i < n)
		{
			cout << "x ";
			pattern(n, i + 1);
		}
		else
		{
			cout << endl;
			pattern(n - 1, 0);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);



	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n; cin >> n;
		pattern(n);
	}
}
