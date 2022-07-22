#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
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

const int mxn = 2e7 + 10;
bitset<mxn> isPrime;
vll PRIMES;
vpl TWIN;

void sieve() {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 2; i < mxn; i++) {
		if (isPrime[i]) {
			for (ll j = i; j * i < mxn; j++) {
				isPrime[j * i] = false;
			}
		}
	}
	for (int i = 0; i < mxn; i++) {
		if (isPrime[i]) PRIMES.push_back(i);
	}
	for (int i = 0; i < PRIMES.size() - 1; i++) {
		if (PRIMES[i] - PRIMES[i + 1] == -2) {
			TWIN.push_back({PRIMES[i], PRIMES[i + 1]});
		}
	}
}

pll get_twin(ll N) {
	return TWIN[N - 1];
}

int main() {
	ll N;
	sieve();
	while (cin >> N) {
		pll ans = get_twin(N);
		cout << ans << endl;
	}
}