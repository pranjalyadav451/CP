#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[250][250];
    int wildCard(string pattern, string str) {
        int N = str.size(), M = pattern.size();
        for (int i = 1; i <= N; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= M; i++) {
            dp[0][i] = (dp[0][i - 1] and pattern[i - 1] == '*');
        }
        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (pattern[j - 1] == '*') {
                    dp[i][j] = (dp[i - 1][j] or dp[i][j - 1]);
                }
                else if (pattern[j - 1] == '?') {
                    dp[i][j] = (dp[i - 1][j - 1]);
                }
                else {
                    dp[i][j] = (str[i - 1] == (pattern[j - 1]) and dp[i - 1][j - 1]);
                }
            }
        }
        return dp[N][M];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}
