#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int father[20000],pd,n,m,c;
bool visit[20000];
 
int getfather(int v)
{
    if (father[v] == v)
	{
       return v;
	}
    return father[v] = getfather(father[v]);
}
 
bool same(int x,int y)
{
     return (getfather(x) == getfather(y));
}
void judge(int x,int y)
{
    int fx,fy;
    fx = getfather(x);
    fy = getfather(y);
    if (fx == fy)
	{
		return ;
	}
	if (visit[fx] && !visit[fy])
	{
		father[fy] = fx;
	}
	if (!visit[fx] && visit[fy])
	{
		father[fx] = fy;
	}
}
void work()
{
	 memset(visit,0,sizeof(visit));
     int i,a,b,ans = 0 ;
	 scanf("%d %d %d",&n,&m,&c);
     for ( i = 0; i < n; i++)
	 {
         father[i] = i;
	 }
	 scanf("%d",&pd);
	 for (i = 1;i <= c;i++)
	 {
		 scanf("%d",&a);
		 visit[a] = 1;
	 }
     for ( i = 1; i <= m; i++)
	 {
         scanf("%d %d",&a,&b);
		 if (a != pd && b != pd)
		 {
			 judge(a,b);
		 }
	 }
	 for (i = 0;i < n;i++)
	 {
		 if (!visit[getfather(i)] && i != pd)
		 {
			 ans++;
		 }
	 }
	 printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		work();
	}
}