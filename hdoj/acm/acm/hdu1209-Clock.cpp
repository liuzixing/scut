#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

struct node{
	int h,m;
	double angle;
}a[10];
bool cmp(node x,node y){
	if (x.angle == y.angle){
		if (x.h == y.h)
			return x.m < y.m;
		return x.h < y.h;
	}
	return x.angle < y.angle;
}
int main(){
	int t;
	char g;
	scanf("%d",&t);
	while (t--){
		for (int i = 0;i < 5;i++){
			scanf("%d%c%d",&a[i].h,&g,&a[i].m);
			int h;
			if (a[i].h > 12)
				h = a[i].h - 12;
			else h = a[i].h;
			double l = (h + a[i].m / 60.0) * 30.0;
			a[i].angle = abs(l - a[i].m * 6.0);
			if (a[i].angle > 180)
				a[i].angle = 360 - a[i].angle;
		}
		sort(a,a + 5,cmp);

		printf("%02d:%02d\n",a[2].h,a[2].m);
	}
}