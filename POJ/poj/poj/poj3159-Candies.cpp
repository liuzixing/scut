#include<iostream>
#include <cstdio>
using namespace std;
const int nMax = 30005;
const int mMax = 150005;
const int inf = 1000000000;

struct node
{
	int v, w, next;
}edge[mMax];
int n, edgeHead[nMax], dict[nMax];
int stack[nMax];
bool vis[nMax];

void spfa(){
	for(int i = 2; i <= n; i ++)
		dict[i] = inf;
	dict[1] = 0;
	int top = 0;     //  spfa的堆栈实现模板。
	stack[++ top] = 1;
	vis[1] = true;
	while(top)
	{
		int u = stack[top --];
		for(int p = edgeHead[u]; p != 0; p = edge[p].next)
		{
			int v = edge[p].v;
			if(dict[v] > dict[u] + edge[p].w)
			{
				dict[v] = dict[u] + edge[p].w;
				if(!vis[v])
				{
					vis[v] = true;
					stack[++ top] = v;
				}
			}
		}
		vis[u] = false;
	}
}

int main(){
	int m, i;
	scanf("%d%d", &n, &m);
	int k = 1;
	while(m --)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[k].v = v;
		edge[k].w = w;
		edge[k].next = edgeHead[u];
		edgeHead[u] = k ++;
	}
	spfa();
	printf("%d\n", dict[n]);
	return 0;
}
