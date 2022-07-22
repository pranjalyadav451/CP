#include<bits/stdc++.h>
using namespace std;

constexpr int MAX = 30;
long long dp[MAX + 1][MAX + 1];

std::string find_kth(int A, int B, long long K) {
	if (A == 0) {
		return std::string(B, 'b');
	}
	if (B == 0) {
		return std::string(A, 'a');
	}
	if (K <= dp[A - 1][B]) {
		return std::string("a") + find_kth(A - 1, B, K);
	}
	else {
		return std::string("b") + find_kth(A, B - 1, K - dp[A - 1][B]);
	}
}

int main() {
	int A, B;
	long long K;
	std::cin >> A >> B >> K;
	dp[0][0] = 1;
	/*
	* Generating all the combinations of nCr
	*/
	for (int i = 0; i <= A; ++i) {
		for (int j = 0; j <= B; ++j) {
			if (i > 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if (j > 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	for (int i = 0; i <= A; i++) {
		for (int j = 0; j <= B; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	std::cout << find_kth(A, B, K) << '\n';
	return 0;
}

