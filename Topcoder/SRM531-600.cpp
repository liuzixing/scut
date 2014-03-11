#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

class NoRepeatPlaylist{
public:
	int f[101][101];
	int numPlaylists(int N,int M,int P){
		memset(f,0,sizeof f);
		if (N == M) return 0;
		for (int i = 1;i <= N;i++){
			for (int j = 1)
	}
};