#include <cstdio>
using namespace std;

int main()
{
    int a;
    double b;
    while (~scanf("%d%lf",&a,&b))
    {
        if (a % 5 != 0 || a + 0.5 > b )
            printf("%.2lf\n",b);
        else
            printf("%.2lf\n",b - a - 0.5);
    }
}
