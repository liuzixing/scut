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

int main()
{
    int m,n,i,j;
    bool f[1200];
    while (scanf("%d %d",&m,&n) != EOF)
    {
        memset(f,0,sizeof(f));
        for (i = m - 1;i >= 0;i--)
        {
            for (j = 1;j <= n;j++)
            if (i + j <= m && f[i + j] == 0)
            {
                f[i] = 1;
                break;
            }
        }
        if (!f[0])
        printf("none\n");
        else
        {
            bool check = 0;
            for (i = 1;i <= n;i++)
            if (!f[i])
            {
                if (!check)
                {
                    printf("%d",i);
                    check = 1;
                }
                else
                {
                    printf(" %d",i);
                }
            }
            printf("\n");
        }
    }
}
