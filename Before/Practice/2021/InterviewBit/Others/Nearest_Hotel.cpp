#include <bits/stdc++.h>
#include <vector>

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



vector<int> nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
	int N = A.size(), M = A[0].size();
	int Q = B.size();
	vector<int> left(M), right(M);
	const int INF = 1e9;
	vector<vector<int>> arr(N, vector<int>(M, INF));

	for (int i = 0; i < N; i++) {
		left.assign(M, -1);
		right.assign(M, -1);
		left[0] = A[i][0] == 1 ? 0 : INF;
		for (int j = 1; j < M; j++) {
			if (A[i][j] == 1) left[j] = j;
			else left[j] = left[j - 1];
		}
		right[M - 1] = A[i][M - 1] == 1 ? M - 1 : INF;
		for (int j = M - 2; j >= 0; j--) {
			if (A[i][j] == 1) right[j] = j;
			else right[j] = right[j + 1];
		}
		for (int j = 0; j < M; j++) {
			arr[i][j] = min(abs(j - left[j]), abs(j - right[j]));
		}
	}

	cout << arr << endl;

	vector<int> res;
	vector<int>top(N), down(N);

	for (int i = 0; i < M; i++) {
		pair<int, int> data = {0, arr[0][i]};
		top[0] = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (data.second + abs(data.first - j) < arr[j][i]) {
				data.second = data.second + abs(data.first - j);
				data.first = j;
			} else {
				data = {j, arr[j][i]};
			}
			top[j] = data.second;
		}

		down[N - 1] = arr[N - 1][i];
		data = {N  - 1 , arr[N - 1][i]};
		for (int j = N - 2; j >= 0; j--) {
			if (data.second + abs(data.first - j) < arr[j][i]) {
				data.second = data.second + abs(data.first - j);
				data.first = j;
			}
			else {
				data = {j, arr[j][i]};
			}
			down[j] = data.second;
		}
		for (int j = 0; j < N; j++) {
			arr[j][i] = min({arr[j][i], top[j], down[j]});
		}
	}

	cout << arr << endl;

	for (int i = 0; i < Q; i++) {
		int col = B[i][1] - 1, row = B[i][0]  - 1;
		res.push_back(arr[row][col]);
	}
	return res;
}

int main() {
	int N , M;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int Q, P;
	cin >> Q >> P;
	vector<vector<int>> B(Q, vector<int>(P));
	for (int i = 0; i < Q; i++) {
		for (int j = 0; j < P; j++) {
			cin >> B[i][j];
		}
	}
	vector<int> ans = nearestHotel(arr, B);
	for (auto a : ans) {
		cout << a << " ";
	}
	cout << endl;

}