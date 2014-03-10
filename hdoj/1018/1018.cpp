#include<iostream>
#include<cmath>
#include <stdio.h>

using namespace std;
 
int main()
{
    int n,i,t;
    double result;
	cin >> t;
    while (t--)
	{
        scanf("%d",&n);
        result = 1;
        for(i=1;i<=n;++i)
            result += log10(double(i));
        printf("%d\n",int(result));
    }
    return 0;
} 
