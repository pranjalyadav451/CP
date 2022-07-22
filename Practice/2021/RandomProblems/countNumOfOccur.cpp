#include <iostream>
#include<string>
using namespace std;
int num(string s, char c)
{
	int found=s.find(c);
	int n=1;
	cout<<found<<endl;
	for(int i=found+1;i<s.size();i++)
	{
		if(s.find(c,i)!=string::npos)
		{
			cout<<s[i]<<endl;
			i=s.find(c,i);
			n++;
		}

	}
	return n;
}
/*char findTheDifference(string s, string t)
{
	int i=0;
	for(;i<t.size();i++)
	{
		if(s.find(t[i])==string::npos)
			break;
		else
		{
			if(num(t,t[i])>num(s,t[i]))
			{
				cout<<num(t,t[i])<<endl;
				cout<<num(s,t[i])<<endl;
				break;
			}
		}
	}
	return t[i];
}
*/
int main()
{

	string as = "aaa";
	cout<<num(as,'a')<<endl;
	//string s,t;
	//cin>>s;
	//cin>>t;
	//cout<<findTheDifference(s,t)<<endl;
    return 0;
}
