#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 2e18;
const ll mod = 1e9 + 7;

vector<vector<ll>> dp;
ll n , m;
ll madd(ll a, ll b){
    return (a % mod + b % mod) % mod;
}

ll rec(vector<ll> &arr,int prev , int i = 1){
    if(i==arr.size()) return 1;
    if(arr[i]!=0){
        ll diff = abs(arr[i] - prev);
        if(diff > 1) return 0;
        return rec(arr,arr[i],i + 1);
    }

    int start = max(1,prev - 1), end = min(m,(long long)(prev + 1));
    ll &ans = dp[i][prev];
    if(ans!=-1) return ans;
    ans = 0;
    for(int can = start; can<= end;can++)
        ans = madd(ans,rec(arr,can,i + 1));
    return ans;
}


void solve(){
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i =0; i < n;i++) cin >> arr[i];


    dp.assign(n + 1,vector<ll>(m + 1,-1));

    ll ans = 0;
    if(arr[0]==0){
        for(int curr=1;curr<=m;curr++) ans = madd(ans, rec(arr,curr));
    }
    else ans = rec(arr,arr[0]);
    cout << ans << endl;
}

int main(){
    solve();
}
