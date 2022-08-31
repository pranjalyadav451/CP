// https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1/?category[]=Greedy
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

	int minOperation(int n) {
		int dp[n + 1];
		dp[0] = 0 , dp[1] = 1 , dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			if (i % 2 == 0) {
				dp[i] = 1 +  min(dp[i / 2] , dp[i - 1]);
			}
			else {
				dp[i] = dp[i - 1] + 1;
			}
		}
		int ans = dp[n];
		return ans;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Solution ob;
		cout << ob.minOperation(n) << endl;
	}
}