//U:把区间[l,r]覆盖成1
//I:把[-∞,l)(r,∞]覆盖成0
//D:把区间[l,r]覆盖成0
//C:把[-∞,l)(r,∞]覆盖成0 , 且[l,r]区间0/1互换
//S:[l,r]区间0/1互换
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1|1

const int maxn = 131072;
bool hash[maxn];
int cover[maxn << 2];
int XOR[maxn << 2];
void FXOR(int rt){
	if (cover[rt] != -1) cover[rt] ^= 1;
	else XOR[rt] ^= 1;
}
void PushDown(int rt){
	if (cover[rt] != -1){
		cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
		XOR[rt << 1] = XOR[rt << 1|1] = 0;
		cover[rt] = -1;
	}
	if (XOR[rt]){
		FXOR(rt << 1);
		FXOR(rt << 1 | 1);
		XOR[rt] = 0;
	}
}
void update(char op,int L,int R,int l,int r,int rt){
	if (L <= l && r <= R){
		if (op == 'U'){
			cover[rt] = 1;
			XOR[rt] = 0;
		}else if (op == 'D'){
			cover[rt] = 0;
			XOR[rt] = 0;
		}else if (op == 'C' || op == 'S')
			FXOR(rt);
		return;
	}
	PushDown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(op,L,R,lson);
	else if (op == 'I' || op == 'C')
		XOR[rt << 1] = cover[rt << 1] = 0;
	if (m < R) update(op,L,R,rson);
	else if (op == 'I' || op == 'C')
		XOR[rt << 1|1] = cover[rt << 1|1] = 0;
}
void query(int l,int r,int rt){
	if (cover[rt] == 1){
		for (int it = l;it <= r;it++)
			hash[it] = true;
		return;
	}
	else if (cover[rt] == 0) return;
	if (l == r) return;
	PushDown(rt);
	int m = (l + r) >> 1;
	query(lson);
	query(rson);
}
int main()
{
	char op,l,r;
	int a,b;
	while (~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r))
	{
		a <<= 1,b <<= 1;
		if (l == '(') a++;
		if (r == ')') b--; 
		if (a > b)
		{
			if (op == 'C' || op == 'I')
				cover[1] = XOR[1] = 0;
		}
		else
			update(op,a,b,0,maxn,1);
	}
		query(0,maxn,1);
		bool flag = false;
		int s = -1,e;
		for (int i = 0;i <= maxn;i++)
		{
			if (hash[i])
			{
				if (s == -1) s = i;
				e = i;
			}
			else if (s != -1)
			{
				if (flag) printf(" ");
				flag = true;
				printf("%c%d,%d%c",(s&1)?'(':'[',s >> 1,(e+1)>>1,(e&1)?')':']');
				s = -1;
			}
		}
		if (!flag) printf("empty set");
		puts("");
		return 0;
}
