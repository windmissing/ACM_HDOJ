/*
由f(n)=f(n-1)+f(n-2)构造矩阵
令
Fn(1,2) = |f(n) f(n-1)|
A(2 2) = |1 1|
		 |1 0|
F1(1 2) = |1 0|
Fn = F(n-1) * A = F1 * A ^ (n-1)
代入n = g(i) = k * i + b 得：Fn = F1 * A ^ (k * i + b - 1)
1)b > 1
Fn = F1 * A^(b-1) * (A^k)^i
Sum(Fn) = F1 * A^(b-1) * Sum((A^k)^i)
2)b = 1
Fn = F1 * (A^k)^i
Sum(Fn) = F1 * Sum((A^k)^i)
3)b = 0
Fn = F1 * A^(k-1) * (A^k)^i------------------n = n - 1
Sum(Fn) = F1 * A^(k-1) * Sum((A^k)^i)--------n = n - 1
其中Sum((A^k)^i)用solve进行二分求和
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	Mat A(2, 2), F1(1, 2), e(2, 2), ans(1, 2), temp(2, 2);
	int b, n, k;
	while(cin>>k>>b>>n>>mod)
	{
		//全1矩阵
		A.clear(2);A.s[1][1] = 0;
		F1.clear(1);
		e.clear(1);
		ans.clear();
 
		temp = A;
		if(b > 1)
		{
			temp.Er_work(b-1);
			F1.Multiply(temp);
		}
		else if(b == 0)
		{
			n--;
			temp.Er_work(k-1);
			F1.Multiply(temp);
		}
		A.Er_work(k);
		A.solve(n-1);
		A.Add(e);
		F1.Multiply(A);
		printf("%I64d\n",F1.s[0][0]);
	}
	return 0;
}