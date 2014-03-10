#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char name[3][30] = {"Wide Receiver","Lineman","Quarterback"};
	double x[3][3] = {4.5,150,200,6.0,300,500,5.0,200,300};
	int i;
	double speed,weight,strength;
	while (scanf("%lf %lf %lf",&speed,&weight,&strength) != EOF)
	{
		if (speed + weight + strength < 0.000000000001)
		{
			break;
		}
		bool flag = 1;
		for (i = 0;i < 3;i++)
		{
			if (speed <= x[i][0] && weight >= x[i][1] && strength >= x[i][2])
			{
				printf("%s ",name[i]);
				flag = 0;
			}
		}
		if (flag)
		{
			printf("No positions");
		}
		printf("\n");
	}
}