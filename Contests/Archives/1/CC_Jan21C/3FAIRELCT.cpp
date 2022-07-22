#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	priority_queue<int,std::vector<int>,greater<int>> john;
    	priority_queue<int> jack;

    	int dummy=0;
    	ll jackSum=0,johnSum=0;

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>dummy;
    		johnSum+=dummy;
    		john.push(dummy);
    	}
    	for (int j = 0; j < m; ++j)
    	{	    		
    		cin>>dummy;
    		jackSum+=dummy;
    		jack.push(dummy);
    	}
    	// cout<<john.top()<<" "<<jack.top()<<endl;
    	// cout<<johnSum<<" "<<jackSum<<endl;
    	int number=0;
    	int small = n >m ? m : n;
    	while(johnSum<=jackSum && small--)
    	{
    		johnSum = johnSum - john.top()+jack.top();
    		jackSum = jackSum - jack.top() + john.top();
    		jack.pop();
    		john.pop();
    		number++;
    	}
    	
    	if(johnSum>jackSum)
    		cout<<number<<endl;
    	else 
    		cout<<-1<<endl;



    }
    return 0;
}