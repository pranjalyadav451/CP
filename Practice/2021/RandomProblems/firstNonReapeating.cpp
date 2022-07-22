#include<bits/stdc++.h>
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

void freq(string A)
{
	unordered_map<char, int>fre;
	for (int i = 0; i < A.size(); ++i)
	{
		if (fre.count(A[i]) == 0)
			fre[A[i]] = 1;
		else
			fre[A[i]]++;
		deb2(A[i], fre[A[i]]);
	}
}


string solve(string A)
{
	queue<char> q;
	string B = "";
	map<char, int> times;

	int len = A.size();

	for (int i = 0; i < len; i++)
	{

		if (times.count(A[i]) == 0)
			times[A[i]] = 1;
		else
			times[A[i]]++;

		q.push(A[i]);

		while (!q.empty() and times[q.front()] > 1)
		{
			q.pop();
		}
		if (q.empty())
			B.push_back('#');
		else
			B.push_back(q.front());
	}

	return B;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		string A;
		cin >> A;
		// freq(A);
		cout << solve(A) << endl;
	}
}
