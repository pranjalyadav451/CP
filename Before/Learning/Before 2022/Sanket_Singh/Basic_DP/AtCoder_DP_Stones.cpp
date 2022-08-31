#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "," << #y << ": " << y << endl

int n = 0, k = 0;
vector<int > arr;
/*
 * https://atcoder.jp/contests/dp/tasks
 * How to pick stones?
 * At each step Taro or Jiro (depending on chance) can pick any element that has
 * not been picked already.
*/
/**
 * Observation
 * We just find if the first player wins or not and we have the result of the game.
 * For that we check if dp[k] == 1, which means there was some elements by picking
 * whom first player can force the second player to lose if the both play optimally.
 * Otherwise, the second player wins.
 * **/

const int mxn = 1e6 + 10;
int dp[mxn] = {};
void solve() {
    for (int i = 1; i <= k ; i++) {
        for (int a : arr) {
            if (a > i) {
                continue;
            }
            if (dp[i - a] == 0) dp[i] = 1;
        }
    }
    cout << (dp[k] == 1 ? "First" : "Second") << endl;
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    for (int &A : arr) cin >> A;
    solve();
}