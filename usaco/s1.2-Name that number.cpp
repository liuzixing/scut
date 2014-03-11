/*
ID: benbenq1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int h[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main()
{
	FILE *fin = fopen("namenum.in","r");
	FILE *fout = fopen("namenum.out","w");
	FILE *dict = fopen("dict.txt","r");
	int i;
	bool flag = 0;
	char num[13],tem[13],name[13];
	fscanf(fin,"%s",&num);
	while (fscanf(dict,"%s",&name) != EOF)
	{
		memset(tem,0,sizeof(tem));
		for (i = 0;i < strlen(name);i++)
		{
			tem[i] = '0' + h[name[i] - 'A'];
		}
		if (!strcmp(tem,num))
		{
			fprintf(fout,"%s\n",name);
			flag = 1;
		}
	}
	if (!flag)
	{
		fprintf(fout,"NONE\n");
	}
	fclose(dict);
	fclose(fin);
	fclose(fout);
}