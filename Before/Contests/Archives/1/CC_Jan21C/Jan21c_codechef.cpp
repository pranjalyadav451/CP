#include <iostream>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll int n,k,d;
		ll int arrSum=0;
		cin>>n>>k>>d;
		ll int dummy;
		for (int i = 0; i < n; ++i)
		{
			cin>>dummy;
			arrSum+=dummy;
		}
		if(arrSum/k>=d)
			cout<<d<<endl;
		else
			cout<<arrSum/k<<endl;
	}
}