#include <bits/stdc++.h>
#include <chrono>
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

namespace _Number_Theory {
// EVERYTHING LOOKS GOOD HERE.
ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


bool test_prime(ll N) {
	if (N <= 1)
		return false;
	if (N <= 3)
		return true;

	if (N % 2 == 0 or N % 3 == 0)
		return false;
	for (ll i = 5; i * i <= N; i += 6) {
		if (N % (i + 2) == 0 or N % i == 0)
			return false;
	}
	return true;
}

std::bitset<15000105> is_prime;
void just_sieve(int N) {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (ll i = 2; i * i <= N; i++) {
		if (is_prime[i]) {
			for (ll j = i; j * i <= N; j++) {
				is_prime[j * i] = false;
			}
		}
	}
}

bool __primes_generated__ = false;
std::vector<ll> primelist;

void genprimes(int N) {
	__primes_generated__ = true;
	just_sieve(N + 10);

	for (ll i = 2; i <= N; i++) {
		if (is_prime[i]) {
			primelist.push_back(i);
		}
	}
}

std::vector<ll> factors(ll N) {
	if (!__primes_generated__) {
		std::cerr << "Just DO IT , (Call genprimes)" << std::endl;
		exit(1);
	}
	std::vector<ll> facs;
	for (ll i = 0; primelist[i] * primelist[i] <= N; i++) {
		if (N % primelist[i] == 0) {
			while (N % primelist[i] == 0) {
				N /= primelist[i];
				facs.push_back(primelist[i]);
			}
		}
	}
	if (N > 1) {
		facs.push_back(N);
	}
	sort(facs.begin(), facs.end());
	return facs;
}
std::vector<ll> getdivs(ll N) {
	std::vector<ll> divs;
	for (ll i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			if (N / i == i)
				divs.push_back(i);
			else
				divs.push_back(i), divs.push_back(N / i);
		}
	}
	return divs;
}
}
using namespace _Number_Theory;

void solve() {
	int N; cin >> N;
	vll arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	ll first_gcd = arr[0], sec_gcd = arr[1];

	for (ll i = 2; i < N; i++) {
		if (i % 2 == 0) {
			first_gcd = gcd(first_gcd, arr[i]);
		} else {
			sec_gcd = gcd(sec_gcd, arr[i]);
		}
	}


	bool check_first = true, check_sec = true;

	for (int i = 1 ; i < N; i += 2) {
		ll current = arr[i] % first_gcd;
		if (current == 0) {
			check_first = false;
			first_gcd = 0;
			break;
		}
	}
	for (int i = 0; i < N; i += 2) {
		ll current = arr[i] % sec_gcd;
		if (current == 0) {
			check_sec = false;
			sec_gcd = 0;
			break;
		}
	}

	if (check_first) {
		cout << first_gcd << endl;
	}
	else if (check_sec) {
		cout << sec_gcd << endl;
	}
	else {
		cout << 0 << endl;
	}

}
int main() {
	int tt = 1;
	// genprimes(1e7);
	cin >> tt; // "UN-COMMENT THIS FOR TESTCASES"
	while (tt--) {
		solve();
	}

}