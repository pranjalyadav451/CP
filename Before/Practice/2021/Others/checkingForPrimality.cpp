#include<bits/stdc++.h>
using namespace std;
// int func()
// {

// }
bool isPrime(int i)
{
        if(i<=1)
            return false;
        else if(i==2 || i==3)
            return true;
        else if(i%2==0 || i%3==0)
            return false;
        
        for(int j=5;j*j<=(i);j+=6)
        {

            if(i%(j+2)==0 || i%j==0)
            {
                return false;
                cout<<i<<"\t"<<j<<endl;
            }
        }
        return true;
}
int countPrimes(int n)
{
	vector<bool>primeNum(n+1,true);
	// we are declaring the size n+1 because the test case 
	//can also contain zero and to take care of that zero 
	//we are declaring array onesize bigger than we require
	//in this problem we are required to find number of
	//primes strictly less than n
	primeNum[0]=false;
	primeNum[1]=false;
	int count=0;

	for (int i = 2; i * i< n; ++i)	
	{
		if (primeNum[i])
		{
			for (int j = i; j*i < n; ++j)
			{
				primeNum[j*i]=false;
			}
		}
	}
	// we are traversing till the index n-1 because the
	//problem requires us to find the count below n
	for (int k = 0; k < n; ++k)
	{
		if(primeNum[k])
		{
			cout<<k<<"\t";
			count++;
		}
	}
	return count;
}
int main()
{
	// for(int i=0;i<100;i++)
	// {
	// 	if(isPrime(i))
	// 		cout<<endl<<i<<" is PRIME"<<endl<<endl;
	// 	else
	// 		cout<<i<<" not prime"<<endl;
	// }
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<countPrimes(n)<<endl;
	}
}
