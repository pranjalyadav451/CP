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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;

		if (a == b)
		{
			cout << "YES\n";
			continue;
		}

		int zero = 0;
		int one = 0;

		for (int i = 0; i < n; i++)
			if (a[i] == '1')
				one++;
			else
				zero++;

		int f = 1;
		bool changed = false;
		for (int i = n - 1; i >= 0; i--)
		{
			//cout<<a[i]<<" "<<b[i]<<" "<<changed<<" "<<i<<" p\n";
			if ((a[i] != b[i] && !changed) || (a[i] == b[i] && changed))
			{
				if (zero == one)
					changed = !changed;
				else
				{
					f = 0;
					break;
				}
			}
			if (a[i] == '1')
				one--;
			else
				zero--;
		}

		if (f == 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}