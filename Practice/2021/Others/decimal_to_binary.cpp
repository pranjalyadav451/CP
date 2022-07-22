// { Driver Code Starts
//Initial Template for C


#include <stdio.h>
#include <string.h>
 // } Driver Code Ends


//User function Template for C

void toBinary(int N)
{
    // your code here
    char s[100];
    int rem;
    int i=0;
    while(N!=0)
    {
    	rem=N%2;
    	N/=2;
    	s[i]=(char)(rem+48);
    	i++;
    }
    for (int j = strlen(s)-1; j >= 0; --j)
    {
    	printf("%c",s[j] );
    }
    printf("%d\n",i );
}

// { Driver Code Starts.

int main() {
	//code
	
	int t;
	scanf("%d", &t);
	
	
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    
	    toBinary(n);
	    printf("\n");
	}
	return 0;
}  // } Driver Code Ends