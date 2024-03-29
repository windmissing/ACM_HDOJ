#include <iostream>
using namespace std;
 
struct node
{
	int price;
	int value;
}t[11][105];
int n,m,k;
int f[11][10005];
 
void test1();
 
int main()
{
	while(cin>>n>>m>>k)
	{
		int i,j,l;
		for(i = 0; i < 11; i++)
			t[i][0].price = 0;
		memset(f,-1,sizeof(f));
		int a,b,c;
		for(i = 0; i < n; i++)
		{
			cin>>a>>b>>c;
			t[a][0].price++;
			int temp = t[a][0].price;
			t[a][temp].price = b;
			t[a][temp].value = c;
		}
		for(i=0;i<=m;i++)
			f[0][i]=0;
		for(i = 1; i <= k; i++ )//组数循环
		{
			for(j = 1; j <= t[i][0].price; j++)//物品循环，t[i][0].price是第i组物品的数量
			{
				for(l =m; l >= t[i][j].price; l--)//价格循环
				{
					//组内DP，对于每一组物品，价格为l时的最大价值
					if(f[i][l] < f[i][l-t[i][j].price] + t[i][j].value && f[i][l-t[i][j].price] != -1)
						f[i][l] = f[i][l-t[i][j].price] + t[i][j].value;
					//组间DP，加入当前组物品，对于价格为l时的最大价值
					if(f[i][l] < f[i-1][l-t[i][j].price] + t[i][j].value && f[i-1][l-t[i][j].price] != -1)
						f[i][l] = f[i-1][l-t[i][j].price] + t[i][j].value;
				}
			}
		}
		if(f[k][m] == -1)
			cout<<"Impossible"<<endl;
		else
			cout<<f[k][m]<<endl;
	}
	return 0;
}
