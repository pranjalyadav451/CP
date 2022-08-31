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


struct Number {
	int value = -1, cnt = 0;

};
int repeatedNumber(const vector<int> &A) {
	Number one, two;
	int N = A.size();
	if (N < 3) return A[0];

	for (int i = 0; i < N; i++ ) {
		if (one.cnt == 0 or one.value == A[i]) one.value = A[i], one.cnt++;
		else if (two.cnt == 0 or two.value == A[i]) two.value = A[i], two.cnt++;

		if (A[i] != one.value and A[i] != two.value) {
			one.cnt--;
			two.cnt--;
			// if (one.cnt == 0 or two.cnt == 0) i--;
		}
	}
	one.cnt = 0;
	two.cnt = 0;
	for (int i = 0; i < N; i++) {
		if (one.value == A[i]) one.cnt++;
		else if (two.value == A[i]) two.cnt++;
	}
	if (one.cnt > N / 3) return one.value;
	if (two.cnt > N / 3) return two.value;
	return -1;
}

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << repeatedNumber(arr) << endl;
}