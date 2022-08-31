#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void run()
{
	int n;
	cin >> n;

	string S;
	cin >> S;

	int ctT = 0, ctM = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] == 'T')
			ctT++;
		else
			ctM++;

		if (ctT < ctM)
		{
			cout << "NO\n";
			return;
		}
	}

	ctT = 0, ctM = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (S[i] == 'T')
			ctT++;
		else
			ctM++;

		if (ctT < ctM)
		{
			cout << "NO\n";
			return;
		}
	}

	if (ctT != 2 * ctM)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		run();
}