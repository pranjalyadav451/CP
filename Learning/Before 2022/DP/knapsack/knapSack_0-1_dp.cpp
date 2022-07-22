#include <bits/stdc++.h>
#define ll long long
using namespace std;

int knapSack(int w, int wt[], int val[], int n)
{
  int dp[n + 1][w + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {
      if (wt[i - 1] <= j)
      {
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  //printing the matrix
  // for (int i = 0; i < n + 1; i++)
  // {
  //     for (int j = 0; j < w + 1; j++)
  //     {
  //         cout << "| ";
  //         cout << dp[i][j] << " ";
  //     }
  //     cout << endl
  //          << "---------------------" << endl;
  // }

  return dp[n][w];
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for (int i = 0; i < n; i++)
      cin >> val[i];
    for (int i = 0; i < n; i++)
      cin >> wt[i];
    cout << knapSack(w, wt, val, n) << endl;
  }
  return 0;
}