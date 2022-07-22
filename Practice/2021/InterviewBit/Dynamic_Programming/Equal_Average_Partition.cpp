#include <bits/stdc++.h>
#include <numeric>
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

vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int index, int sum, int sz) {
	if (sz == 0) return (sum == 0);
	if (index >= total_size) return false;

	if (dp[index][sum][sz] == false) return false;

	if (sum >= original[index]) {
		res.push_back(original[index]);
		if (possible(index + 1, sum - original[index], sz - 1)) return true;
		res.pop_back();
	}

	if (possible(index + 1, sum, sz)) return true;

	return dp[index][sum][sz] = false;
}

vector<vector<int> > avgset(vector<int> &Vec) {
	sort(Vec.begin(), Vec.end());
	original.clear();
	original = Vec;
	dp.clear();
	res.clear();

	int total_sum = 0;
	total_size = Vec.size();

	for (int i = 0; i < total_size; ++i) total_sum += Vec[i];

	dp.resize(original.size(), vector<vector<bool> > (total_sum + 1, vector<bool> (total_size, true)));

	// We need to minimize size_of_set1. So, lets search for the first
	// size_of_set1 which is possible.
	for (int i = 1; i < total_size; i++) {
		// Sum_of_Set1 has to be an integer
		if ((total_sum * i) % total_size != 0) continue;

		int Sum_of_Set1 = (total_sum * i) / total_size;

		if (possible(0, Sum_of_Set1, i)) {
			// Lets get the elements in group 2 now that we have group 1.
			int ptr1 = 0, ptr2 = 0;
			vector<int> res1 = res;
			vector<int> res2;
			while (ptr1 < Vec.size() || ptr2 < res.size()) {
				if (ptr2 < res.size() && res[ptr2] == Vec[ptr1]) {
					ptr1++;
					ptr2++;
					continue;
				}
				res2.push_back(Vec[ptr1]);
				ptr1++;
			}

			vector<vector<int> > ans;
			ans.push_back(res1);
			ans.push_back(res2);
			return ans;
		}
	}

	// Not possible.
	vector<vector<int> > ans;
	return ans;
}

int main() {
	int N; cin >> N;
	vector<int> arr(N);
	for (auto &a : arr)
		cin >> a;
	vector<vector<int>> ans = avgset(arr);
	cout << ans << endl;
}