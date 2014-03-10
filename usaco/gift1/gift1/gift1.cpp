// gift1.cpp : 定义控制台应用程序的入口点。
//


/*
ID: benbenq1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct person 
  { 
	int total;
    string name;
	int init()
	{
		total = 0;
		return 0;
	}
  };
	
int main() 
{
	person giver[10], receiver[10], people[10];
    int n, i, j, k;
	int friends[10] = {0};
    string name;

    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> n;
    for (i = 1; i <= n; i++)
	{
		fin>> people[i].name;
	}
	for (i = 1;i <= n; i++)
	{
		fin = fopen("gift1.in");
        fout = fopen("gift1.out");
		fscanf(fin, "%d %d",&people[i].total,&friends[i]);
    	giver[i].total = people[i].total / friends[i] * friends[i];
		for (j = 1; j <= friends[i];j++)
		{
			fin >> name ;
            for (k = 1;k <= n; k++)
			{
				if (name == people[k].name)
				{
					receiver[i].total +=  people[i].total / friends[i];
					break;
				}
			}
		}
	}
	for (i = 1;i <= n; i++)
	{
		fout << people[i].name <<" "<< people[i].total - giver[i].total + receiver[i].total <<endl;
	}
    return 0;
}

