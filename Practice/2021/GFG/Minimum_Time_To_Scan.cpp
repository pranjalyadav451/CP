#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl
class Solution {
public:
    int minTime(int S1, int S2, int N) {
        int left = 1, right = N, mid = 0, ans = INT_MAX;

        int small = min(S1, S2), big = max(S1, S2);

        while (left <= right) {
            mid = left + (right - left) / 2;
            int left_cost = small * mid, right_cost = big * (N - mid);
            ans = min(ans, max(left_cost, right_cost));
            if (right_cost > left_cost) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int S1, S2, N;
        cin >> S1 >> S2 >> N;

        Solution ob;
        cout << ob.minTime(S1, S2, N) << "\n";
    }
    return 0;
}