#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll madd(ll a, ll b){
    return (a % mod  + b % mod) % mod;
}
void solve(){
    ll n,x; cin >> n >> x;
    vector<ll>coins(n);
    for(int i=0; i < n;i++) cin >> coins[i];
    sort(coins.begin(),coins.end());

    vector<ll> dp(x + 1);
    dp[0] = 1;
    for(ll i =0; i < n;i++){
        for(ll each = 1;each <=x;each++){
            if(each - coins[i] < 0) continue;
            dp[each] = madd(dp[each],dp[each - coins[i]]);
        }
    }

    ll ans = dp[x];
    cout << ans << endl;
}

int main(){
    solve();
}
