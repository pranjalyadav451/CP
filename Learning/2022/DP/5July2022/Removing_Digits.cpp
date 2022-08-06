#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> dp;
const ll INF = 2e18;

void solve(){
    int n; cin >> n;
    vector<ll> dp(n + 1, INF);
    dp[0] =0;
    for(ll each = 1; each <=n ;each++){
        set<int> uniq; ll t = each;
        while(t){
            uniq.insert(t % 10);
            t /=10;
        }
        for(auto a:uniq) dp[each] = min(dp[each], dp[each - a] + 1);
    }
    ll ans = dp[n];
    cout << ans << endl;
}

int main(){
    solve();
}
