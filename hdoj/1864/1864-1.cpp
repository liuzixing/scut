#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int d[35],f[3000010];

void dp(int m,int x)
{
	memset(f,0,sizeof(f));
	for (int i = 1;i <= x;i++)
	{
		for (int j = m;j >= d[i];j--)
		{
			f[j] = (f[j - d[i]] + d[i] > f[j]) ? f[j - d[i]] + d[i] :f[j];
		}
	}
	printf("%.2lf\n",f[m] / 100.0);
}

int main()
{
	int n,m,x;
	double q,t,aa,bb,cc;
	char c;
	while (scanf("%lf %d",&q,&n) && n)
	{
		x = 0;
		memset(d,0,sizeof(d));
		while (n--)
		{
			bool flag = true;
			scanf("%d",&m);
			aa = 0;bb = 0;cc = 0;
			while (m--)
			{
				scanf(" %c:%lf",&c,&t);
				switch(c)
				{
				case 'A':aa +=t;break;
				case 'B':bb +=t;break;
				case 'C':cc +=t;break;
				default:flag =false;break;
				}
		    	if ((aa > 600) || (bb > 600) || (cc > 600) || (aa + bb + cc > 1000))
		    	{
		    		flag = false;
		    	}
			}
		    if (flag)
	    	{
				x++;
		    	d[x] = int((aa + bb + cc) * 100);
	    	}
		}
		
		dp(int(q * 100),x);
	}
}