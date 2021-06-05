/*完全背包
有N种物品和一个容量为V的背包，每种物品都有无限件可用。
第i种物品的费用是c[i]，价值是w[i]。
令f[i][v]表示前i种物品恰放入一个容量为v的背包的最大权值
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v}
优化：f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}*/
void CompletePack(int cost, int value)
{
	int v;
    for( v = cost; v <= V; v++)
	{
		if(dp[v-cost] == -1)continue;
		if(dp[v] == -1)dp[v] = dp[v-cost]+value;
		else dp[v] = min( dp[v], dp[v-cost]+value);
	}
}
```
本题的程序：

```c++
#include "Bag.h"
#include <iostream>
using namespace std;
 
int main()  
{  
    int t, e, f, i;  
    cin>>t;  
    while (t--)  
    {  
        cin>>e>>f>>N;  
        V = f - e; 
        for (i = 0; i < N; i++)   
            cin>>v[i]>>c[i];   
        memset(dp, -1, sizeof(dp));  
        dp[0] = 0;  
		for(i = 0; i < N; i++)
			CompletePack(c[i], v[i]);     
        if (dp[V] == -1)  
            cout << "This is impossible.\n";  
        else  
            cout << "The minimum amount of money in the piggy-bank is " << dp[V] << ".\n";  
    }   
    return 0;  
}  