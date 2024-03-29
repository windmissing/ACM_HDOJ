#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10010

int n,m,q;
int tol;//边的个数
int cnt;//点的个数

/*****************并查集，用于把树木合成树**********************/
int root = 0;//添加的虚结点
int father[MAX];
void Merge(int a, int b);
int Find(int a);
/***************************************************************/

/*********************LCA-RMQ-ST*******************************/
struct Edge
{
	int v;
	int len;		//若仅求结点与公共祖先的单位距离，len=1
	Edge* link;
};
struct Node
{
	int rlen;		//到根结点的距离
	Edge* link;
};
Edge buffer[MAX*2];
void Add_Edge(int a, int b, int c);//建树
int index[MAX*2];//第i个访问的结点的编号
int deep[MAX*2];//第i个访问的结点的深度
int first[MAX];//第i个结点是第几个访问的
bool vis[MAX] = {0};//第i个结点是否被访问过
Node node[MAX];
void DFS(int root, int deepth, int rlen);               
int dp[MAX*2][16];   //存放是deep的区间最小值的下标
void RMQ_PRE(int *deep, int n);//求任意两点间的最小值的下标
int RMQ(int l, int r);//已经两个结点的first,求最近公共祖先的first
int LCA(int a, int b);//已经两个结点，求最近公共祖先
/***************************************************************/

void init();
int main()
{
	while(scanf("%d%d%d", &n, &m, &q) != EOF)
	{
		init();

		int a,b,c,i,tm =  m;
		while(tm--)
		{
			scanf("%d%d%d", &a, &b, &c);
			Add_Edge(a,b,c);
			Add_Edge(b,a,c);
			Merge(a,b);
		}

		for(i = 1; i <= n; i++)
			Find(i);
		bool Hash[MAX] = {0};
		for(i = 1; i <= n; i++)
			Hash[father[i]] = 1;
		for(i = 1; i <=  n; i++)
		{
			if(Hash[i])
			{
				Add_Edge(root, i, 0);
				Add_Edge(i, root, 0);
			}
		}
		DFS(root, 0, 0);
		RMQ_PRE(deep, 2*(n+1)-1);

		while(q--)
		{
			scanf("%d%d", &a, &b);
			if(father[a] != father[b])
				printf("Not connected\n");
			else
			{
				c = LCA(a, b);
				printf("%d\n",node[a].rlen + node[b].rlen - 2*node[c].rlen);
			}
		}
	}
	return 0;
}

void init()
{
	int i;
	memset(node, 0, sizeof(node));
	for(i = 0; i <= n; i++)
		father[i] = i;
	tol = 0;
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(first, 0, sizeof(first));
	memset(dp, 0, sizeof(dp));
}

void Add_Edge(int a, int b, int c)
{
	Edge * temp = &buffer[tol++];
	temp->v = b;
	temp->len = c;
	temp->link = node[a].link;
	node[a].link = temp;
}

void Merge(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);
	if(fa < fb)
		father[fb] = fa;
	else if(fa > fb)
		father[fa] = fb;
}

int Find(int a)
{
	int x = a,ret;
	while(x != father[x])
		x = father[x];
	ret = x;
	while(a != ret)
	{
		x = a;
		a = father[a];
		father[x] = ret;
	}
	return ret;
}

void DFS(int root, int deepth, int rlen)
{
	vis[root] = 1;
	node[root].rlen = rlen;

	cnt++;
	index[cnt] = root;
	deep[cnt] = deepth;

	if(first[root] == 0)
		first[root] = cnt;

	Edge *temp = node[root].link;
	while(temp)
	{
		if(vis[temp->v] == 0)
		{
			DFS(temp->v, deepth+1, rlen+temp->len);
			cnt++;
			index[cnt] = root;
			deep[cnt] = deepth;
		}
		temp = temp->link;
	}
}

int LCA(int a, int b)
{
	int fa = first[a];
	int fb = first[b];
	if(fa <= fb)
		return index[RMQ(fa,fb)];
	else
		return index[RMQ(fb,fa)];
}
void RMQ_PRE(int *deep, int n)
{
	int i,j;
	for(i = 1; i <= n; i++)
		dp[i][0] = i;
	for(j = 1; 1<<j <= n; j++)
	{
		int k = 1<<(j-1);
		for(i = 1; i+k < n; i++)
		{
			if(deep[dp[i][j-1]] <= deep[dp[i+k][j-1]])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i+k][j-1];
		}
	}
}

int RMQ(int a, int b)
{
	int dis = abs(b-a)+1;
	int k = log(double(dis)) / log(2.0);
	if(deep[dp[a][k]] <= deep[dp[b-(1<<k)+1][k]])
		return dp[a][k];
	else
		return dp[b-(1<<k)+1][k];
}
