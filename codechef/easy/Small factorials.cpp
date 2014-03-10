#include <cstdio>
#include <string.h>
using namespace std;

int t,n;
int ans[160],a[160];
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i = 2;i < 160;i++)
            ans[i] = 0;
        ans[0] = ans[1] = 1;
        for (int i = 2;i <= n;i++)
        {
            int l = ans[0] + 2;
            for (int j = 1;j < 160;j++)
                a[j] = 0;
            for (int j = 1;j <= l;j++)
            {
                a[j] += ans[j] * i;
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
            while (a[l] == 0)
                l--;
            for (int i = 1;i <= l;i++)
                ans[i] = a[i];
            ans[0] = l;
        }
        for (int i = ans[0];i > 0;i--)
            printf("%d",ans[i]);
        puts("");
    }
}
