#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int n) 
{
	string res;
	int rem;
	int temp=n;
    while(temp!=0)
    {
        rem = temp%26;
        temp/=26;
        if(rem!=0)
        	res.push_back(static_cast<char>(64+rem));
        else
        {
        	res.push_back('Z');
        	temp--;
        }
    }
    //more elegant solution in the 2nd last leetcode submission
    /*
    https://leetcode.com/problems/excel-sheet-column-title/discuss/784392/C%2B%2B-Oneliner-Recursive-Vs.-Iterative-Solutions-Explained-100-Time-~95-Space
    */
    reverse(res.begin(),res.end());
    return res; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        cout<<convertToTitle(n)<<endl;
    }
}