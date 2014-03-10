#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <memory.h>
#include<iostream>
#include<algorithm>
#define MAX 110
#define MAXINT 123456789
using namespace std;
struct group_node
{
	int u,v,w;
}group[MAX][MAX];
int group_line[MAX];
int gll;
int road[MAX][MAX];
int min_path[MAX][MAX];
int result;


int n, ts,nv[MAX],bf[MAX][2];//nv就是记录那个集合的
vector<int> map[MAX],f_map[MAX];
int num[MAX];
int f[MAX], fp;
bool used[MAX];

void dfs1(int x) {
bf[x][0] = ts++;
for(int i = 0; i < map[x].size(); ++i) {
   if(bf[map[x][i]][0] == -1) dfs1(map[x][i]);
}
bf[x][1] = ts++;
f[--fp] = x;
}
void dfs2(int x) {
nv[x] = ts;
num[ts]++;
for(int i = 0; i <f_map[x].size(); ++i) {
   if( (nv[f_map[x][i]] < 0)) dfs2(f_map[x][i]);
}
}
void connected() {
 memset(num,0,sizeof(num));
 int i;
fp = n;
ts = 0;
memset(bf, -1, sizeof(bf));
memset(nv, -1, sizeof(nv));
for( i = 0; i < n; ++i) {
   if(bf[i][0] == -1) dfs1(i);
}
ts = 0;
for(i = 0; i < n; ++i) {
   if(nv[f[i]] < 0) {
    dfs2(f[i]);
    ++ts;
   }
}
}
void init()
{
int i;
for(i=0;i<n+1;i++) 
  {
   map[i].clear();
   f_map[i].clear();
  }
}
void addpath(int a,int b)
{
	map[a].push_back(b);
	f_map[b].push_back(a);
}
//**************************
/*int n,ts;
int mat[MAX][MAX];
int nv[MAX];
int find_components(int n,int mat[][MAXN],int* id){
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN],i,j,k,t;
	for (k=0;k<n;id[k++]=0);
	for (k=0;k<n;k++)
		if (!id[k]){
			for (i=0;i<n;i++)
				a[i]=b[i]=c[i]=d[i]=0;
			a[k]=b[k]=1;
			for (t=1;t;)
				for (t=i=0;i<n;i++){
					if (a[i]&&!c[i])
						for (c[i]=t=1,j=0;j<n;j++)
							if (mat[i][j]&&!a[j])
								a[j]=1;
					if (b[i]&&!d[i])
						for (d[i]=t=1,j=0;j<n;j++)
							if (mat[j][i]&&!b[j])
								b[j]=1;
				}
			for (ret++,i=0;i<n;i++)
				if (a[i]&b[i])
					id[i]=ret;
		}
	return ret;
}
*/
//***************************
bool groupok(int now)
{
	group_line[gll++]=now;
	int i,next_number=0,pre_number=0,temp=-1;
	for(i=0;i<ts;i++)
	{
		if(group[now][i].w!=0){
			next_number++;
			temp=i;
		}
		if(group[i][now].w!=0)
		{
			pre_number++;
		}
	}
	if(pre_number<=1)
	{
		if(next_number==1)
		{
			if(groupok(temp)) return true;
			else return false;
		}
		else if(next_number==0) return true;
		else return false;
	}
	else return false;
}
bool ok()
{
	if(groupok(nv[0]) && gll==ts) return true;
	else return false;
}

void floyd()
{
	int i,j,k;

	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		 if(i==j) min_path[i][j]=0;
		 else if(road[i][j]>0) min_path[i][j]=road[i][j];
		 else min_path[i][j]=MAXINT;

	for(k=0;k<n;k++)
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   if(min_path[i][k]+min_path[k][j]<min_path[i][j])
		   min_path[i][j]=min_path[i][k]+min_path[k][j];
}
int find_road(int city,int start,int end)
{
	//TODO
	//cout<<city<<" "<<start<<" "<<end<<endl;
	int next_per[10];
	int nl=1,i,length;
	for(i=0;i<n;i++)
	{
		if(nv[i]==city)
		{
			if(i!=start && i!=end){
				next_per[nl++]=i;
			}
		}
	}
	next_per[0]=start;
	length=nl;
	if(end!=-1) {next_per[nl]=end;length++;}
	int best=MAXINT;
	do
	{
		int result=0;
		for(i=0;i<length-1;i++)
		{
			result+=min_path[next_per[i]][next_per[i+1]];
		}
		if(result<best)best=result;
	}while(next_permutation(next_per+1,next_per+nl));
	return best;
}
int startpoint(int city)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(group[i][city].w!=0) return group[i][city].v;
	}
	return 0;
}
int endpoint(int city)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(group[city][i].w!=0) return group[city][i].u;
	}
	return -1;
}
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	int i,j;
	int m,u,v,w;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) return 0;
		scanf("%d",&m);
		init();
		memset(road,0,sizeof(road));
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			addpath(u,v);
			road[u][v]=w;
		}
		connected();
	//	ts=find_components(n,mat,nv);
		memset(group,0,sizeof(group));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(road[i][j]!=0 &&nv[i]!=nv[j]){
					group[nv[i]][nv[j]].u=i;
					group[nv[i]][nv[j]].v=j;
					group[nv[i]][nv[j]].w=road[i][j];
				}
			}
		}
		gll=0;
		if(ok())
		{
			result=0;
			int city;
			floyd();
			for(int i=0;i<gll;i++)
			{
				city=group_line[i];
				if(i==0) result+=find_road(city,0,endpoint(city));
				else if(i==gll-1) result+=find_road(city,startpoint(city),-1);
				else result+=find_road(city,startpoint(city),endpoint(city));

				if(i!=gll-1) result+=group[group_line[i]][group_line[i+1]].w;
				//printf("%d\n",result);
			}
			printf("%d\n",result);
		}
		else printf("-1\n");
	}
	return 0;
}
