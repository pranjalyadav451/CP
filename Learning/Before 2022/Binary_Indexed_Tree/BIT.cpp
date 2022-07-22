#include<bits/stdc++.h>
using namespace std;

// To find the rightmost set bit
/*
	-X = 2's complement of X.
	X & (-X) -> only the rightmost bit of X is set.

	To remove the rightmost bit from X :
	X = X - (X&(-X))


	// what will the bit array store.

	bit[i] -> will store the sum from j + 1 to i
	where j => number formed by removing the rightmost set bit from i

*/


class BIT {
	long long N;
	vector<long long> bit;

	BIT(long long size) {
		N = size + 1;
		bit.assign(N, 0);
	}
	long long sum(long long i) {
		long long ans = 0;
		for (; i > 0; i -= (i & -i)) {
			ans += bit[i];
		}
	}
	void update(long long i , long long x) {
		for (; i <= N; i += i & (-i)) {
			bit[i] += x;
		}
	}

};

int main() {

}