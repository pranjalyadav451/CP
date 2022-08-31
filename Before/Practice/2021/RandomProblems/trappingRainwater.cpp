#include<bits/stdc++.h>

using namespace std;

int trappingWater(int h[], int n)
{
	int leftM=0,rightM=0;
	int left=0,right=n-1;
	long long int ans=0;
	while(left<right)
	{
		if(h[left]<h[right])
		{
			if(leftM<h[left])
				leftM=h[left];
			else
				ans+=leftM - h[left];
			left++;
			cout<<"left is->"<<left<<endl;
		}
		else
		{
			if(rightM<h[right])
				rightM=h[right];
			else
				ans+=rightM- h[right];
			right--;
			cout<<"right is ->"<<right<<endl;
		}
		cout<<ans<<endl;
	}
	return ans;
}

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
