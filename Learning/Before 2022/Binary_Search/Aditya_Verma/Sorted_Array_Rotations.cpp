#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define dbgg(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl

class Solution {
public:
    int findKRotation(int arr[], int n) {
        int left = 0 , right = n - 1 , mid = 0 , ans = 0;
        int mn = INT_MAX;

        while (left <= right) {
            mid = left + (right - left ) / 2;
            if (arr[left] < mn) {mn = arr[left]; ans = left;}
            if (arr[mid] < mn) {mn = arr[mid]; ans = mid;}
            if (arr[right] < mn) {mn = arr[right]; ans = right;}

            if (arr[right] > arr[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

/**
    -- write the alternate approach here (one which uses the pivot property).
**/

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}