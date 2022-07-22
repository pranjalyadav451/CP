#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n>>k;

        // cout<<n<<endl;
        // cout<<"------------------"<<endl;
    	int num=n;
    	int dummy;
    	ll sum=0;
    	priority_queue<int>boxes;
        int hello =0;

    	while(n--)
    	{
    		cin>>dummy;
    		boxes.push(dummy);
    		sum+=dummy;
    	}

    	int count=0;
    	ll mike = 0;
    	ll tracy = 0;
        // bool alt = true;

    	if(num>=2 && sum>=2*k)
    	{
            // cout<<"num is - "<<num<<endl;
    		while(num!=0)
    		{
                // cout<<"num is - "<<num<<endl;
    			if((num% 2 ==1 && mike < k) || tracy >=k)
                {
                    mike += boxes.top();
                    // cout<<"Mike is at - "<<mike<<endl;
                    boxes.pop();
                    // alt = false;
                }
                if((num%2 ==0 && tracy<k) || mike >= k)
                {
                    tracy += boxes.top();
                    // cout<<"Tracy is at - "<<tracy<<endl;
                    boxes.pop();
                    // cout<<"tracy is - "<<endl;
                    // alt = true;
                }

                count++;

                if(mike>=k && tracy >= k)
                {
                    cout<<count<<endl;
                    break;
                }

                num--;
                // cout<<"The top of the box is - "<<boxes.top()<<endl;
    		}
            if(mike<k || tracy < k)
                {
                    cout<<-1<<endl;
                    // break;
                }
    	}
        else 
            cout<<-1<<endl;
            // cout<<-1<<endl;
        // cout<<"------------------------"<<endl;

    }
    return 0;
}