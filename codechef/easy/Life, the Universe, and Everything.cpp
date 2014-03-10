#include <cstdio>
using namespace std;

int main()
{
    int a;
    while (~scanf("%d",&a))
    {
        if (a != 42)
            printf("%d\n",a);
        else
            break;
    }
    return 0;
}
