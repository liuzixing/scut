#include <iostream>
#include <cstdio>
using namespace std;
int a,n,c;
bool flag;
int main(){
    while (scanf("%d",&n)!=EOF){
        flag = c = 0;
        for (int i = 0;i < n;i++){
            scanf("%d",&a);
            if (a == 1 && !flag && i != n-1) c++;
            else flag = 1;
        }
        if (c % 2 == 0 || n == 1) printf("Alice\n");
        else printf("Bob\n");
    }
}
