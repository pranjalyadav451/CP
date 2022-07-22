#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
	set<int> left_side;
	int N = A.size();
	
	vector<int> max_from_right(N);
	max_from_right[N -1] = A[N -1];
	for (int i = N - 2; i >= 0; i--) {
		max_from_right[i] = max(max_from_right[i + 1], A[i]);
	}

	left_side.insert(A[0]);
	int ans = 0;
	for (int i = 1; i < N - 1; i++) {
		auto just_smaller = left_side.lower_bound(A[i]);
		if(just_smaller!=left_side.begin()){
			just_smaller--;
		}
		int on_right = max_from_right[i + 1];

		if (just_smaller != left_side.end() and *just_smaller < A[i] and on_right > A[i]) {
			ans = max(ans, *just_smaller + A[i] + on_right);
		}
		left_side.insert(A[i]);
	}
	return ans;
}




int main() {
	int N = 0; cin >> N;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ans = solve(A);
	cout << ans << endl;
}