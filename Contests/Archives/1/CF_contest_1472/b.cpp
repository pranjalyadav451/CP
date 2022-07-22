#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0,a=0,b=0;
        //check above if the two variables 'a' and 'b' are necessary
        cin>>n;

        int dummy=0;
        int c1=0,c2=0;

        for (int i = 0; i < n; ++i)
        {
            cin>>dummy;
            if(dummy==1)
                c1++;
            else
                c2++;
        }
        // cout<<"c1 is - "<<c1<<endl;
        // cout<<"c2 is - "<<c2<<endl;

        if(c1%2==0)
        {

            if(c1==0 && c2%2==1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
    return 0;
}