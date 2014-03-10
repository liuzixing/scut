#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
using namespace std;

__int64 num;
string str;
void output (__int64 k)
{
    int a[1000],p = 0;
    while (k)
    {
        a[p++] = k % 2;
        k /= 2;
    }
    for (int i = p - 1;i >= 0;i--)
    printf("%d",a[i]);
    printf("\n");
}
__int64 solve()
{
    for (int i = 1;i < 1000000;i++)
    {
        __int64 k = num * i;
        int j = str.length() - 1;
        while (k)
        {
            if (k % 2 == (str[j] - '0'))
            j--;
            if (j < 0)
            break;
            k /= 2;
        }
        if (j < 0)
        return num * i;
    }
}
int main()
{
    while (cin >> str)
    {
        scanf("%I64d",&num);
        if (str == "0")
        {
            cout << "0" << endl;
            continue;
        }
        __int64 ans = solve();
        output(ans);
    }
    return 0;
}
