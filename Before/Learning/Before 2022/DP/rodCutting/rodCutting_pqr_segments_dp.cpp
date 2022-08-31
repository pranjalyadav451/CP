// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;

        //calling function maximizeTheCuts()
        cout << maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends

//Complete this function
int dp[4][10001];
int solve(int len, int arr[], int size)
{
    int dp[size + 1][len + 1];

    for (int j = 0; j <= len; j++)
        dp[0][j] = -1;

    for (int i = 0; i <= size; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            if (arr[i - 1] <= j and dp[i][j - arr[i - 1]] != -1)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - arr[i - 1]] + 1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[size][len] == -1 ? 0 : dp[size][len];
}

int maximizeTheCuts(int n, int x, int y, int z)
{

    int arr[] = {x, y, z};
    return solve(n, arr, 3);
}