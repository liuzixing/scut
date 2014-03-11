#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n,d,tot,k;
struct node{
	char a[25],b[25];
	int t;
}f[1002],ans[1002];
int main(){
	scanf("%d%d",&n,&d);
	for (int i = 0;i < n;i++)
		scanf("%s%s%d",&f[i].a,&f[i].b,&f[i].t);
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n ;j++)
			if (f[j].t - f[i].t > 0 && f[j].t - f[i].t <= d && !strcmp(f[i].a,f[j].b) && !strcmp(f[i].b,f[j].a))
				ans[tot++] = f[i];
	if (!tot) {printf("0\n");return 0;}
	k = tot;
	for (int i = 0;i < tot - 1;i++)
		for (int j = i + 1;j < tot;j++)
			if ((!strcmp(ans[i].a,ans[j].a) && !strcmp(ans[i].b,ans[j].b)) 
				||(!strcmp(ans[i].a,ans[j].b) && !strcmp(ans[i].b,ans[j].a))){
				ans[i].a[0] = '-';
				k--;
			}
	printf("%d\n",k);
	for (int i = 0;i < tot;i++)
		if (ans[i].a[0] != '-')
		printf("%s %s\n",ans[i].a,ans[i].b);
}