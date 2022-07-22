/*
 * Intro
 * solving problems recursively
 * we try to build the solution incrementally
 * removing those solutions which do not satisfy the constraints of the problem
 * */
/*
 * do
 * recur
 * undo*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void findPermutations(string s,int left,int right)
{
	if(left==right)
		cout<<s<<endl;
	else{

		int len = s.size();
		for(int i=left;i<=right;i++)
		{
			//do
			//cout<<"do ->"<<s<<endl;
			swap(s[left],s[i]);
			//cout<<"recur -> "<<s<<endl;
			//recur
			findPermutations(s,left+1,right);
			//undo
			//cout<<"undo -> "<<s<<endl;
			swap(s[left],s[i]);

		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		findPermutations(s,0,s.size()-1);
	}
}

