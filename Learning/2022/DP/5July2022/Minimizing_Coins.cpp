#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 2e18;
void solve(){
    ll n , x; cin >> n >> x;
    vector<ll> coins(n);
    for(int i=0; i < n;i++) cin >> coins[i];

    vector<ll> dp(x + 1,INF);
    dp[0] = 0;
    for(ll each = 1;each<=x;each++){
        for(int i =0;i < n;i++){
            if(each - coins[i] < 0) continue;
            dp[each] = min(dp[each],dp[each - coins[i]] + 1);
        }
    }
    ll ans = dp[x];
    if(ans==INF) cout << - 1 << endl;
    else cout << ans << endl;
}

int main(){
    solve();
}
