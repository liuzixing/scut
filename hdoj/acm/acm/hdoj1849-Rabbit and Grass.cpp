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
    int i,m,a[1001],ans,p;
    while (scanf("%d",&m) != EOF && m)
    {
        ans = 0;
        for (i = 0;i < m;i++)
        {
            scanf("%d",&a[i]);
            ans ^= a[i];
        }
        if (ans == 0)
        {
            printf("Grass Win!\n");
        } 
        else
        {
            printf("Rabbit Win!\n");
        }
    }
}
