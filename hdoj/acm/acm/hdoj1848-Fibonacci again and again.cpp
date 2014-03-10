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

int fibonacci[15];
int k = 15;
int sg[1001];
int SG(int n)
{
    int i,temp,judge[16] = {0};
    for (i = 0;i < k;i++)
    {
        temp = n - fibonacci[i];
        if (temp < 0)
        {
            break;
        }
        if (sg[temp] == -1)
        {
            sg[temp] = SG(temp);
        }
        judge[sg[temp]] = 1;
    }
    for (i = 0;;i++)
    {
        if (!judge[i])
        {
            return i;
        }
    }
}
int main()
{
    int i,m,n,ans,p;
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (i = 2;i < 15;i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    memset(sg,-1,sizeof(sg));
    while (scanf("%d %d %d",&m,&n,&p) != EOF && m + n + p)
    {
        ans = SG(m)^SG(n)^SG(p);
        if (ans == 0)
        {
            printf("Nacci\n");
        }
        else
        {
            printf("Fibo\n");
        }
    }
}
