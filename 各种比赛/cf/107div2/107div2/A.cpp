#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;

int n,k,l,c,d,p,nl,np;
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	printf("%d\n",min(min(k * l/nl,c*d),p/np)/n);
}