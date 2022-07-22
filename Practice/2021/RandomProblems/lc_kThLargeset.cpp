#include <bits/stdc++.h>
using namespace std;
int kL(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> h;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (h.size() <= k || h.top() < v[i])
            h.push(v[i]);
        // else
        //h.emplace(v[i]);
        if (h.size() > k)
            h.pop();
    }
    // while(h.size()>k)
    // h.pop();
    // cout << "h.size()->" << h.size() << endl;
    return h.top();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << kL(v, k) << endl;
    }
    return 0;
}