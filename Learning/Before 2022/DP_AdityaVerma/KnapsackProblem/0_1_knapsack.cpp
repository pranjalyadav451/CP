#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
	int maxValue = 0;
	if (n == 0 or W == 0)
		return 0;
	else
	{
		if (wt[n - 1] <= W)
			maxValue += max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
		else
			maxValue += knapSack(W, wt, val, n - 1);

		return maxValue;
	}
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, w;
		cin >> n >> w;
		int val[n];
		int wt[n];
		for (int i = 0; i < n; i++)
			cin >> val[i];
		for (int i = 0; i < n; i++)
			cin >> wt[i];
		cout << knapSack(w, wt, val, n) << endl;
	}
	return 0;
}