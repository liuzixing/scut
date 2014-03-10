#include <iostream>
#include <stdio.h>
using namespace std;

void change (char a[],int aa[])
{
	int i,len;
	len = strlen(a);
	for (i = 0;i < len;i++)
	{
		aa[len - i] = a[i] - 'A';
	}
	while (aa[len] == 0)
	{
		len--;
	}
	aa[0] = len;
	return;
}
void add_print(int a[],int b[])
{
	int i;
	if (a[0] < b[0])
		a[0] = b[0];
	for (i = 1;i <= a[0];i++)
	{
		a[i + 1] += (a[i] + b[i]) / 26;
		a[i] = (a[i] + b[i]) % 26;
	}
	if (a[a[0] + 1] > 0)
	{
		a[0]++;
	}
	for (i = a[0];i > 0;i--)
	{
		printf("%c",char(a[i] + 'A'));
	}
	printf("\n");
}
int main()
{
	char a[201],b[201];
	int aa[201],bb[201];
	while (scanf("%s %s",&a,&b) != EOF)
	{
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		change(a,aa);
		change(b,bb);

		add_print(aa,bb);
	}
}