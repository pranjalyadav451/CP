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


// Very good question and concept.
// Visit the interviewbit submissions and find out why the line position of
// `odd_prefix[current_odd]++` line affects the solution.


int solve(vector<int> &A, int B) {
    int N = A.size();
    vector<int> odd_prefix(N + 1);
    int current_odd = 0 , count = 0;

    odd_prefix[0] = 1;

    for (int i = 0; i < N; i++) {
        if (A[i] & 1) current_odd++;
        if (current_odd >= B) count += odd_prefix[current_odd - B];
        odd_prefix[current_odd]++;
    }

    return count ;
}

int main() {
    int N , B;
    cin >> N >> B;
    vector<int> arr(N);
    for (auto &a : arr) cin >> a;

    int ans = solve(arr, B);
    cout << ans << endl;
}