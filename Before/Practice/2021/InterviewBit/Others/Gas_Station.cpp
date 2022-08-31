#include <bits/stdc++.h>
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


int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
	int N = A.size();
	int curr_fuel = 0, req = 0 , start = 0;
	// cout << A << B;
	int dist = 0;

	for (int i = 0; i < 2 * N; i++) {
		if (dist == N) return start;

		curr_fuel += A[i % N] , req = B[i % N];
		if (curr_fuel >= req) {
			cout << "Inside Success" << endl;
			dbgg(i, start);
			dbgg(curr_fuel, req);
			dbgg(A[i], B[i]);
			cout << "------" << endl;

			curr_fuel -= req;
			dist++;
		}
		else {
			cout << "Inside failure" << endl;
			dbgg(i, start);
			dbgg(curr_fuel, req);
			dbgg(A[i], B[i]);
			cout << "------" << endl;

			dist = 0;
			start = (i + 1) % N;
			curr_fuel = 0;
		}
		dbg(dist);
		dbgg(i, start);
		dbgg(curr_fuel, req);
		dbgg(A[i], B[i]);
		cout << "\n\n\n\n";
	}
	return -1;
}


int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (auto &a : A)
		cin >> a;
	cin >> N;
	for (auto &b : B)
		cin >> b;
	int ans = canCompleteCircuit(A, B);
	cout << ans << endl;
}
