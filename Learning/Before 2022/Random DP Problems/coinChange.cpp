#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ll cnt = 0;

class Solution
{
public:
    /*
    N - amount
    M - number of different coins
    - we have infinite supply of coins of each type
*/
    long long int count(int arr[], int m, int n, int cnt = 0)
    {
        if (n == 0 and m == 0)
        {
            return 1;
        }
        else if (m == 0)
        {
            return 0;
        }
        else
        {
            if (arr[m - 1] <= n)
            {
                cnt += count(arr, m, n - arr[m - 1]);
                cnt += count(arr, m - 1, n);
            }
            else
            {
                cnt += count(arr, m - 1, n);
            }
            return cnt;
        }
        
    }
};

int main()
{
    int t;
    // cout << "hello" << endl;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}