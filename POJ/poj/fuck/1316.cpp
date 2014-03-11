#include <iostream>
using namespace std;

int main()
{
	int a[10001] = {0},i,j,k;
	for (i = 1;i < 10000;i++)
	{
		k = i;
		while (k < 10000)
		{
            int sum = k;
		    j = k;
		    while (j)
		    {
		       	sum +=j % 10;
		    	j /= 10;
	    	}
			if (sum <10000)
			{
				a[sum] = 1;
			}
			k = sum;
		}	
	}
	a[1] = 0;
	for (i = 1;i <10000;i++)
	{
		if (a[i] == 0)
		{
			cout << i << endl;
		}
	}
}