#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int  MAXN = 5100;
struct node
{
	int l,w;
}a[MAXN];
int opt[MAXN];
int n,ans;

bool cmp(node x,node y)
{
	if (x.l == y.l)
		return x.w < y.w;
	return x.l < y.l;
}
void init()
{
      int i;
      scanf("%d",&n);
      for (i = 1; i <= n; i++)
      {
           scanf("%d %d",&a[i].l,&a[i].w);
           opt[i] = 0;
      }
      ans = 1;
}

void work()
{
      int i,j;
      a[0].w = 20000;     
      for (i = 1; i<=n; i++)
           for (j = i-1; j>=0; j--)
                 if (a[i].w < a[j].w && opt[i] < opt[j]+1)
                      opt[i] = opt[j]+1;
      for (i = 1; i<=n; i++)
           ans = ans>opt[i]?ans:opt[i];
}

int main()
{
      int i,t;
      scanf("%d",&t);
      for (i = 0; i<t; i++)
      {
           init();
		   sort(a + 1,a + n + 1,cmp);
           work();
           printf("%d\n",ans);
      }
      return 0;

}

