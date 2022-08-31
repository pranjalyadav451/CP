#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a;
	cin>>a;
	cout<<a<<endl;
	vector<int>m{1,2,34,5};
	for(auto i:m)
	{
		cout<<i;
	}
	for(int i:m)
	{
		cout<<i<<endl;
	}
}
