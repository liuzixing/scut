#include <vector>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
#define arraysize 200005
int maxData = 0x7fffffff;
typedef struct edge
{
	int to;
	int w;
}edge;
vector<edge> adjmap[arraysize]; //vector实现邻接表

int n,m,s,ans;

int main()
{
	int i,l;
	while (~scanf("%d%d%d",&n,&m,&s)){
		for(i=1;i<2 * n+1;++i)       //此处特别注意对邻接表清空 
			adjmap[i].clear();
		for(i=0;i<m;++i)         //双向 
		{
			int u,v,w;
			edge temp;
			scanf("%d%d%d",&v,&u,&w);
			temp.to = u;
			temp.w = w;
			adjmap[v].push_back(temp);
			temp.to = v;
			adjmap[u].push_back(temp);      
		}
		dfs(s);
		scanf("%d",&l);
		printf("%d\n",ans);
	}
}


