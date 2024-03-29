/*
矩阵结合DP
dp[i][j]表示长度为i的pendant，用了j种珍珠，所构成的方案数，
则dp[i][j] = dp[i-1][j] * j + dp[i-1][j-1] * (k-j+1)。
ans[n]  = dp[1][k]+…+dp[n][k] = ans[n-1] + dp[n][k]。
结合矩阵特性，并在矩阵中同时求出ans
令：
Fn(1,k+1) = |dp[n][1] dp[n][2] …… dp[n][k] ans[n-1]|
F1(1,k+1) = |k                                       |
             |1 k-1            |
			 |   2  k-2        |
A(k+1,k+1) = |		…………   |
			 |				k 1|
			 |                1|
Fn = F1 * A ^ (n-1)
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	int t, n, k, i;
	__int64 ans;
	mod = 1234567891;
	Mat A, F;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &k);
		A.ReSize(k+1, k+1);
		F.ReSize(1, k+1);
		for(i = 0;i < k; ++i)  
        {  
            A.s[i][i+1]=k-i-1;  
            A.s[i][i]=i+1;  
        }
		A.s[k][k] = 1;
		A.s[k-1][k] = 1;
		F.s[0][0] = k % mod;
		//因为求的是ans[n]，所以多乘一次
		A.Er_work(n);
		F.Multiply(A);
		ans = F.s[0][k];
		printf("%I64d\n", ans);
 
	}
	return 0;
}