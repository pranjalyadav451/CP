#include <bits/stdc++.h>
#include <chrono>
#include <queue>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


typedef long long                           ll;
typedef pair<ll, ll>                        pll;
typedef vector<vector<ll>>                  vvl;
typedef vector<pll>                         vpl;
typedef pair<int, int>                      pii;
typedef long double                         ld;
typedef vector<ll>                          vll;

#define all(x)                              (x).begin(),(x).end()
#define REP(i, a, b)                        for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b)                       for (int i = (a); i >= (b); (i)--)
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

bool check(vll &arr) {
	int N = arr.size();
	vll good;
	ll prev = -1;
	for (int i = 0; i < N; i++) {
		if (arr[i] != -1 and prev > arr[i] or arr[i] > i + 1) {
			return false;
		}
		if (arr[i] != -1) prev = arr[i];
	}
	return true;
}
void print_vec(vll &ans) {
	for (auto &a : ans) cout << a << " ";
	cout << endl;
}

void solve() {
	int N;
	cin >> N;
	vll arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	bool possible = check(arr);
	if (!possible) {
		cout << - 1 << endl;
		return;
	}

	vll ans(N, -1);
	multiset<int> valid, invalid;

	for (int i = 0; i <= N; i++) {
		valid.emplace(i);
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] != -1) {
			valid.erase(arr[i]);
			invalid.emplace(arr[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		int current = arr[i];
		if (current == -1) {
			// cout << valid << endl;
			ans[i] = *valid.begin();
			valid.erase(ans[i]);
			continue;
		}

		while (i < N and arr[i] == current) {
			ans[i] = *valid.begin();
			valid.erase(valid.begin());

			if (invalid.find(arr[i]) != invalid.end()) invalid.erase(invalid.find(arr[i]));
			if (invalid.find(arr[i]) == invalid.end()) {
				valid.emplace(arr[i]);
			}

			current = arr[i];
			i++;
		}
		i--;
	}

	print_vec(ans);
}
int main() {
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}