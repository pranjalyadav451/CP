// I will try this and try this on my own
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}
void sort(int arr[],int n){
	int low=0;
	int high = n-1;
	for(int i=0;i<=high;i++)
	{
		if(arr[i]==0)
		{
			swap(arr[i],arr[low]);
			low++;
		}
		else if(arr[i]==2)
		{
			cout<<"i ->"<<i<<"  high->"<<high<<endl;
			swap(arr[i],arr[high]);
			high--;
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
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,n);
		print(arr,n);
	}

}
