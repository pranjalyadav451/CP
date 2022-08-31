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
void print_ans(vector<int>&arr, int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	// cout << endl;
}

void print(vector<int>&arr)
{
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}


void solve(vector<int>& arr, int n)
{
	vector<int>maxP;
	int mx = INT_MIN;
	int mxi = -1;

	for (int i = 0; i < n; i++)
	{
		if (mx < arr[i])
		{
			mx = arr[i];
			mxi = i;
		}
		maxP.push_back(mxi);
	}

	int start = -1;

	for (int i = n - 1; i >= 0;)
	{
		start = maxP[i];
		print_ans(arr, start, i);
		i = start - 1;
	}

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
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		// vector<int>res(n);
		solve(arr, n);
		cout << endl;

	}
}