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
vector<edge> adjmap[arraysize]; //vectorʵ���ڽӱ�

int n,m,s,ans;

int main()
{
	int i,l;
	while (~scanf("%d%d%d",&n,&m,&s)){
		for(i=1;i<2 * n+1;++i)       //�˴��ر�ע����ڽӱ���� 
			adjmap[i].clear();
		for(i=0;i<m;++i)         //˫�� 
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


