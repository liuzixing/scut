#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <string.h>
#include <stack>

using namespace std;

bool v[100005];
int n,m,t;
bool isprime[100005];
int prime[10005],tot;
char c[3];
int main(){
	int cc = sqrt(100000.0);
	
	for (int i = 2;i <= cc;i++){
		if (!isprime[i]){
			for (int j = i + i ;j <= 100000;j += i)
				isprime[j] = 1;
		}
	}
	for (int i = 2;i < 100000;i++)
		if (!isprime[i])
			prime[tot++] = i;

	scanf("%d%d",&n,&m);
	for (int i = 0;i < m;i++){
		scanf("%s %d",c,&t);
		if (c[0] == '+'){
			if (v[t]){
				printf("Already on\n");
				continue;
			}
			bool flag = false;
			for (int j = 0;j < tot;j++){
				flag = false;
				if (prime[j] <= t && t % prime[j] == 0){
					for (int k = prime[j] ;k <= n;k += prime[j])
						if (v[k])
						{
							printf("Conflict with %d\n",k);
							flag = true;
							break;
						}
				}
				if (flag)
					break;
			}
			if (!flag){
				printf("Success\n");
				v[t] = 1;
			}
		}
		else{
			if (!v[t])
				printf("Already off\n");
			else{
				printf("Success\n");
				v[t] = 0;
			}
		}
	}
}