#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

vector <int> stamps;
vector <int> customers;
map <int,int> cnt;
vector <int> tem;
vector <int> result;
/*������շ��䷽����Result[0] :��ǰ���䷽������Ʊ�����࣬Result[1]:��ǰ���䷽������Ʊ����Ŀ��Result[2]:��ŵ�ǰ���䷽���е�����ֵ���ģ�����ľʹ��ÿ����Ʊ����Ŀ��*/

int request;
bool Tie;

void updeta()
{
	if (tem[0] > result[0])
	{
		result = tem;
	}
	else if (tem[0] == result[0] && tem[1] < result[1])
	{
		result = tem;
	}
	else if (tem[0] == result[0] && tem[1] == result[1] && tem[2] > result[2])
	{
		result = tem;
	}
	else if (tem[0] == result[0] && tem[1] == result[1] && tem[2] == result[2] && result != tem)
	{
		Tie = true;
	}
	if (result == tem)
		Tie = false;
}
void solve(int n,int r)
{
	if (tem[1] > 4)
		return;
	if (r == request)
		updeta();
	for (int i = n;i >= 0;i--)
	{
		if (r + stamps[i] <= request)
		{
			int tp = tem[0];
			if (i != n || tem[0] == 0)
				tem[0]++;
			tem[1]++;
			int t = tem[2];
			if (stamps[i] > tem[2])
				tem[2] = stamps[i];
			tem[3 + i]++;
			solve(i,r + stamps[i]);
			if (tp < tem[0])
				tem[0]--;
			tem[1]--;
			tem[2] = t;
			tem[3 + i]--;
		}
	}
}
void print()
{
	cout << request << " ";
	if (Tie)
		cout << "(" <<result[0] << "): tie" << endl;
	else if (result[0] == 0)
		cout << "---- none" << endl;
	else
	{
		cout << "(" <<result[0] << "):";
		for (int i = 3;i < result.size();i++)
			for (int j = 0;j < result[i];j++)
				cout << " " << stamps[i - 3];
		cout << endl;
	}
}

void init(int t)
{
	request = customers[t];
	tem.assign(3 + stamps.size(),0);
	result.assign(3 + stamps.size(),0);
	Tie = false;
	solve(stamps.size() - 1,0);
	print();
}
int main()
{
	int t;
	while (cin >> t && t)
	{
		cnt[t]++;
		stamps.push_back(t);
		while (cin >> t && t)
		{
			if (cnt[t]++ < 5)
				stamps.push_back(t);
		}
		while (cin >> t && t)
		{
			customers.push_back(t);
		}
		sort(stamps.begin(),stamps.end());
		for (int i = 0;i < customers.size();i++)
			init(i);
		cnt.clear();
		customers.clear();
		stamps.clear();
	}
}