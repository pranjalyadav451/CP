#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int left, int right)
{
	//base case when left == right
	if (left == right)
		return true;
	else
	{
		if (arr[left] < arr[left + 1] && left + 1 <= right)
		{
			return isSorted(arr, left + 1, right);
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		if (isSorted(arr, 0, n - 1))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}
