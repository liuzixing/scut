#include <iostream>
#include "stdio.h"
using namespace std;
struct Node
{
	int num;
	Node * next;
};
bool check (int i,int k)
{
	int j = 1, n, tem, count;
	int a[30] = {0};
	Node *head, *temp;
    n = k * 2;
	head = new Node;
	head ->num = 1;
	temp = new Node;
	head->next = temp;
	while (j < n - 1)
	{
		j++;
		temp->num = j;
		temp->next = new Node;
		temp = temp->next;
	}	
	j++;
	temp->num = j;
	temp->next = head;
	tem = i % n;
    temp = head;
	for (j = 1; j <= k;j++)
	{
		count = 1;
		while (count < tem - 1 )
		{
			temp = temp->next;
			count++;
		}
		if (temp->next->num > k)
		{
			temp->next = temp->next->next;
		}
		else
			return false;
		temp = temp ->next;
	}
	return true;
}
int main()
{
	int k, i;
	scanf ("%d", &k);
	while (k)
	{
		i = k + 1;
		while (!check(i, k))
		{
			i++;
		}
		printf("%d",i);
		scanf ("%d",&k);
	}

    
}
