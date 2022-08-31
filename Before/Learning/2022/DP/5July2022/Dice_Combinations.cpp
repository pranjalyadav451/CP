#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;


ll madd(ll a, ll b){
    a%=mod;b%=mod;
    return (a + b) % mod;
}
void solve(){
    int n; cin >> n;

    vector<long long > dp(n + 1);
    dp[0] = 1;

    for(ll each = 1;each <=n;each++){
        for(ll i = 1;i<=6;i++){
            if(each - i < 0) continue;
            dp[each] = madd(dp[each],dp[each - i]);
        }
    }
    ll ans = dp[n];
    cout << ans << endl;
}

int main(){
    solve();
}
