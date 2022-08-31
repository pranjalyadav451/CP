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

const int N = 2e5;

vector<ll> arr(N);

/*
	--> Russell decided that an explorer with inexperience e can only join the group of e or more people.
	--> Not all explorers need to go in groups, some can stay at the camp too.
*/

int solve(int n)
{
	sort(arr.begin(), arr.begin() + n);

	int len = 1;
	int count = 0;

	for (int i = 0; i < n;)
	{
		while (len < arr[i] and i < n)
		{
			len++;
			i++;
		}
		if (len == arr[i])
		{
			count++;
			len = 1;
		}
		i++;
	}
	return count;
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
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cout << solve(n);
		cout << endl;
	}
}