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

/**
 * My initial thoughs were right about the question
 * just forgot to consider the case when the number of students are more than the number of books
 * It cost me 180 points probably. So, fron now on take care of these corner cases.
*/


int maxPagesPossible(vector<int> &A, int B, int pages) {
    int cnt_div = 0, current_page_cnt = 0;
    int N = A.size();
    for (int i = 0; i < N; i++) {
        if (A[i] > pages) return N + 1;
        current_page_cnt = 0;
        int j = i ;
        while (j < N and current_page_cnt + A[j] <= pages) {
            current_page_cnt += A[j];
            j++;
        }
        cnt_div++;
        i = --j;
    }

    return cnt_div;

}
int books(vector<int> &A, int B) {
    int total = accumulate(A.begin(), A.end(), 0);
    int left = 1, right = total, mid = 0, ans = -1;
    int N = A.size();
    if (B > N) return -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        auto temp = maxPagesPossible(A, B, mid);
        if (temp <= B) {
            ans = mid;
            right = mid - 1;
        }
        else {
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
    int ans = books( arr, B);
    cout << ans << endl;
}