#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
struct ret
{
	int lx,ly,rx,ry;
}a[300];
int x[1000],y[1000];
struct ans
{
	bool f;
	int x,y;
};
ans solve(int len,int n,int tw,int th,int w,int h)
{
	int i,j,k;
	ans t;
	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			if(x[j]+tw<=w && y[i]+th<=h)
			{
				for(k=0;k<n;k++)
					if(x[j]>=a[k].rx || x[j]+tw<=a[k].lx || y[i]>=a[k].ry || y[i]+th<=a[k].ly)
						continue;
					else
						break;
				if(k==n)
				{
					t.f=true;
					t.x=x[j];
					t.y=y[i];
					return t;
				}
			}
	t.f=false;
	return t;
}
int main()
{
	//freopen("test.in","r",stdin);
	int i,j,w,h,T,n,len,tw,th;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&w,&h);
		x[0]=0;y[0]=0;len=1;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&a[i].lx,&a[i].ly,&a[i].rx,&a[i].ry);
			x[len]=a[i].lx;y[len++]=a[i].ly;
			x[len]=a[i].rx;y[len++]=a[i].ry;
		}
		sort(x,x+len);
		sort(y,y+len);
		scanf("%d %d",&tw,&th);
		ans temp=solve(len,n,tw,th,w,h);
		if(temp.f)
			printf("%d %d\n",temp.x,temp.y);
		else
			printf("Fail!\n");
	}
	return 0;
}
