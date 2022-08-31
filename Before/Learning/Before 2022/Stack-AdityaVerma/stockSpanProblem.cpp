// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
// } Driver Code Ends

// Function to calculate span
// price[]: price array in input
// n: size of array
void nextGreaterToRight(int source[], int len, vec<int> &resultIndex)
{

    stack<int> load;
    for (int i = 0; i < len; i++)
    {
        while (not load.empty() and source[load.top()] < source[i])
            load.pop();
        if (load.empty())
            resultIndex.push_back(i + 1);
        else
            resultIndex.push_back(i - load.top());
        load.push(i);
    }
}
vector<int> calculateSpan(int price[], int n)
{
    vec<int> res;
    nextGreaterToRight(price, n, res);
    return res;
}

// { Driver Code Starts.

int main()
{
    cout << "hello" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> s = calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends