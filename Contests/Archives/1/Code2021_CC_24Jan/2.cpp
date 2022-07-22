#include<bits/stdc++.h>
#define ll long long
#define vec vector
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
#define fo(i,n) for(i=0;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


using namespace std;
//basically this question is greedy method
// where I have to find the minimum number of moves to get all the cards from alisha
bool comp(std::pair<int, int>a, std::pair<int, int>b)
{
	return a.f + a.s < b.f + b.s;
}
void solve(vec<char>&card, vec<pair<int, int>>&price)
{
	int sunil = 0;
	int blue = 0;
	int red = 0;
	int A = 0;
	int B = 0;
	int n = card.size();
	int turns = 0;
	for ( int i = 0; i < n; i++ )
	{
		if (red >= price[i].first and blue >= price[i].second)
		{
			red = red - max(price[i].f - A, 0);
			blue = blue - max(price[i].s - B, 0);
			if (card[i] == 'R')
				A++;
			else if (card[i] == 'B')
				B++;
			turns++;
		}
		else
		{
			blue++;
			red++;
			turns++;
		}

	}
	cout << turns << endl;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	// vec<char>card(n);
	char card;

	vec < pair<char, pair<int, int>> price(n);
	int r, b;
	for (int i = 0; i < n; i++)
	{
		cin >> card;
		cin >> r >> b;
		price[i].first = card;
		price[i].second = make_pair(r, b);
	}

	solve(price);
}