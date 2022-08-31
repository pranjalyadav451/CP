#include<bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl


ll other_LIS(vector<long long> const& a) {
	int n = a.size();
	const int INF = 1e9;
	vector<int> d(n + 1, INF);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[j - 1] < a[i] && a[i] < d[j]) {
				d[j] = a[i];
			}
		}
	}

	int ans = 0;
	cout << d << endl;
	for (int i = 0; i <= n; i++) {
		if (d[i] < INF)
			ans = i;
	}
	return ans;
}





void print_LIS(vector<int>& parent, vector<long long>& arr, int i) {
	if (parent[i] == i) {
		cout << arr[i] << " ";
		return;
	}
	print_LIS(parent, arr, parent[i]);
	cout << arr[i] << " ";
}




ll go_find(vector<int> &dp, int idx) {
	// the maximum length upto
}

ll LIS(vector<ll> &arr, int N) {
	vector<int> dp(N, 1);
	vector<int> parent(N);

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					parent[i] = j;
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	print_LIS(parent, arr, N - 1);
	cout << endl;
	return dp[N - 1];
}

void solve() {
	int N;
	cin >> N;
	vector<ll> arr(N);
	for (ll &A : arr) {
		cin >> A;
		// cout << A << " ";
	}
	// cout <<arr<<endl;
	ll ans = LIS(arr, N);
	ll other_ans = other_LIS(arr);
	dbg(other_ans);
	cout << ans << endl;
}

int main() {
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
}
