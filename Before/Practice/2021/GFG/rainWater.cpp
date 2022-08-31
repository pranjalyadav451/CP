#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int max=-1;
        int maxIndex=-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>max)
            {
                max=arr[i];
                maxIndex=i;
            }
        }
        cout<<"Maximum number is "<<max<<endl;
        //finding the second largest number
        int secondLargest=-1;
        int secIndex=-1;
        int rainWater=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>=secondLargest && j!=maxIndex)
            {
                secondLargest = arr[j];
                secIndex=j;
            }
            cout<<"Finding second largest is "<<secondLargest<<endl;
        }
        cout<<"Second Largest number is "<<secondLargest<<endl;
        if(secondLargest==-1)
            cout<<rainWater<<endl;
        else
        {
            int k=secIndex<maxIndex?secIndex:maxIndex;
            for(;k<maxIndex;k++)
            {
                if(secondLargest - arr[k]>0)
                {
                    rainWater+=secondLargest-arr[k];

                }
            }
            cout<<rainWater<<endl;
        }
    }
	return 0;
}