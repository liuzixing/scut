#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
char a[51][51];
int c[2501][2],d[2501][2];
bool v[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m,cc,dd;
void dfs(int x,int y,int b[2501][2],int &bb)
{
    for (int i = 0;i < 4;i++)
    {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if (xx >= 0 && yy >= 0 && xx < n && yy < m)
        {
            if (a[xx][yy] == 'X' && !v[xx][yy])
            {
                b[bb][0] = xx;
                b[bb++][1] = yy;
                v[xx][yy] = 1;
                dfs(xx,yy,b,bb);
            }
        }
    }
}
int main(){
    while (cin >> n >> m){
        int i,j;
        for (i = 0;i < n;i++)
            cin >> a[i];
        for (i = 0;i < n ;i++)
            for (j = 0;j < m ;j++)
                if (a[i][j] == 'X')
                    goto me;
        me:
        cc = dd = 0;
        memset(v,0,sizeof v);
        v[i][j] = 1;
        if (i < n && j < m)
        {
            c[cc][0] = i;
            c[cc][1] = j;
            cc++;
        }
        dfs(i,j,c,cc);
        for (i = 0;i < n;i++)
            for (j = 0;j < m;j++)
                if (a[i][j] == 'X' && v[i][j] == 0)
                    goto me2;
        me2:
        v[i][j] = 1;
        if (i < n && j < m)
        {
            d[dd][0] = i;
            d[dd][1] = j;
            dd++;
        }
        dfs(i,j,d,dd);

        int ans = 31313213;
        for (i = 0;i < cc;i++)
            for (j = 0;j < dd;j++)
                if (ans > abs(c[i][0] - d[j][0]) + abs(c[i][1] - d[j][1]))
                    ans = abs(c[i][0] - d[j][0]) + abs(c[i][1] - d[j][1]);
        printf("%d\n",ans - 1);
    }
}
