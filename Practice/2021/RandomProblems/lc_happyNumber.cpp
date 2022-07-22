#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
this was a very good problem and this problem might have
seriously lowered my submission acceptance rate on leetcode
I took this problem as an easy which this was not
this problem was simple yet tricky
like the digital root problem
- this was related to finding the repeating patterns
in a sequence.
*/
bool isHappy(int n)
{
    unordered_set<int> s;
    s.insert(n);
    ll sum = 0;
    while (s.count(sum) == 0 && n > 1)
    {
        s.insert(sum);
        sum = 0;
        while (n != 0)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        n = sum;
    }
    if (n == 1)
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (isHappy(n) == 1)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout <<isHappy(n) << endl;
    }
    return 0;
}