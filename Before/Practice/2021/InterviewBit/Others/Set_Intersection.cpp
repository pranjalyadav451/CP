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
#define log_all(...)                        logger(#__VA_ARGS__, __VA_ARGS__)

bool comp(const vector<int> &A, const vector<int> &B) {
	if (A[1] == B[1]) return A[0] < B[0];
	return A[1] < B[1];
}

int setIntersection(vector<vector<int> > &A) {
	set<int> intersect;
	int N = A.size();
	sort(A.begin(), A.end(), comp);

	// cout << A << endl;

	pair<int, int> prev = {A[0][1], A[0][1] - 1};

	intersect.insert(prev.first);
	intersect.insert(prev.second);

	for (int i = 1; i < N; i++) {
		int start = A[i][0], end = A[i][1];
		if (!(prev.first >= start and prev.first <= end)) {
			intersect.insert(end);
			prev.first = end;
		}
		if (!(prev.second >= start and prev.second <= end)) {
			intersect.insert(end - 1);
			prev.second = end - 1;
		}
		cout << intersect << endl;

	}
	return intersect.size();
}


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(2));
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int ans = setIntersection(arr);
	cout << ans << endl;
}
