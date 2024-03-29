/*
二维费用背包-完全背包
费用1是忍耐值，费用2是杀怪数量（不用输入，都是1）
因为每个怪都可以杀无限个，所以是完全背包，调用模板即可
*/
#include "Bag2D.h"
#include <iostream>
using namespace std;
 
int main()
{
	int n,m,k,s,i,j;
	while(cin>>n>>m>>k>>s)
	{
		//n：所需的经验值
		V1 = m;//m：保留的忍耐度
		N = k;//k：怪的种类数
		V2 = s;//s：最多杀怪数
		memset(dp, 0, sizeof(dp));
		for(i = 0; i < k; i++)
			cin>>v[i]>>c1[i] ;
		for(i = 0; i < N; i++)
			CompletePack2D(c1[i], 1, v[i]);
		//查找满足value>=n所需要的最小费用1
		for(i = 0; i <= V1; i++)
		{
			for(j = 0; j <= V2; j++)
			{
				if(dp[i][j] >= n)
				{
					cout<<m-i<<endl;
					break;
				}
			}
			//如果j循环以break结束
			if(j <= V2)break;
		}
		//如果i循环不是以break结束
		if(i == V1+1)
			cout<<-1<<endl;
	}
	return 0;
}
