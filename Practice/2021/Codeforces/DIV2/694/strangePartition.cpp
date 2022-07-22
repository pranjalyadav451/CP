#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << " => " << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

#define MOD 1000000007
using namespace std;

pair<ll int, ll int> solve(vector<ll int> &arr, ll int n, ll int x)
{
  pair<ll int, ll int> ans;

  ll maxi = 0, mini = 0;

  for (int i = 0; i < n; i++)
  {
    maxi += arr[i] % x == 0 ? arr[i] / x : arr[i] / x + 1;
    mini += arr[i];
  }

  mini = mini % x == 0 ? mini / x : mini / x + 1;
  ans.first = mini;
  ans.second = maxi;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--)
  {

    ll int n, x;
    cin >> n >> x;
    vector<ll int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    cout << solve(arr, n, x).first << " " << solve(arr, n, x).second << endl;
  }
}
