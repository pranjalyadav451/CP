#include<bits/stdc++.h>
using namespace std;
// this is not a dp problem because of the fact that
// I could do this in constant space and linear time
// with two pointer method.
// This might be solvable using the dp approach but
// there is no need for that.
int solve(int arr[], int n)
{
	int left = 0, right = 0;
	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[right] >= arr[i])
		{
			maxLen = max(maxLen, right - left + 1);
			left = i;
			right = i;
		}
		else
		{
			right = i;
		}
		maxLen = max(right - left + 1, maxLen);

	}
	return maxLen;

}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve(arr, n) << endl;
}
