#include <cstdio>
#include <algorithm>
using namespace std;

int x,y;
bool v[1000001];
int main(){
	for (int i = 1;i <= 1000000;i++){
		x = i;
		y = i;
		while (y){
			x = x + y % 10;
			y /= 10;
		}
		if(x <= 1000000)
			v[x] = 1;
	}
	for (int i = 1;i <= 1000000;i++)
		if (!v[i])
			printf("%d\n",i);
}