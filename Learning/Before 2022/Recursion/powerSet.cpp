#include<bits/stdc++.h>
using namespace std;
vector<string>power;
// At each step we have two choices whether or not we have to
// include the element
// We exit when we have exhausted the given string

void powerSet(string s, string current, int i, int right)
{
	if (i > right)
		power.push_back(current);
	else
	{
		(powerSet(s, current, i + 1, right));
		(powerSet(s, current + s[i], i + 1, right));
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int right = s.size() - 1;
		string current = "";
		powerSet(s, current, 0, right);
		for (const string a : power)
			cout << a << endl;
	}
}
