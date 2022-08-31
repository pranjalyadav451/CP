#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>a[j];
		}
		int alice=0,bob=0;
		for (int i = 0; i < n; ++i)
		{
			if (alice<=bob)
			{
				alice+=a[i];
			}
			else
				bob+=a[i];
		}
		if(alice==bob)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}