#include <bits/stdc++.h>
using namespace std;

#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl



int solve(vector<int> &A, int B) {
	int left = 0 , right = A.size() - 1, mid = 0, ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (A[mid] <= B) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	return ans == -1 ? A.size() : ans;
}

int main() {
	int N, B; cin >> N >> B;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = solve(arr, B);
	cout << ans << endl;
}