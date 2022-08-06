#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, x; cin >> n >> x;
    vector<ll> prices(n), pages(n);

    for(int i =0; i < n;i++) cin >> prices[i];
    for(int i =0; i < n;i++) cin >> pages[i];
    
    vector<vector<ll>> dp(2,vector<ll>(x + 1));
    
    // i -> needs to be the top-level loop
    for(int i =1; i <= n;i++){
        for(ll each= 1; each<= x;each++){
            if(each < prices[i - 1]){
                dp[i % 2][each] = dp[(i - 1) % 2][each];
            }
            else
            dp[i % 2][each] = max(dp[(i - 1) % 2][each],dp[(i - 1) % 2][each - prices[i - 1]] + pages[i - 1]);
        }
    }

    ll ans = dp[n % 2][x];
    cout << ans << endl;
}
int main(){
    solve();
}
