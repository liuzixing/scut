#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "thelastUpdate.h"
#include "getPoint.h"
using namespace std;

const int ar[2][15] = { 1,3,5,7,9,  11,13,15,17,19, 21,23,25,27,29,
2,4,6,8,10, 12,14,16,18,20, 22,24,26,28,30 };

int main()
{
    clock_t start=clock();
	node b[50][50];
	int i, j, k, state = 0;
	ifstream fin ("input5.txt");
	ofstream fout("output5.txt");
	for (i=0; i<50; i++)
		for (j=0; j<50; j++)
		{
			fin>>num[i][j];
			//48640num[i][j] = rand()%4+2;
			//fout<<num[i][j]<<" ";
		}

		//初始化
		for (i=0; i<50; i++)
			for (j=0; j<50; j++)
				for (k=0; k<num[i][j]; k++)
					b[i][j].a[k] = -10;
		i = j = 0;

		//按照事先设计好的规则，给每个格子填上3个数
		while (i<50 && j<50)
		{
			switch(state)
			{
			case 0:{
				int x = 0;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;
				x = 4;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				i++;
				j--;
				x = 9;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;
				x = 12;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;
				if (j < 50)
				{
					i--;
					state = 1;
				}
				else
				{
					j = 0;
					i++;
					state = 2;
				}
				   }break;

			case 1:{
				int x = 0;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;
				x = 3;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				i++;
				j--;
				x = 8;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;
				x = 12;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[state][x];
					x++;
				}
				b[i][j].length = k;
				j++;

				i--;
				state = 0;
				   }break;

			case 2:{
				int x = 1;
				j++;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[1][x];
					x++;
				}
				b[i][j].length = k;
				j--;
				x = 4;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[1][x];
					x++;
				}
				b[i][j].length = k;
				i++;
				j++;
				x = 7;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[1][x];
					x++;
				}
				b[i][j].length = k;
				j--;
				x = 11;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[1][x];
					x++;
				}
				b[i][j].length = k;
				j += 2;
				if (j < 50)
				{
					i--;
					state = 3;
				}
				else
				{
					j = 0;
					i++;
					state = 0;
				}
				   }break;
			case 3:{
				int x = 1;
				j++;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[0][x];
					x++;
				}
				b[i][j].length = k;
				j--;
				x = 5;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[0][x];
					x++;
				}
				b[i][j].length = k;
				i++;
				j++;
				x = 8;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[0][x];
					x++;
				}
				b[i][j].length = k;
				j--;
				x = 11;
				for (k=0; k<num[i][j]&&k<3; k++)
				{
					b[i][j].a[k] = ar[0][x];
					x++;
				}
				b[i][j].length = k;
				j += 2;
				i--;
				state = 2;
				   }break;
			default:;
			}

		}

		//填满剩余的数字，并优化
		for (int z=0; z<8; z++)
			thefirstupdate(b, 0, 49, 0, 49);

		for(int ca = 0 ; ca < 1; ca++){
		for(int x1 = 0 ; x1 < 50; x1++)
        for(int y1 = 0 ; y1 < 50; y1++)
		{
		    int p = num[x1][y1];
			for(int n1 = 0 ; n1 < p; n1++)
			{
				int x2,y2;
				for(int n2 = n1+1 ; n2 < p; n2++)
				{
					int gain = updateof2point(b,x1,y1,n1,x1,y1,n2);
					//if(gain) printf("%d ",gain);
				}

				for(int i = 0;  i < 8; i++)
				{
					x2 = x1+ dx[i];
					y2 = y1+ dy[i];
					int q = num[x2][y2];
					if((x2>=0 && x2< n && y2 >= 0 && y2< n) ==false)
						continue;
					else
						for(int n2 = 0 ; n2 < q; n2++)
						{
							int gain = updateof2point(b,x1,y1,n1,x2,y2,n2);
							//if(gain) printf("%d ", gain);
						}
				}

				for(int i = 8;  i < 24; i++)
				{
					x2 = x1+ dx[i];
					y2 = y1+ dy[i];
					int q = num[x2][y2];
					if((x2>=0 && x2< n && y2 >= 0 && y2< n) ==false)
						continue;
					else
						for(int n2 = 0 ; n2 < q; n2++)
						{
							int gain = updateof2point(b,x1,y1,n1,x2,y2,n2);
							//if(gain) printf("%d ", gain);
						}
				}
			}
		} }
        for (int z=0; z<8; z++)
			thelastupdate(b, 0, 49, 0, 49);


		for (i=0; i<50; i++)
		{
			for (j=0; j<50; j++)
			{
				//fout<<num[i][j]<<" ";
				for (k=0; k<num[i][j]; k++)
					fout<<b[i][j].a[k]<<" ";
				fout<<", ";
			}
			fout<<endl;
		}

		//for(int i = 0 ; i < n ;i++){
		//for(int j = 0 ; j < n ; j++)
		//printf("%d ",b[i][j].a[0]);
		//printf("\n");)

		cout<<" " << getpoint(b)<<endl;

		clock_t end=clock();
		float time=(float)(end-start)/CLOCKS_PER_SEC;
		printf("%f\n",time);
		system( "PAUSE ");
}
