#include <iostream>
#include <cstdio>
using namespace std;

char f[1024][1024];
int heap[2048];
int n,l;
int main(){
	while (~scanf("%d %d",&n,&l)){
		if (n == 0  && l == 0) break;
		int cost = 0;
		for (int i = 0;i < n;i++)
			scanf("%s",f[i]);
		for (int i = 0;i < l;i++){
			for (int j = 0;j < n;j++)
				heap[n + j] = 1 << (f[j][i] - 'A');
			for (int j = n - 1;j > 0;j--){
				heap[j] = heap[j + j] & heap[j + j + 1];
				if (!heap[j]){
					cost++;
					heap[j] = heap[j + j] | heap[j + j + 1];
				}
			}
			char ch = 'A';
			while (heap[1] >>= 1)
				++ch;
			printf("%c",ch);
		}
		printf(" %d\n",cost);
	}
}