#include <cstdio>
using namespace std;

int main()
{
    int n,k,a,ans = 0;
    scanf("%d%d",&n,&k);
    while (n--)
    {
        scanf("%d",&a);
        if (a % k == 0)
            ans++;
    }
     printf("%d\n",ans);
}
