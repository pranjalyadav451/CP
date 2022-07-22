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

ll solve(vector<ll> arr, ll n, ll x)
{
  ll sum = 0;

  return sum;
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
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << solve(arr, n, x) << endl;
  }
}
