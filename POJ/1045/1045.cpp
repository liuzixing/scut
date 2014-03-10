#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
	double Vs,R,C,w;
	int n,i;
	cin >> Vs >> R >> C >> n;
	for (i = 0;i < n ;i++)
	{
		cin >> w;
		printf("%.3f\n",w*C*R*Vs/sqrt(w*w*C*C*R*R+1.0)) ;
	}
}