#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
	if (n == 1)
		cout << "1" << endl;
	else
	{
		print(n - 1);
		cout < k < n << endl;
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
		print(n);
	}
}
