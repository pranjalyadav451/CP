//this is a really good program that I did but I am not able 
//do anymore of this because I am exhausted because of my 
//routine
#include<iostream>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
void printPrime(int n)
{
	int count = 0;
	for(int i=6;i<=n;i++)
	{
		if(isPrime(i))
			cout<<i<<endl;
	}
}
int main()
{
	int n;
	//cout<<"Primes upto  : "<<endl;
	cin>>n;
	printPrime(n);
}
