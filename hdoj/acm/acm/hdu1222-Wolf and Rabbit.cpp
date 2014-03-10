#include <cstdio>
using namespace std;

int n,m;
int gcd(int x,int y){
    return !y?x:gcd(y,x % y);
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&m);
        if (gcd(n,m) == 1)
            printf("NO\n");
        else printf("YES\n");
    }
}
