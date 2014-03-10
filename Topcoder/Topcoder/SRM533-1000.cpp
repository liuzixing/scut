#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

class MagicalGirl{
public:
	double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain){
		int N = day.size();

		double w[52];
		//vector<vector<double> >  dp(N, vector<double>(M)); 
		double **dp = new double*[N + 2];
		for (int i = 0;i < N + 2;i++)
			dp[i] = new double[M + 5];
		//double dp[51][101];
		int d[52],g[52];
		bool visited[52];
		memset(visited,0,sizeof visited);
		for (int i = 1;i <= N;i++){
			int early = 100000000,which = 0;
			for (int j = 0;j < N;j++)
				if (!visited[j])
					if (day[j] < early){
						early = day[j];
						which = j;
					}
			visited[which] = true;
			d[i] = day[which];
			w[i] = win[which] / 100.0;
			g[i] = gain[which];
		}
		d[0] = 0;
		for (int i = N;i >= 0;i--)
			for (int j = 1;j <= M;j++){
				if (i == N || (j - (d[i + 1] - d[i]) <= 0))
					dp[i][j] = (d[i] + j) * 1.00;
				else{
					int after = min(M,j - (d[i + 1] - d[i]) + g[i + 1]);
					dp[i][j] = max(dp[i + 1][j - (d[i + 1] - d[i])],
						(1.0 - w[i+1]) * d[i + 1] + 
						w[i + 1] * dp[i + 1][after]);
				}
			}
		return dp[0][M];
	}
}a;

int main(){
	int M,N = 1,tem;
	vector<int> day,win,gain;
	scanf("%d",&M);
	for (int i = 0;i < N;i++){
		scanf("%d",&tem);
		day.push_back(tem);
	}
	for (int i = 0;i < N;i++){
		scanf("%d",&tem);
		win.push_back(tem);
	}
	for (int i = 0;i < N;i++){
		scanf("%d",&tem);
		gain.push_back(tem);
	}
	printf("%.2lf\n",a.maxExpectation(M,day,win,gain));
}