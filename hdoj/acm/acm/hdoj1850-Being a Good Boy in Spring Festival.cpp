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
    int i,j,m,a[101],ans,p,t;
    while (scanf("%d",&m) != EOF && m)
    {
        ans = 0;
        t = 0;
        for (i = 0;i < m;i++)
        {
            scanf("%d",&a[i]);
            t ^= a[i];
        }
        for(j = 0;j < m;j++)
        {
            if (j == 0)
            {
                t ^= a[j];
            }
            else
            {
                t ^= a[j];
                t ^= a[j - 1];
            }
            if (t < a[j])
            ans++;
        }
        printf("%d\n",ans);
    }
}
