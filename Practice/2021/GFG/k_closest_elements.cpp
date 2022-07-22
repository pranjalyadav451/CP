// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
int closeness = -1;
int toclose = -1;
auto comp = [] (int a, int b)
{
    if (abs(a - toclose) == abs(b - toclose))
    {
        return a > b;
    }
    return abs(a - toclose) < abs(b - toclose);

};
class Solution {
public:

    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        toclose = x;
        vector<int>ans;
        priority_queue < int, vector<int>, decltype(comp)>kclose(comp);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != x)
                kclose.push(arr[i]);
            if (kclose.empty() == false and kclose.size() > k)
                kclose.pop();
        }

        while (not kclose.empty())
        {
            ans.push_back(kclose.top());
            kclose.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends