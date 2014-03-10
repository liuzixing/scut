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

int main()
{
    set<int> a,b,c;
    int n,m,t;
    while (scanf("%d %d",&n,&m) != EOF)
    {
        a.clear();
        b.clear();
        c.clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&t);
            a.insert(t);
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&t);
            b.insert(t);
        }

        set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
        set<int>::iterator it;
        for (it = c.begin();it != c.end();it++)
        if (it == c.begin())
        printf("%d",*it);
        else
        printf(" %d",*it);
        printf("\n");
    }
}
