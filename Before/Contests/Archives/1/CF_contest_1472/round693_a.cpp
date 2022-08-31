#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w,h,n;
		cin>>w>>h>>n;

		int count=1;
		int i=1;
		while(w%2==0 || h%2==0)
		{
			if(w%2==0)
			{	
				w/=2;
				count+=i;
				i*=2;
					
			}
			if(h%2==0)
			{
					h/=2;
				count+=i;
					i*=2;
			}
			if(count>=n)
				break;
		}
		if(count>=n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}