
// I will try this and try this on my own
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&arr,int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}
void threeWayPartition(vector<int>& ar,int a, int b)
{
	int aPointer=0,bPointer=ar.size()-1;
	for(int i=0;i<=bPointer;i++)
	{
		if(ar[i]<a)
		{
			swap(ar[aPointer],ar[i]);
			aPointer++;

		}
		else if(ar[i]>b)
		{
			swap(ar[bPointer],ar[i]);
			bPointer--;
			i--;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b;
		cin>>a>>b;
		vector<int>arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		threeWayPartition(arr,a,b);
		print(arr,n);
	}

}
