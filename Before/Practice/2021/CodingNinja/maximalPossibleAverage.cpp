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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);



	int testCase = 1;
	// cin >> testCase;
	while (testCase--)
	{
		int n;
		int k;
		cin >> n;
		cin >> k;
		double a[n];
		fo(i, n)
		cin >> a[i];




		// vector<pair<int, double>> av;
		double init = 0;
		fo(i, k)
		{
			init += a[i];
		}
		long double initialAverage = double(init) / double(k);

		long double temp = 0;
		long double maxa = initialAverage;
		for (int i = 0; i <= n - k; i++)
		{
			deb(i);
			for (int j = i + k; j < n; j++)
			{
				temp = init + a[j];

				temp = ((double)(temp)) / ((double)(j - i + 1));
				maxa = max(maxa, temp);
			}
			init = init - a[i] + a[i + k ];
		}
		std::cout << std::setprecision(6) << std::fixed;
		maxa = trunc(maxa * 1000000) / 1000000;
		cout << maxa << endl;


	}
}
