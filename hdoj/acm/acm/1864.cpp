#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,x,i,j;
	double q,t,d[35],f[35],ans,aa,bb,cc;
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
		    	d[x] = aa + bb + cc;
	    	}
		}
		memset(f,0,sizeof(f));
		ans = 0;
		for (i = 1;i <= x;i++)
		{
			for (j = 1;j <= i;j++)
			{
				f[i] = (f[j] + d[i] > f[i] && f[j] + d[i] <= q)? f[j] + d[i]:f[i];
			}
			ans = (ans < f[i]) ? f[i] : ans;
		}
		printf("%.2lf\n",ans);
	}
}