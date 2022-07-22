#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubarraySum(int arr[], int n) {
        int sum = 0, mx = -2e7, current = 0;
        for (int i = 0; i < n; i++) {
            current += arr[i];
            if (arr[i] >= current) {
                sum = arr[i];
                current = arr[i];
            }
            else {
                sum = current;
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};


int main()
{
    int t, n;

    cin >> t;
    while (t--)    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}