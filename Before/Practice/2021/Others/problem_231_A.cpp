#include<iostream>
using namespace std;
int main()
{
	int n=0;
	cin>>n;
	int toSolve=0;
	while(n--)
	{
		const int numberOfProblems =3;
		int dummy;
		int count=0;
		for (int i = 0; i < numberOfProblems; ++i)
		{
			cin>>dummy;
			if(dummy==1)
				count++;
		}
		if(count>=2)
			toSolve++;
	}
	cout<<toSolve;

}