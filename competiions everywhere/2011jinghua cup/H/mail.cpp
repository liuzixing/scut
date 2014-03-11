//Trie
#include<iostream>
#include<cstring>
using namespace std;

const int kind = 256;
	 
class trie_node
{
public:
	trie_node()
	{
		is_word = false;
		for(int i = 0;i<kind;i++)
			node[i] = NULL;
	}	
	bool is_word ; 
	trie_node *node[kind];
};
	 
class Trie
{
public:		    
	trie_node *root;  
	Trie(){root = NULL;}
	bool trie_search(const char *str);  
	void trie_insert(const char *str);    		 
 
};
bool Trie::trie_search(const char *str) 
{
	trie_node *temp = root;
	for(int i = 0;i<strlen(str);i++)
	{
	
		if(temp->node[str[i]] == NULL)
			return false;
		temp = temp->node[str[i]];

	}
	return temp->is_word;
};

void Trie::trie_insert(const char *str)   
{
	int site;
	if(root == NULL)
		root = new trie_node;
	trie_node *temp = root;
	for(int i = 0;i<strlen(str);i++)
	{
		site = str[i];
		if(temp->node[site] == NULL)
		{
			temp->node[site] = new trie_node;
			temp = temp->node[site];
		}
		else
			temp = temp->node[site];

	}
	temp->is_word = true;
};
		 
int main()
{
	char s[31];	 
	int n;		 
	Trie x;
	scanf("%d",&n);
	getchar();
	while(n--) 		 
	{
		gets(s);
		x.trie_insert(s);
	}
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(s);
		if(x.trie_search(s))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
