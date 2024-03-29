/*
s[i][j]表示i秒钟后第j个灯的情况
s[i][j] = (s[i-1][j] + s[i-1][j-1]) % 2;
令
Fn(1,len) = |s[i][0] s[i][1] …… s[i][len]|
F0(1,len)为输入状态
A(len len) = |1 1        |
			 |  1 1      |
			 |    ……   |
			 |1         1|
Fn = F0 * A ^ n
这题中模板会超时，要把模板中Multiply()的%放到()外面才可以
*/
#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	Mat A, F;
	mod = 2;
	char str[MAX];  
	int n, len, i;
	while (scanf("%d",&n)!=EOF)
	{
		scanf("%s",str); 
		len = strlen(str);
		F.ReSize(1, len);
		A.ReSize(len, len);
		for(i = 0; i < len; i++)
		{
			F.s[0][i] = str[i]-'0';
			A.s[i][i] = 1;
			if(i==0)
				A.s[len-1][i] = 1;
			else
				A.s[i-1][i] = 1;
		}
		A.Er_work(n);
		F.Multiply(A);
		for(i = 0; i < len; i++)
			printf("%d",F.s[0][i]); 
		printf("\n");
	}
	return 0;
}