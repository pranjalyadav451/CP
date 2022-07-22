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




int candy(vector<int> &ratings) {
	int candies = 0;
	int size = ratings.size();
	vector<int> lefttoright(size, 1);
	vector<int> righttoleft(size, 1);

	for (auto l = 1; l < size; ++l)
		if (ratings[l] > ratings[l - 1])
			lefttoright[l] = lefttoright[l - 1] + 1;

	for (auto r = size - 2; r >= 0; --r)
		if (ratings[r] > ratings[r + 1])
			righttoleft[r] = righttoleft[r + 1] + 1;

	for (auto i = 0; i < size; ++i)
		candies += max(lefttoright[i], righttoleft[i]);

	return candies;
}






int main() {
	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ans = candy(arr);
	cout << ans << endl;
}