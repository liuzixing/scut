#include <cstdio>
using namespace std;

int two[31];
int main()
{
    int t,n;
    two[0] = 1;
    for (int i = 1;two[i - 1] < 1000000000;i++)
        two[i] = two[i - 1] * 2;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i = 30;i >= 0;i--)
            if (two[i] <= n)
            {
                printf("%d\n",two[i]);
                break;
            }
    }
    return 0;
}
