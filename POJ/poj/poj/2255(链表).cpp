#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int len,pre = 0;;
char preord[30],inord[30];
struct node
{
	char dot;
	node* nextl;
	node* nextr;
};
void buildtree(node *&now,int l,int r)
{
	int i;
	pre++;	
	if (l==r)
	{
		now->dot = inord[l];
		now->nextl = NULL;
		now->nextr = NULL;
		printf("%c",now->dot);
		free(now);
		return;
	}
	for (i = l;i <= r;i++)
		{
			
			if (inord[i] == preord[pre])
			{
				
				now->dot = preord[pre];
				if (i - 1 >= l)
				{
					now->nextl = new node;
					buildtree(now->nextl,l,i-1);
				}
				else
				{
					now->nextl = NULL;
				}
				if (i + 1 <=r)
				{
					now->nextr = new node;
					buildtree(now->nextr,i + 1,r);
				}
				else
				{
					now->nextr = NULL;
				}
				break;
			}
		}
	printf("%c",now->dot);
	free(now);
}
int main()
{

	int i;
	while (scanf("%s %s",&preord,&inord) == 2)
	{
		node *head = new node;
		head->dot = preord[0];
		head->nextl = NULL;
		head->nextr = NULL;
		len = strlen(preord);
		for (i = 0;i < len;i++)
		{
			if (inord[i] == head->dot)
			{
				if (i - 1 >= 0)
				{
					head->nextl = new node;
					buildtree(head->nextl,0,i-1);
				}

				if (i + 1 < len)
				{
					head->nextr = new node;
					buildtree(head->nextr,i + 1,len - 1);
				}
				break;
			}
		}
		printf("%c",head->dot);
		free(head);
	}
	
}