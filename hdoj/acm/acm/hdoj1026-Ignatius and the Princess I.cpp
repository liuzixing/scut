#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
char g[110][110];
int qx[100100],qy[100100],step[110][110],path[110][110];
void printpath(int tail)
{
    int i,tem;
	if (tail == 0)
		return;
    printpath(path[qx[tail]][qy[tail]]);
	if (g[qx[tail]][qy[tail]] != '.')
	{
		tem = step[qx[tail]][qy[tail]] - (g[qx[tail]][qy[tail]] - '0');
	}
	else
	{
		tem = step[qx[tail]][qy[tail]];
	}
    if (g[qx[path[qx[tail]][qy[tail]]]][qy[path[qx[tail]][qy[tail]]]] != '.')
    {
        for (i = g[qx[path[qx[tail]][qy[tail]]]][qy[path[qx[tail]][qy[tail]]]] - '0';i >= 1 ;i--)
        {
            printf("%ds:FIGHT AT (%d,%d)\n",tem - i - 1,qx[path[qx[tail]][qy[tail]]],qy[path[qx[tail]][qy[tail]]]);
        }
    }
    printf("%ds:(%d,%d)->(%d,%d)\n", step[qx[path[qx[tail]][qy[tail]]]][qy[path[qx[tail]][qy[tail]]]],qx[path[qx[tail]][qy[tail]]],qy[path[qx[tail]][qy[tail]]],qx[tail],qy[tail]);
}
int main()
{
    int m,n,i,j,head,tail,Min,t;
    while (scanf("%d %d",&n,&m) != EOF)
    {
        getchar();
        for (i = 0;i < n;i++)
        {
            cin >> g[i] ;
            getchar();
        }
		memset(step,0,sizeof(step));
        head = 0;
        tail = 1;
        step[0][0] = 1;
		Min = 0x7fffffff;
        qx[0] = 0;
        qy[0] = 0;
        bool flag = 1;
        while (head < tail)
        {
            for (i = 0;i < 4;i++)
            {
                int x = qx[head] + dx[i];
                int y = qy[head] + dy[i];
				int tem = step[qx[head]][qy[head]] + 1;
                if (x >= 0 && x < n && y >= 0 && y < m  && g[x][y] != 'X')
                {
					if (g[x][y] > '0' && g[x][y] <= '9')
					{
						tem += g[x][y] - '0';
					}
					if (step[x][y] == 0 || step[x][y] > tem)
					{
						qx[tail] = x;
						qy[tail] = y;
						step[x][y] = tem;
						path[x][y] = head;
						if (x == n - 1 && y == m - 1)
						{
							if (Min > step[x][y])
							{
								Min = step[x][y];
								t = tail;
							}
							flag = 0;
						}
						tail++;
					}
                }
            }
            head++;
        }

		if (flag)
        {
            printf("God please help our poor hero.\nFINISH\n");
        }
		else
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",step[qx[t]][qy[t]] - 1);
            printpath(t);
            if (g[qx[t]][qy[t]] != '.')
            {
                for (j = g[qx[t]][qy[t]] - '0';j > 0  ;j--)
                {
                    printf("%ds:FIGHT AT (%d,%d)\n",step[qx[t]][qy[t]] - j,qx[t],qy[t]);
                }
            }
            printf("FINISH\n");
		}

    }
}
