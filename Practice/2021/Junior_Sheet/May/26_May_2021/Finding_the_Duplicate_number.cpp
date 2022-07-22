#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e : v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef long double ld;
#define ALL(x) (x).begin(),(x).end()
#define REP(i, a, b) for (int i = (a); i <= (b); (i)++)
#define RREP(i, a, b) for (int i = (a); i >= (b); (i)--)
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << "  " << #y << ": " << y << endl

/** *** GLOBALS *** **/



/** *** FUNCTIONS *** **/

/**
class Solution {
    public int findDuplicate(int[] nums) {
        int left = 0, right = nums.length;
        while(left<right){
            int mid = left + (right-left)/2;
            int count = 0;
            for(int i:nums) if(i<=mid) count++;
            if(count > mid){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
}
**/

/** Good question of Binary Search*/

int dup(vector<int> &arr, int n) {
	int left = 1, right = arr.size() - 1;
	int ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		int count = 0;
		// counting the number of numbers less than or equal to a given value.
		// if the count of such values is greater than the number, than answer doesn't exist
		// in the range [1,mid - 1]
		for (int i : arr) {
			if (i <= mid)
				count++;
		}
		dbgg(left, right);
		dbgg(mid, count);
		if (count > mid) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
			// finding the first bad value.
		}
		dbgg(left, right);
		cout << endl;
	}
	return ans;
}


int main() {
	/** *** INPUT *** **/
	int tt = 1;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int &a : arr) {
			cin >> a;
		}
		/** *** SOLUTION *** **/
		cout << dup(arr, n) << endl;
	}



}
