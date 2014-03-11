#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <memory.h> 
#include <stack> 

using namespace std; 

#define N 362882 

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; 
int flag[10]; 
int dx[] = {1, -1, 0, 0};   //这个数组可以去掉，之前用的是一维转二维，所以用到这个数组 
int dy[] = {0, 0, -1, 1};  //这个数组可以去掉，之前用的是一维转二维，所以用到这个数组 
char *s1 = "dulr"; 
char *s2 = "udrl"; 
int a[3][3]; 

struct node 
{ 
	int a[9]; 
	int sp; 
	int zero; 
} q1[N/2], q2[N/2], start, over; 

char op1[N], op2[N]; //记录每个状态的操作 
int p1[N] = {0}, p2[N] = {0};  //记录当前状态的上一个状态 

int cantor(node a)   //康拓展开，查看a.a[]的数组组成的数在排列中是第几大 
{ 
	memset(flag, 0, sizeof(flag)); 
	int i, j, num; 
	int ans = 0; 
	for(i = 0; i < 9; i++) 
	{ 
		num = 0; 
		for (j = 0; j < a.a[i]; j++) 
			if(!flag[j]) 
				num++; 
		flag[a.a[i]] = 1; 
		ans += num * fact[8-i]; 
	} 
	return ans; 
} 

void dbfs() 
{ 
	int visit1[N] = {0}, visit2[N] = {0}; //当前状态是否访问过 
	int head1, head2, tail1, tail2; 
	head1 = head2 = 0; 
	tail1 = tail2 = -1; 
	node temp1, temp2, cur1, cur2; 
	q1[++tail1] = start; 
	q2[++tail2] = over; 
	int index1, index2; 
	index1 = cantor(start); 
	index2 = cantor(over); 
	p1[index1] = index1; 
	p2[index2] = index2; 
	visit1[index1] = 1; 
	visit2[index2] = 1; 
	int i, j, k, jj, kk; 
	int t1, t2, tt; 
	int v; 
	while(head1 <= tail1 || head2 <= tail2) 
	{ 
		if(head1 <= tail1) 
		{ 
			temp1 = q1[head1++]; 
			index1 = cantor(temp1); 
			if(visit2[index1]) 
			{ 
				stack<char>q; 
				v = index1; 
				while(p1[v] != v) 
				{ 
					q.push(op1[v]); 
					v = p1[v]; 
				} 
				while(!q.empty()) 
				{ 
					printf("%c", q.top()); 
					q.pop(); 
				} 
				v = index1; 
				while(p2[v] != v) 
				{ 
					printf("%c", op2[v]); 
					v = p2[v]; 
				} 
				printf("\n"); 
				return ; 
			} 
			jj = temp1.zero / 3; 
			kk = temp1.zero % 3; 
			for(i = 0; i < 4; i++) 
			{ 
				j = jj + dx[i]; 
				k = kk + dy[i]; 
				cur1 = temp1; 
				if(j >= 0 && j < 3 && k >= 0 && k < 3) 
				{ 
					t1 = 3 * j + k; //所要交换的新的点的位置 
					t2 = temp1.zero; //为x的点的位置 

					tt = cur1.a[t1];         //交换两个位置 
					cur1.a[t1] = cur1.a[t2]; 
					cur1.a[t2] = tt; 

					cur1.zero = t1; 
					t1 = cantor(cur1); 
					if(!visit1[t1])  //还没被访问过 
					{ 
						visit1[t1] = 1; 
						p1[t1] = index1; 
						op1[t1] = s1[i]; 
						if(visit2[t1]) //当前节点在另一个方向上已经被访问过 
						{ 
							stack<char>q; 
							v = t1; 
							while(p1[v] != v) 
							{ 
								q.push(op1[v]); 
								v = p1[v]; 
							} 
							while(!q.empty()) 
							{ 
								printf("%c", q.top()); 
								q.pop(); 
							} 
							v = t1; 
							while(p2[v] != v) 
							{ 
								printf("%c", op2[v]); 
								v = p2[v]; 
							} 
							printf("\n"); 
							return ; 
						} 
						q1[++tail1] = cur1; //入队列 
					} 
				} 
			} 
		} 
		if(head2 <= tail2) 
		{ 
			temp2 = q2[head2++]; 
			index2 = cantor(temp2); 
			if(visit1[index2])  //已经被另一个方向访问过了，结束 
			{ 
				stack<char>q; 
				v = index2; 
				while(p1[v] != v) 
				{ 
					q.push(op1[v]); 
					v = p1[v]; 
				} 
				while(!q.empty()) 
				{ 
					printf("%c", q.top()); 
					q.pop(); 
				} 
				v = index2; 
				while(p2[v] != v) 
				{ 
					printf("%c", op2[v]); 
					v = p2[v]; 
				} 
				printf("\n"); 
				return ; 
			} 
			jj = temp2.zero / 3; 
			kk = temp2.zero % 3; 
			for(i = 0; i < 4; i++) 
			{ 
				j = jj + dx[i]; 
				k = kk + dy[i]; 
				cur2 = temp2; 
				if(j >= 0 && j < 3 && k >= 0 && k < 3) 
				{ 
					t1 = 3 * j + k; 
					t2 = temp2.zero; 

					tt = cur2.a[t1]; 
					cur2.a[t1] = cur2.a[t2]; 
					cur2.a[t2] = tt; 

					cur2.zero = t1; 
					t1 = cantor(cur2); 
					if(!visit2[t1]) 
					{ 
						visit2[t1] = 1; 
						p2[t1] = index2; 
						op2[t1] = s2[i]; 
						if(visit1[t1]) 
						{ 
							stack<char>q; 
							v = t1; 
							while(p1[v] != v) 
							{ 
								q.push(op1[v]); 
								v = p1[v]; 
							} 
							while(!q.empty()) 
							{ 
								printf("%c", q.top()); 
								q.pop(); 
							} 
							v = t1; 
							while(p2[v] != v) 
							{ 
								printf("%c", op2[v]); 
								v = p2[v]; 
							} 
							printf("\n"); 
							return ; 
						} 
						q2[++tail2] = cur2; 
					} 
				} 
			} 
		} 
	} 

} 

bool isSolveable (node s)      //移动奇数个位置，奇偶性改变（逆序数推论） 
{ 
	int n = 0, num = 0, i, j, arr[10]; 
	for (i = 0; i < 9; i++) 
	{ 
		if (s.a[i] != 0) arr[++n] = s.a[i]; 
	} 
	for (i = 0; i <= 8; i++) 
	{ 
		for (j = i + 1; j <= 8; j++) 
		{ 
			if (arr[i] > arr[j]) num++; 
		} 
	} 
	if (num & 0x1) return false; 
	return true; 
} 

char s[10]; 

int main() 
{ 
	//    freopen("a.in","r",stdin); 
	while(cin >> s[0]) 
	{ 
		int i; 
		for(i = 1; i < 9; i++) 
			cin >> s[i]; 
		for(i = 0; i < 9; i++) 
			if(s[i] == 'x') 
			{ 
				start.a[i] = 0; 
				start.zero = i; 
			} 
			else 
				start.a[i] = s[i] - '0'; 
		start.sp = 0; 
		over.sp = 0; 
		over.zero = 8; 
		for(i = 0; i < 8; i++) 
			over.a[i] = i + 1; 
		over.a[8] = 0; 
		if (isSolveable(start)) 
			dbfs(); 
		else 
			printf("unsolvable\n"); 
	} 
	return 0; 
} 
