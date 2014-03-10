#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct node{
	int s,p,num;
}f[101];
int n,a,b,c[6],score[101];

bool cmp(node x,node y){
	if (x.p == y.p)
		return x.s < y.s;
	return x.p > y.p;
}
int getpoint(bool x,int p){
	int y;
	switch(p){
	case 5:y = 100;break;
	case 4:y = 90;break;
	case 3:y = 80;break;
	case 2:y = 70;break;
	case 1:y = 60;break;
	case 0:y = 50;break;
	}
	if (x && p != 5 && p != 0)
		y += 5;
	return y;
}
int main(){
	while (~scanf("%d",&n)){
		if (n == -1) break;
		memset(c,0,sizeof c);
		for (int i = 0;i < n;i++){
			scanf("%d %d:%d:%d",&f[i].p,&a,&b,&f[i].s);
			f[i].s += a * 3600 + b * 60;
			f[i].num = i;
			c[f[i].p]++;
		}

		sort(f,f + n,cmp);
		int lastp = 6,now = 0;
		for (int i = 0;i < n;i++){
			if (lastp != f[i].p){
				lastp = f[i].p;
				now = 1;
			}
			if (lastp == f[i].p){
				score[f[i].num] = getpoint(now <= c[lastp] / 2,lastp);
				now++;
			}
		}
		for (int i = 0;i < n;i++)
			printf("%d\n",score[i]);
		puts("");
	}
}