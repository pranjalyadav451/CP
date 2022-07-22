#include <bits/stdc++.h>
using namespace std;

// Recursive Function
int minCoins(int coins[], int m, int N)
{
    // base case
    if (N == 0)
        return 0;
    if (N != 0 and m == 0)
        return INT_MAX;
    //   int res = INT_MAX;

    //   for (int i=0; i<m; i++)
    //   {
    //     if (coins[i] <= N)
    //     {
    //       int sub_res = 1 + minCoins(coins, m, N-coins[i]);
    //       // see if result can minimized
    //       if (sub_res < res)
    //         res = sub_res;
    //     }
    //   }

    if (coins[m - 1] <= N)
    {
        return min(minCoins(coins, m, N - coins[m - 1]) + 1, minCoins(coins, m - 1, N));
    }
    else
        return minCoins(coins, m - 1, N);

    //   return res;
}

int main()
{
    int coins[] = {1, 2, 3, 4, 5};
    int sum = 11;
    int total_coins = 5;
    cout << minCoins(coins, total_coins, sum);
}