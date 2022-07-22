// TODO : Do this and then do any other thing.
#include<bits/stdc++.h>
using namespace std;

class BIT {
public:
	vector<long long> bit;
	long long N;
	BIT(int size) {
		N = size;
		bit.assign(N + 1, 0);
	}
	long long sum(long long i) {
		long long ans = 0;
		for (; i >= 1; i -= i & (-i)) {
			ans += bit[i];
		}
		return ans;
	}
	void update(long long i, long long x) {
		for (; i <= N; i += i & (-i)) {
			bit[i] += x;
		}
	}
};

int main() {
	int tt;
	while (tt--) {

	}
}