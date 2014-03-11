#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person
{
	int id;
	int salary;
	int height;
	int bossId;
	int sub;
};

bool func1(const Person& p1, const Person& p2)
{
	return p1.salary < p2.salary;
}

bool func2(const Person& p1, const Person& p2)
{
	return p1.id < p2.id;
}

Person p[30000];

int search(int low, int high, int id)
{
	while(low <= high)
	{
		int mid = (low+high)>>1;
		if(p[mid].id == id)
			return mid;
		else if(id < p[mid].id)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

int main()
{
	int cnt;
	int m, q;
	scanf("%d", &cnt);
	while(cnt--)
	{
		memset(p, 0, sizeof(p));		
		scanf("%d%d", &m, &q);
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &p[i].id, &p[i].salary, &p[i].height);
		sort(p, p+m, func1);

		for (int i = 0; i < m; ++i)
		{
			for(int j = i+1; j < m; ++j)
				if(p[i].height <= p[j].height)
				{
					p[i].bossId = p[j].id;
					p[j].sub = p[j].sub + p[i].sub + 1;
					break;
				}
		}
		sort(p, p+m, func2);
		int queryid;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d", &queryid);
			int index = search(0, m-1, queryid);
			printf("%d %d\n", p[index].bossId, p[index].sub);
		}
	}
	return 0;
}