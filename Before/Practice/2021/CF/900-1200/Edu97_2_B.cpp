#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

using namespace std;

int minOps(string &arr, int n)
{
	int cz = 0;
	int co = 0;
	arr.pb('.');
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1] and arr[i] == '0')
			cz++;
		if (arr[i] == arr[i + 1] and arr[i] == '1')
			co++;
	}

	return max(co, cz);

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
		string s;
		cin >> s;

		cout << minOps(s, n) << endl;
	}
}

/*
    Notes -:
*/