#include <bits/stdc++.h>
using namespace std;

#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl



int solve(vector<int> &A, int B) {
	int left = 0 , right = A.size() - 1, mid = 0 , ans = 0;
	int N = A.size();
	int peak_idx = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		int pre = mid > 0 ? mid - 1 : mid, next = next < N - 1 ? mid + 1 : mid;

		// dbgg(left, right);
		// dbgg(A[pre], A[next]);
		// dbg(A[mid]);
		// dbgg(peak_idx, mid);
		// cout << endl;

		if (A[mid] > A[pre] and A[mid] > A[next]) {
			peak_idx = mid;
			break;
		}
		if (A[pre] > A[next]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "peak idx : " << peak_idx << endl;
	left = 0, right = peak_idx , mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (B == A[mid]) return mid;
		else {
			if (B > A[mid]) left = mid + 1;
			else right = mid - 1;
		}
	}
	left = peak_idx + 1, right = N - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (B == A[mid]) return mid;
		else {
			if (B > A[mid]) right = mid - 1;
			else left = mid + 1;
		}
	}
	return -1;
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