// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int dp[1001][1001];

void printList(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    // cout << endl;
}

class Solution
{
public:
    string printLcs(int x, int y, string s1, string s2)
    {
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }


        for (int i = 0; i <= x; i++) {
            printList(dp[i], y + 1);
        }
        cout << endl;
        string res;



        for (int i = x, j = y; i >= 1 && j >= 1;) {
            if (s1[i - 1] == s2[j - 1])
            {
                res.push_back(s1[i - 1]);
                i--; j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.printLcs(x, y, s1, s2) << endl;
    }
    return 0;
}