/*
令
Fn(1,10) = |f(n) f(n-1) …… f(n-9)|
F9(1,10) = |9 8 7 6 5 4 3 2 1 0|
           |a0 1                |
           |a1   1              |
		   |a2     1            |
		   |a3       1          |
A(10,10) = |a4         1        |
		   |a5           1      |
		   |a6             1    |
		   |a7               1  |
		   |a8                 1|
		   |a9                  |
当n > 9 时
Fn = F9 * (A ^ (n-9))
f(n) = Fn[0][0]
当 n <= 9 时
f(n) = n
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	Mat A(10,10),F(1,10);
	int k,i,ans;
	while(cin>>k>>mod)
	{
		if(k < 10)
		{
			cout<<k<<endl;
			continue;
		}
		A.clear();
		F.clear();
		for(i = 0; i < 10; i++)
			F.s[0][i] = 10-i-1;
		for(i = 0; i < 10; i++)
			cin>>A.s[i][0];
		for(i = 1; i < 10; i++)
			A.s[i-1][i] = 1;
		A.Er_work(k-9);
		F.Multiply(A);
		ans = F.s[0][0];
		cout<<ans<<endl;
	}
	return 0;
}