#include <cstdio>
using namespace std;

int m,n,ans;
int main(){
    scanf("%d",&n);
    while (n--){
        ans = 0;
        scanf("%d",&m);
        int k = 2;
        while (m){
            ans += m % k;
            m /= k;
            k++;
        }
        printf("%d\n",ans);
    }
}
