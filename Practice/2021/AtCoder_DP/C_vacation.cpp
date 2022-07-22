#include <bits/stdc++.h>
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

const int N = 1e5 + 10;

// int dp[3][N];
// int solve(int arr[][3], int n)
// {
//     memset(dp, 0, sizeof(dp));

//     int a, b, c;
//     cin >> a >> b >> c;

//     dp[0][0] = a;
//     dp[1][0] = b;
//     dp[2][0] = c;

//     for (int i = 1; i < n; i++)
//     {
//         cin >> a >> b >> c;

//         dp[0][i] = a + max(dp[1][i - 1], dp[2][i - 1]);
//         dp[1][i] = b + max(dp[2][i - 1], dp[0][i - 1]);
//         dp[2][i] = c + max(dp[1][i - 1], dp[0][i - 1]);
//     }

//     return max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
// }



// int solve_rec(int arr[][3], int n, int prev = -1)
// {
//     if (n == 0)
//         return 0;
//     else
//     {
//         if (prev == -1)
//         {
//             return max({arr[n - 1][0] + solve_rec(arr, n - 1, 0), arr[n - 1][1] + solve_rec(arr, n - 1, 1), arr[n - 1][2] + solve_rec(arr, n - 1, 2)});
//         }

//         if (prev == 0)
//         {
//             return max(arr[n - 1][1] + solve_rec(arr, n - 1, 1) , arr[n - 1][2] + solve_rec(arr, n - 1, 2));
//         }
//         if (prev == 1)
//         {
//             return max(arr[n - 1][0] + solve_rec(arr, n - 1, 0) , arr[n - 1][2] + solve_rec(arr, n - 1, 2));

//         }
//         if (prev == 2)
//         {
//             return max(arr[n - 1][1] + solve_rec(arr, n - 1, 1) , arr[n - 1][0] + solve_rec(arr, n - 1, 0));
//         }
//     }
// }




int solve_rec1(int arr[][3], int n, int prev = -1)
{
    if (n == 0)
        return 0;
    else
    {
        int mx = 0;
        for (int i = 0; i < 3; i++)
        {
            if (prev != i)
                mx = max ( mx , arr[n - 1][i] + solve_rec1(arr, n - 1, i));
        }
        return mx;
    }
}

int dp[3][N];


int solve_memo(int arr[][3], int n, int prev = -1)
{
    if (n == 0)
        return 0;
    else
    {
        int mx = 0, i = 0, temp = 0;

        for (i = 0; i < 3; i++)
        {
            if (prev != i)
            {
                if (dp[i][n - 1] != -1)
                    temp =  dp[i][n - 1];
                else
                    dp[i][n - 1] = temp = solve_memo(arr, n - 1, i);

                mx = max ( mx , arr[n - 1][i] + temp);
            }
        }

        return  mx;
    }

}


// int solve(int arr[][3], int n)
// {
//     memset(dp, 0, sizeof(dp));

//     // int init_max = max({arr[0][0], arr[0][1], arr[0][2]});

//     dp[1][1] = arr[0][0];
//     dp[2][1] = arr[0][1];
//     dp[3][1] = arr[0][2];


//     for (int i = 1; i <= 3; i++)
//     {
//         for (int j = 2; j <= n; j++)
//         {
//             if (i == 1)
//             {
//                 dp[i][j] = dp[i][j - 1] + max(arr[j - 1][1], arr[j - 1][2]);
//             }
//             if (i == 2)
//             {
//                 dp[i][j] =  dp[i][j - 1] + max(arr[j - 1][0], arr[j - 1][2]);
//             }
//             if (i == 3)
//             {
//                 dp[i][j] = dp[i][j - 1] + max(arr[j - 1][0], arr[j - 1][1]);
//             }
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return max({dp[1][n], dp[2][n], dp[3][n]});


// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[n][3];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve_memo(arr, n) << endl;
}