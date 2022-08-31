#include<bits/stdc++.h>
using namespace std;
string rev = "";
void revStr(string s, int i, int right)
{
	// cout << "pushing back" << s[i] << endl;

	if (i == right)
	{
		rev += (s[i]) ;
	}
	else {
		revStr(s, i + 1, right);
		rev += (s[i]);
	}
}
int main()
{
	int t; 	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = 0;
		int right = n - 1;
		revStr(s, i, right);
		cout << rev << endl;
	}
}
