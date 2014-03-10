#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;

int dx,dy,k;
__int64 x,y,ans,tx,ty,n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	scanf("%I64d%I64d%d",&x,&y,&k);
	for (int i = 0;i < k;i++){
		scanf("%d %d",&dx,&dy);
		tx = ty = 0;
		if (dx > 0)
			tx = (n - x) / dx;
		else if (dx < 0)
			tx = (x - 1) / (-dx);
		if (dy > 0)
			ty = (m - y) / dy;
		else if (dy < 0)
			ty = (y - 1) / (-dy);
		if (dx == 0)
			tx = ty;
		else if (dy != 0)	
			tx = min(tx,ty);
		ans += tx;
		x = x + tx * dx;
		y = y + tx * dy;
	}
	printf("%I64d\n",ans);
}
