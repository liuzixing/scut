#include <cstdio>
#include <string.h>
using namespace std;

int n,k,q[150001],step[150001];
bool v[200001];

int  bfs(){
	int head = 0,tail = 1;
	q[head] = n;
	v[n] = 1;
	while (head != tail){
		int t[3] = {q[head] + 1,q[head] - 1,q[head] + q[head]};
		for (int i = 0;i < 3;i++){
			if (t[i] >= 0 && t[i] <= k + k && !v[t[i]]){
				q[tail] = t[i];
				step[tail] = step[head] + 1;
				v[t[i]] = 1;
				if (t[i] == k)
					return step[tail];
				tail = (tail + 1) % 150001;
			}
		}
		head = (head + 1) % 150001;
	}
}
int main(){
	while (~scanf("%d %d",&n,&k)){
		if (k <= n){
			printf("%d\n",n - k);
			continue;
		}
		memset(v,0,sizeof v);
		printf("%d\n",bfs());
	}
}