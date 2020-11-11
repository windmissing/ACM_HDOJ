#include <iostream>
using namespace std;
#define MAXN 105
#define MAXV1 105
#define MAXV2 105
int c1[MAXN], c2[MAXN], v[MAXN], dp[MAXV1][MAXV2];
int N, V1, V2;
 
/*
二维费用的背包问题
有N件物品,每件物品，具有两种不同的费用,最大费用分别为V1和V2；
选择这件物品必须同时付出这两种代价；
第i件物品所需的两种代价分别为c1[i]和 c2[i]，物品的价值为w[i]。
f[i][v][u]=max{f[i-1][v][u],f[i-1][v-a[i]][u-b[i]]+w[i]}
*/
 
//0-1背包
void ZeroOnePack2D(int cost1, int cost2, int value)
{
	int v1, v2;
    for( v1 = V1; v1 >= cost1; v1--)
	{
		for(v2 = V2; v2 >= cost2; v2--)
			dp[v1][v2] = max( dp[v1][v2], dp[v1-cost1][v2-cost2]+value);
	}
}
 
//完全背包
void CompletePack2D(int cost1, int cost2, int value)
{
	int v1, v2;
    for( v1 = cost1; v1 <= V1; v1++)
	{
		for(v2 = cost2; v2 <= V2; v2++)
			dp[v1][v2] = max( dp[v1][v2], dp[v1-cost1][v2-cost2]+value);
	}
}
