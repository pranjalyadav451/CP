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
void subset(int a[], int n, int i = 0, string s = "{")
{
	if (i == n)
	{
		if (s.empty() == false)
			cout << s << "}" << endl;
		else
		{
			cout << "{ }" << endl;
		}
	}
	else
	{
		subset(a, n, i + 1, s + to_string(a[i]) + "," );
		subset(a, n, i + 1, s);
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
		int n;
		cin >> n;
		int arr[n];
		fo(i, n)
		cin >> arr[i];
		subset(arr, n);
	}
}
