#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m, int res = 0)
    {
        if (n == 0 or m == 0)
            return 0;
        else
        {
            if (S1[n - 1] == S2[m - 1])
                return longestCommonSubstr(S1, S2, n - 1, m - 1, res + 1);

            return max(res, max(longestCommonSubstr(S1, S2, n - 1, m, 0), longestCommonSubstr(S1, S2, n, m - 1, 0)));
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
