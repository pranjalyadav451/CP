#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<n;
	unordered_map<string,int> ourMap;
	//inser
	pair<string,int>p("abc",1);
	ourMap.insert(p);
	ourMap["def"]=2;
	cout<<ourMap["def"]<<endl;
	cout<<ourMap["abc"]<<endl;


	//checking presence of a key
	if(ourMap.count("ghi")>0)
	{
		cout<<"ghi is present"<<endl;
	}
	else
		cout<<"ghi is not present"<<endl;
	if(ourMap.count("ghi")>0)
	{
		cout<<"ghi is present"<<endl;
	}
	else
		cout<<"ghi is not present"<<endl;
	//erasing an element
	ourMap.erase("abc");
	cout<<ourMap.size()<<endl;
}
