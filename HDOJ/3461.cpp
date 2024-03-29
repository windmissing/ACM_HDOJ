/*
这题程序不难，关键想法比较难，以下内容来自别人的空间
如果没有区间存在,答案是26^n,每增加一个区间,n-1(因为这个区间可以变成26种状态~).
但是要注意的是,比如已经有(1,10)和(1,3)在了,此时再增加(4,10)就没有作用了
使用并查集对于[l,r]我们将l,r+1两个点并起,如果新线段的两个点是同一个集合，就不用减了
*/
#include <iostream>
#include "UFS.h"
#include <cmath>
using namespace std;
 
int mod = 1000000007;
int exp(int a, int n);
UFS ufs;
int main()
{
	int n,m, ans;
 
	while(cin>>n>>m)
	{
		ans = n;
		ufs.clear();
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			if(ufs.Find(a) != ufs.Find(b+1))
			{
				ufs.Union(a, b+1);
				ans--;
			}
		}
		cout<<exp(26, ans)<<endl;
	}
	return 0;
}
 
//非递归求幂
int exp(int a, int n)
{
	__int64 temp1 = 1, temp2 = a;
	while(n)
	{
		if(n & 1)
			temp1 =( temp1 * temp2 ) % mod;
		n>>=1;
		temp2 =( temp2 * temp2 ) % mod;
	}
	return temp1;
}
