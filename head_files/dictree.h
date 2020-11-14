// 用指针传递的字典树
#include <string>
using namespace std;
 
#define NUM 26
#define TYPE 'A'
 
class dictree
{
public:
	dictree *child[NUM];
	string *value;//节点所存的数据，根据题目而使用不同的类型或数据
	dictree(){memset(child,0,sizeof(child));value=NULL;}
	~dictree();
	bool insert(string s, string s2);
	string search(string s);
};
//把信息s2插入到结点s处
bool dictree::insert(string s,string s2)
{
	int len,i,j;
	dictree *current,*newnode;
	len=s.length();
	if(len==0)return 0;
	current=this;
	for(i=0;i<len;i++)
	{
		if(current->child[s[i]-TYPE]!=0)
			current=current->child[s[i]-TYPE];
		else
		{
			newnode=(dictree *)malloc(sizeof(dictree));
			for(j=0;j<26;j++)
				newnode->child[j]=0;
			current->child[s[i]-TYPE]=newnode;
			current=newnode;
		}
		if(i == len - 1)current->value=new string(s2);
	}
	return 0;
}
//搜索s结点的信息
string dictree::search(string s)
{
	int len,i;
	string ret = "";
	dictree *current;
	len=s.length();
	if(len==0)return ret;
	current=this;
	for(i=0;i<len;i++)
	{
		if(current->child[s[i]-TYPE]!=0)
			current=current->child[s[i]-TYPE];
		else
			return ret;
		if(i == len - 1)ret = *current->value;
	}
	return ret;
}
dictree::~dictree()
{
	if(this == NULL)
		return;
	for(int i = 0; i < 26; i++)
		delete this->child[i];
	delete value;
}
