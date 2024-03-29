/*
两个数论公式：
f(k) = ( (1+sqrt(5)) / 2 ) ^ k - ( (1-sqrt(5)) / 2) ^ k
(1+a)^n = Sum(C(k|n) * (a^k))
推导过程：
  Sum(C(k|n) * f(k))
= Sum(C(k|n) * ( (1+sqrt(5)) / 2 ) ^ k - ( (1-sqrt(5)) / 2) ^ k)
= Sum(C(k|n) * (1+sqrt(5)) / 2 ) ^ k) - Sum(C(k|n) * (1-sqrt(5)) / 2 ) ^ k)
= ( (3+sqrt(5)) / 2 ) ^ k - ( (3-sqrt(5)) / 2) ^ k
= ( (1+sqrt(5)) / 2 ) ^ 2k - ( (1-sqrt(5)) / 2) ^ 2k
= f(2k)
构造矩阵是浮云
Fn(1,2) = |f(n) f(n-1)|
F1(1,2) = |f(1) f(1)| = |1 0|
A(2,2) = |1 1|
		 |1 0|
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	Mat A(2,2),F(1,2);
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &mod);
		if(n == 0)
		{
			printf("0\n");
			continue;
		}
		A.clear(2);A.s[1][1] = 0;
		F.clear(1);
		A.Er_work(n*2-1);
		F.Multiply(A);
		printf("%d\n", F.s[0][0]);
	}
	return 0;
}