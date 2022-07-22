#include<bits/stdc++.h>
using namespace std;
void print(vector<int>a)
{

    cout<<"size ->"<<a.size()<<endl;
    //cout<<"----------------------"<<endl;
    for(int i =0;i<a.size();i++)
        cout<<"index ->"<<i<<"  value ->"<<a[i]<<endl;
    cout<<"----------------------"<<endl;
}

vector<int> getRow(int r)
{
        vector<int>past={};
        vector<int>present={1};

        for(int i =0; i<r+1;i++)
        {
            present.resize(i+1);
            for(int j=0;j<(i+1);j++)
            {
				if(j==0 || j==i)
					present[j]=1;
				else{
					present[j]=past[j-1]+past[j];
				}
            }
            past=present;
        }
        return present;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>res;
		res = getRow(n);
		for(int i =0;i<res.size();i++)
			cout<<res[i]<<"  ";
		cout<<endl;
	}
}

