#include <iostream>
#include <cmath>
using namespace std;


#define MAXN 128
#define eps 1e-6
#define DIM 5


int cnt;


int gauss_cpivot(int n,double a[][MAXN],double b[]){
	int i,j,k,row;
	double maxp,t;
	for (k=0;k<n;k++){
		for (maxp=0,i=k;i<n;i++)
			if (fabs(a[i][k])>fabs(maxp))
				maxp=a[row=i][k];
		if (fabs(maxp)<eps)
			return 0;
		if (row!=k){
			for (j=k;j<n;j++)
				t=a[k][j],a[k][j]=a[row][j],a[row][j]=t;
			t=b[k],b[k]=b[row],b[row]=t;
		}
		for (j=k+1;j<n;j++){
			a[k][j]/=maxp;
			for (i=k+1;i<n;i++)
				a[i][j]-=a[i][k]*a[k][j];
		}
		b[k]/=maxp;
		for (i=k+1;i<n;i++)
			b[i]-=b[k]*a[i][k];
	}
	for (i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++)
			b[i]-=a[i][j]*b[j];
	return 1;
}


template <int T>
struct Afpoint{
	Afpoint() {
		for( int i = 0 ; i < T ; i++ )
			x[i] = 0;
	}

	void print(){
		for( int i = 0 ; i < T ; i++ )
			printf("%.2lf ", x[i]);
		//	printf("\n");
	}

	int read() {
		int i = 0;
		while( i < T && cin >> x[i] ) i++;
		if( i == T ) return 1;
		return 0;
	}

	double x[T];
	Afpoint operator / ( double dd ) const;
	Afpoint operator * ( double dd ) const;

};
template< int T>
Afpoint<T> Afpoint<T>::operator /(double dd) const {
	Afpoint<T> ret = *this;
	for( int i = 0 ; i < T ; i++ )
		ret.x[i] /= dd;
	return ret;
}

template< int T>
Afpoint<T> Afpoint<T>::operator *(double dd) const {
	Afpoint<T> ret = *this;
	for( int i = 0 ; i < T ; i++ )
		ret.x[i] *= dd;
	return ret;
}

template <int T>
Afpoint<T> operator + ( Afpoint<T> a, Afpoint<T> b ){
	Afpoint<T> ret = a;
	for( int i = 0 ; i < T ; i++ )
		ret.x[i] += b.x[i];
	return ret;
}


template <int T>
Afpoint<T> operator - ( Afpoint<T> a, Afpoint<T> b ){
	Afpoint<T> ret = a;
	for( int i = 0 ; i < T ; i++ )
		ret.x[i] -= b.x[i];
	return ret;
}

template <int T>
double dis(Afpoint<T> a, Afpoint<T> b ) {
	double sum = 0;
	for( int i = 0 ; i < T ; i++ )
		sum += (a.x[i] - b.x[i])*(a.x[i] - b.x[i]);
	return sqrt(sum);

}

template <int T>
double dot(Afpoint<T> a, Afpoint<T> b) {
	double sum = 0;
	for( int i = 0 ; i < T ; i++ )
		sum += a.x[i] * b.x[i];
	return sum;
}

template <int T>
Afpoint<T> center( int m, Afpoint<T> * p ) {
	int i,j,k;
	double a[DIM+1][MAXN];
	double b[MAXN];
	for( j = 0 ; j < m - 1 ; j++ ){
		for( k = 0 ; k < m - 1 ; k++ ){
			a[j][k] = dot(p[j]-p[m-1],p[k]-p[m-1]);
		}
		b[j] = a[j][j]/2.0;
	}
	Afpoint<T> ret;
	gauss_cpivot(m-1,a,b);
	
	double ss = 1.0;
	for( i = 0 ; i < m - 1 ; i++ )
		ss -= b[i];
	b[m-1] = ss;

	bool flag = true;
	int victim = 0;
	for( i = 1 ; i < m ;i++)
		if( b[i] < b[victim] )
		{
			victim = i;
		}
	if(b[victim] < 0)
	{
		flag = false;
	}
	if(flag)
	{
		for( i = 0 ; i < m ; i++ )
			ret = ret + p[i] * b[i];
		return ret;
	}
	else
	{
		int n = 0;
		Afpoint<T> np[DIM+1];
		for( i = 0 ; i < m ; i++)
			if( i - victim ) np[n++] = p[i];
		return center(n,np);
	}
	

}




Afpoint<DIM> maxcic, p[MAXN];
double r;
int curset[MAXN],posset[DIM+1];
int set_cnt,pos_cnt;

int in_cic(int pt) {
	if( dis(maxcic, p[pt]) < r + eps ) return 1;
	return 0;
}

int cal_mincic() {
	if( pos_cnt == 1 || pos_cnt == 0 ) {
		return 0;
	}
	else{
		Afpoint<DIM> t[DIM+1]; //
		for( int i = 0 ; i < pos_cnt ; i++ )
			t[i] = p[posset[i]];
		maxcic = center(pos_cnt,t);
		r = dis(maxcic,t[0]);

	}
	return 1;
}

int minidisk() {
	cnt++;
	if( set_cnt == 0 || pos_cnt == DIM+1 ){
		return cal_mincic();
	}
	int tt = curset[--set_cnt];
	int res = minidisk();
	set_cnt++;
	if( !res || !in_cic(tt)) {
		set_cnt--;
		posset[pos_cnt++] = curset[set_cnt];
		res = minidisk();
		pos_cnt--;
		curset[set_cnt++] = curset[0];
		curset[0] = tt;
	}
	return res;
}
int n;
bool check()
{int i;
	for(i=0;i<n;i++)
	{
		if(dis(maxcic, p[i])>r+eps)
			return false;
	}
	return true;
	
}


int main(){
	
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	cnt = 0;
	while( scanf("%d",&n) == 1 ){
		int i;
		cnt = 0;
		for( i = 0 ; i < n ; i++ ) p[i].read();
		if( n == 1 ) {
			maxcic = p[0];
			r = 0;
		}
		else {
			set_cnt = n;
			pos_cnt = 0;
			for( i = 0 ; i < n ; i++ ) curset[i] = i;
			minidisk();
		}
		printf("%.2lf\n",r);
		//fprintf(stderr, "%d\n", check());
	}
	return 0;
}
