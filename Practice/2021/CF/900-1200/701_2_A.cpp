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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		ll a, b;
		cin >> a >> b;

		int current = 0, prev = INT_MAX, temp = a, iter = 0;

		for (int i = b == 1 ? 2 : b ; ; i++)
		{
			current = 0;
			temp = a;
			while (temp > 0)
			{
				temp /= i;
				current++;
			}
			if (current + iter > prev)
				break;
			prev = current + iter;
			iter++;
		}

		if (b == 1)
			cout << prev + 1 << endl;
		else
			cout << prev << endl;

	}
}