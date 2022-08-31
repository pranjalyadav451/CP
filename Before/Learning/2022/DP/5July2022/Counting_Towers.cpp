#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll madd(ll a, ll b){ return (a % mod + b % mod) % mod; }
ll mmul(ll a, ll b){ return (a % mod * b % mod) % mod; }

vector<vector<ll>> dp;
void cal(){
    int n = 1e6;
    dp[1][0] = 1;
    dp[1][1] = 1;
   
    for(int i=2;i<=n;i++){
        dp[i][0] = madd(mmul(4, dp[i - 1][0]) , dp[i - 1][1]);
        dp[i][1] = madd(mmul(2, dp[i - 1][1]) , dp[i - 1][0]);
    }
}

void solve(){
    int n; cin >> n;
    // how many ways can we make the height n - 1 len
    ll ans = madd(dp[n][0] , dp[n][1]);
    cout << ans << endl;
}
int main(){
    int tt; cin >> tt;
    dp.assign(1e6 + 1,vector<ll>(2,0));
    cal();
    while(tt--)
        solve();
}
