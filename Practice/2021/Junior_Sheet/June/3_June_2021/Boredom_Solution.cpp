#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
#define log_all(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[" << "( " << vars << " )" << " :-> ( ";
    string delim = ""; (..., (cout << delim << values, delim = ", ")); cout << " )]" << endl;
}


#define ll long long

using namespace std;

int main() {
    ll n, ma = 0;
    cin >> n;
    vector<ll>a(n + 1), count(1000000);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        count[a[i]]++;
        if (a[i] > ma) {
            ma = a[i];
        }
    }
    vector<ll>dp(ma + 1);
    dp[0] = 0;
    dp[1] = count[1];
    for (ll i = 2; i <= ma; ++i) {
        // log_all(i, count[i], dp[i - 1], dp[i - 2]);
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
    }
    cout << dp << endl;
    cout << dp[ma];
    return 0;
}

/**
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MOD 1000000007
#define int long long
#define N 100005

int a[N], freq[N] = {0}, dp[N];

/*
EXPLANATION OF THE RECURRENCE EQUATION:
First, precompute the frequency of occurrence of each element in Alex's sequence
(using the array "freq")

dp[i] stores the maximum sum that Alex can get USING ONLY numbers from 1 to i
So, dp[0] is 0
dp[1] is freq[1] i.e., number of '1's in the sequence

For i = 1 to (10 ^ 5), dp[i] is calculated using the inference that each set of "i"s
(assuming they occur in the sequence) can either all be picked OR not picked at all:

dp[i] = max(I, II), where

I = dp[i - 1] represents the situation where "i" isn't picked at all
(As "i" isn't picked at all, none of the "i - 1"s will be deleted, and the sum will be
 the same as the one calculated for dp[i - 1])

II = dp[i - 2] + (freq[i] * i) represents the situation where all "i"s are picked
(As all the "i"s are picked, all the "i - 1"s WILL be deleted, and we cannot consider
 dp[i - 1] at all, given that dp[i - 1] was itself computed while considering the
 situation where all the "i - 1"s may be picked. Instead, we use dp[i - 2]; the sum
 computed therein is safe to use, given none of the "i - 2"s will be deleted when the
 "i"s are picked. Also, as we are picking all the "i"s, our previous sum (i.e., dp[i-2])
  will increase by freq[i] * i
 )
*/
/*
main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = freq[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + (freq[i] * i));
    }
    cout << dp[N];
}
*/
