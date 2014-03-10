#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    __int64 sum,t,a,n,max;
    cin >> t;
    while (t--)
    {
        max = -1;
        scanf("%I64d",&n);
        sum = 0;
        while (n--)
        {
            scanf("%I64d",&a);
            if (a > max)
            {
                max = a;
            }
            sum += a;
        }
        if (sum - max + 1 >= max)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
