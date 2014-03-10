#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string>v;
vector<string>::iterator it;

int main()
{
	string ss,res;
	char ch[1000],op;
	int i,j,n;
	while(gets(ch))
	{
		for(i=0;ch[i]!='\0';i++)
		{     
			j=i;
			while(ch[i]==ch[j]&&ch[j]!='\0')
			{
				ss+=ch[j];
				j++;
			}
			v.push_back(ss);
			ss="";i = j-1;
		}
		// for(it=v.begin();it!=v.end();it++)
		//	   cout<<*it<<endl;            //查看子串
		for(it=v.begin(),ss="";it!=v.end();it++)
		{
			if((*it).size()==1)         //子串长度为1
			{
				if((*it)[0]=='1')   //看字符是否为1
					ss+="11";
				else
					ss+=*it;
				if(it+1==v.end())   //如果刚好结束
				{
					res+='1';
					res+=ss;
					res+='1';
				}
			}
			else                         //子串长度不为1
			{
				if(ss.size())         
				{
					res+='1';
					res+=ss;
					res+='1';
					ss="";
				}
				if((*it).size()>9)
				{
					n = (*it).size();
					while(n>9) 
					{
						res += '9';
						res += (*it)[0];
						n -= 9;
					}

					if(n!=1)   
					{
						op = '0' + n;
						res += op;
						res += (*it)[0];
					}
					else            //长度大于9的子串处理最后剩下个数为1的字符
					{
						op = (*it)[0];
						*it = "";
						*it += op;
						it--;
					}
				}
				else
				{
					op = '0' + (*it).size();
					res += op;
					res += (*it)[0];
				}
			}
		}
		cout << res << endl;
		res = "";
		ss = "";
		v.clear();
	}
	return 0;
}
