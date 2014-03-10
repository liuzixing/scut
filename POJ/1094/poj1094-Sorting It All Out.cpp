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

const int RANGE = 26;
int g[RANGE][RANGE] = {0};
int inDegree[RANGE] = {0};
int list[RANGE] = {0};
int toposort(int n)
{
    int i,j = 0,u;
    bool multiSolution = false;
    stack<int> stack;
    int in[RANGE];
    memcpy(in,inDegree,sizeof(in));
    memset(list,0,sizeof(list));
    for (i = 0;i < n;i++)
    {
        if (inDegree[i] == 0)
        {
            stack.push(i);
        }
    }
    while (!stack.empty())
    {
        if (stack.size() > 1)
        {
            multiSolution = 1;
        }
        u = stack.top();
        stack.pop();
        list[j++] = u;
        for (i = 0;i < n;i++)
        {
            if (g[u][i])
            {
                if (--in[i] == 0)
                {
                    stack.push(i);
                }
            }
        }
    }
    if (j != n)//ÓÐ»·
    return 1;
    if (multiSolution)
    return 2;
    return 0;
}
int main()
{
    int i,ans,k,n,m;
    char a = 0,b = 0;
    int determined = 0,inconsistency = 0;
    while (scanf("%d %d",&n,&m) != EOF && n + m)
    {
        memset(g,0,sizeof(g));
        memset(inDegree,0,sizeof(inDegree));
        determined = 0;
        inconsistency = 0;
        for (i = 1;i <= m;i++)
        {
            scanf("\n%c<%c",&a,&b);
            if (!inconsistency && !determined)
            {
                if (g[b - 'A'][a - 'A'] == 1)
                {
                    if (!inconsistency && !determined)
                    {
                        printf("Inconsistency found after %d relations.\n",i);
                        inconsistency = 1;
                        continue;
                    }
                }
                g[a - 'A'][b - 'A'] = 1;
                inDegree[b - 'A']++;
                ans = toposort(n);
                if (ans == 0)
                {
                    printf("Sorted sequence determined after %d relations: ", i);
                    for (k = 0;k < n;k++)
                    {
                        printf("%c",list[k] + 'A');
                    }
                    printf(".\n");
                    determined = 1;
                }
                else if(ans == 1)
                {
                    printf("Inconsistency found after %d relations.\n", i);
                    inconsistency = 1;
                }

            }
        }
        if (!determined && !inconsistency)
        {
            printf("Sorted sequence cannot be determined.\n");
        }
    }
}
