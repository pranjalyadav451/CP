#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> firstAndLast(vector<int> &arr, int n, int x) {
		int left = 0, right = n - 1, mid = 0, ans = -1;
		vector<int> res;

		while (left <= right) {
			mid = left + (right - left) / 2;
			if (arr[mid] == x) {
				ans = mid;
			}
			else if (arr[mid] > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (ans == -1) { return {};}
		else {
			int start = ans , end = ans;
			while (arr[start] == x and start >= 0) {start--;}
			while (arr[end] == x and end < n) {end++;};
			res = {start + 1, end - 1};
			return res;
		}
	}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		Solution obj;
		vector<int> ans = obj.firstAndLast(arr, n, x) ;
		for (int i : ans) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
