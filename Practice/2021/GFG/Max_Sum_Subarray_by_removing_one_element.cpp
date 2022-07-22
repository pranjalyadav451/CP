#include <bits/stdc++.h>
using namespace std;






class Solution
{
public:
    int maxSumSubarray(int A[], int n) {
        // What to do here now.
        for (int i = 0; i < n; i++) {
            // what to do now here I don't understand this.
        }
    }
};


int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];


        Solution obj;
        cout << obj.maxSumSubarray(a, n) << endl;
    }
}

