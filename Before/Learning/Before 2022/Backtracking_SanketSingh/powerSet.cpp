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
vec<int> print;
void powerSet(std::vector<int> &t, int j = 0)
{
	if (j > t.size() - 1)
	{
		if (print.size() != 0)
			for (int i = 0; i < print.size(); i++)
				cout << print[i] << " ";
		else
			cout << "is empty";
		cout << endl;
		return;
	}

	print.push_back(t[j]);
	powerSet(t, j + 1);
	print.pop_back();
	powerSet(t, j + 1);

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
		vec<int> test(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> test[i];
		}
		powerSet(test);
	}
}
