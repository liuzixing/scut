#include <cmath>
#include <cstdio>
#include <iostream>
const int PSIZE = 10000;

int plist[PSIZE], pcount = 0;
int ff[16],nff[16],ccnt;

bool prime(int n) 
{
	if ((n != 2 && !(n % 2)) || (n != 3 && !(n % 3)) || (n != 5 && !(n % 5)) || (n != 7 && !(n % 7)))
		return false;
	for (int i = 0; plist[i] * plist[i] <= n; ++i)
		if (n % plist[i] == 0)
			return false;
	return n > 1;
}

void initPrime() 
{
	plist[pcount++] = 2;
	for (int i = 3; i <= 10000; i += 2) 
		if (prime(i)) 
			plist[pcount++] = i;
}

int primeFactor(int n, int * f, int * nf)
{
	int cnt = 0;
	int n2 = (int) sqrt((double) n);
	for (int i = 0; n > 1 && plist[i] <= n2; ++i) 
		if (n % plist[i] == 0)
		{
			for (nf[cnt] = 0; n % plist[i] == 0; n /= plist[i]) 
				++nf[cnt];
			f[cnt++] = plist[i];
		}
	if (n > 1) 
	{
		nf[cnt] = 1;
		f[cnt++] = n;
	}
	return cnt;
}

bool go(int n,int mi,int k)
{
	int f[16],nf[16];
	int cnt = primeFactor(n,f,nf);
	int j=0;
	for(int i = 0;i < cnt;++i)
		nf[i] *= mi;
	for(int i = 0;i < cnt && j < ccnt;)
	{
		if(f[i] == ff[j])
		{
			if(nff[j] > nf[i])
				return false;
			++i,++j;
		}
		else if(f[i] > ff[j])
			return false;
		else
			++i;
	}
	return j == ccnt;
}

int main()
{
	int n,m,k;
	initPrime();
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int cur,ans = 0;
		ccnt = primeFactor(k,ff,nff); 
		for(int i = 0;i < n;++i)
		{
			scanf("%d",&cur);
			if(go(cur,m,k))
				++ans;
		}
		printf("%d\n",ans);
	}
}
