#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int q, d;
		cin >> q >> d;

		for (int i = 0; i < q; i++)
		{
			int flag = 0;
			int x;
			cin >> x;
			if (x >= d * 10)
				flag = 1;
			if (flag == 0)
			{
				while (x >= d)
				{
					if (x % d == 0)
					{
						flag = 1;
						break;
					}
					x -= 10;
				}
			}
			if (flag)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}