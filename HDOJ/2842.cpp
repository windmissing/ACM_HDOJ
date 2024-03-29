/*
取下前n个环步骤是先取下前n-2个环，再取下第n个环，再还原前n-2个环，最后取下前n-1个环。
递推公式：f(n) = f(n-1) + 2 * f(n-2) + 1
构造矩阵：
Fn(1,3) = |f(n) f(n-1) 1|
F2(1,3) = |f(2) f(1) 1| = |2 1 1|
         |1 1 0|
A(3,3) = |2 0 0|
         |1 0 1|
Fn = F2 * A^(n-2)
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int a[3][3] = {1,1,0,2,0,0,1,0,1};
int main()
{
	Mat A(3,3),F(1,3);
	int s, i, j;
	mod = 200907;
	while(cin>>s && s)
	{
		if(s < 3)
		{
			cout<<s<<endl;
			continue;
		}
		A.clear();
		F.clear(2);F.s[0][0] = 2;
		for(i = 0; i < 3; i ++)
		{
			for(j = 0; j < 3; j++)
				A.s[i][j] = a[i][j];
		}
		A.Er_work(s-2);
		F.Multiply(A);
		cout<<(int)F.s[0][0]<<endl;
	}
	return 0;
}