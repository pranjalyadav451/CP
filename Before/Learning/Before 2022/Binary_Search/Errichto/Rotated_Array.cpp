#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int findSmallest(vector<int> &arr, int n) {
    int lo = 0, hi = arr.size() - 1, mid;
    int ans = INT_MAX;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        ans = min({ans,arr[mid],arr[lo]});

        if (arr[mid] >= arr[lo]) {
            lo = mid + 1;
        }
        else hi = mid -1;
    }
    return ans;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int>arr(n);

        for (int &a : arr) {
            cin >> a;
        }
        cout << findSmallest(arr, n);
        cout << endl;

    }
}