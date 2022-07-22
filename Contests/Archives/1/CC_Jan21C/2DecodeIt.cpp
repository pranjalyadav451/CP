#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char c;
		int count = 0;
		int b = 8;
		int val = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> c;
			// cout<<c<<endl;

			//decoding the string
			if (count < 4)
			{
				val += b * (int(c) - int('0'));
				b /= 2;
				count++;
			}

			//printing the string
			if (count == 4)
			{
				cout << static_cast<char>(val + int('a'));
				b = 8;
				count = 0;
				val = 0;
			}
		}
		cout << endl;
	}
	return 0;
}