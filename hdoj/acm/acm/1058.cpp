#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	__int64 f[5843],t;
	int n,i,j = 1,k = 1,l = 1,m = 1;
	f[1] = 1;
	for (i = 2;i < 5843;i++)
	{
		f[i] = 2000000000000;
		if (f[i] > f[j] * 2)
		{
			f[i] = f[j] * 2;
			t = f[i];
		}
		if (f[i] > f[k] * 3)
		{
			f[i] = f[k] * 3;
			t = f[i];
		}
		if (f[i] > f[l] * 5)
		{
			f[i] = f[l] * 5;
			t = f[i];
		}
		if (f[i] > f[m] * 7)
		{
			f[i] = f[m] * 7;
			t = f[i];
		}
		j = (f[j] * 2 == t) ? j + 1:j;
		k = (f[k] * 3 == t) ? k + 1:k;
		l = (f[l] * 5 == t) ? l + 1:l;
		m = (f[m] * 7 == t) ? m + 1:m;
	}
	while (cin >> n && n)
	{
		switch(n % 100)
		{
		case 11:
		case 12:
		case 13:printf("The %dth humble number is %I64d.\n",n,f[n]);continue;
		default: break;
		}
		switch(n % 10)
		{
		case 1:printf("The %dst humble number is %I64d.\n",n,f[n]);break;
		case 2:printf("The %dnd humble number is %I64d.\n",n,f[n]);break;
		case 3:printf("The %drd humble number is %I64d.\n",n,f[n]);break;
		default :printf("The %dth humble number is %I64d.\n",n,f[n]);break;
		}
	}
}