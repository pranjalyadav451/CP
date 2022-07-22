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


bool isPossible(vector<int> &A, int sub_size, map<int, int> cnt, int more_than_2) {
    for (int i = 0; i < sub_size; i++) {
        cnt[A[i]]--;
        if (cnt[A[i]] == 2) {
            more_than_2--;
        }
    }
    if (more_than_2 == 0) return true;
    int left = 1, N = A.size();

    for (int i = left; i + sub_size - 1 <= N; i++) {
        int prev = A[i - 1] , next = A[i + sub_size - 1];
        ++cnt[prev];
        --cnt[next];
        if (cnt[prev] == 3) more_than_2++;
        if (cnt[next] == 2) more_than_2--;

        if (more_than_2 == 0) return true;

    }
    cout << endl << endl;
    return false;
}

int solve(vector<int> &A) {
    map<int, int> cnt;
    int N = A.size() , more_than_2 = 0;
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
        if (cnt[A[i]] == 3) more_than_2++;
    }



    int lower = 0, upper = N - 2;
    int ans = N - 2;
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (isPossible(A, mid , cnt, more_than_2)) {
            ans = mid;
            upper = mid - 1;
        }
        else {
            lower = mid + 1;
        }
    }
    return ans;
}

int main() {
    int N , B;
    cin >> N;
    vector<int> arr(N);
    for (auto &a : arr)
        cin >> a;
    int ans = solve(arr);
    cout << ans << endl;
}