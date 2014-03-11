#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#define MAXN 11000
#define MAXE (MAXN*10)
using namespace std;
map<string, int> var2int;


int G[MAXN],vc=0;
int getNo( const char* str )
{
	string t = str;
	if(var2int.count(t))
		return var2int[t];
	return var2int[t] = ++vc;

	
}
unsigned int value[MAXN];
unsigned int dcValue[MAXN];
struct Edge
{
	int d,next;
}edge[MAXE];
int ec;

int addEdge( int s, int e )
{
	++ec;
	edge[ec].d = e;
	edge[ec].next = G[s];
	G[s] = ec;
}

int rmEdge( int s ){
	G[s] = 0;
}

int abs(int v)
{
	return v<0?-v:v;
}


int visitTime[MAXN];
int thisTime;
unsigned int DFS( int s )
{
	int e;
	if(s<0) s=-s;
	visitTime[s] = thisTime;
	e = G[s];
	while( e )
	{ 
		if( visitTime[abs(edge[e].d)] - thisTime ) 
			DFS( edge[e].d );
		e = edge[e].next;
	}
	value[s] = dcValue[s];
	e = G[s];
	while( e )
	{
		if(edge[e].d>0)
			value[s] += value[edge[e].d];
		else value[s] -= value[-edge[e].d];

		e = edge[e].next;
	}
	return value[s];
}

char buf[1024],input[1024];
int isQ( const char* str )
{
	while( *str )
		if( *str++ == '=' ) return 0;
	return 1;
}

char *getLeft( const char* str )
{
	int pos = 0;
	while(*str!='=')
	{
		buf[pos++] = *str++;
		buf[pos] = 0;
	}
	//printf("%s\n",buf);
	return buf;
}
void parse( int left, const char* str )
{
	int pos = 0;
	while(*str++ != '=');
	//printf("%s\n", str);
	int tmp;
	int sign = 1;
	dcValue[left]=0;
	G[left] = 0;
	while(*str)
	{
		tmp = 0;
		while(*str<='9' && *str>='0')
		{
			tmp *= 10;
			tmp += *str -'0';
			str++;
		}
		//if(tmp) printf("num:%d\n", tmp);
		dcValue[left] += sign*tmp;
		if(*str=='+') sign=1,str++;
		else if(*str=='-') sign=-1,str++;
		pos = 0;
		while(*str<='z' && *str>='a')
		{
			buf[pos++] = *str++;
			buf[pos]=0;
		}
		if(pos) addEdge(left, sign*getNo(buf));
	}
}

int main()
{
	while( gets(input) != NULL )
	{
		//printf("%s\n", input);
		if( isQ( input ) )
		{
			++thisTime;
			printf("%u\n", DFS( getNo( input ) ));
		}
		else
		{
			parse( getNo(getLeft(input)), input );
		}
	}
	return 0;

}
