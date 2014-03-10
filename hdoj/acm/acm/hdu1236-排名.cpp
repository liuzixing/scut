#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;

int n,m,g,t,a,ans;
int p[151];
struct node{
	__int64 rank;
	char name[25];
	int score;
}f[10005];
bool cmp(node x,node y){
	if (x.score == y.score)
		return (strcmp(x.name,y.name) < 0);
	return x.score > y.score;
}
int main(){
	while (~scanf("%d",&n)){
		if (n == 0) break;
		scanf("%d%d",&m,&g);
		ans = 0;
		for (int i = 1;i <= m;i++)
			scanf("%d",&p[i]);
		for (int i = 0;i < n;i++){
			scanf("%s %d",&f[i].name,&t);
			f[i].score = 0;
			while (t--){
				scanf("%d",&a);
				f[i].score += p[a];
			}
			if (f[i].score >= g)
				ans++;
		}

		sort(f,f + n,cmp);
		printf("%d\n",ans);
		for (int i = 0;i < n && ans > 0;i++)
			if (f[i].score >= g){
				printf("%s %d\n",f[i].name,f[i].score);
				ans--;
			}
	}
}