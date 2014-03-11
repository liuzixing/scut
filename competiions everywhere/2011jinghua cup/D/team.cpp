#include<iostream>
#define MAXL 1001000
#define L(v) (v<<1)
#define R(v) ((v<<1)+1)
using namespace std;
struct snake_node
{
	int type;
	int pos;
};
struct node
{
	int l,r;
	__int64 number[3][7];//0 for downsnake 1 for upsnake 2 for line
}tree[MAXL*2];
__int64 all[7][MAXL];
int n,m,o;
void next_node(snake_node  &a)
{
	if(a.type==0)
	{
		a.pos++;
		if(a.pos==n) a.type=1;
	}
	else
	{
		a.pos--;
		if(a.pos==1) a.type=0;
	}
}
snake_node cal(snake_node in,int length)
{
	//TODO
	if(in.type==2) return in;
	else
	{
		int a=length%(2*(n-1));
		for(int i=0;i<a;i++)
		{
			next_node(in);
		}
	}
	return in;
}
void deal(int v)
{
	if(tree[v].l==tree[v].r) return ;
	snake_node  re,temp;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			temp.type=j;
			temp.pos=i;
			if(i==1 && j==1) continue;
			if(i==n && j==0) continue;
			re=cal(temp,tree[L(v)].r-tree[L(v)].l+1);
			tree[v].number[j][i]=tree[L(v)].number[j][i]+tree[R(v)].number[re.type][re.pos];
		}
	}
}
void build(int v,int left,int right)
{
	tree[v].l=left;tree[v].r=right;
	if(left==right){
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				tree[v].number[j][i]=(i-1)*m+left;
		return ;
	}
	else
	{
		int mid=(left+right)>>1;
		build(L(v),left,mid);
		build(R(v),mid+1,right);
		deal(v);
	}
}
void init()
{
	build(1,1,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			all[i][j]=(i-1)*m+j;
}
void changetree(int v,int row,int col,int num)
{
	if(tree[v].l==tree[v].r)
	{
		for(int j=0;j<3;j++)
			tree[v].number[j][row]=num;
		return ;
	}
	int mid=(tree[v].l+tree[v].r)>>1;
	if(col<=mid)changetree(L(v),row,col,num);
	else changetree(R(v),row,col,num);
	deal(v);
}
void change(int row,int col,int num)
{
	changetree(1,row,col,num);
	all[row][col]=num;
}
void turn(int col)
{
	int temp=all[n][col];
	for(int i=2;i<=n;i++)
	{
		change(i,col,all[i-1][col]);
		all[i][col]=all[i-1][col];
	}
	change(1,col,temp);
	all[1][col]=temp;
}
__int64 query(int v,int left,int right,snake_node innode)
{
	__int64 re;
	if(tree[v].l==left&&tree[v].r==right)
	{
		re=tree[v].number[innode.type][innode.pos];
	}
	else
	{
		int mid=(tree[v].l+tree[v].r)>>1;
		if(right<=mid) re=query(L(v),left,right,innode);
		else if(left>mid) re=query(R(v),left,right,innode);
		else
		{
			snake_node renode=cal(innode,mid-left+1);
			re=query(L(v),left,mid,innode)+query(R(v),mid+1,right,renode);
		}
	}
//	printf("%d %d %d %d %d\n",left,right,re,innode.pos,innode.type);
	return re;
}
__int64 queryline(int left,int right,int begin)
{
	snake_node temp;
	temp.pos=begin;
	temp.type=2;
	return query(1,left,right,temp);	
}
__int64 querysnake(int left,int right,int begin)
{
	snake_node temp;
	temp.pos=begin;
	if(temp.pos==n)temp.type=1;
	else temp.type=0;

	return query(1,left,right,temp);	
}
int main()
{
	int test;
	char in[20];
	int a,b,c,d;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&n,&m,&o);
		init();
		while(o--)
		{
			scanf("%s",in);
			if(in[0]=='e')
			{
				scanf("%d %d %d %d",&a,&b,&c,&d);
				int t1=all[a][b],t2=all[c][d];
				change(a,b,t2);
				change(c,d,t1);
			}
			else if(in[0]=='r')
			{
				scanf("%d %d %d",&a,&b,&c);
				change(a,b,c);
			}
			else if(in[0]=='t')
			{
				scanf("%d",&a);
				turn(a);
			}
			else if(in[0]=='l')
			{
				scanf("%d %d %d",&a,&b,&c);
				printf("%I64d\n",queryline(a,b,c));
			}
			else if(in[0]=='s')
			{
				scanf("%d %d %d",&a,&b,&c);
				printf("%I64d\n",querysnake(a,b,c));
			}
		}
	}
	return 0;
}
