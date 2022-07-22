#include<bits/stdc++.h>
using namespace std;

class Solution
{
	int ans( int n,int x,int y,int z,int *dp  )
    {
          if(n==0)return 0;
          else if(n<0)return INT_MIN;
          if(dp[n]!=-1)
          {
              return dp[n];
          }
          
          dp[n]= 1+ max({ans(n-x,x,y,z,dp),ans(n-y,x,y,z,dp),ans(n-z,x,y,z,dp)});
          return dp[n];
    }
    
    
    
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int cuts [] = {x,y,z};
        dp[0] = 0;
        for(int i = 1; i <= n;i++){
            for(int j = 0 ;j < 3;j++){
                if(i >= cuts[j]){
                    dp[i] = max(dp[i - cuts[j]], dp[i]);
                }
            }
            if(dp[i] > -1) dp[i]++;
        }
        return dp[n] <0?0:dp[n];
    }
};

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }
	return 0;
}