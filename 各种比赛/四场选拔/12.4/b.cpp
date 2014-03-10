#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	char s1[100],s2[100];
	while (cin >> s1 >> s2)
	{
		if (s1[0] == 'i')
		{
			if (s1[1] == 't')
			{
				if (s2[0] == 'w')
			    {
			    	printf("it was\n");
			    }
		    	else
		    	{
		    		printf("it is\n");
			    }
			}
			else
			{
				if (s2[0] == 'w')
			    {
			    	printf("I was\n");
			    }
		    	else
		    	{
		    		printf("I am\n");
			    }

			}
			continue;
		}
		if (s1[0] == 'I')
		{
			if (s2[0] == 'w')
			{
                 printf("I was\n");
			}
			else
			{
				printf("I am\n");
			}
			continue;
		}
		if (s1[0] == 'y')
		{
			if (s2[0] == 'w')
			{
				printf("you were\n");
			}
			else
			{
				printf("you are\n");
			}
			continue;
		}
		if (s1[0] == 't')
		{
	        if (s2[0] == 'w')
			{
				printf("they were\n");
			}
			else
			{
				printf("they are\n");
			}
			continue;
		}
		if (s1[0] == 'h')
		{
	        if (s2[0] == 'w')
			{
				printf("he was\n");
			}
			else
			{
				printf("he is\n");
			}
			continue;
		}
	}
	return 0;
}