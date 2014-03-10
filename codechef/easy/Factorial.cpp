#include <cstdio>
using namespace std;

int five[20];
int main()
{
    int T,n,ans;
    five[0] = 5;
    for (int i = 1;i < 13;i++)
        five[i] = five[i - 1] * 5;
    scanf("%d",&T);
    while (T--)
    {
        ans = 0;
        scanf("%d",&n);
        for (int i = 0;i < 13;i++)
            ans +=  n / five[i];
        printf("%d\n",ans);
    }
}
