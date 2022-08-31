#include <bits/stdc++.h>
#define ll long long

using namespace std;

int numSubsetGivenDiff(int n, int arr[], int target)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int upperLimit = sum / 2;
    bool dp[n + 1][upperLimit + 1];

    for (int i = 0; i <= upperLimit; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= upperLimit; j++)
        {
            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    vector<int> res;

    for (int i = 0; i <= upperLimit; i++)
    {
        if (dp[n][i])
        {
            res.push_back(i);
        }
    }

    cout << "sum =>" << sum << endl;
    for (size_t i = 0; i < res.size(); i++)
        cout << res[i] << " " << sum - res[i] << endl;
    cout << endl;

    int count = 0;

    for (size_t i = 0; i < res.size(); i++)
    {
        if (sum - 2 * res[i] == target)
            count++;
    }
    return count;
}

int main()
{
    int tt = 1;
    cin >> tt;

    while (tt--)
    {
        int n;
        cin >> n;

        int target;
        cin >> target;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << numSubsetGivenDiff(n, arr, target) << endl;
    }
}
