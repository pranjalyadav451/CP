#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)
#define fo(i, n) for (int i = 0; i < n; i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

// int longestSubsequence(int left, int right, int a[], int prev = -1)
// {

//     if (left > right)
//     {
//         return 0;
//     }
// int count = 0;
//     if (prev < a[left])
//     {
//         // prev = a[left];
//         count = 1+longestSubsequence(left+1,right,a,a[left]);
//     }
//     int nocount = longestSubsequence(left+1,right,a,prev);
//     return max(count,nocount);
// }
// The above is a correct solution
int longestSubsequence(int left, int right, int a[], int prev = -1)
{
    if (left > right)
        return 0;
    if (a[left] > prev)
    {
        return max(longestSubsequence(left + 1, right, a, prev), 1 + longestSubsequence(left + 1, right, a, a[left]));
    }
    else
    {
        return longestSubsequence(left + 1, right, a, prev);
    }
}
//The above is my correct solution

// int longestSubsequence(int left, int right, int a[], int prev = -1)
// {
//     if (left > right)
//         return 0;
//     if (a[left] > prev)
//     {
//         prev = a[left];
//         return max(longestSubsequence(left + 1, right, a, prev), 1 + longestSubsequence(left + 1, right, a, prev));
//         // this is where I was doing wrong because
//         // I'm updating prev even if I am not considering the element in count and that was doing everything wrong
//         // when the if condition is true
//         // we have two options
//         // whether we should include the current element or not
//         // if we include the current element then the prev ->current element and count->count+1
//         // if we don't include the current element the prev ->no change and count->no change
//         // and in the ELSE part below we cannot change prev or count because the condition is not met.
//     }
//     else
//     {
//         return longestSubsequence(left + 1, right, a, prev);
//     }
// }
//while doing recursion
// look at the choices that you have with you
// look at what will change
// generally we ahve two choices at each step check what is changing at those two steps
// and think of how it will change
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n;
        cin >> n;
        int a[n];
        fo(i, n)
                cin >>
            a[i];
        cout << longestSubsequence(0, n - 1, a) << endl;
    }
}