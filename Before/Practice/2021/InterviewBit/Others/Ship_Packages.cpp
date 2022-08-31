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


#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl

bool isPossible(vector<int> &A, int given_days, int cap) {
	int N = A.size();
	int days = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > cap) return false;
		int current_load = 0 , j = i;
		while (j < N and current_load + A[j] <= cap) {
			current_load += A[j];
			j++;
		}
		i = --j;
		days++;
	}
	return days <= given_days;
}
int solve(vector<int> &A, int B) {
	int total = 0, N = A.size();
	for (int i = 0; i < N; i++) {
		total += A[i];
	}
	int left = 1 , right = total , mid = 0 , ans = -1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (isPossible(A, B, mid)) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return ans;
}




int main() {
	int N , B;
	cin >> N >> B;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = solve( arr, B);
	cout << ans << endl;
}