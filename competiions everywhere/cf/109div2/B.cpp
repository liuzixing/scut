#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>
#include <stack>

using namespace std;

struct node{
	int a,b;
}c[1001];
int n,ans,now;
bool cmp(node x,node y){
	if (x.b == y.b)
		return x.a > y.a;
	return x.b > y.b;
}
int main(){
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d %d",&c[i].a,&c[i].b);
	sort(c,c + n,cmp);
	now = 1;
	for (int i = 0;i < n;i++){
		if (!now)
			break;
		now--;
		ans += c[i].a;
		now += c[i].b;
	}
	printf("%d\n",ans);
}