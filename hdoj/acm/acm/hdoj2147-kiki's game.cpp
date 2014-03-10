//先用画出NP状态图，找规律……
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
    int m,n;
    while (scanf("%d %d",&n,&m) && (n + m))
    {
        if ((n & 1) && (m & 1))
        printf("What a pity!\n");
        else
        printf("Wonderful!\n");
    }
}
