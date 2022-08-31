#include <bits/stdc++.h>
using namespace std;
#define dbg(x)                              cout << #x << ": " << x << endl
#define dbgg(x, y)                          cout << #x << ": " << x << "  " << #y << ": " << y << endl
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A>                ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A>                ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>                ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T>                ostream& operator<<(ostream& os, const list<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>      ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B>    ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }


vector<int> maxone(vector<int> &A, int B) {
	int N = A.size();
	int start = 0 , end = 0 ;
	int max_length = 0;
	queue<int> zeros;
	pair<int, int> ans;

	while (end < N) {
		if (A[end] == 0) {
			zeros.push(end);
		}

		if (zeros.size() > B) {
			start = zeros.front() + 1;
			zeros.pop();
		}
		if (end - start + 1 > max_length) {
			max_length = end - start + 1;
			ans = {start, end};
		}
		end++;
	}

	vector<int> result;
	for (int i = ans.first; i <= ans.second; i++) {
		result.push_back(i);
	}
	return result;
}

int main() {
	int N , B;
	cin >> N >> B;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> ans = maxone(arr, B);
	cout << ans << endl;
}
