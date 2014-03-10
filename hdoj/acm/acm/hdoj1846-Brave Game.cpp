#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
using namespace std;


int main()
{
    int i,j,c,k,n,m,f[1001];
    cin >> c;
    while (c--)
    {
        scanf("%d %d",&n,&m);
        memset(f,0,sizeof(f));
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= m;j++)
            {
                if (i - j >=0 && !f[i - j])
                {
                    f[i] = 1;
                    break;
                }
            }
        }
        if (f[n])
        {
            printf("first\n");
        }
        else
        {
            printf("second\n");
        }
    }

}
