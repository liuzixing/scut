#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

const int maxn = (1 << 18);
struct node{
	int p,c,ind;
}b[20001];
int k,n;
char name[101],f[maxn];
bool ans[maxn];
int sum[maxn];
int num,len;
bool cmp(node x,node y){
	if (x.c == y.c)
		return x.ind < y.ind;
	return x.c < y.c;
}

int lowbit(int x){
	return x&-x;
}

void insert(int x,int t){
	while(x<maxn){
		sum[x]+=t;
		x+=lowbit(x);
	}
}
int find(int k){
	int cnt=0,ans=0;
	for(int i=20;i>=0;i--){
		ans+=(1<<i);
		if(ans>=maxn || cnt+sum[ans]>=k)ans-=(1<<i);
		else cnt+=sum[ans];
	}
	return ans+1;
}

int main(){
	scanf("%d%s",&k,&name);
	scanf("%d",&n);
	for (int i = 0;i < n;i++){
		scanf("%d %c",&b[i].p,&b[i].c);
		b[i].ind = i;
	}
	sort(b,b + n,cmp);
	len = k * strlen(name);
	for (int i = 0;i < k;i++)
		for (int j = 0;j < strlen(name);j++)
			f[i * strlen(name) + j] = name[j];
	for (int i = 0;i < n;i++){
		memset(sum,0,sizeof sum);
		for (int j = 0;j < len;j++)
			if (f[j] == b[i].c)
				insert(j + 1,1);
		char tem = b[i].c;
		while (b[i].c == tem && i < n){
			int tem2 = find(b[i].p) - 1;
			ans[tem2] = 1;
			insert(tem2 + 1,-1);
			i++;
		}
		i--;
	}
	for (int i = 0;i < len;i++)
		if (!ans[i])
			printf("%c",f[i]);
	puts("");

}