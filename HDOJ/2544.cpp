#include <iostream>
using namespace std;
int road[105][105],dis[105],n;
bool In[105];
int Dijkstra(int start, int end);
int main()
{
	int m,a,b,c;
	while(cin>>n>>m && (n||m))
	{
		memset(road, 0, sizeof(road));
		memset(In, 0, sizeof(In));
		memset(dis, 0, sizeof(dis));
		while(m--)
		{
			cin>>a>>b>>c;
			if(road[a][b] == 0 || road[a][b] > c)
			{
				road[a][b] = c;	
				road[b][a] = c;
			}
		}
		cout<<Dijkstra(1,n)<<endl;
	}
}
int Dijkstra(int start, int end)
{
	if(start == end)
		return 0;
	int min,i,temp;
	In[start] = 1;
	while(In[end] == 0)
	{
		min = 0x7FFFFFF;
		for(i = 1; i <= n; i++)
		{
			if(In[i])continue;
			if(road[start][i] && !dis[i])
				dis[i] = road[start][i];
			if(dis[i] && dis[i] < min)
			{
				temp = i;
				min = dis[i];
			}
		}
		if(min == 0x7FFFFFF)
			break;
		In[temp] = 1;
		for(i = 1; i <= n; i++)
			if(road[temp][i] && ! In[i])
				if(!dis[i] || dis[i]>dis[temp]+road[temp][i])
					dis[i] = dis[temp] + road[temp][i];
	}
	if(dis[end])
		return dis[end];
	else return -1;
}