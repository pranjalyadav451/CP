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

vector<vector<int>> res;

void go_down(int &row , int &col , int A, int &val) {
	int i = 0;
	for (i = row; i < A and res[i][col] == -1; i++) {
		res[i][col] = val++;
	}
	col--;
	row = i - 1;
}
void go_up(int &row , int &col , int A, int &val) {
	int i = 0;
	for (i = row; i >= 0 and res[i][col] == -1; i--) {
		res[i][col] = val++;
	}
	col++;
	row = i + 1;
}
void go_left(int &row , int &col , int A, int &val) {
	int i = col;
	for (i = col; i >= 0 and res[row][i] == -1; i--) {
		res[row][i] = val++;
	}
	row--;
	col = i + 1;
}

void go_right(int &row , int &col , int A, int &val) {
	int i = col;
	for ( i = col; i < A and res[i][col] == -1; i++) {
		res[row][i] = val++;
	}
	row++;
	col = i - 1;
}


vector<vector<int> > generateMatrix(int A) {
	res.assign(A, vector<int> (A, -1));
	int row = 0 , col = 0;
	int current_dir = 0;
	int val = 1;

	while (row >= 0 and row < A and col < A and col >= 0) {
		go_right(row, col, A, val);
		go_down(row, col, A, val);
		go_left(row, col, A, val);
		go_up(row, col, A, val);
		if (res[row][col] != -1) return res;
		current_dir = (current_dir + 1) % 4;
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> res = generateMatrix(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}
}
