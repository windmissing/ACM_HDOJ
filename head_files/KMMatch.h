// 带权的二分匹配
#include <queue>
#include <algorithm>
/*********************************************************/
//这些都是KM模板
const int N = 305;//二分图中每一个子图的点的最大数
const int INF = 1<<28;//正无穷
 
bool xckd[N], yckd[N];//在一次DFS中，Xi与Yi是否在交错树上
int  n;//点的个案
int edge[N][N];//二维权值信息用矩阵来存储
int xmate[N], ymate[N];//保存匹配结果
int lx[N], ly[N];//Xi与Yi和标号，即解说中的A[]和B[]
int slack[N];//松弛量
int prev[N];//?
queue<int> Q;
 
bool bfs();//寻找增广路径
void agument(int);
int KMMatch();//KM算法
/*********************************************************/
bool bfs()
{
	while(!Q.empty())
	{
		int p = Q.front(), u = p>>1;
		Q.pop();
		if(p&1)
		{
			if(ymate[u] == -1)
			{
				agument(u);
				return true;
			}
			else
			{
				xckd[ymate[u]] = true;
				Q.push(ymate[u]<<1);
			}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(yckd[i])continue;
				else if(lx[u] + ly[i] != edge[u][i])
				{
					int ex = lx[u] + ly[i] - edge[u][i];
					if(slack[i] > ex)
					{
						slack[i] = ex;
						prev[i] = u;
					}
				}
				else
				{
					yckd[i] = true;
					prev[i] = u;
					Q.push((i<<1)|1);
				}
			}
		}
	}
	return false;
}
 
void agument(int u)
{
	while(u != -1)
	{
		int pv = xmate[prev[u]];
		ymate[u] = prev[u];
		xmate[prev[u]] = u;
		u = pv;
	}
}
 
int KMMatch()
{
	int i, j, mn;
	memset(ly, 0, sizeof(ly));
	for(i = 0; i < n; i++)
	{
		lx[i] = -INF;
		for(j = 0; j < n; j++)
		{
			lx[i] = lx[i]>edge[i][j]?lx[i]:edge[i][j];
		}
	}
	memset(xmate, -1, sizeof(xmate));
	memset(ymate, -1, sizeof(ymate));
	bool agu = true;
	for(mn = 0; mn < n; mn++)
	{
		if(agu)
		{
			memset(xckd, 0, sizeof(xckd));
			memset(yckd, 0, sizeof(yckd));
			for(i = 0; i < n; i++)
				slack[i] = INF;
			while(!Q.empty())
				Q.pop();
			xckd[mn] = true;
			Q.push(mn<<1);
		}
		if(bfs())
		{
			agu = true;
			continue;
		}
		int ex = INF;
		mn--;
		agu = false;
		for(i = 0; i < n; i++)
			if(!yckd[i])
				ex = ex<slack[i]?ex:slack[i];
		for(i = 0; i < n; i++)
		{
			if(xckd[i])
				lx[i] -= ex;
			if(yckd[i])
				ly[i] += ex;
			slack[i] -= ex;
		}
		for(i = 0; i < n; i++)
			if(!yckd[i] && slack[i] == 0)
			{
				yckd[i] = true;
				Q.push((i<<1)|1);
			}
	}
	int cost = 0;
	for(i = 0; i < n; i++)
		cost += edge[i][xmate[i]];
	return cost;
}
