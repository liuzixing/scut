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
    int i,j,m,n,ans,c;
    cin >> c;
    bool f[10001];
    while (c--)
    {
        memset(f,0,sizeof(f));
        scanf("%d %d",&n,&m);
        for (i = n - 1;i >= 0;i--)
        {
            for (j = 1;j <= m;j++)
            if (i + j <= n && f[i + j] == 0)
            {
                f[i] = 1;
                break;
            }
        }
        if (f[0])
        printf("Grass\n");
        else
        printf("Rabbit\n");
    }
}
