#include <iostream>
#include <stdio.h>
using namespace std;

int  main()
{
	int N,ans,n,m,i,j;
	cin >> N;
	while (N--)
	{
		int count = 0;
	    while (cin >> n >> m && (n != 0 || m != 0) )
	    {
	    	count ++;
        	ans = 0;
		    for (i = 1;i < n - 1;i++)
	    	{
		    	for (j = i + 1;j < n;j++)
		    	{
		    		if ((i * i + j * j + m) % (i * j) == 0 )
		    		{
			    		ans++;
			    	}
		    	}
		    }
			printf("Case %d: %d\n",count,ans);
	    }
		if  (N > 0)
		{
			printf("\n");
		}
	}
}