#include <bits/stdc++.h>

// Both versions of code are working perfectly
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<int> findSubarray(int arr[], int n) {
        // ll sum = 0 , len = 0, mx_len = 0, mx = 0;
        // vector<int> res, temp;
        // for (int i = 0; i < n; i++) {
        //     if (arr[i] < 0) {
        //         sum = 0; len = 0; temp.clear();
        //         continue;
        //     }
        //     else {
        //         while (arr[i] >= 0 and i < n) {
        //             sum += arr[i];
        //             temp.push_back(arr[i]);
        //             len++; i++;
        //         }
        //         if (sum > mx) {
        //             mx = sum; res = temp;
        //         }
        //         if (sum == mx and len > mx_len) {
        //             res = temp;
        //         }
        //         i--;
        //     }
        // }
        // if (res.size() == 0) return { -1};
        // else return res;

        ll sum = 0 , mx = 0, len = 0, mx_len = 0, st = -1, mn_st = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                sum = 0; len = 0; st = -1;
            }
            else {
                sum += arr[i];
                st = st == -1 ? i : st;
                len++;
                if (sum > mx) {
                    mx = sum; mx_len = len; mn_st = st;
                }
                if (sum == mx and len > mx_len) {
                    mn_st = st;
                }
            }
        }
        vector<int> res;
        // mn_st >=0 -> to rule out the cases when all numbers are negative,
        // because then mn_st would be -1, and the while loop will give runtime-error.
        while (mn_st >= 0 and mn_st < n and arr[mn_st] >= 0) {
            res.push_back(arr[mn_st++]);
        }
        return res.size() == 0 ? res = { -1}: res;
    }
};


void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

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
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
