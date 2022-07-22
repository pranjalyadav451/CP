#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

struct BIT {

	llong N;
	vector<llong> bit;

	BIT(int size) {
		N = size;
		bit.assign(N + 1, 0);
	}

	llong sum(llong i) {
		llong ans = 0;
		for (; i >= 1; i -= (i & (-i))) {
			ans += bit[i];
		}
		return ans;
	}
	void update(llong i, llong x) {
		for (; i <= N; i += (i & (-i))) {
			bit[i] += x;
		}
	}
};

/*

*/


int main() {
	int N;
	cin >> N;
	vector<llong> arr(N);
	for (auto &a : arr)
		cin >> a;
	BIT fenwick(N);

	for (int i = 1; i <= N; i++) {
		fenwick.update(i, arr[i - 1]);
	}


	int queries; cin >> queries;

	while (queries--) {
		int q_type = 0; cin >> q_type;
		if (q_type == 1) {
			llong i , x;
			cin >> i >> x;
			fenwick.update(i, x - arr[i]);
		}
		else {
			llong i;
			cin >> i;
			cout << fenwick.sum(i) << endl;
		}
	}
}