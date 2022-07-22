// Cool Question


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

bool isBad(vector<int>& v)
{
	int s = 0;
	for (int i : v)
		s += i;
	if (s % 2)
		return 0;

	bitset<200005> b;
	b[0] = 1;
	for (int i : v)
		b |= (b << i);
	return b[s / 2];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}



	if (not isBad(arr))
		cout << 0 << endl;
	else
	{
		pair<int, int> mn = {31, -1};

		for (int i = 0; i < n; i++)
		{
			mn = min(mn, {__builtin_ctz(arr[i]), i + 1});
		}
		cout << 1 << endl;
		cout << mn.ss << endl;
	}


}

/*
    Notes -:
    	-> concept of bit masking. e.g. - subset sum problem using bitset and bit masking.
    	-> __builtin_ctz(x) - counts the number of trailing zeroes in bit representation of x.

*/