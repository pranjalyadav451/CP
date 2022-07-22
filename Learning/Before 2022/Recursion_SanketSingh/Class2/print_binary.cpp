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
void printBinary(int n, int prev = -1, string s = "")
{
	if (n == 0)
	{
		cout << s << endl;
	}
	else if (prev == 1)
	{
		printBinary(n - 1, 0, s + "0");
	}
	else
	{
		printBinary(n - 1, 0, s + "0");
		printBinary(n - 1, 1, s + "1");
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
		printBinary(n);
		cout << endl;
	}
}
