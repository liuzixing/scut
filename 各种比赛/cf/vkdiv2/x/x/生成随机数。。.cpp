#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <fstream>
#include "getpoint.h"

using namespace std;

int main(){
	freopen("test.txt","r",stdin);
	srand(time(0));
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++){
			scanf("%d",&num[i][j]);
			//num[i][j] = 5;
			for (int k = 0;k < num[i][j];k++)
				bb[i][j].a[k] = rand()%30 + 1;
		}
	for (int i = 0;i < 50;i++)
		thelastupdate(bb,0,49,0,49);
	printf("%d\n",getpoint(bb,0,49,0,49));
}