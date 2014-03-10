#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#include <set>
#include <map>
using namespace std;
int n;
bool f ;
char a[10],b[10],stack[10],*path[20],len;

void check(int topa,int top,int topb)
{
  while (topa <= n && topb < n)
  {
	  if (top != -1 && stack[top] == b[topb])
	  {
		  top--;
		  path[len] = "out";
		  len++;
		  topb++;
	  }
	  else
	  {
		  top++;
		  path[len] = "in";
		  len++;
		  stack[top] = a[topa];
		  topa++;
	  }
  }
  if (topb == n)
	  f = 1;
}
int main()
{
    while (scanf("%d %s %s",&n,&a,&b) != EOF)
    {
        len = 0 ;
        f = 0;

        check(0,-1,0);
        if (!f)
        {
            printf("No.\n");
            printf("FINISH\n");
			continue;
        }
		printf("Yes.\n");
		for (int i = 0;i < len;i++)
			printf("%s\n",path[i]);
		printf("FINISH\n");
    }
}
