#include<iostream>
#include<time.h>
#include <windows.h> 
#include <stdio.h> 
#define MAXL 1000000
using namespace std;
struct node
{
	int data;
	int point;
}maxdui[MAXL],mindui[MAXL];
int maxl,minl;
int adddui( node dui[],int x,int & dl,bool bigger, node other[])
{
	if(dl==0){dui[1].data=x;dl++;return 1;}
	dl++;
	dui[dl].data=x;
	int now=dl,father=now>>1;
	int address;
	node swap;
	while(father>=1)
	{
		if( (bigger&&dui[father].data<dui[now].data) || 
			(!bigger && dui[father].data>dui[now].data) )
		{
			address=dui[father].point;
			swap=dui[father];
			dui[father]=dui[now];
			dui[now]=swap;

			other[address].point=now;
			now=father;
			father=now>>1;
		}
		else return now;
	}
	return now;
}
void init()
{
	 maxl=minl=0;
}
void debug(){
	int i;
	for(i=0;i<10;i++) printf("%d ",maxdui[i].data);
	printf("%d",maxl);
	printf("\n");
	for(i=0;i<10;i++) printf("%d ",maxdui[i].point);
	printf("\n");
	for(i=0;i<10;i++) printf("%d ",mindui[i].data);
	printf("%d",minl);
	printf("\n");
	for(i=0;i<10;i++) printf("%d ",mindui[i].point);
	printf("\n");
		printf("\n");
}
void add(int x)
{
	int w1=adddui(mindui,x,minl,false,maxdui);
	int w2=adddui(maxdui,x,maxl,true,mindui);
	maxdui[w2].point=w1;
	mindui[w1].point=w2;
}
void deldui(node dui[],int point,int &dl,bool bigger,node other[])
{
	int address,address2;
	node swap;
	address=dui[dl].point;
	dui[point]=dui[dl];
	dl--;
	other[address].point=point;
	int now=point,biao;
	int lc=now<<1,rc=lc+1;
	while(now<=dl)
	{
		if(lc<=dl) 
		{
			if(rc<=dl) 
			{
				if( (bigger &&dui[lc].data>dui[rc].data) ||
					(!bigger &&dui[lc].data<dui[rc].data) )
					biao=lc;
				else biao=rc;
			}
			else biao=lc;
		}
		else
		{
			if(rc<=dl) biao=rc;
			else return ;
		}
		if( (bigger && dui[biao].data>dui[now].data) || 
			(!bigger && dui[biao].data<dui[now].data) )
		{
			address=dui[biao].point;
			address2=dui[now].point;
			swap=dui[biao];
			dui[biao]=dui[now];
			dui[now]=swap;

			other[address].point=now;
			other[address2].point=biao;
			now=biao;
			lc=now<<1;rc=lc+1;
		}
		else return;

	}
}
int del(bool bigger)
{
	int w,returndata;
	if(maxl==0 ||minl==0)return -1;
	if(bigger) 
	{
		returndata=maxdui[1].data;
		w=maxdui[1].point;
		mindui[w].point=0;
		deldui(maxdui,1,maxl,true,mindui);
		deldui(mindui,w,minl,false,maxdui);
	}
	else
	{
		returndata=mindui[1].data;
		w=mindui[1].point;
		maxdui[w].point=0;
		deldui(mindui,1,minl,false,maxdui);
		deldui(maxdui,w,maxl,true,mindui);
	}
	return returndata;
}
void printtime()
{
	SYSTEMTIME sys; 
GetLocalTime( &sys ); 
printf( "ºÁÃë¼¶±ð%03d\n",sys.wMilliseconds); 
}
int main()
{
//	printtime();
	char a[10];int b=1;
	int n;
	init();
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		if(strcmp(a,"pick")==0) {
			scanf("%d",&b);
			add(b);
		}
		else if(strcmp(a,"eat")==0) {
			printf("%d\n",del(true));
		}
		else if(strcmp(a,"throw")==0) {
			printf("%d\n",del(false));
		}
		//debug();
	}
	//printtime();
	return 0;
}
