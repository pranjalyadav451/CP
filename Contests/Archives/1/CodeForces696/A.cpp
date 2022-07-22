#include <bits/stdc++.h>
using namespace std;
string getA(string b, int len)
{
	string res;
	res.push_back('1');
	int preSum = (int)b[0] + 1 - '0';
	for (int i = 1; i < len; i++)
	{
		if (preSum == 1)
		{
			if (b[i] == '0')
				res.push_back('0');
			else
				res.push_back('1');
			// preSum = res[i] + b[i] - 2 * '0';
		}
		else if (preSum == 2)
		{
			if (b[i] == '0')
				res.push_back('1');
			else
				res.push_back('0');
		}
		else
			res.push_back('1');

		preSum = res[i] + b[i] - 2 * '0';
	}

	return res;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int len = 0;
		cin >> len;
		string b;
		cin >> b;
		cout << getA(b, len) << endl;
	}
}
/*
1
110
100
101101
101110
*/