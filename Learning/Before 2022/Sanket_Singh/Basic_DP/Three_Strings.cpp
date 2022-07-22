/*
 * You are given three strings, find the longest common subsequence of the three strings.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl


const int mxn = 1e3 + 10;
int dp[mxn][mxn] = {0};

string lcs_helper(string &first, string &second) {
	int m = first.size(), n = second.size();
	// If any of the given strings has a length of zero, the length of lcs will be zero.\
	// Initialization :
	memset(dp, 0, sizeof(dp));

	// Building up the solution.
	for (int i = 1 ; i <= m ; i++) {
		for (int j = 1; j <= n ; j++) {
			if (first[i - 1 ] == second[j - 1]) { // keep track of the indices of the strings.
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// Retrieving the LCS
	string res;
	while (m >= 1 and n >= 1) {
		if (first[m - 1] == second[n - 1]) {
			res.push_back(first[m - 1]);

			m--, n--;
		}
		else {
			if (dp[m - 1][n] > dp[m][n - 1]) {
				m--;
			}
			else {
				n--;
			}
		}

	}
	reverse(res.begin(), res.end());
	return res;
}




void lcs(vector<string> &arr) {
	string first = arr[0], second = arr[1], third = arr[2];
	string res = lcs_helper(first, second);
	cout << res << endl;

}
// NOT COMPLETE
int main() {
	vector<string> arr(3);
	for (auto &A : arr) cin >> A;
	lcs(arr);
}