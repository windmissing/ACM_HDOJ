/*
1750ms
边长为1，所以用BFS求最短路
对于每一个点，做一次BFS，求出以这个点为出发点时的最短路径树的长度和它包含的边
记录长度是用于求值，记录边是用于优化。因为只有处于最短路径树上的边的改动才会影响到结果
如果要去的边的不在最短路径树上，不影响结果，如果在，则重新计算
优化后还是超时，网上的解题报告都说用short，还是跑了1750ms，可能这题用vector来存储不太合适
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 105
 
struct node
{
	short start;
	short end;
}E[3005];
vector<vector<int> >V(MAX);
short dis[MAX], vis[MAX];
bool hash[MAX][3005];
void BFS(short start, short edge);
int main()
{
	short n, m, i, j, k, a, b, ans, temp;
	bool flag;
	while(scanf("%hd%hd",&n,&m)!=EOF)
	{
		flag = 1;
		for(i = 0; i <= n; i++)
			V[i].clear();
		memset(dis, 0, sizeof(dis));
		memset(hash, 0, sizeof(hash));
		for(i = 0; i < m; i++)
		{
			scanf("%hd%hd",&a,&b);
			E[i].start = a;
			E[i].end = b;
			V[a].push_back(i);
			V[b].push_back(i);
		}
		for(i = 1; i <= n; i++)
		{
			if(!flag)break;
			BFS(i, -1);
			if(i == 1)
			{
				for(j = 1; j <= n; j++)
				{
					if(vis[j] == 0)
					{
						flag = 0;
						break;
					}
				}
			}
			for(j = 1; j <= n; j++)
				dis[i] = dis[i] + vis[j] - 1;
		}
		for(i = 0; i < m; i++)
		{
			if(flag == 0)
			{
				printf("INF\n");
				continue;
			}
			ans = 0;
			for(j = 1; j <= n; j++)
			{
				if(ans == -1)break;
				if(hash[j][i] == 0)
					ans = ans + dis[j];
				else
				{
					temp = 0;
					BFS(j, i);
					for(k = 1; k <= n; k++)
					{
						if(temp == -1)break;
						if(vis[k] == 0)temp = -1;
						else temp = temp + vis[k] - 1;
					}
					if(temp == -1)ans = -1;
					else ans = ans + temp;
				}
			}
			if(ans == -1)
				printf("INF\n");
			else
				printf("%hd\n",ans);
		}
	}
	return 0;
}
 
void BFS(short start,short edge)
{
	memset(vis, 0, sizeof(vis));
	int p, q, i;
	queue<int> Q;
	vis[start] = 1;
	Q.push(start);
	while(!Q.empty())
	{
		p = Q.front();Q.pop();
		for(i = 0; i < V[p].size(); i++)
		{
			q = E[V[p][i]].start + E[V[p][i]].end - p;
			if(vis[q])continue;
//			if(edge!=-1 && ((E[edge].start==p&&E[edge].end==q)||(E[edge].start==q&&E[edge].end==p)))
			if(edge == V[p][i])
				continue;
			if(edge == -1)
				hash[start][V[p][i]] = 1;
			vis[q] = vis[p] + 1;
			Q.push(q);
		}
	}
}