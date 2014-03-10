#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 10001;
int n,d,t;
int sum[12];//sum[i]��i����i+1���ż�����ֵ

struct node{
	int l,r;
	int level,exp;//����������ȼ��������ֵ
	int min_dis;//���������Ҫ���������С����ϵ��
	int lazy;//�����仹�ж��پ���ϵ��û���ͷŵ�������
}tree[N << 2];

inline void PushUp(int rt){//���ϸ��½ڵ����Ϣ
	int tl = rt << 1,tr = rt << 1 | 1;
	tree[rt].exp = max(tree[tl].exp,tree[tr].exp);
	tree[rt].level = max(tree[tl].level,tree[tr].level);
	tree[rt].min_dis = min(tree[tl].min_dis,tree[tr].min_dis);
}
void build(int l,int r,int rt){//����
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].level = 1;
	tree[rt].exp = 0;
	tree[rt].min_dis = sum[1];
	tree[rt].lazy = 0;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l,mid,rt << 1);
	build(mid + 1,r,rt << 1 | 1);
}

inline void PushDown(int rt){//����lazyֵ
	int l = rt << 1,r = rt << 1 | 1;
	tree[l].exp += tree[l].level * tree[rt].lazy;
	tree[l].lazy += tree[rt].lazy;
	tree[l].min_dis -= tree[rt].lazy;

	tree[r].exp += tree[r].level * tree[rt].lazy;
	tree[r].lazy += tree[rt].lazy;
	tree[r].min_dis -= tree[rt].lazy;
	tree[rt].lazy = 0;
}

void update(int l,int r,int val,int rt){
	int mid = (tree[rt].r + tree[rt].l) >> 1,L = rt << 1,R = rt << 1 | 1;
	if (tree[rt].l == tree[rt].r){//���ΪҶ�ӽڵ㣬������ȼ���exp��min_dis
		tree[rt].exp += tree[rt].level * val;
		while (tree[rt].exp >= sum[tree[rt].level])
			tree[rt].level++;
		tree[rt].min_dis = (sum[tree[rt].level] - tree[rt].exp)/tree[rt].level+((sum[tree[rt].level]-tree[rt].exp)%tree[rt].level!=0);
		return;
	}
	if (l <= tree[rt].l && tree[rt].r <= r){
		if (val >= tree[rt].min_dis){//�������е�Ҫ����
			PushDown(rt);
			update(l,r,val,L);
			update(l,r,val,R);
			PushUp(rt);//����ά��rt����Ϣ
		}
		else{//������û��Ҫ�����ĵ�
			tree[rt].exp += tree[rt].level * val;
			tree[rt].min_dis -= val;
			tree[rt].lazy += val;
		}
		return;
	}
	if (tree[rt].lazy){//��������lazy
		PushDown(rt);
	}
	if (l <= mid) update (l,r,val,L);
	if (mid < r) update(l,r,val,R);
	PushUp(rt);//ÿ��update�����PushUp������Ϊt���ӽڵ���º�t��exp,level,dis_min���п��ܸı�
}
int query(int l,int r,int rt){
	int tl = rt << 1,tr = rt << 1 | 1;
	int mid = (tree[rt].r + tree[rt].l) >> 1,ans = 0;
	if (l <= tree[rt].l && tree[rt].r <= r)
		return tree[rt].exp;
	if (tree[rt].lazy)
		PushDown(rt);
	if (l <= mid) ans = max(ans,query(l,r,tl));
	if (r > mid) ans = max(ans,query(l,r,tr));
	return ans;
}

inline int getint(){
	char c;
	while (c = getchar(),c < '0' || c > '9');
	int r = c - '0';
	while (c = getchar(),c >= '0' && c <= '9')
		r = r * 10 + c - '0';
	return r;
}
int main(){
	int l,r,Case,temp;
	char op[2];
	Case = getint();
	for (int k = 1;k <= Case;k++){
		n = getint();d = getint(); t = getint();
		sum[0] = 0;
		for (int i = 1;i < d;i++)
			sum[i] = getint();
		sum[d] = 1 << 30;
		build(1,n,1);
		printf("Case %d:\n",k);
		while (t--){
			scanf("%s",op);
			l = getint();
			r = getint();
			if (op[0] == 'Q')
				printf("%d\n",query(l,r,1));
			else{
				temp = getint();
				update(l,r,temp,1);
			}
		}
		puts("");
	}
	return 0;
}