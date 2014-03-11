#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,t1,which;
struct node{
	int c,t,num;
}f[1001];
double ans = 1e13;
double sum,tem;
bool cmp(node x,node y){
	if (x.t == y.t)
		return x.c > y.c;
	return x.t < y.t;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i = 0;i < n;i++){
		scanf("%d%d",&f[i].c,&f[i].t);
		sum += f[i].c;
		f[i].num = i + 1;
		if (f[i].t == 1)
			t1++;
	}
	sort(f,f + n,cmp);
	int m = min(t1,k);
	for (int i = 1;i <= m;i++){
		tem = sum;
		for (int j = 0;j < i - 1;j++)
			tem -= 0.5 * f[j].c;
		if (k == i)
			tem -= min(f[t1 - 1].c,f[n - 1].c) * 0.5;
		else
			tem -= f[t1 - 1].c * 0.5;
		if (tem < ans)
			ans = tem;
	}
	printf("%.1lf\n",ans);
	for (int j = 0;j < k - 1;j++)
		printf("1 %d\n",f[j].num);
	printf("%d",n - k + 1);
	for (int i = k - 1;i < n;i++)
		printf(" %d",f[i].num);
	puts("");
}