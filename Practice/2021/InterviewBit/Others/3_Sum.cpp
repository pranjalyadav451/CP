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

int just_smaller(vector<int> &A, int left, int right, long long target) {
    int mid = 0 , ans = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if ((long long)A[mid] <= target) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
int just_greater(vector<int> &A, int left, int right, long long target) {
    int mid = 0 , ans = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if ((long long)A[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
int threeSumClosest(vector<int> &A, int B) {
    long long N = A.size();
    long long abs_diff = 1e9;
    long long sum = 0;
    sort(A.begin(), A.end());

    cout << A << endl;

    for (long long i = 0; i < N; i++) {
        for (long long j = i + 1; j < N; j++) {
            long long current_sum = (long long)A[i] + (long long)A[j];
            long long target = (long long)B - current_sum;
            long long upper = just_greater(A, j + 1, N - 1, target);
            long long lower
                = just_smaller(A, j + 1, N - 1, target);

            long long current_upper = upper != -1 ? A[i] + A[j] + A[upper] : 1e9;
            long long current_lower = lower != -1 ? A[i] + A[j] + A[lower] : -1e9;

            if (abs_diff > abs(current_lower - B)) {
                abs_diff = abs(current_lower - B);
                sum = current_lower;
            }
            if (abs_diff > abs(current_upper - B)) {
                abs_diff = abs(current_upper - B);
                sum = current_upper;
            }

        }
    }
    return sum;
}

int main() {
    int N , B;
    cin >> N >> B;
    vector<int> arr(N);
    for (auto &a : arr)
        cin >> a;
    int ans = threeSumClosest( arr, B);
    cout << ans << endl;
}