#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
    if (!a || !b) return a > b ? a : b;
    for (int t;t = a % b;a = b,b = t);
    return b;
}
int main()
{
    int n,ans;
    while (scanf("%d",&n) != EOF)
    {
        ans = 1;
        for (int i = 2;i < n;i++)
        {
            if (gcd(i,n) == 1)
            ans++;
        }
        printf("%d\n",ans);
    }
}
