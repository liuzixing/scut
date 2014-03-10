#include <cstdio>
#include <cmath>
struct node
{
	int l,r,rest;
}tree[2000001];
char name[500001][12];
int num[500001];
const int max[35][2] = {498960,200,332640,192,277200,180,221760,168,166320,160,110880,144,83160,128,55440,120,50400,108,45360,100,27720,96,25200,90,20160,84,15120,80,10080,72,7560,64,5040,60,2520,48,1680,40,1260,36,840,32,720,30,360,24,240,20,180,18,120,16,60,12,48,10,36,9,24,8,12,6,6,4,4,3,2,2,1,1};
void maketree(int p,int x,int y)
{
	tree[p].l = x;
	tree[p].r = y;
	tree[p].rest = y - x + 1;
	if (x == y)
		return;
	int mid = (x + y) >> 1,next = p << 1;
	maketree(next,x,mid);
	maketree(next | 1,mid + 1,y);
}
int query(int n,int p = 1)
{
	if (tree[p].l == tree[p].r)
		return tree[p].l;
	int next = p << 1;
	if (n <= tree[next].rest)
		return query(n,next);
	else
		return query(n - tree[next].rest,next | 1);
}
void deletenum(int n,int p = 1)
{
	tree[p].rest--;
	if (tree[p].l == tree[p].r)
		return;
	int next = p << 1,mid = (tree[p].l + tree[p].r) >> 1;
	if (n <= mid)
		deletenum(n,next);
	else
		deletenum(n,next | 1);
}
int main()
{
	int n,k,i,now,nn,x,p;
	while (scanf("%d %d",&n,&k) != EOF)
	{
		p = 0 ;
		while (n < max[p][0])
			p++;
		x = max[p][0];
		maketree(1,1,n);
		for (i = 1;i <= n;i++)
		{
			scanf("%s",&name[i]);
			scanf("%d",&num[i]);
		}
		i = 1;
		nn = n;
		now = k;

		while (i < x)
		{
			n--;
			if (n > 0)
			{
				deletenum(k);

				if (num[k] > 0)
					now = (now - 1 + num[k] % n) % n;
				else
					now = (now  +  n - (-num[k]) % n ) % n;
				//找出下一个出列的人的相对排名，
				if (now == 0)
					now = n;
				k = query(now);
				i++;
				if (k == 0)
					k = nn;
			}	
		}
		printf("%s %d",name[k],max[p][1]);
	}
}
