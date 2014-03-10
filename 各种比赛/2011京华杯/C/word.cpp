#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A,B,C,M;
char in[1010];
int hashtable[10100];
int hash()
{
	int i=0;
	int p=0;
	while(in[i])
	{
		p+=A*((i+1)*B+in[i]);
		i++;
	}
	p=p%C;
	return p;
}
bool ok(int a)
{
	int m=M-1,now=a,i;
	for(i=0;i<=C;i++)
	{
		if(now>=hashtable[i])now-=hashtable[i];
		else
		{
			if(m>0)m--;
			else return false;
			if(a>=hashtable[i])now =a-hashtable[i];
			else return false;
		}
	}
	return true;
}
int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	while(testcase--)
	{
		memset(hashtable,0,sizeof(hashtable));
		scanf("%d %d %d %d",&M,&A,&B,&C);
		int word=0;
		while(1)
		{
			scanf("%s",in);
			if(strcmp(in,"END")==0)break;
			word++;
			int p=hash();
			hashtable[p]++;
		}
		if(word==0) printf("0\n");
		else
		{
			int mid,l=0,r=1001000;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(ok(mid))r=mid;
				else l=mid+1;
			}
			printf("%d\n",l);
		}
	}
	return 0;
}
