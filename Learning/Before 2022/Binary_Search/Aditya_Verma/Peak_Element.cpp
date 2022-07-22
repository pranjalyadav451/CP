#include<bits/stdc++.h>
using namespace std;


/* The function should return the index of any
   peak element present in the array */

class Solution
{
public:
	int peakElement(int arr[], int n) {
		int left = 0 , right = n - 1 , mid = 0, ans = -1;
		while (left <= right) {
			mid = left + (right - left) / 2;

			int prev = mid > 0 ? mid - 1 : mid, next = next < n - 1 ? mid + 1 : mid;
			if (arr[mid] >= arr[prev] and arr[mid] >= arr[next]) {
				ans = mid;
				break;
			}
			else {
				if (arr[prev] > arr[next]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
		}
		return ans;
	}
};


int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], tmp[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			tmp[i] = a[i];
		}
		bool f = 0;
		Solution ob;

		int A = ob. peakElement(tmp, n);

		if (A<0 and A >= n)
			cout << 0 << endl;
		else
		{
			if (n == 1 and A == 0)
				f = 1;
			else if (A == 0 and a[0] >= a[1])
				f = 1;
			else if (A == n - 1 and a[n - 1] >= a[n - 2])
				f = 1;
			else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
				f = 1;
			else
				f = 0;
			cout << f << endl;
		}

	}

	return 0;
}