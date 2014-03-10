#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000002];
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < t;i++)
        scanf("%d",&a[i]);
    sort(a,a + t);
    for (int i = 0;i < t;i++)
        printf("%d\n",a[i]);
}
