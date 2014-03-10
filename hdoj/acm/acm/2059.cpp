#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main()
{
	int i,j,n,c,t,l,vr,vt1,vt2,p[101];
	double s1,f[102],min;//s1ÍÃ×Ó£¬s2ÎÚ¹ê
	while (scanf("%d",&l) != EOF)
	{
		scanf("%d %d %d",&n,&c,&t);
		scanf("%d %d %d",&vr,&vt1,&vt2);
		for (i = 1;i <= n;i++)
		{
			scanf("%d",&p[i]);
		}
		p[0] = 0;
		p[n + 1] = l;
		s1 = 1.0 * l / vr;
		memset(f,0,sizeof(f));
		for (i = 1;i < n + 2;i++)
		{
			min = 0xfffffff;
			for (j = 0;j < i;j++)
			{
				int len = p[i] - p[j];
				double tem = len > c ? 1.0 * c / vt1 + (len - c + 0.0) / vt2 : 1.0 * len / vt1;
				if (j) 
				{
					tem += t;
				}
				tem += f[j];
				min = (min > tem) ? tem : min;
			}
			f[i] = min;
		}
		printf((s1 < f[n + 1]) ? "Good job,rabbit!\n":"What a pity rabbit!\n");
	}

}