#include <bits/stdc++.h>
using namespace std;
int countVowelStrings(int n)
{
    vector<int> a(5, 1);
    for (size_t i = 1; i < n; i++)
    {
        for (int j = 3; j >= 0; j--)
            a[j] += a[j + 1];
    }
    int ans = 0;
    for (int &k : a)
        ans += k;
    return ans;
}
// learn dp and recursion
//the above approach is good more intuitive than the gfg article.
// I have to prove this
//the dp approach mentioned in the gfg article is very good
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        //cout << t << endl;
        int n;
        cin >> n;
        cout << countVowelStrings(n);
    }
    return 0;
}