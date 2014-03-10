/*
ID: benbenq1
PROG: fracdec
LANG: C++
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
char tem[100100];
char ans[100100];
int lastrem[100100];
int main()
{
	int d,n,k,i,rem,len;
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	scanf("%d %d",&n,&d);
	sprintf(ans,"%d.",n / d);
	for (i = 0;i < 100100;i++)
		lastrem[i] = -1;
	rem = n % d;
	for (i = 0;;i++)
	{
		if (rem == 0)
		{
			if (i == 0)
				sprintf(ans + strlen(ans),"0");
			else
				sprintf(ans + strlen(ans),"%s",tem);
			break;
		}
		if (lastrem[rem] != -1)
		{
			k = lastrem[rem];
			sprintf(ans + strlen(ans),"%.*s(%s)",k,tem,tem + k);
			break;
		}
		lastrem[rem] = i;
		n = rem * 10;
		tem[i] = n / d + '0';
		rem = n % d;
	}
	len = strlen(ans);
	for (i = 0;i < len;i += 76)
		printf("%.76s\n",ans + i);
}
