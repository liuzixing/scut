#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
 
int main()
{
	int a[1002],n,i,j;
	while (cin >> n)
	{
		for (i = 0;i <n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		cout << a[n-2]<< endl;
	}

}