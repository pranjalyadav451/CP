#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int>a)
{
	int max=INT_MIN;
	for(auto &element:a)
		if(max<element)
			max=element;
	return max;
}
void print(vector<int> v)
{
	for(auto &element:v)
		cout<<element<<endl;
	cout<<endl;
}
int getMaximumGenerated(int n) 
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;

	vector<int>v(n+1,-1);
	v[0]=0;
	v[1]=1;
    int max = 1;
	for (int i = 2; i <= n; ++i)
	{
		if(i%2==1)
		{
			v[i] = v[(i-1)/2] + v[(i+1)/2];
		}
		else
		{
			v[i]=v[i/2];
		}
        if(max<v[i])
            max=v[i];
	}
	return max;     
}

int main()
{
	int t; 
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<"maximum ->"<<getMaximumGenerated(n)<<endl;
	}
	for(int i =0;i<=100;i++)
		cout<<i<<endl;
}
