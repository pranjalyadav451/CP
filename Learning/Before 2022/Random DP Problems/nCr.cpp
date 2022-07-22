// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++
#define ull unsigned long long
#define MOD 1000000007
long long int dp[1000 + 1][800 + 1];
class Solution {
public:
    Solution()
    {
        int n = 1000, r = 800;

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        long long var = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i and j <= 800; j++)
            {
                dp[i][j] = (dp[i - 1][j] % MOD + dp[i - 1][j - 1] % MOD) % MOD;
            }
        }
    }


    int nCr(int n, int r)
    {



        return dp[n][r];
    }//735309323
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
}  // } Driver Code Ends